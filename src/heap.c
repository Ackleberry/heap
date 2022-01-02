/*******************************************************************************
 * @file   heap.c
 *
 * @brief  Heap implementation
 *
 * @author Brooks Anderson <bilbrobaggins@gmail.com>
 ******************************************************************************/

/*============================================================================*
 *                              I N C L U D E S                               *
 *============================================================================*/
#include "heap.h"

/*============================================================================*
 *                      P U B L I C    F U N C T I O N S                      *
 *============================================================================*/

void Heap_Init(Heap_t *pObj, void *pBuf, size_t bufSize, size_t dataSize)
{
    pObj->size = 0;
    pObj->pBuf = pBuf;
    pObj->bufSize = bufSize;
    pObj->dataSize = dataSize;
}

bool Heap_IsEmpty(Heap_t *pObj)
{
    return pObj->size == 0;
}

bool Heap_IsFull(Heap_t *pObj)
{
    return pObj->size == (pObj->bufSize / pObj->dataSize);
}

Heap_Error_e Heap_Insert(Heap_t *pObj, void *pDataInVoid)
{
    Heap_Error_e err = Heap_Error_None;
    uint8_t *pDataIn = (uint8_t *)pDataInVoid;

    if (Heap_IsFull(pObj))
    {
        err = Heap_Error;
    }
    else
    {
        /* Adjust heap based off incoming data */
        size_t curIdx = pObj->size;
        size_t parentIdx = curIdx / 2;
        while (curIdx > 0 && (*pDataIn > pObj->pBuf[parentIdx]))
        {
            pObj->pBuf[curIdx] = pObj->pBuf[parentIdx];
            curIdx = parentIdx;
            parentIdx = curIdx / 2;
        }

        /* Insert data */
        pObj->pBuf[curIdx] = *pDataIn;
        pObj->size++;
    }

    return err;
}

Heap_Error_e Heap_Extract(Heap_t *pObj, void *pDataOutVoid)
{
    Heap_Error_e err = Heap_Error_None;
    uint8_t *pDataOut = pDataOutVoid;

    if (Heap_IsEmpty(pObj))
    {
        err = Heap_Error;
    }
    else
    {
        /* Copy the root element out */
        *pDataOut = pObj->pBuf[0];

        /* Copy last element into root */
        pObj->pBuf[0] = pObj->pBuf[pObj->size - 1];

        /* Reduce heap size by 1 */
        pObj->size--;

        /* Adjust heap */
        size_t mPos;
        size_t iPos = 0;
        size_t lPos;
        size_t rPos;
        uint8_t tempRoot = pObj->pBuf[0];

        while (1)
        {
            /* Select the larger child element */
            lPos = (2 * iPos) + 1;
            rPos = (2 * iPos) + 2;

            if ((lPos < pObj->size) && (pObj->pBuf[lPos] > pObj->pBuf[iPos]))
            {
                mPos = lPos;
            }
            else
            {
                mPos = iPos;
            }

            if ((rPos < pObj->size) && (pObj->pBuf[rPos] > pObj->pBuf[mPos]))
            {
                mPos = rPos;
            }

            if (mPos == iPos)
            {
                break;
            }
            else
            {
                uint8_t temp = pObj->pBuf[mPos];
                pObj->pBuf[mPos] = pObj->pBuf[iPos];
                pObj->pBuf[iPos] = temp;
                iPos = mPos;
            }
        }
    }

    return err;
}