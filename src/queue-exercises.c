#include "queue.h"
#include "double-ll.h"
#include <stdio.h>
#include <stdlib.h>

STATUS pushQueue(queue **q, int value)
{
	return enqueue(q, value);
}

STATUS dequeueAtTail(queue **inputQ, queue **tempQ, int *lastValue)
{

	int value, return_value;
	STATUS status;

	/* Take items from the queue until it's empty. Put each item on a tempQ. Once we reach
	 * the end, treat the first items in the queue differently by returning it. The
	 * remaining items are added back to the original queue.
	 */
	status = dequeue(inputQ,&value);
	if (status == CF_SUCCESS)
	{
		enqueue(tempQ,value);
		status = dequeueAtTail(inputQ,tempQ,lastValue);
		if (status != CF_SUCCESS)
		{
			*lastValue = value;
			status = CF_SUCCESS;
		}
		else
		{

			status = dequeue(tempQ, &value);
			if (status == CF_SUCCESS)
			{
				enqueue(inputQ, value);
			}
			status = CF_SUCCESS;
		}
	}

	return status;
}

STATUS popQueue(queue **q, int *value)
{
	STATUS status = CF_SUCCESS;
	queue tempQ;
	queue *pt = &tempQ;

	tempQ.head = NULL;
	tempQ.tail = NULL;

	if (((*q)->head) != NULL)
		dequeueAtTail(q, &pt, value);
	else
		status = CF_ERROR;
	return status;
}

