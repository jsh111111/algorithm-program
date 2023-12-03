#ifndef BTREE_INSERTION_H
#define BTREE_INSERTION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEYS 3  // B-트리의 최대 키 수 (예시로 3을 사용)

// B-트리 노드 구조체 선언
typedef struct BTreeNode {
    int keys[MAX_KEYS];
    struct BTreeNode *children[MAX_KEYS + 1];
    int numKeys;
    int isLeaf;
} BTreeNode;

// 함수 선언
BTreeNode* createBTreeNode(int isLeaf);
void insertInBTree(BTreeNode **root, int key);
void splitChild(BTreeNode *parent, int index, BTreeNode *child);
void insertNonFull(BTreeNode *node, int key);
void printBTree(BTreeNode *node);
void explainBTreeInsertion();
void showBTreeInsertion();
void performBTreeInsertion();
void BTreeInsertionMenu();

#endif // BTREE_INSERTION_H
