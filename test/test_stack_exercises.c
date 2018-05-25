/*!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "stack.h"
#include "linked-list.h"
#include "stack_exercises.h"

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
