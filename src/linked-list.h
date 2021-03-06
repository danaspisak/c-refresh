#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef int STATUS;

#define LL_ERROR 	0
#define LL_SUCCESS 	1

typedef struct LLNode
{
 int value;
 struct LLNode *next;
} llnode;


STATUS createNode(llnode **);
void destroyNode(llnode *);
STATUS insertBeginning(llnode **,int);
STATUS insertAfter(int, llnode *);
llnode *accessIndex(llnode *,int);
STATUS deleteAfter(llnode *);
STATUS deleteBeginning(llnode **);
void deleteList(llnode **);
llnode *find(llnode*,int);
llnode *findR(llnode *,int);
STATUS swap(llnode **, int, int);

llnode *reverse(llnode **, llnode **);
llnode *middle(llnode *);


void printList();
int length(llnode *);
int lengthR(llnode *);

void merge(llnode *, llnode **);
llnode *mergeSort(llnode **);


#endif
