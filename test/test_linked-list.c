/*!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "linked-list.h"


llnode *LIST_HEAD = NULL;


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_access_as_index(void)
{
	llnode *testNode = NULL;

    /* Setup a linked-list */
	insertBeginning(&LIST_HEAD, 8);
	insertBeginning(&LIST_HEAD, 7);
	insertBeginning(&LIST_HEAD, 3);

	testNode = accessIndex(LIST_HEAD, 0);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(3,testNode->value);

	testNode = accessIndex(LIST_HEAD, 1);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(7,testNode->value);

	testNode = accessIndex(LIST_HEAD, 2);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(8,testNode->value);

	testNode = accessIndex(LIST_HEAD, -1);
	TEST_ASSERT_NULL(testNode);

	testNode = accessIndex(LIST_HEAD, 4);
	TEST_ASSERT_NULL(testNode);
}

void test_function_should_insert_after(void)
{
    llnode *testNode = NULL;


    testNode = accessIndex(LIST_HEAD, 0);
    TEST_ASSERT_EQUAL(3, testNode->value);
    insertAfter(4,testNode);

    testNode = accessIndex(LIST_HEAD, 1);
    TEST_ASSERT_EQUAL(4, testNode->value);

    testNode = accessIndex(LIST_HEAD, 2);
    TEST_ASSERT_EQUAL(7, testNode->value);
}

void test_function_should_delete_beginning(void)
{
	STATUS status;
    llnode *testNode = NULL;
    int val;

    testNode = accessIndex(LIST_HEAD, 1);
    val = testNode->value;
    status = deleteBeginning(&LIST_HEAD);
    TEST_ASSERT_EQUAL(LL_SUCCESS,status);
    testNode = accessIndex(LIST_HEAD, 0);
    TEST_ASSERT_EQUAL(val,testNode->value);

    status = deleteBeginning(&LIST_HEAD);
    TEST_ASSERT_EQUAL(LL_SUCCESS,status);
    status = deleteBeginning(&LIST_HEAD);
    TEST_ASSERT_EQUAL(LL_SUCCESS,status);
    status = deleteBeginning(&LIST_HEAD);
    TEST_ASSERT_EQUAL(LL_SUCCESS,status);

    /* list should be empty now, returns an error */
    status = deleteBeginning(&LIST_HEAD);
    TEST_ASSERT_EQUAL(LL_ERROR,status);
}

void test_function_should_delete_after(void)
{
	STATUS status;
    llnode *testNode = NULL;
    int val;


    /* Setup a linked-list */
	insertBeginning(&LIST_HEAD, 8);
	insertBeginning(&LIST_HEAD, 7);
	insertBeginning(&LIST_HEAD, 3);
	// [3,7,8]
	testNode = accessIndex(LIST_HEAD, 2);
	val = testNode->value;
	status = deleteAfter(accessIndex(LIST_HEAD, 0));
	// [3,8]
    TEST_ASSERT_EQUAL(LL_SUCCESS,status);
    testNode = accessIndex(LIST_HEAD, 1);
    TEST_ASSERT_EQUAL(val,testNode->value);

    /* Try to deleteAfter on final node */
    status = deleteAfter(accessIndex(LIST_HEAD, 1));
    TEST_ASSERT_EQUAL(LL_ERROR,status);

    /* Try to deleteAfter NULL */
    status = deleteAfter(NULL);
    TEST_ASSERT_EQUAL(LL_ERROR,status);

    /* Try using listHead */
    status = deleteAfter(accessIndex(LIST_HEAD, 0));
    TEST_ASSERT_EQUAL(LL_SUCCESS,status);

    /* Can't deleteAfter the final and only node */
    status = deleteAfter(LIST_HEAD);
    TEST_ASSERT_EQUAL(LL_ERROR,status);
}

void test_function_should_return_length(void)
{
    llnode *myList = NULL;
    int val;

    val = length(myList);
    TEST_ASSERT_EQUAL(0,val);

    val = lengthR(myList);
    TEST_ASSERT_EQUAL(0,val);

    /* Setup a linked-list */
	insertBeginning(&myList, 8);
	insertBeginning(&myList, 7);
	insertBeginning(&myList, 3);

    val = length(myList);
    TEST_ASSERT_EQUAL(3,val);

    val = lengthR(myList);
    TEST_ASSERT_EQUAL(3,val);
}
