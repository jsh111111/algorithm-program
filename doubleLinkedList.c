// double_list.c

#include "doubleLinkedList.h"

// �� ��� ����
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// ����Ʈ�� ���� �κп� ��� ����
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// ����Ʈ�� �� �κп� ��� ����
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

// �־��� Ű�� ���� ��� ����
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

// ����Ʈ ���
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ����Ʈ ����
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

    // ������ ���ڷ� ����Ʈ �۵� ���� �����ֱ�
    for (int i = 0; i < 10; i++) {
        insertAtEnd(&head, i);  // ����Ʈ�� ���� ���� �߰�
    }
    printf("����Ʈ: ");
    displayList(head);

    // ����� �Է��� ���� ���� �߰�
    int number;
    printf("����Ʈ ���� �κп� �߰��� ���ڸ� �Է��ϼ���: ");
    scanf("%d", &number);
    insertAtFront(&head, number);
    printf("������Ʈ�� ����Ʈ: ");
    displayList(head);

    // ����Ʈ ����
    freeList(&head);
}
