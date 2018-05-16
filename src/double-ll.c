#include "double-ll.h"
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
STATUS dlCreateNode(dllnode **newNode)
{
	STATUS status = CF_SUCCESS;

	*newNode = malloc(sizeof(dllnode));
	if (*newNode)
	{
		(*newNode)->next = NULL;
		(*newNode)->prev = NULL;
	}
	else
	{
		status = CF_ERROR;
		(*newNode) = NULL;
	}

	return status;
}

void dlDestroyNode(dllnode *toDestroy)
{
	free((void *)toDestroy);
}

STATUS dlInsertBeginning(dllnode **head,int value)
{
	STATUS status = CF_SUCCESS;
	dllnode *newNode;

	status = dlCreateNode(&newNode);
	if (status == CF_SUCCESS)
	{
		newNode->value = value;
		newNode->next = *head;
		newNode->prev = NULL;
		if (*head != NULL)
		{
			(*head)->prev = newNode;
		}

		*head = newNode;
	}
	return status;
}

dllnode *dlAccessIndex(dllnode *listHead, int index)
{
	dllnode *foundNode = NULL;
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
