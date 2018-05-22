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

STATUS dlInsertAfter(int value, dllnode *afterThis)
{
	STATUS status = CF_ERROR;
	dllnode *newNode;

	if (afterThis)
	{
		status = dlCreateNode(&newNode);
		if (status == CF_SUCCESS)
		{
			newNode->value = value;
			newNode->next = afterThis->next;
			newNode->prev = afterThis;
			afterThis->next->prev = newNode;
			afterThis->next = newNode;
		}
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

STATUS dlDeleteBeginning(dllnode **listHead)
{
	STATUS status = CF_ERROR;
	dllnode *nextNode;

	if (*listHead != NULL)
	{
		nextNode = (*listHead)->next;
		if (nextNode != NULL)
		{
			nextNode->prev = NULL;
		}
		dlDestroyNode(*listHead);
		*listHead = nextNode;
		status = CF_SUCCESS;
	}

	return status;
}

void dlDeleteList(dllnode **head)
{
	while (dlDeleteBeginning(head) == CF_SUCCESS);
}

STATUS dlDeleteIndex(dllnode **listHead,int index)
{
	STATUS status = CF_ERROR;
	dllnode *tmpNode, *prevNode,*nextNode;

	if (index == 0)
	{
		status = dlDeleteBeginning(listHead);
	}
	else if (index > 0)
	{
		tmpNode = dlAccessIndex(*listHead,index);
		if (tmpNode == NULL)
		{
			status = CF_ERROR;
		}
		else
		{
			tmpNode->prev->next = tmpNode->next;
			if (tmpNode->next != NULL)
			{
				tmpNode->next->prev = tmpNode->prev;
			}
			dlDestroyNode(tmpNode);
			status = CF_SUCCESS;
		}
	}

	return status;
}


int dlSize(dllnode *listHead)
{
	int size = 0;
	dllnode *tmpNode = listHead;

	while(tmpNode != NULL)
	{
		size++;
		tmpNode = tmpNode->next;
	}

	return size;
}

dllnode *dlMiddle(dllnode *head)
{
	return dlAccessIndex(head, dlSize(head)/2);
}

STATUS dlSwap(dllnode **listHead, dllnode *nodeX, dllnode *nodeY)
{
	dllnode *tmpNode;
	STATUS return_status = CF_ERROR;


	if ((*listHead != NULL) && (nodeX != NULL) && (nodeY != NULL) && (nodeX != nodeY))
	{

		if ((nodeX->next != nodeY) && (nodeY->next != nodeX))
		{
			if (nodeX->prev != NULL)
				nodeX->prev->next = nodeY;
			else
				*listHead = nodeY;

			if (nodeY->prev != NULL)
				nodeY->prev->next = nodeX;
			else
				*listHead = nodeX;

			/* what if nodeX->next is nodeY */
			tmpNode = nodeX->next;

			nodeX->next = nodeY->next;
			if (nodeY->next != NULL)
				nodeY->next->prev = nodeX;
			if (nodeY->next != tmpNode)
				nodeY->next = tmpNode;
			if (tmpNode != NULL)
				tmpNode->prev = nodeY;

			tmpNode = nodeY->prev;
			nodeY->prev = nodeX->prev;
			nodeX->prev = tmpNode;

			return_status = CF_SUCCESS;
		}
		else
		{
			/* For adjacent nodes, make X before Y */
			/* Swap pointer to X and Y */
			if (nodeY->next == nodeX)
			{
				tmpNode = nodeX;
				nodeX = nodeY;
				nodeY = tmpNode;
			}

			if (nodeX->prev != NULL)
				nodeX->prev->next = nodeY;
			else
				*listHead = nodeY;

			nodeY->prev = nodeX->prev;
			if (nodeY->next != NULL)
				nodeY->next->prev = nodeX;
			nodeX->next = nodeY->next;
			nodeY->next = nodeX;
			nodeX->prev = nodeY;

			return_status = CF_SUCCESS;
		}
	}

	return return_status;
}

void dlReverse(dllnode **listHead)
{
	dllnode *tmpNode;
	dllnode *currNode;

	currNode = *listHead;
	tmpNode = currNode->next;

	while(tmpNode != NULL)
	{
		currNode->next = currNode->prev;
		currNode->prev = tmpNode;

		currNode = tmpNode;
		tmpNode = currNode->next;

	}
}
