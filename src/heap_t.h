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
    size_t   dummpy;    /*!< dummy*/
} Heap_t;

#endif /* HEAP_T_H_INCLUDED */