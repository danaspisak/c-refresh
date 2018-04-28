#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

/*!
 * 	\brief Create a node to be added to the linked list.
 *
 * 	\params **newNode pointer to the newly allocated node. NULL if status is not SUCCESS
 *
 * 	\return status returns an error for memory allocation
 *
 */
STATUS createNode(llnode **newNode)
{
	STATUS status = LL_SUCCESS;

	*newNode = malloc(sizeof(llnode));
	if (*newNode)
	{
		(*newNode)->next = NULL;
	}
	else
	{
		status = LL_ERROR;
		(*newNode) = NULL;
	}

	return status;
}

void destroyNode(llnode *toDestroy)
{
	free((void *)toDestroy);
}

STATUS insertBeginning(llnode **listHead, int value)
{
	STATUS status = LL_SUCCESS;
	llnode *newNode;
	status = createNode(&newNode);
	if (status == LL_SUCCESS)
	{
		newNode->value = value;
		newNode->next = *listHead;
		*listHead = newNode;
	}
	return status;
}

STATUS insertAfter(int value, llnode *afterThis)
{
	STATUS status = LL_ERROR;
	llnode *newNode;

	if (afterThis)
	{
		status = createNode(&newNode);
		if (status == LL_SUCCESS)
		{
			newNode->value = value;
			newNode->next = afterThis->next;
			afterThis->next = newNode;
		}
	}

	return status;

}

llnode *accessIndex(llnode *listHead, int index)
{
	llnode *foundNode = NULL;
	int i=0;
	if (index >= 0)
	{
		foundNode = listHead;
		while(i < index && foundNode)
		{
			i++;
			foundNode = foundNode->next;
		}
	}
	return foundNode;
}


void printList(llnode *listHead)
{
	llnode *currNode = listHead;

	while(currNode)
	{
		printf("value: %d\n",currNode->value);
		currNode = currNode->next;
	}

}

STATUS deleteAfter(llnode *preNode)
{
	STATUS status = LL_SUCCESS;

	llnode *newNext;
	if (preNode == NULL)
	{
		status = LL_ERROR;
	}
	else if (preNode->next == NULL)
	{
		status = LL_ERROR;
	}
	else
	{
		newNext = ((llnode *)preNode->next)->next;
		destroyNode(preNode->next);
		preNode->next = newNext;
	}

	return status;
}

STATUS deleteBeginning(llnode **listHead)
{
	STATUS status = LL_ERROR;
	llnode *nextNode;

	if (*listHead != NULL)
	{
		nextNode = (*listHead)->next;
		destroyNode(*listHead);
		*listHead = nextNode;
		status = LL_SUCCESS;
	}

	return status;
}

int length(llnode *listHead)
{
	int i = 0;

	if (listHead)
	{
		i++;
		while(listHead->next)
		{
			i++;
			listHead = listHead->next;
		}
	}

	return i;
}

int lengthR(llnode *node)
{
	if(node == NULL)
		return 0;

	return 1 + lengthR(node->next);
}
