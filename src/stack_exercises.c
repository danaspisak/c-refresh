#include "stack.h"
#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

STATUS checkBalanced(char *input)
{
	STATUS status = LL_SUCCESS;
	llnode *stack = NULL;
	int value;

	if (input == NULL)
	{
		status = LL_ERROR;
	}
	while ((*input != 0) && (status == LL_SUCCESS))
	{
		if ((*input == '{') || (*input == '(') || (*input == '['))
		{
			value = (int)*input;
			status = push(&stack, value);
		}
		else
		{
			status = pop(&stack, &value);
			if (((*input == '}') && ((char)value != '{')) ||
				((*input == ']') && ((char)value != '[')) ||
				((*input == ')') && ((char)value != '(')))
			{
				status = LL_ERROR;
			}
		}
		input++;
	}

	deleteList(&stack);
	return status;
}
