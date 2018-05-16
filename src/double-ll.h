#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

typedef int STATUS;

#define CF_ERROR 	0
#define CF_SUCCESS 	1

typedef struct DLLNode
{
 int value;
 struct DLLNode *prev;
 struct DLLNode *next;
} dllnode;

STATUS dlCreateNode(dllnode **);
void dlDestroyNode(dllnode *);
STATUS dlInsertBeginning(dllnode **,int);
dllnode *dlAccessIndex(dllnode *, int);

#endif
