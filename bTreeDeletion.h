#ifndef BTREE_DELETION_H
#define BTREE_DELETION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEYS 3  // B-트리의 최대 키 수 (예시로 3을 사용)

typedef struct BTreeNode {
    int keys[MAX_KEYS];  // 키를 저장하는 배열
    struct BTreeNode *children[MAX_KEYS + 1];  // 자식 노드 포인터 배열
    int numKeys;  // 현재 노드의 키 수
    int isLeaf;  // 리프 노드인지 여부
} BTreeNode;

// 함수 선언
BTreeNode* createBTreeNode(int isLeaf);
void insertInBTree(BTreeNode **root, int key);
void splitChild(BTreeNode *parent, int index, BTreeNode *child);
void insertNonFull(BTreeNode *node, int key);
void deleteFromBTree(BTreeNode **root, int key);
void printBTree(BTreeNode *node, int level);
void explainBTreeDeletion();
void showBTreeDeletion();
void performBTreeDeletion();
void BTreeDeletionMenu();

#endif // BTREE_DELETION_H
