#include "stack.h"
#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

STATUS push(llnode **list, int item)
{
	return insertBeginning(list, item);
}

STATUS pop(llnode **list, int *return_item)
{
	if (*list != NULL)
	{
		*return_item = (*list)->value;
	}

	return deleteBeginning(list);
}

STATUS peek(llnode *list, int *return_item)
{
	STATUS status = LL_ERROR;

	if (list != NULL)
	{
		*return_item = list->value;
		status = LL_SUCCESS;
	}

	return status;
}

int isEmpty(llnode *list)
{
	return (list == NULL);
}
