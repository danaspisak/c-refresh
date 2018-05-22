/*!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "stack.h"
#include "linked-list.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_push (void)
{
	llnode *head = NULL;
	STATUS status;

	status = push(&head, 5);
	TEST_ASSERT_EQUAL(LL_SUCCESS, status);

	status = push(&head, 4);
	TEST_ASSERT_EQUAL(LL_SUCCESS, status);

	TEST_ASSERT_EQUAL(4, head->value);
	TEST_ASSERT_EQUAL(5, head->next->value);
	TEST_ASSERT_EQUAL(NULL, head->next->next);

	deleteList(&head);
}

void test_function_should_pop(void)
{
	llnode *head = NULL;
	int value;
	STATUS status;

	push(&head, 5);
	push(&head, 4);

    status = pop(&head,&value);
    TEST_ASSERT_EQUAL(LL_SUCCESS, status);
	TEST_ASSERT_EQUAL(4, value);
	status = pop(&head, &value);
	TEST_ASSERT_EQUAL(5, value);
	status = pop(&head, &value);
	TEST_ASSERT_NOT_EQUAL(LL_SUCCESS, status);

	deleteList(&head);
}

void test_function_should_peek(void)
{
	llnode *head = NULL;
	int value;
	STATUS status;

	push(&head, 5);
	status = peek(head, &value);
	TEST_ASSERT_EQUAL(LL_SUCCESS,status);
	TEST_ASSERT_EQUAL(5, value);

	push(&head, 4);
	status = peek(head, &value);
	TEST_ASSERT_EQUAL(LL_SUCCESS,status);
	TEST_ASSERT_EQUAL(4, value);

	pop(&head, &value);
	pop(&head, &value);
	status = peek(head,&value);
	TEST_ASSERT_NOT_EQUAL(LL_SUCCESS,status);

	deleteList(&head);
}

void test_function_isEmpty(void)
{
	llnode *head = NULL;
	int value;
	STATUS status;

	value = isEmpty(head);
	TEST_ASSERT_NOT_EQUAL(1,value);

	push(&head, 5);
	push(&head, 4);

	value = isEmpty(head);
	TEST_ASSERT_NOT_EQUAL(0,value);

    status = pop(&head,&value);
	value = isEmpty(head);
	TEST_ASSERT_NOT_EQUAL(0,value);

    status = pop(&head,&value);
	value = isEmpty(head);
	TEST_ASSERT_NOT_EQUAL(1,value);

	deleteList(&head);

}
