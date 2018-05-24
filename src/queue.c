#include "queue.h"
#include "double-ll.h"
#include <stdio.h>
#include <stdlib.h>

STATUS enqueue(queue **q, int value)
{
	STATUS status = CF_ERROR;

	if (*q != NULL)
	{
		if ((*q)->head == NULL)
		{
			/* Empty queue */
			status = dlInsertBeginning(&((*q)->tail), value);
			if (status == CF_SUCCESS)
				(*q)->head = (*q)->tail;
		}
		else
		{
			status = dlInsertAfter(value, (*q)->tail);
			if (status == CF_SUCCESS)
				(*q)->tail = (*q)->tail->next;
		}
	}

	return status;
}

STATUS dequeue(queue **q, int *value)
{
	STATUS status = CF_ERROR;

	if(*q != NULL)
	{
		if ((*q)->head != NULL)
		{
			*value = (*q)->head->value;
		}
		status = dlDeleteBeginning(&((*q)->head));
		if (status == CF_SUCCESS)
		{
			/* Check if we're at the end */
			if ((*q)->head == NULL)
			{
				(*q)->tail = NULL;
			}
		}
	}

	return status;
}

/*
void rear(queue *q,int*);
void front(queue *q, int*);
*/
