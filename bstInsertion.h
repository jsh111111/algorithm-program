// bstInsertion.h
#ifndef BST_INSERTION_H
#define BST_INSERTION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// BST 노드 구조체 선언
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// 함수 선언
Node* createNode(int key);
Node* insertNode(Node* node, int key);
void printTreeInOrder(Node* node);
void printTree(Node* node);
void explainBSTInsertion();
void showBSTInsertion();
void performBSTInsertion();
void BSTInsertionMenu();

#endif