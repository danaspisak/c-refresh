/*!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "double-ll.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_dlInsertBefore (void)
{
	dllnode *head;
	STATUS status;


  
}

void test_function_should_access_as_index(void)
{
	dllnode *testNode = NULL;
	dllnode *listHead = NULL;

    /* Setup a linked-list */
	dlInsertBeginning(&listHead, 8);
	dlInsertBeginning(&listHead, 7);
	dlInsertBeginning(&listHead, 3);

	testNode =dlAccessIndex(listHead, 0);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(3,testNode->value);

	testNode = dlAccessIndex(listHead, 1);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(7,testNode->value);

	testNode = dlAccessIndex(listHead, 2);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(8,testNode->value);

	testNode = dlAccessIndex(listHead, -1);
	TEST_ASSERT_NULL(testNode);

	testNode = dlAccessIndex(listHead, 4);
	TEST_ASSERT_NULL(testNode);

    dlDeleteList(&listHead);
}

void test_function_should_insert_after(void)
{
    dllnode *testNode = NULL;
    dllnode *listHead = NULL;

    /* Setup a linked-list */
	dlInsertBeginning(&listHead, 8);
	dlInsertBeginning(&listHead, 7);
	dlInsertBeginning(&listHead, 3);

    testNode = dlAccessIndex(listHead, 0);
    TEST_ASSERT_EQUAL(3, testNode->value);
    dlInsertAfter(4,testNode);

    testNode = dlAccessIndex(listHead, 1);
    TEST_ASSERT_EQUAL(4, testNode->value);

    testNode = dlAccessIndex(listHead, 2);
    TEST_ASSERT_EQUAL(7, testNode->value);

    dlDeleteList(&listHead);
}

void test_function_should_delete_beginning(void)
{
	STATUS status;
    dllnode *testNode = NULL;
    dllnode *listHead = NULL;
    int val;

    /* Setup a linked-list */
	dlInsertBeginning(&listHead, 8);
	dlInsertBeginning(&listHead, 7);
	dlInsertBeginning(&listHead, 3);
	dlInsertBeginning(&listHead, 2);


    testNode = dlAccessIndex(listHead, 1);
    val = testNode->value;
    status = dlDeleteBeginning(&listHead);
    TEST_ASSERT_EQUAL(CF_SUCCESS,status);
    testNode = dlAccessIndex(listHead, 0);
    TEST_ASSERT_EQUAL(val,testNode->value);

    status = dlDeleteBeginning(&listHead);
    TEST_ASSERT_EQUAL(CF_SUCCESS,status);
    status = dlDeleteBeginning(&listHead);
    TEST_ASSERT_EQUAL(CF_SUCCESS,status);
    status = dlDeleteBeginning(&listHead);
    TEST_ASSERT_EQUAL(CF_SUCCESS,status);

    /* list should be empty now, returns an error */
    status = dlDeleteBeginning(&listHead);
    TEST_ASSERT_EQUAL(CF_ERROR,status);

    dlDeleteList(&listHead);
}

void test_function_should_delete_at_index(void)
{
	STATUS status;
    dllnode *testNode = NULL;
    dllnode *listHead = NULL;
    int val;

    /* Setup a linked-list */
	dlInsertBeginning(&listHead, 8);
	dlInsertBeginning(&listHead, 7);
	dlInsertBeginning(&listHead, 3);
	dlInsertBeginning(&listHead, 2);

	/* Negative number */
	status = dlDeleteIndex(&listHead, -1);
	TEST_ASSERT_EQUAL(CF_ERROR, status);

	/* Beyond list */
	status = dlDeleteIndex(&listHead, 4);
	TEST_ASSERT_EQUAL(CF_ERROR, status);

	/* Last element */
	status = dlDeleteIndex(&listHead, 3);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
    testNode = dlAccessIndex(listHead, 3);
    TEST_ASSERT_EQUAL(NULL, testNode);
    testNode = dlAccessIndex(listHead, 2);
    TEST_ASSERT_EQUAL(7, testNode->value);

	/* Middle element */
	status = dlDeleteIndex(&listHead, 1);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
    testNode = dlAccessIndex(listHead, 2);
    TEST_ASSERT_EQUAL(NULL, testNode);
    testNode = dlAccessIndex(listHead, 1);
    TEST_ASSERT_EQUAL(7, testNode->value);

	/* First element */
	status = dlDeleteIndex(&listHead, 0);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
    testNode = dlAccessIndex(listHead, 2);
    TEST_ASSERT_EQUAL(NULL, testNode);
    testNode = dlAccessIndex(listHead, 0);
    TEST_ASSERT_EQUAL(7, testNode->value);

    dlDeleteList(&listHead);
}

void test_function_should_return_list_size(void)
{
	STATUS status;
    dllnode *testNode = NULL;
    dllnode *listHead = NULL;
    int val;


    /* Empty list */
    val = dlSize(listHead);
    TEST_ASSERT_EQUAL(0,val);

    /* Setup a linked-list */
	dlInsertBeginning(&listHead, 8);
    val = dlSize(listHead);
    TEST_ASSERT_EQUAL(1,val);

	dlInsertBeginning(&listHead, 7);
	dlInsertBeginning(&listHead, 3);
	dlInsertBeginning(&listHead, 2);
    val = dlSize(listHead);
    TEST_ASSERT_EQUAL(4,val);

	dlDeleteList(&listHead);
    val = dlSize(listHead);
    TEST_ASSERT_EQUAL(0,val);
}

void test_function_should_return_middle(void)
{
	STATUS status;
    dllnode *testNode = NULL;
    dllnode *listHead = NULL;
    int val;

    /* Empty list */
	testNode = dlMiddle(listHead);
	TEST_ASSERT_EQUAL(NULL,testNode);


    /* 1 item */
	dlInsertBeginning(&listHead, 8);
	testNode = dlMiddle(listHead);
	TEST_ASSERT_EQUAL(8,testNode->value);

	/* 2 items */
	dlInsertBeginning(&listHead, 7);
	testNode = dlMiddle(listHead);
	TEST_ASSERT_EQUAL(8,testNode->value);

	/* 3 items */
	dlInsertBeginning(&listHead, 3);
	testNode = dlMiddle(listHead);
	TEST_ASSERT_EQUAL(7,testNode->value);

	dlDeleteList(&listHead);
}

void test_function_should_swap(void)
{
	dllnode *myList = NULL;
	dllnode *foundNode = NULL;
	dllnode *verifyNode = NULL;
	dllnode *nodeX, *nodeY;

	STATUS status;

	/* Setup a linked-list */
	dlInsertBeginning(&myList, 0);
	dlInsertBeginning(&myList, 8);
	dlInsertBeginning(&myList, 7);
	dlInsertBeginning(&myList, 3);
	dlInsertBeginning(&myList, 4);
	dlInsertBeginning(&myList, 9);
	dlInsertBeginning(&myList, 1);
    /* [1,9,4,3,7,8,0] */
	/* X is not next to Y */
	nodeX = dlAccessIndex(myList,1);
	nodeY = dlAccessIndex(myList,3);
	/* Swapping 9, 3 */
	status = dlSwap(&myList, nodeX, nodeY);
	/* [1,3,4,9,7,8,0] */
	TEST_ASSERT_EQUAL(status, CF_SUCCESS);
	foundNode = dlAccessIndex(myList, 1);
	TEST_ASSERT_EQUAL(3, foundNode->value);
	foundNode = dlAccessIndex(myList, 3);
	TEST_ASSERT_EQUAL(9, foundNode->value);

	/* Nodes are next to eachother */
	nodeX = dlAccessIndex(myList,1);
	nodeY = dlAccessIndex(myList,2);
	/* [1,3,4,9,7,8,0] */
	/* Swapping 3, 4 */
	status = dlSwap(&myList, nodeX, nodeY);
	/* [1,4,3,9,7,8,0] */
	TEST_ASSERT_EQUAL(status, CF_SUCCESS);
	foundNode = dlAccessIndex(myList, 1);
	TEST_ASSERT_EQUAL(4, foundNode->value);
	foundNode = dlAccessIndex(myList, 2);
	TEST_ASSERT_EQUAL(3, foundNode->value);
	foundNode = dlAccessIndex(myList, 3);
	TEST_ASSERT_EQUAL(9, foundNode->value);

	/* X is head */
	/* Y is head */


	/* Try some failures when values are not found */
	status = dlSwap(&myList, NULL, NULL);
	TEST_ASSERT_EQUAL(CF_ERROR, status);

	status = dlSwap(&myList, NULL, nodeY);
	TEST_ASSERT_EQUAL(CF_ERROR, status);

	status = dlSwap(&myList, nodeX, NULL);
	TEST_ASSERT_EQUAL(CF_ERROR, status);

	dlDeleteList(&myList);
}
