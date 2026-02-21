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
static void freeNode(Node* node);
void bstFree(BST* tree);
static void bstInorderNode(Node* node);
void bstInorder(BST* tree); // LNR
static void bstPreorderNode(Node* node);
void bstPreorder(BST* tree); // NLR
static void bstPostorderNode(Node* node);
void bstPostorder(BST* tree); // LRN
