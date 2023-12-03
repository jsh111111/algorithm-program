// double_list.c

#include "doubleLinkedList.h"

// 새 노드 생성
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 리스트의 시작 부분에 노드 삽입
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// 리스트의 끝 부분에 노드 삽입
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// 주어진 키를 가진 노드 삭제
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    free(temp);
}

// 리스트 출력
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 리스트 해제
void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void doubleLinkedList() {
    system("cls");
    Node* head = NULL;

    // 임의의 숫자로 리스트 작동 과정 보여주기
    for (int i = 0; i < 10; i++) {
        insertAtEnd(&head, i);  // 리스트의 끝에 숫자 추가
    }
    printf("리스트: ");
    displayList(head);

    // 사용자 입력을 통한 숫자 추가
    int number;
    printf("리스트 시작 부분에 추가할 숫자를 입력하세요: ");
    scanf("%d", &number);
    insertAtFront(&head, number);
    printf("업데이트된 리스트: ");
    displayList(head);

    // 리스트 해제
    freeList(&head);
}
