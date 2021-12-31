#ifndef HEAP_TEST_HELPER_H_INCLUDED
#define HEAP_TEST_HELPER_H_INCLUDED

#include "heap.h"

#define ELEMENTS_IN(array)    ( sizeof(array) / sizeof(array[0]) )

void TestHelper_PrintHeap(Heap_t *pObj);

#endif /* HEAP_TEST_HELPER_H_INCLUDED */
