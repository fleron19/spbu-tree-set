#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

BST* newBst(void)
{
    BST* bst = (BST*)malloc(sizeof(*bst));
    if (bst == NULL) {
        printf("Allocation error\n");
        return NULL;
    }
    bst->root = NULL;
    bst->size = 0;
    return bst;
}

void bstInsert(BST* tree, int value)
{
    if (tree->root == NULL) {
        Node* node = (Node*)malloc(sizeof(*node));
        if (node == NULL) {
            printf("Allocation error\n");
            return;
        }
        tree->size++;
        node->value = value;
        node->leftChild = NULL;
        node->rightChild = NULL;
        tree->root = node;
        return;
    }
    Node* curr = tree->root;
    while (true) {
        if (value > curr->value) {
            if (curr->rightChild != NULL) {
                curr = curr->rightChild;
            } else {
                Node* node = (Node*)malloc(sizeof(*node));
                if (node == NULL) {
                    printf("Allocation error\n");
                    return;
                }
                tree->size++;
                node->value = value;
                curr->rightChild = node;
                node->leftChild = NULL;
                node->rightChild = NULL;
                break;
            }
        } else if (value < curr->value) {
            if (curr->leftChild != NULL) {
                curr = curr->leftChild;
            } else {
                Node* node = (Node*)malloc(sizeof(*node));
                if (node == NULL) {
                    printf("Allocation error\n");
                    return;
                }
                tree->size++;
                node->value = value;
                curr->leftChild = node;
                node->leftChild = NULL;
                node->rightChild = NULL;
                break;
            }
        } else {
            break;
        }
    }
}

bool bstContains(BST* tree, int value)
{
    if (tree->size == 0) {
        return false;
    } else {
        Node* curr = tree->root;
        while (true) {
            if (value == curr->value) {
                return true;
            }
            if (value > curr->value) {
                if (curr->rightChild == false) {
                    return false;
                }
                curr = curr->rightChild;
            } else {
                if (curr->leftChild == false) {
                    return false;
                }
                curr = curr->leftChild;
            }
        }
    }
}

static void freeNode(Node* node)
{
    if (node == NULL) {
        return;
    }

    freeNode(node->leftChild);
    freeNode(node->rightChild);

    free(node);
}

void bstFree(BST* tree)
{
    freeNode(tree->root);
    free(tree);
}

static void bstInorderNode(Node* node)
{
    if (node != NULL) {
        bstInorderNode(node->leftChild);
        printf("%d ", node->value);
        bstInorderNode(node->rightChild);
    }
}

void bstInorder(BST* tree)
{
    if (tree->size != 0) {
        bstInorderNode(tree->root);
    } else {
        printf("Tree is empty");
    }
    printf("\n");
}

static void bstPreorderNode(Node* node)
{
    if (node != NULL) {
        printf("%d ", node->value);
        bstPreorderNode(node->leftChild);
        bstPreorderNode(node->rightChild);
    }
}

void bstPreorder(BST* tree)
{
    if (tree->size != 0) {
        bstPreorderNode(tree->root);
    } else {
        printf("Tree is empty");
    }
    printf("\n");
}

static void bstPostorderNode(Node* node)
{
    if (node != NULL) {
        bstPostorderNode(node->leftChild);
        bstPostorderNode(node->rightChild);
        printf("%d ", node->value);
    }
}

void bstPostorder(BST* tree)
{
    if (tree->size != 0) {
        bstPostorderNode(tree->root);
    } else {
        printf("Tree is empty");
    }
    printf("\n");
}

int bstSize(BST* tree)
{
    return tree->size;
}

static int nodeHeight(Node* node)
{

    if (node == NULL) {
        return 0;
    }

    return MAX(nodeHeight(node->rightChild), nodeHeight(node->leftChild)) + 1;
}

int bstHeight(BST* tree)
{
    if (tree->size == 0) {
        return 0;
    }
    return nodeHeight(tree->root) - 1;
}

bool bstMin(BST* tree, int* val)
{
    if (tree->size == 0) {
        return false;
    }
    Node* curr = tree->root;
    int prevMin = curr->value;
    while (curr) {
        prevMin = curr->value;
        curr = curr->leftChild;
    }
    *val = prevMin;
    return true;
}
bool bstMax(BST* tree, int* val)
{
    if (tree->size == 0) {
        return false;
    }
    Node* curr = tree->root;
    int prevMax = curr->value;
    while (curr) {
        prevMax = curr->value;
        curr = curr->rightChild;
    }
    *val = prevMax;
    return true;
}

static bool findKth(Node* node, int* k, int* val)
{
    if (node == NULL) {
        return false;
    }

    // when K-th element is found, the recursion will unwind
    if (findKth(node->leftChild, k, val)) {
        return true;
    }

    (*k)--;
    if (*k == 0) {
        *val = node->value;
        return true;
    }

    return findKth(node->rightChild, k, val);
}

// I think bool is better, but task is task
int bstMinKth(BST* tree, int* val, int k)
{
    int isValid = 1;

    if (k <= 0) {
        printf("Index must be positive!\n");
        isValid = 0;
    }
    if (tree == NULL) {
        printf("Tree is not found!\n");
        return 0;
    }
    if (tree->size < k) {
        printf("Size of tree < index!\n");
        isValid = 0;
    }
    if (!isValid) {
        return 0;
    }
    int counter = k;
    findKth(tree->root, &counter, val);

    return 1;
}