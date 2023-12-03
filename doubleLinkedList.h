// double_list.h

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// 이중 연결 리스트의 노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 함수 선언
Node* createNode(int data);
void insertAtFront(Node** head, int data);
void deleteNode(Node** head, int key);
void displayListForward(Node* head);
void displayListBackward(Node* tail);
void freeList(Node** head);
void doubleLinkedList();

#endif
