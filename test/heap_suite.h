#ifndef HEAP_SUITE_INCLUDED
#define HEAP_SUITE_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "greatest.h"
#include "heap_test_helper.h"
#include "heap.h"

/* Declare a local suite. */
SUITE(Heap_Suite);

TEST dummy(void)
{
    /*****************    Arrange    *****************/

    /*****************     Act       *****************/

    /*****************    Assert     *****************/

    PASS();
}

SUITE(Heap_Suite)
{
    /* Unit Tests */
    RUN_TEST(dummy);
}

#endif /* HEAP_SUITE_INCLUDED */