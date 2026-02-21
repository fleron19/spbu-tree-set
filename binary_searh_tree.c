#include "binary_searh_tree.h"
#include <stdio.h>
#include <stdlib.h>

BST* newBst()
{
    BST* bst = (BST*)malloc(sizeof(*bst));
    bst->root = NULL;
    return bst;
}

void bstInsert(BST* tree, int value)
{
    if (tree->root == NULL) {
        Node* node = (Node*)malloc(sizeof(*node));
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
    if (tree->root == NULL) {
        return false;
    } else {
        Node* curr = tree->root;
        while (true) {
            if (value == curr->value) {
                return true;
            }
            if (value > curr->value) {
                if (!curr->rightChild) {
                    return false;
                }
                curr = curr->rightChild;
            } else {
                if (!curr->leftChild) {
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
    if (tree->root == NULL) {
        free(tree);
        return;
    }

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
    if (tree->root != NULL) {
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
    if (tree->root != NULL) {
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
    if (tree->root != NULL) {
        bstPostorderNode(tree->root);
    } else {
        printf("Tree is empty");
    }
    printf("\n");
}
