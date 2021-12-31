#include <stdio.h>
#include "heap_test_helper.h"

void TestHelper_PrintHeap(Heap_t *pObj)
{
    printf("\n");

    for (size_t idx = 1; idx < pObj->size; idx++)
    {
        printf("%d ", pObj->pBuf[idx]);
    }

    printf("\n");
}