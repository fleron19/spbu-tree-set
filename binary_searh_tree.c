#include "binary_searh_tree.h"
#include <stdlib.h>

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
                curr->rightChild = node;
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
                curr->leftChild = node;
                break;
            }
        }
    }
}
