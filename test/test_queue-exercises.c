/*!
 *
 */
#include "queue.h"
#include "double-ll.h"
#include "queue-exercises.h"
#include <stdio.h>
#include <stdlib.h>
#include "unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_act_like_stack(void)
{
	queue q;
	queue *pq = &q;

	int value;
	STATUS status;

    q.head = NULL;
    q.tail = NULL;

	pushQueue(&pq, 1);
	pushQueue(&pq, 2);
	pushQueue(&pq, 3);
	pushQueue(&pq, 4);
	pushQueue(&pq, 5);

    status = popQueue(&pq,&value);
	TEST_ASSERT_EQUAL(5, value);
	status = popQueue(&pq, &value);
	TEST_ASSERT_EQUAL(4, value);
	status = popQueue(&pq, &value);
	TEST_ASSERT_EQUAL(3, value);
	status = popQueue(&pq, &value);
	TEST_ASSERT_EQUAL(2, value);
	status = popQueue(&pq, &value);
	TEST_ASSERT_EQUAL(1, value);
	status = popQueue(&pq, &value);
	TEST_ASSERT_NOT_EQUAL(CF_SUCCESS, status);


	dlDeleteList(&(q.head));
}
