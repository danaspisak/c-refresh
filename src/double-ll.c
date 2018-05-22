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


dllnode *dlMergeSort(dllnode **list)
{
	dllnode *a, *b, *c, *d;
	dllnode *currNode, *newList;
	int l = dlSize(*list);

	/* Only continue to divide if we have more than a node */
	if (l > 1)
	{
		a = dlAccessIndex(*list,(l /2) -1);

		/* Divide the list [0..a][b..end] */
		b = a->next;       // b is the first node of the second list
		a->next = NULL;    // terminate the first list
		b->prev = NULL;

		/* Continue to divide the lists */
		c = dlMergeSort(list);
		d = dlMergeSort(&b);

		/* Merge sorted lists */
		newList = NULL;
		while ((c != NULL) && (d != NULL))
		{
			if (c->value > d->value)
			{
				/* If it's the first time, set the initial head */
				if (newList == NULL)
				{
					newList = d;
					d->prev = NULL;
				}
				else
				{
					currNode->next = d;
					d->prev = NULL;
				}
				currNode = d;
				d = d->next;
			}
			else
			{
				/* If it's the first time, set the initial head */
				if (newList == NULL)
				{
					newList = c;
					c->prev = NULL;
				}
				else
				{
					currNode->next = c;
					c->prev = currNode;
				}

				currNode = c;
				c = c->next;
			}
		}

		/* Link in the remaining nodes from the non-empty list */
		if (c == NULL)
		{
			currNode->next = d;
			d->prev = currNode;
		}
		else
		{
			currNode->next = c;
			c->prev = currNode;
		}

	}
	else
		newList = *list;

	return newList;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int dlPartition (dllnode **list, int low, int high)
{
	dllnode *pivotNode;
	dllnode *jNode;
	int i,j;

    // pivot (Element to be placed at right position)
    pivotNode = dlAccessIndex(*list,high);

    i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
    	jNode = dlAccessIndex(*list,j);

        if (jNode->value <= pivotNode->value)
        {
            i++;    // increment index of smaller element
            dlSwap(list, dlAccessIndex(*list,i), dlAccessIndex(*list,j));
        }
    }
    //swap arr[i + 1] and arr[high])
    dlSwap(list, dlAccessIndex(*list, i+1), dlAccessIndex(*list,high));
    return (i + 1);
}

void dlQuickSort(dllnode **node,int low, int high)
{
	int pi;

	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now
		   at right place */
		pi = dlPartition(node, low, high);

		dlQuickSort(node, low, pi - 1);  // Before pi
		dlQuickSort(node, pi + 1, high); // After pi
	}
}
