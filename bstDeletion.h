#ifndef BST_DELETION_H
#define BST_DELETION_H

#include "bstInsertion.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
Node* deleteNode(Node* node, int key);
Node* findMinNode(Node* node);
void explainBSTDeletion();
void showBSTDeletion();
void performBSTDeletion();
void BSTDeletionMenu();

#endif // BST_DELETION_H