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

void Heap_Init(Heap_t *pObj)
{

}

bool Heap_IsEmpty(Heap_t *pObj)
{
    return true;
}

bool Heap_IsFull(Heap_t *pObj)
{
    return true;
}

Heap_Error_e Heap_Insert(Heap_t *pObj, void *pDataInVoid)
{
    return Heap_Error_None;
}

Heap_Error_e Heap_Extract(Heap_t *pObj, void *pDataOutVoid)
{
    return Heap_Error_None;
}