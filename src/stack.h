#ifndef STACK_H
#define STACK_H

#include "linked-list.h"

/* push, pop, peek, isEmpty */
STATUS push(llnode **list, int item);
STATUS pop(llnode **list, int *return_item);
STATUS peek(llnode *list, int *return_item);
int isEmpty(llnode *list);

#endif
