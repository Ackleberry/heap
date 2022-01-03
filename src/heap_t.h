/*******************************************************************************
 * @file  heap_t.h
 *
 * @brief Heap public function declarations
 *
 * @author Brooks Anderson <bilbrobaggins@gmail.com>
 ******************************************************************************/
#ifndef HEAP_T_H_INCLUDED
#define HEAP_T_H_INCLUDED

/*============================================================================*
 *                              I N C L U D E S                               *
 *============================================================================*/
#include <stddef.h>
#include <stdint.h>

/*============================================================================*
 *                                D E F I N E S                               *
 *============================================================================*/


/*============================================================================*
 *                     F U N C T I O N    P O I N T E R S                     *
 *============================================================================*/

/*******************************************************************************
 * @brief   Data agnostic compare function pointer
 *
 * @details The caller must define this function so the module knows how to
 *          compare the data.
 *
 * @param pDataRefVoid  Refernece data
 * @param pDataVoid     Data compared against the reference
 *
 * @returns -1 - DataIn is less than Reference
 *           0 - DataIn is equal to Reference
 *          +1 - DataIn is greater than Reference
 ******************************************************************************/
typedef int8_t (*CmpFnPtr_t)(void *pDataRefVoid, void *pDataVoid);

/*============================================================================*
 *                           E N U M E R A T I O N S                          *
 *============================================================================*/

/**
 * @brief Error flag
**/
typedef enum _Heap_Error_e
{
    Heap_Error_None = 0,
    Heap_Error      = 1,
} Heap_Error_e;

/*============================================================================*
 *                             S T R U C T U R E S                            *
 *============================================================================*/

/**
 * @brief  Heap Object
 *
 * @note   This object should never be directly manipulated by the caller.
**/
typedef struct _Heap_t
{
    size_t      size;     /*!< Current size of heap */
    uint8_t    *pBuf;     /*!< Pointer to the heap buffer */
    size_t      bufSize;  /*!< Size of the heap buffer */
    size_t      dataSize; /*!< Size of the data type being stored in the heap */
    CmpFnPtr_t  pCmpFn;  /*!< User defined function used to compare a specific data type */
} Heap_t;

#endif /* HEAP_T_H_INCLUDED */