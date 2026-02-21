#pragma once
#include <stdbool.h>

typedef struct BST BST;
typedef struct Node Node;

void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);
