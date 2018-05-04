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

    while (deleteBeginning(&myList) == LL_SUCCESS);
}

void test_function_should_find(void)
{
	llnode *myList = NULL;
	llnode *foundNode = NULL;
	llnode *verifyNode = NULL;

	/* Setup a linked-list */
	insertBeginning(&myList, 3);
	insertBeginning(&myList, 8);
	insertBeginning(&myList, 7);
	insertBeginning(&myList, 3);
	insertBeginning(&myList, 4);
	insertBeginning(&myList, 9);
	insertBeginning(&myList, 1);

	foundNode = find(myList, 4);
    TEST_ASSERT_NOT_EQUAL(NULL,foundNode);
    TEST_ASSERT_EQUAL(foundNode->value, 4);

	foundNode = find(myList, 8);
    TEST_ASSERT_NOT_EQUAL(NULL,foundNode);
    TEST_ASSERT_EQUAL(foundNode->value, 8);

	foundNode = find(myList, -1);
    TEST_ASSERT_EQUAL(NULL,foundNode);

    verifyNode = accessIndex(myList,6);
    TEST_ASSERT_EQUAL(verifyNode->value, 3);
    foundNode = find(myList,3);
    TEST_ASSERT_NOT_EQUAL(verifyNode, foundNode);
    TEST_ASSERT_NOT_EQUAL(foundNode->next, NULL);
    foundNode = find(foundNode->next,3);
    TEST_ASSERT_EQUAL(verifyNode, foundNode);

    /* Use recursive function this time */
	foundNode = findR(myList, 4);
    TEST_ASSERT_NOT_EQUAL(NULL,foundNode);
    TEST_ASSERT_EQUAL(foundNode->value, 4);

	foundNode = findR(myList, 8);
    TEST_ASSERT_NOT_EQUAL(NULL,foundNode);
    TEST_ASSERT_EQUAL(foundNode->value, 8);

	foundNode = findR(myList, -1);
    TEST_ASSERT_EQUAL(NULL,foundNode);

    verifyNode = accessIndex(myList,6);
    TEST_ASSERT_EQUAL(verifyNode->value, 3);
    foundNode = findR(myList,3);
    TEST_ASSERT_NOT_EQUAL(verifyNode, foundNode);
    TEST_ASSERT_NOT_EQUAL(foundNode->next, NULL);
    foundNode = findR(foundNode->next,3);
    TEST_ASSERT_EQUAL(verifyNode, foundNode);

    while (deleteBeginning(&myList) == LL_SUCCESS);
}

void test_function_should_swap(void)
{
	llnode *myList = NULL;
	llnode *foundNode = NULL;
	llnode *verifyNode = NULL;
	STATUS status;

	/* Setup a linked-list */
	insertBeginning(&myList, 3);
	insertBeginning(&myList, 8);
	insertBeginning(&myList, 7);
	insertBeginning(&myList, 3);
	insertBeginning(&myList, 4);
	insertBeginning(&myList, 9);
	insertBeginning(&myList, 1);

	status = swap(&myList, 1, 9);
	TEST_ASSERT_EQUAL(status, LL_SUCCESS);
	foundNode = accessIndex(myList, 0);
	TEST_ASSERT_EQUAL(9, foundNode->value);
	foundNode = accessIndex(myList, 1);
	TEST_ASSERT_EQUAL(1, foundNode->value);

	/* Try some failures when values are not found */
	status = swap(&myList, 0, 0);
	TEST_ASSERT_EQUAL(status, LL_ERROR);

	status = swap(&myList, 0, 3);
	TEST_ASSERT_EQUAL(status, LL_ERROR);

	status = swap(&myList, 3, 0);
	TEST_ASSERT_EQUAL(status, LL_ERROR);

    while (deleteBeginning(&myList) == LL_SUCCESS);
}

void test_function_should_reverse(void)
{
	llnode *myList = NULL;
	llnode *tNode = NULL;
	STATUS status;

	/* Setup a linked-list */
	insertBeginning(&myList, 3);
	insertBeginning(&myList, 8);
	insertBeginning(&myList, 7);
	insertBeginning(&myList, 3);
	insertBeginning(&myList, 4);
	insertBeginning(&myList, 9);
	insertBeginning(&myList, 1);

	reverse(&myList, &tNode);

	TEST_ASSERT_EQUAL(3,accessIndex(myList,0)->value);
	TEST_ASSERT_EQUAL(8,accessIndex(myList,1)->value);
	TEST_ASSERT_EQUAL(7,accessIndex(myList,2)->value);
	TEST_ASSERT_EQUAL(3,accessIndex(myList,3)->value);
	TEST_ASSERT_EQUAL(4,accessIndex(myList,4)->value);
	TEST_ASSERT_EQUAL(9,accessIndex(myList,5)->value);
	TEST_ASSERT_EQUAL(1,accessIndex(myList,6)->value);

	while (deleteBeginning(&myList) == LL_SUCCESS);
}

void test_function_should_return_middle(void)
{
	llnode *myList = NULL;
	llnode *tNode = NULL;
	STATUS status;

	/* Setup a linked-list */
	insertBeginning(&myList, 3);

	tNode = middle(myList);
	TEST_ASSERT_EQUAL(3, tNode->value);

	insertBeginning(&myList, 8);
	tNode = middle(myList);
	TEST_ASSERT_EQUAL(3, tNode->value);

	insertBeginning(&myList, 7);
	tNode = middle(myList);
	TEST_ASSERT_EQUAL(8, tNode->value);

	insertBeginning(&myList, 3);
	tNode = middle(myList);
	TEST_ASSERT_EQUAL(8, tNode->value);

	while (deleteBeginning(&myList) == LL_SUCCESS);
}
