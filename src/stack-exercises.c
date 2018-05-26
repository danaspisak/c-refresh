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

void insertAtBottom(llnode **head, int item)
{
	int value;

	/* Move everything off the stack until it's empty
	 * and then place the item we want at the bottom and replace
	 * the item from the function stack.
	 */
	if (isEmpty(*head))
	{
		push(head, item);
	}
	else
	{
		pop(head, &value);
		insertAtBottom(head, item);
		push(head, value);
	}
}

void reverseStack(llnode **head)
{
	int value;

	/* Empty the stack with each item on the function stack, then
	 * reinsert by putting the item as the bottom of the stack.
	 */
	if (!isEmpty(*head))
	{
		pop(head, &value);
		reverseStack(head);
		insertAtBottom(head, value);
	}
}

void enqueueStack(llnode **head, int value)
{
	push(head, value);
}

int removeBottomOfStack(llnode **head)
{
	int value, return_value;

	/* Recurively go until the stack is empty. Use the funtion return value
	 * to pass back the last item. Place the other items back on the stack.
	 */
	if (!isEmpty(*head))
	{
		pop(head, &value);
		if (isEmpty(*head))
		{
			return_value = value;
		}
		else
		{
			return_value = removeBottomOfStack(head);
			push(head, value);
		}
	}

	return return_value;
}

void dequeueStack(llnode **head, int *value)
{
	*value = removeBottomOfStack(head);
}

