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
	dllnode *list_head = NULL;

    /* Setup a linked-list */
	dlInsertBeginning(&list_head, 8);
	dlInsertBeginning(&list_head, 7);
	dlInsertBeginning(&list_head, 3);

	testNode =dlAccessIndex(list_head, 0);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(3,testNode->value);

	testNode = dlAccessIndex(list_head, 1);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(7,testNode->value);

	testNode = dlAccessIndex(list_head, 2);
	TEST_ASSERT_NOT_NULL(testNode);
	TEST_ASSERT_EQUAL(8,testNode->value);

	testNode = dlAccessIndex(list_head, -1);
	TEST_ASSERT_NULL(testNode);

	testNode = dlAccessIndex(list_head, 4);
	TEST_ASSERT_NULL(testNode);
}
