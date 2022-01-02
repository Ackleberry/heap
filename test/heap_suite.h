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

TEST Heap_can_report_empty(void)
{
    /*****************    Arrange    *****************/
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    /*****************     Act       *****************/
    bool isEmpty = Heap_IsEmpty(&heap);

    /*****************    Assert     *****************/
    ASSERT_EQ(true, isEmpty);

    PASS();
}

TEST Heap_can_report_not_empty(void)
{
    /*****************    Arrange    *****************/
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    uint8_t dataIn = 10;
    Heap_Insert(&heap, &dataIn);

    /*****************     Act       *****************/
    bool isEmpty = Heap_IsEmpty(&heap);

    /*****************    Assert     *****************/
    ASSERT_EQ(false, isEmpty);

    PASS();
}

TEST Heap_can_report_full(void)
{
    /*****************    Arrange    *****************/
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    uint8_t dataIn = 10;
    Heap_Insert(&heap, &dataIn);
    Heap_Insert(&heap, &dataIn);
    Heap_Insert(&heap, &dataIn);
    Heap_Insert(&heap, &dataIn);
    Heap_Insert(&heap, &dataIn);

    /*****************     Act       *****************/
    bool isFull = Heap_IsFull(&heap);

    /*****************    Assert     *****************/
    ASSERT_EQ(true, isFull);

    PASS();
}

TEST Heap_can_report_not_full(void)
{
    /*****************    Arrange    *****************/
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    /*****************     Act       *****************/
    bool isFull = Heap_IsFull(&heap);

    /*****************    Assert     *****************/
    ASSERT_EQ(false, isFull);

    PASS();
}

TEST Heap_extract_fails_if_empty(void)
{
    /*****************    Arrange    *****************/
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    /*****************     Act       *****************/
    uint8_t dataOut;
    Heap_Error_e err = Heap_Extract(&heap, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Heap_Error, err);

    PASS();
}

TEST Heap_insert_fails_if_full(void)
{
    /*****************    Arrange    *****************/
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    uint8_t dataIn = 10;
    Heap_Insert(&heap, &dataIn);
    Heap_Insert(&heap, &dataIn);
    Heap_Insert(&heap, &dataIn);
    Heap_Insert(&heap, &dataIn);
    Heap_Insert(&heap, &dataIn);

    /*****************     Act       *****************/
    Heap_Error_e err = Heap_Insert(&heap, &dataIn);

    /*****************    Assert     *****************/
    ASSERT_EQ(Heap_Error, err);

    PASS();
}

TEST Heap_can_extract_1_byte_data_types(void)
{
    /*****************    Arrange    *****************/
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    uint8_t dataIn = 10;
    Heap_Insert(&heap, &dataIn);

    /*****************     Act       *****************/
    uint8_t dataOut;
    Heap_Error_e err = Heap_Extract(&heap, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Heap_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Heap_can_extract_full_buffer_of_1_byte_data_types_decending(void)
{
    /*****************    Arrange    *****************/
    uint8_t err = (uint8_t)Heap_Error_None;
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    uint8_t dataIn[] = { 50, 40, 30, 20, 10 };
    Heap_Insert(&heap, &dataIn[0]);
    Heap_Insert(&heap, &dataIn[1]);
    Heap_Insert(&heap, &dataIn[2]);
    Heap_Insert(&heap, &dataIn[3]);
    Heap_Insert(&heap, &dataIn[4]);

    /*****************     Act       *****************/
    uint8_t dataOut[4];
    err |= Heap_Extract(&heap, &dataOut[0]);
    err |= Heap_Extract(&heap, &dataOut[1]);
    err |= Heap_Extract(&heap, &dataOut[2]);
    err |= Heap_Extract(&heap, &dataOut[3]);
    err |= Heap_Extract(&heap, &dataOut[4]);

    /*****************    Assert     *****************/
    ASSERT_EQ(Heap_Error_None, (Heap_Error_e)err);
    ASSERT_EQ(dataIn[0], dataOut[0]);
    ASSERT_EQ(dataIn[1], dataOut[1]);
    ASSERT_EQ(dataIn[2], dataOut[2]);
    ASSERT_EQ(dataIn[3], dataOut[3]);
    ASSERT_EQ(dataIn[4], dataOut[4]);

    PASS();
}

TEST Heap_can_extract_full_buffer_of_1_byte_data_types_ascending(void)
{
    /*****************    Arrange    *****************/
    uint8_t err = (uint8_t)Heap_Error_None;
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    uint8_t dataIn[] = { 10, 20, 30, 40, 50 };
    Heap_Insert(&heap, &dataIn[0]);
    Heap_Insert(&heap, &dataIn[1]);
    Heap_Insert(&heap, &dataIn[2]);
    Heap_Insert(&heap, &dataIn[3]);
    Heap_Insert(&heap, &dataIn[4]);

    /*****************     Act       *****************/
    uint8_t dataOut[4];
    err |= Heap_Extract(&heap, &dataOut[0]);
    err |= Heap_Extract(&heap, &dataOut[1]);
    err |= Heap_Extract(&heap, &dataOut[2]);
    err |= Heap_Extract(&heap, &dataOut[3]);
    err |= Heap_Extract(&heap, &dataOut[4]);

    /*****************    Assert     *****************/
    ASSERT_EQ(Heap_Error_None, (Heap_Error_e)err);
    ASSERT_EQ(dataIn[4], dataOut[0]);
    ASSERT_EQ(dataIn[3], dataOut[1]);
    ASSERT_EQ(dataIn[2], dataOut[2]);
    ASSERT_EQ(dataIn[1], dataOut[3]);
    ASSERT_EQ(dataIn[0], dataOut[4]);

    PASS();
}

TEST Heap_can_extract_full_buffer_of_1_byte_data_types_random(void)
{
    /*****************    Arrange    *****************/
    uint8_t err = (uint8_t)Heap_Error_None;
    Heap_t heap;
    uint8_t buf[5];
    Heap_Init(&heap, buf, sizeof(buf), sizeof(buf[0]));

    uint8_t dataIn[] = { 30, 50, 40, 10, 20 };
    Heap_Insert(&heap, &dataIn[0]);
    Heap_Insert(&heap, &dataIn[1]);
    Heap_Insert(&heap, &dataIn[2]);
    Heap_Insert(&heap, &dataIn[3]);
    Heap_Insert(&heap, &dataIn[4]);

    /*****************     Act       *****************/
    uint8_t dataOut[4];
    err |= Heap_Extract(&heap, &dataOut[0]);
    err |= Heap_Extract(&heap, &dataOut[1]);
    err |= Heap_Extract(&heap, &dataOut[2]);
    err |= Heap_Extract(&heap, &dataOut[3]);
    err |= Heap_Extract(&heap, &dataOut[4]);

    /*****************    Assert     *****************/
    ASSERT_EQ(Heap_Error_None, (Heap_Error_e)err);
    ASSERT_EQ(dataIn[1], dataOut[0]);
    ASSERT_EQ(dataIn[2], dataOut[1]);
    ASSERT_EQ(dataIn[0], dataOut[2]);
    ASSERT_EQ(dataIn[4], dataOut[3]);
    ASSERT_EQ(dataIn[3], dataOut[4]);

    PASS();
}

SUITE(Heap_Suite)
{
    RUN_TEST(Heap_can_report_empty);
    RUN_TEST(Heap_can_report_not_empty);
    RUN_TEST(Heap_can_report_full);
    RUN_TEST(Heap_can_report_not_full);
    RUN_TEST(Heap_extract_fails_if_empty);
    RUN_TEST(Heap_insert_fails_if_full);
    RUN_TEST(Heap_can_extract_1_byte_data_types);
    RUN_TEST(Heap_can_extract_full_buffer_of_1_byte_data_types_decending);
    RUN_TEST(Heap_can_extract_full_buffer_of_1_byte_data_types_ascending);
    RUN_TEST(Heap_can_extract_full_buffer_of_1_byte_data_types_random);
}

#endif /* HEAP_SUITE_INCLUDED */