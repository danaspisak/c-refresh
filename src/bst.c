#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

bstNode *bstCreateNode(char key, int value)
{
	bstNode *newNode = NULL;
	newNode = malloc(sizeof(bstNode));
	newNode->left = newNode->right = NULL;
	newNode->element.key = key;
	newNode->element.value = value;

	return newNode;
}

void bstDeleteNode(bstNode *node)
{
	free((void *)node);
}

void bstAdd(bstNode **root, bstNode *newNode)
{
	/* No root, assign this as the root */
	if (*root == NULL)
	{
	  *root = newNode;
	}
	/* Insert to the left */
	else if (newNode->element.key <= (*root)->element.key)
	{
		bstAdd(&(*root)->left, newNode);
	}
	/* Insert to the right */
	else
	{
		bstAdd(&(*root)->right, newNode);
	}
}

int bstSearch(bstNode **root, char key)
{
	if (*root == NULL)
	{
		return 0;
	}
	else if ((*root)->element.key == key)
	{
		return 1;
	}
	/* Insert to the left */
	else if (key <= (*root)->element.key)
	{
		return bstSearch(&(*root)->left, key);
	}
	/* Insert to the right */
	else
	{
		return bstSearch(&(*root)->right, key);
	}
}
