// circularLinkedlist.h

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// 원형 연결 리스트의 노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 함수 선언
Node* createNode(int data);
void insertAtFront(Node** head, int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int key);
void displayList(Node* head);
void freeList(Node** head);
void circularLinkedlist();

#endif
