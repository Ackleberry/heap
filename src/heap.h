/*******************************************************************************
 * @file   heap.h
 *
 * @brief  Heap public function declarations
 *
 * @author Brooks Anderson <bilbrobaggins@gmail.com>
 ******************************************************************************/

#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

/*============================================================================*
 *                              I N C L U D E S                               *
 *============================================================================*/
#include <stddef.h>
#include <stdbool.h>

#include "heap_t.h"

/*============================================================================*
 *                 F U N C T I O N    D E C L A R A T I O N S                 *
 *============================================================================*/

/*******************************************************************************
 * @brief    Initializes the heap object
 *
 * @details  The caller is responsible for allocating the heap object, and
 *           heap buffer.
 *
 * @param pObj      Pointer to the heap object
 * @param pBuf      Pointer to the heap buffer
 * @param bufSize   Size of the buffer, must be an integer multiple of datasize
 * @param dataSize  Size of the data type that the heap is handling
 * @param pCmpFn    Pointer to compare function used for comparing data
 *
 * @return none
 ******************************************************************************/
void Heap_Init(Heap_t *pObj, Heap_Type_e type, void *pBuf, size_t bufSize,
               size_t dataSize, CmpFnPtr_t pCmpFn);

/*******************************************************************************
 * @brief  Check if the heap is empty
 *
 * @param pObj  Pointer to the heap object
 *
 * @returns true if empty
 ******************************************************************************/
bool Heap_IsEmpty(Heap_t *pObj);

/*******************************************************************************
 * @brief Check if the heap is full
 *
 * @param pObj  Pointer to the heap object
 *
 * @returns true if full
 ******************************************************************************/
bool Heap_IsFull(Heap_t *pObj);

/*******************************************************************************
 * @brief  Pushes some data type onto the heap
 *
 * @param pObj         Pointer to the heap object
 * @param pDataInVoid  Pointer to the data that will be pushed onto the heap
 *
 * @returns Heap error flag
 ******************************************************************************/
Heap_Error_e Heap_Insert(Heap_t *pObj, void *pDataInVoid);

/*******************************************************************************
 * @brief  Pops some data type off the heap
 *
 * @param pObj          Pointer to the heap object
 * @param pDataOutVoid  Pointer to the data that will be popped off the heap
 *
 * @returns Heap error flag
 ******************************************************************************/
Heap_Error_e Heap_Extract(Heap_t *pObj, void *pDataOutVoid);

#endif /* HEAP_H_INCLUDED */