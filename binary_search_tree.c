#include "binary_search_tree.h"
#include "stack.h"
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

static bool findKth(Node* node, int* val, int* k)
{
    if (node == NULL) {
        return false;
    }

    // when K-th element is found, the recursion will unwind
    if (findKth(node->leftChild, val, k)) {
        return true;
    }

    (*k)--;
    if (*k == 0) {
        *val = node->value;
        return true;
    }

    return findKth(node->rightChild, val, k);
}

bool bstMinKth(BST* tree, int* val, int k)
{
    bool isValid = true;

    if (k <= 0) {
        printf("Index must be positive!\n");
        isValid = false;
    }
    if (tree == NULL) {
        printf("Tree is not found!\n");
        return false;
    }
    if (tree->size < k) {
        printf("Size of tree < index!\n");
        isValid = false;
    }
    if (!isValid) {
        return false;
    }
    int counter = k;
    findKth(tree->root, val, &counter);

    return true;
}

static void bstMergeRec(BST* into, Node* curr1, Node* curr2)
{
    if (curr1 != NULL) {
        bstInsert(into, curr1->value);
        bstMergeRec(into, curr1->leftChild, curr1->rightChild);
    }
    if (curr2 != NULL) {
        bstInsert(into, curr2->value);
        bstMergeRec(into, curr2->leftChild, curr2->rightChild);
    }
}

BST* bstMerge(BST* tree1, BST* tree2)
{
    BST* res = newBst();
    Node* curr1 = tree1->root;
    Node* curr2 = tree2->root;
    bstMergeRec(res, curr1, curr2);
    return res;
}

void bstDelete(BST* tree, int value)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    Node* current = tree->root;
    Node* parent = NULL;

    while (current != NULL && current->value != value) {
        parent = current;
        if (value < current->value) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }
    if (current == NULL) {
        return;
    }
    if (current->leftChild != NULL && current->rightChild != NULL) {
        Node* successor = current->rightChild;
        Node* successorParent = current;
        while (successor->leftChild != NULL) {
            successorParent = successor;
            successor = successor->leftChild;
        }
        current->value = successor->value;
        current = successor;
        parent = successorParent;
    }

    Node* child;
    if (current->leftChild != NULL) {
        child = current->leftChild;
    } else {
        child = current->rightChild;
    }
    if (parent == NULL) {
        tree->root = child;
    } else {
        if (parent->leftChild == current) {
            parent->leftChild = child;
        } else {
            parent->rightChild = child;
        }
    }
    free(current);
    tree->size--;
}

Iterator* iteratorInit(BST* tree)
{
    Iterator* it = (Iterator*)malloc(sizeof(Iterator));
    int filled = 0;
    it->currIdx = 0;
    it->size = tree->size;
    it->values = (int*)calloc(it->size, sizeof(int));
    if (it->values == NULL) {
        printf("Allocation error\n");
        return it;
    }

    Node* curr = tree->root;
    Stack* stack = newStack();
    while (curr != NULL || !isEmpty(stack)) {
        while (curr != NULL) {
            push(stack, curr);
            curr = curr->leftChild;
        }
        curr = (Node*)pop(stack);
        it->values[filled] = curr->value;
        filled++;
        curr = curr->rightChild;
    }

    deleteStack(stack);
    return it;
}

bool iteratorHasNext(Iterator* it)
{
    return it->currIdx < it->size;
}

int iteratorNext(Iterator* it)
{
    if (!iteratorHasNext(it))
        return -1;
    int res = it->values[it->currIdx];
    it->currIdx++;
    return res;
}

void iteratorFree(Iterator* it)
{
    free(it->values);
    free(it);
}
