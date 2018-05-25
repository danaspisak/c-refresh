/*!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "queue.h"
#include "double-ll.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_enqueue(void)
{
	STATUS status;

	queue myQueue;
	queue *qp = &myQueue;
	myQueue.head = NULL;
	myQueue.tail = NULL;

	status = enqueue(&qp, 2);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_EQUAL(myQueue.head, myQueue.tail);
	TEST_ASSERT_NOT_EQUAL(NULL, myQueue.head);

	status = enqueue(&qp, 3);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_NOT_EQUAL(myQueue.head, myQueue.tail);
	TEST_ASSERT_EQUAL(3, (myQueue.tail)->value);
	TEST_ASSERT_EQUAL(2, (myQueue.head)->value);

	status = enqueue(&qp, 4);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_NOT_EQUAL(myQueue.head, myQueue.tail);
	TEST_ASSERT_EQUAL(4, (myQueue.tail)->value);
	TEST_ASSERT_EQUAL(2, (myQueue.head)->value);

	dlDeleteList(&(myQueue.head));
}

void test_function_should_dequeue(void)
{
	STATUS status;
	int value;
	queue myQueue;
	queue *qp = &myQueue;

	myQueue.head = NULL;
	myQueue.tail = NULL;

	status = enqueue(&qp, 2);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_EQUAL(myQueue.head, myQueue.tail);
	TEST_ASSERT_NOT_EQUAL(NULL, myQueue.head);

	status = dequeue(&qp, &value);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_EQUAL(2, value);
	TEST_ASSERT_EQUAL(NULL, myQueue.head);
	TEST_ASSERT_EQUAL(myQueue.head, myQueue.tail);


	status = enqueue(&qp, 2);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_EQUAL(myQueue.head, myQueue.tail);
	TEST_ASSERT_NOT_EQUAL(NULL, myQueue.head);

	status = enqueue(&qp, 3);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_NOT_EQUAL(myQueue.head, myQueue.tail);
	TEST_ASSERT_EQUAL(3, (myQueue.tail)->value);
	TEST_ASSERT_EQUAL(2, (myQueue.head)->value);

	status = enqueue(&qp, 4);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_NOT_EQUAL(myQueue.head, myQueue.tail);
	TEST_ASSERT_EQUAL(4, (myQueue.tail)->value);
	TEST_ASSERT_EQUAL(2, (myQueue.head)->value);

	status = dequeue(&qp, &value);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_EQUAL(2, value);

	status = dequeue(&qp, &value);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_EQUAL(3, value);

	status = dequeue(&qp, &value);
	TEST_ASSERT_EQUAL(CF_SUCCESS, status);
	TEST_ASSERT_EQUAL(4, value);

	TEST_ASSERT_EQUAL(NULL, myQueue.head);
	TEST_ASSERT_EQUAL(myQueue.head, myQueue.tail);

	dlDeleteList(&(myQueue.head));


}
void test_function_should_return_front_rear(void)
{
	STATUS status;
	int value;
	queue myQueue;
	queue *qp = &myQueue;

	myQueue.head = NULL;
	myQueue.tail = NULL;

	status = enqueue(&qp, 2);
	front(qp, &value);
	TEST_ASSERT_EQUAL(2,value);

	value = 0;
	rear(qp, &value);
	TEST_ASSERT_EQUAL(2,value);

	status = enqueue(&qp, 3);
	front(qp, &value);
	TEST_ASSERT_EQUAL(2,value);
	value = 0;
	rear(qp, &value);
	TEST_ASSERT_EQUAL(3,value);

	dlDeleteList(&(myQueue.head));
}
