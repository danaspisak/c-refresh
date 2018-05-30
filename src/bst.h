#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct bstElement {
	char key;
	int  value;
}bstElement;

typedef struct bstNode {
	struct bstNode *left;
	struct bstNode *right;
	struct bstElement element;
} bstNode;

bstNode *bstCreateNode(char key, int value);
void bstAdd(bstNode **root, bstNode *newNode);
bstNode *bstSearch(bstNode **root, char key);
bstNode *bstDelete(bstNode *root, char key);

#endif
