#ifndef STACK_EXERCISES_H
#define STACK_EXERCISES_H

#include "linked-list.h"

STATUS checkBalanced(char *);
void reverseStack(llnode **head);
void enqueueStack(llnode **head, int value);
void dequeueStack(llnode **head, int *value);
#endif
