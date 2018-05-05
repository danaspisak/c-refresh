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

void deleteList(llnode **head)
{
	while (deleteBeginning(head) == LL_SUCCESS);
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

llnode *find(llnode *node, int value)
{
	llnode *foundNode = NULL;

	while(node != NULL)
	{
		if (node->value == value)
		{
			foundNode = node;
			break;
		}
		node = node->next;

	}

	return foundNode;
}

llnode *findR(llnode *node, int value)
{

	if(node == NULL)
		return 0;

	if (node->value == value)
		return node;

	return findR(node->next, value);
}

STATUS findIndex(llnode *node, int value, int *index)
{
	STATUS status = LL_ERROR;
	int currIndex = 0;

	if (index != NULL)
	{
		while(node != NULL)
		{
			if(node->value == value)
			{
				*index = currIndex;
				status = LL_SUCCESS;
			}
			node = node->next;
			currIndex++;
		}
	}

	return status;
}


STATUS swap(llnode **node, int valueX, int valueY)
{
	llnode *nodeX, *nodeY, *preNodeX, *preNodeY, *tmpNode;
	STATUS return_status = LL_ERROR;

	if (*node != NULL )
	{
		preNodeX = NULL;
		nodeX = *node;
		while(nodeX && nodeX->value != valueX)
		{
			preNodeX = nodeX;
			nodeX = nodeX->next;
		}

		preNodeY = NULL;
		nodeY = *node;
		while(nodeY && nodeY->value != valueY)
		{
			preNodeY = nodeY;
			nodeY = nodeY->next;
		}

		/* Check we found both values */
		if ((nodeX != NULL ) && (nodeY != NULL))
		{
			if (nodeX != nodeY)
			{
				// If x is not head of linked list
				if (preNodeX != NULL)
				   preNodeX->next = nodeY;
				else // Else make y as new head
				   *node = nodeY;

				// If y is not head of linked list
				if (preNodeY != NULL)
				   preNodeY->next = nodeX;
				else  // Else make x as new head
				   *node = nodeX;

				// Swap next pointers
				tmpNode = nodeY->next;
				nodeY->next = nodeX->next;
				nodeX->next  = tmpNode;
			}
			return_status = LL_SUCCESS;
		}
	}

	return return_status;
}



llnode *reverse(llnode **head, llnode **node)
{
	llnode *tmpNode;

	if (*node == NULL)
		*node = *head;
	if((*node)->next != NULL)
	{
		tmpNode = reverse(head, &(*node)->next);
		tmpNode->next = *node;
		(*node)->next = NULL;
	}
	else
		*head = *node;

	return *node;
}

llnode *middle(llnode *head)
{
	return accessIndex(head, length(head)/2);
}

/*!
 * \brief Alternating merge by adding nodes of head2 between nodes of head1, does
 * not run longer than head1.
 * https://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/
 */
void merge(llnode *head1, llnode **head2)
{
	llnode *curList1, *curList2;
	llnode *tnode, *tnode2;

	if((*head2 != NULL) && (head1 != NULL))
	{
		curList1 = head1;
		curList2 = *head2;

		while(curList1 != NULL && curList2 != NULL)
		{
			tnode = curList1->next;
			curList1->next = curList2;
			curList1 = tnode;

			tnode2 = curList2->next;
			curList2->next = tnode;
			curList2 = tnode2;
			*head2 = tnode2;
		}
	}
}

llnode *mergeSort(llnode **list)
{
	llnode *a, *b, *c, *d;
	llnode *currNode, *newList;
	int l = length(*list);

	/* Only continue to divide if we have more than a node */
	if (l > 1)
	{
		a = accessIndex(*list,(l /2) -1);

		/* Divide the list [0..a][b..end] */
		b = a->next;       // b is the first node of the second list
		a->next = NULL;    // terminate the first list

		/* Continue to divide the lists */
		c = mergeSort(list);
		d = mergeSort(&b);

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
				}
				else
				{
					currNode->next = d;
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
				}
				else
				{
					currNode->next = c;
				}

				currNode = c;
				c = c->next;
			}
		}

		/* Link in the remaining nodes from the non-empty list */
		if (c == NULL)
			currNode->next = d;
		else
			currNode->next = c;

	}
	else
		newList = *list;

	return newList;
}

