#include "binary_searh_tree.h"
#include <stdlib.h>

struct BST {
    struct Node* root;
};

struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
};

BST* newBst() {
    BST* bst = (BST*)malloc(sizeof(*bst));
    return bst;
}

void bstInsert(BST* tree, int value) {
    if (tree->root == NULL) {
        Node* node = (Node*)malloc(sizeof(*node));
        node->value = value;
        tree->root = node;
        return;
    }
    Node* curr = tree->root;
    while (true) {
        if (value > curr->value) {
            if (curr->rightChild != NULL) {
                curr = curr->rightChild;
                continue;
            }
            else {
                Node* node = (Node*)malloc(sizeof(*node));
                node->value = value;
                break;
            }
        }
        else if (value < curr->value){
            if (curr->leftChild != NULL) {
                curr = curr->leftChild;
                continue;
            }
            else {
                Node* node = (Node*)malloc(sizeof(*node));
                node->value = value;
                break;
            }
        }
    }
}
