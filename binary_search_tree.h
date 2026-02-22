#pragma once
#include <stdbool.h>

struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct BST {
    struct Node* root;
    int size;
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

static int nodeHeight(Node* node);
int bstHeight(BST* tree);
int bstSize(BST* tree);
int bstMin(BST* tree); // min for empty = -1
int bstMax(BST* tree); // max for empty = -1
