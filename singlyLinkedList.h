// list.h

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// 연결 리스트의 노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 함수 선언
Node* createNode(int data);
void insertNode(Node** head, int data);
void deleteNode(Node** head, int key);
void displayList(Node* head);
void freeList(Node** head);
void singlyLinkedList();

#endif
