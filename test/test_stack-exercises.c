/*!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "stack.h"
#include "linked-list.h"
#include "stack-exercises.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_check_balance (void)
{
	STATUS status;
	char balanced[] = "[()]{}{[()()]()}";
	char unbalanced[] = "[(])";

	status = checkBalanced(balanced);
	TEST_ASSERT_EQUAL(LL_SUCCESS, status);

	status = checkBalanced(unbalanced);
	TEST_ASSERT_EQUAL(LL_ERROR, status);

}

void test_function_should_reverse_stack(void)
{
	llnode *stack = NULL;
	int value;

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);

	reverseStack(&stack);
	pop(&stack, &value);
	TEST_ASSERT_EQUAL(1, value);
	pop(&stack, &value);
	TEST_ASSERT_EQUAL(2, value);
	pop(&stack, &value);
	TEST_ASSERT_EQUAL(3, value);
	pop(&stack, &value);
	TEST_ASSERT_EQUAL(4, value);
}

void test_function_should_queue_from_stack(void)
{
	llnode *queue = NULL;
	int value;

	enqueueStack(&queue, 1);
	enqueueStack(&queue, 2);
	enqueueStack(&queue, 3);
	enqueueStack(&queue, 4);

	dequeueStack(&queue, &value);
	TEST_ASSERT_EQUAL(1, value);
	dequeueStack(&queue, &value);
	TEST_ASSERT_EQUAL(2, value);
	dequeueStack(&queue, &value);
	TEST_ASSERT_EQUAL(3, value);
	dequeueStack(&queue, &value);
	TEST_ASSERT_EQUAL(4, value);
}
