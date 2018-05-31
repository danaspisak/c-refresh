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

	bstDeleteTree(root);
}

void test_function_should_search(void)
{
	bstNode *root = NULL;
    int status;
	bstNode *node;

	node = bstCreateNode('k', 5);
	bstAdd(&root, node);

	node = bstCreateNode('j', 4);
	bstAdd(&root, node);

	node = bstCreateNode('l', 6);
	bstAdd(&root, node);

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

	bstDeleteTree(root);
}

void test_function_should_delete_node(void)
{
	bstNode *root = NULL;
	bstNode *node = NULL;

	char keys[] = {'k','g','a','h','i','j','n','p','o','l'};

	for (int i=0; i<10;i++)
	{
		node = bstCreateNode(keys[i],i);
		bstAdd(&root,node);
	}

	/* Delete a leaf node */
	node = bstDelete(root, 'a');
	TEST_ASSERT_EQUAL(root, node);
	node = bstSearch(&root, 'a');
	TEST_ASSERT_EQUAL(NULL, node);
	node = bstSearch(&root, 'g');
	TEST_ASSERT_EQUAL(NULL, node->left);
	TEST_ASSERT_NOT_EQUAL(NULL, node->right);

	/* Delete node with 1 child on right */
	node = bstDelete(root, 'g');
	node = bstSearch(&root, 'g');
	TEST_ASSERT_EQUAL(NULL, node);
	node = bstSearch(&root, 'k');
	TEST_ASSERT_EQUAL(node->left, bstSearch(&root,'h'));

	/* Delete node with 1 child on left */
	node = bstDelete(root, 'p');
	node = bstSearch(&root, 'p');
	TEST_ASSERT_EQUAL(NULL, node);
	node = bstSearch(&root, 'n');
	TEST_ASSERT_EQUAL(node->right, bstSearch(&root,'o'));

    /* Delete node with 2 children */
	node = bstDelete(root, 'k');
	root = node;
	TEST_ASSERT_EQUAL('l', root->element.key);

	bstDeleteTree(root);

}

