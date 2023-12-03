#ifndef COLLISION_RESOLUTION_H
#define COLLISION_RESOLUTION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10

// 연결 리스트 노드 구조체
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// 해시 테이블 (연결 리스트 배열 및 정수 배열)
extern Node* chainingHashTable[TABLE_SIZE];
extern int linearProbingHashTable[TABLE_SIZE];

int hashFunction(int key);
Node* createNode(int key);
void initializeHashTable();
void insertWithChaining(int key);
void insertWithLinearProbing(int key);
void printChainingHashTable();
void printLinearProbingHashTable();
void explainCollisionResolution();
void showCollisionResolutionProcess();
void collisionResolution();

#endif // COLLISION_RESOLUTION_H
