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
    pObj->size = 1;
    pObj->pBuf = pBuf;
    pObj->bufSize = bufSize;
    pObj->dataSize = dataSize;
}

bool Heap_IsEmpty(Heap_t *pObj)
{
    return pObj->size == 1;
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
        /* Adjust heap based of incoming data */
        size_t curIdx = pObj->size;
        size_t parentIdx = curIdx / 2;
        while (parentIdx > 0 && (*pDataIn > pObj->pBuf[parentIdx]))
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
        *pDataOut = pObj->pBuf[1];

        /* Copy last element into root */
        pObj->pBuf[1] = pObj->pBuf[pObj->size - 1];

        /* Reduce heap size by 1 */
        pObj->size--;

        /* Adjust heap */
        size_t childIdx = 2;
        uint8_t tempRoot = pObj->pBuf[1];
        while (childIdx <= pObj->size)
        {
            /* Select the greater child element */
            if (childIdx < pObj->size && pObj->pBuf[childIdx] < pObj->pBuf[childIdx + 1])
            {
                childIdx++;
            }

            /* If child is smaller then the heap is adjusted */
            if (tempRoot >= pObj->pBuf[childIdx])
            {
                break;
            }

            /* Copy child to parent node */
            pObj->pBuf[childIdx / 2] = pObj->pBuf[childIdx];
            childIdx = 2 * childIdx;
        }
        pObj->pBuf[childIdx / 2] = tempRoot;

    }

    return err;
}