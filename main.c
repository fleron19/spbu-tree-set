#include "binary_search_tree.h"
#include <stdio.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

bool testbstInsert_1()
{
    BST* bst = newBst();
    bstInsert(bst, 5);
    bstInsert(bst, 1);
    bstInsert(bst, 6);
    if (bst->root->value != 5) {
        return false;
    }
    if (bst->root->leftChild->value != 1) {
        return false;
    }
    if (bst->root->rightChild->value != 6) {
        return false;
    }

    Node* rc = bst->root->rightChild;
    Node* lc = bst->root->rightChild;
    if (rc->leftChild || rc->rightChild || lc->leftChild || lc->rightChild) {
        return false;
    }

    bstFree(bst);
    return true;
}

bool testbstInsert_2()
{
    BST* bst = newBst();
    bstInsert(bst, 1);
    bstInsert(bst, 3);
    bstInsert(bst, 3);
    bstInsert(bst, 7);
    if (bst->root->value != 1) {
        return false;
    }
    if (bst->root->rightChild->value != 3) {
        return false;
    }
    if (bst->root->rightChild->rightChild->value != 7) {
        return false;
    }
    if (bst->root->leftChild) {
        return false;
    }
    bstFree(bst);
    return true;
}

bool testbstContains_1()
{
    BST* bst = newBst();
    bstInsert(bst, 5);
    bstInsert(bst, 1);
    bstInsert(bst, 6);
    bstInsert(bst, 8);
    bool res = bstContains(bst, 8);
    bstFree(bst);
    return res;
}

bool testbstContains_2()
{
    BST* bst = newBst();
    bstInsert(bst, 5);
    bstInsert(bst, 1);
    bstInsert(bst, 6);
    bstInsert(bst, 8);
    bool res = !bstContains(bst, 12);
    bstFree(bst);
    return res;
}

int main(int argc, char** argv)
{
    bool testMode = false;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "--test") == 0) {
            testMode = true;
            break;
        }
    }

    if (testMode) {
        bool (*tests[4])() = { &testbstInsert_1, &testbstInsert_2,
            &testbstContains_1, &testbstContains_2 };
        for (int testNum = 0; testNum < 4; ++testNum) {
            if (tests[testNum]()) {
                printf(GREEN("Test %d passed!\n"), testNum + 1);
            } else {
                printf(RED("Test %d failed!\n"), testNum + 1);
                return 1;
            }
        }
        return 0;
    }
    BST* bst = newBst();
    printf("Empty tree tests: \n");
    printf("LNR = ");
    bstInorder(bst); 
    printf("NLR = ");
    bstPreorder(bst); 
    printf("LRN = ");
    bstPostorder(bst); // all 3 - empty

    printf("Tree size = %d\n", bstSize(bst));
    printf("Tree height = %d\n", bstHeight(bst));
    printf("Max Value = %d\n", bstMax(bst));
    printf("Min Value = %d\n", bstMin(bst));

    printf("----------------------------- \n");

    printf("Not empty tree tests: \n");
    bstInsert(bst, 10);
    bstInsert(bst, 5);
    bstInsert(bst, 3);
    bstInsert(bst, 7);
    bstInsert(bst, 6);
    bstInsert(bst, 9);
    bstInsert(bst, 11);
    bstInsert(bst, 15);
    bstInsert(bst, 14);

    printf("LNR = ");
    bstInorder(bst); // 3 5 6 7 9 10 11 14 15
    printf("NLR = ");
    bstPreorder(bst); // 10 5 3 7 6 9 11 15 14
    printf("LRN = ");
    bstPostorder(bst); // 3 6 9 7 5 14 15 11 10

    printf("Tree size = %d\n", bstSize(bst));
    printf("Tree height = %d\n", bstHeight(bst));
    printf("Max Value = %d\n", bstMax(bst));
    printf("Min Value = %d\n", bstMin(bst));
    return 0;
}
