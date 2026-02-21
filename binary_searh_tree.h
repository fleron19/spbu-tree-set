#pragma once
#include <stdbool.h>

struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct BST {
    struct Node* root;
};

typedef struct Node Node;
typedef struct BST BST;

void bstInsert(BST* tree, int value);
BST* newBst(void);
bool bstContains(BST* tree, int value);
void freeNode(Node* node);
void bstFree(BST* tree);
