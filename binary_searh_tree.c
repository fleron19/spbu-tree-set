#include "binary_searh_tree.h"

struct BST {
    struct Node* root;
};

struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
};
