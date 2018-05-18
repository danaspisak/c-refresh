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

