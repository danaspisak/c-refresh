#ifndef QUEUE_H
#define QUEUE_H

#include "double-ll.h"

typedef struct Queue {
	dllnode *head;
	dllnode *tail;
} queue;

STATUS enqueue(queue **q, int);
STATUS dequeue(queue **q, int *);
void rear(queue *q,int*);
void front(queue *q, int*);


#endif
