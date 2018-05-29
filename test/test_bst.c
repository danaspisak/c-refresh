/*!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "bst.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_add(void)
{
	bstNode *root = NULL;
    int status;
	bstNode *node;

	node = bstCreateNode('k', 5);
	TEST_ASSERT_EQUAL(5, node->element.value);
	TEST_ASSERT_EQUAL('k', node->element.key);

	bstAdd(&root, node);
	TEST_ASSERT_NOT_EQUAL(NULL, root);
	TEST_ASSERT_EQUAL(node, root);

	node = bstCreateNode('j', 4);
	bstAdd(&root, node);
	TEST_ASSERT_NOT_EQUAL(node, root);
	TEST_ASSERT_EQUAL(root->left, node);

	node = bstCreateNode('l', 6);
	bstAdd(&root, node);
	TEST_ASSERT_NOT_EQUAL(node, root);
	TEST_ASSERT_EQUAL(root->right, node);

	node = bstSearch(&root, 'k');
	TEST_ASSERT_EQUAL('k', node->element.key);

	node = bstSearch(&root, 'j');
	TEST_ASSERT_EQUAL('j', node->element.key);

	node = bstSearch(&root, 'a');
	TEST_ASSERT_EQUAL(NULL, node);

	node = bstSearch(&root, 'l');
	TEST_ASSERT_EQUAL('l', node->element.key);

	node = bstCreateNode('o', 6);
	bstAdd(&root, node);
	node = bstCreateNode('t', 6);
	bstAdd(&root, node);
	node = bstCreateNode('s', 6);
	bstAdd(&root, node);

	node = bstSearch(&root, 'o');
	TEST_ASSERT_EQUAL('o', node->element.key);

	node = bstSearch(&root, 's');
	TEST_ASSERT_EQUAL('s', node->element.key);

	node = bstSearch(&root, 't');
	TEST_ASSERT_EQUAL('t', node->element.key);
}
