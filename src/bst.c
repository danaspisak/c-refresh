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

bstNode *bstSearch(bstNode **root, char key)
{
	if (*root == NULL)
	{
		return NULL;
	}
	else if ((*root)->element.key == key)
	{
		return *root;
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

bstNode *bstFindMin(bstNode *root)
{
	bstNode *tmp = root;

	while (tmp->left != NULL)
	{
		tmp = tmp->left;
	}

	return tmp;
}


bstNode *bstDelete(bstNode *root, char key)
{
	if (root != NULL)
	{
		/* Go left */
		if (key < root->element.key)
		{
			/* Update the parent if it was modified */
			root->left = bstDelete(root->left, key);
		}
		/* Go right */
		else if (key > root->element.key)
		{
			/* Update the parent if it was modified */
			root->right = bstDelete(root->right, key);
		}
		/* We have a match */
		else
		{
			/* Is a leaf */
			if ((root->left == NULL) && (root->right == NULL))
			{
				bstDeleteNode(root);
				root = NULL;
			}
			/* Has 1 child to the right, set root to get returned */
			else if (root->left == NULL)
			{
				bstNode *tmp = root;
				root = root->right;
				bstDeleteNode(tmp);
			}
			/* Has 1 child to the left, set root to get returned */
			else if (root->right == NULL)
			{
				bstNode *tmp = root;
				root = root->left;
				bstDeleteNode(tmp);
			}
			// Has 2 children
			else
			{
				bstNode *tmp = bstFindMin(root->right);
				/* Copy the data over and delete the duplicate */
				root->element.key = tmp->element.key;
				root->element.value = tmp->element.value;
				root->right = bstDelete(root->right, tmp->element.key);
			}
		}
	}

	return root;
}

