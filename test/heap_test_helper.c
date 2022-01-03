#include <stdio.h>
#include "heap_test_helper.h"

void TestHelper_PrintHeap(Heap_t *pObj)
{
    printf("\n");

    for (size_t idx = 0; idx < pObj->size; idx++)
    {
        printf("%d ", pObj->pBuf[idx]);
    }

    printf("\n");
}

int8_t TestHelper_Compare1ByteData(void *pDataRefVoid, void *pDataInVoid)
{
    int8_t retVal;
    uint8_t *pDataRef = (uint8_t *)pDataRefVoid;
    uint8_t *pDataIn = (uint8_t *)pDataInVoid;

    if (*pDataIn > *pDataRef)
    {
        retVal = 1;
    }
    else if (*pDataIn < *pDataRef)
    {
        retVal = -1;
    }
    else
    {
        retVal = 0;
    }

    return retVal;
}
