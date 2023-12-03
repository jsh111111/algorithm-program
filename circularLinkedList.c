// list.c

#include "circularLinkedlist.h"
#include "allHeaders.h"

// �� ��� ����
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode;  // ���� ���� ����Ʈ�� ���� �ڱ� �ڽ��� ����Ŵ
    return newNode;
}

// ����Ʈ�� ���� �κп� ��� ����
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {  // ������ ��� ã��
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

// ����Ʈ�� �� �κп� ��� ����
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// �־��� Ű�� ���� ��� ����
void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    Node *temp = *head, *prev = NULL;
    while (temp->data != key) {
        if (temp->next == *head) return;  // Ű�� ã�� ����
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head && temp->next == *head) {  // �ϳ��� ��常 �ִ� ���
        *head = NULL;
    } else {
        if (temp == *head) {
            *head = (*head)->next;
        }
        prev->next = temp->next;
    }
    free(temp);
}

// ����Ʈ ���
void displayList(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(%d���� ���ư�)\n", head->data);
}

// ����Ʈ ����
void freeList(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != *head);

    *head = NULL;
}

void circularLinkedlist() {
    system("cls");
    Node* head = NULL;

    // ������ ���ڷ� ����Ʈ �۵� ���� �����ֱ�
    for (int i = 0; i < 10; i++) {
        insertAtEnd(&head, i);
    }
    printf("���� ����Ʈ: ");
    displayList(head);

    // ����� �Է��� ���� ���� �߰�
    int number;
    printf("����Ʈ ���� �κп� �߰��� ���ڸ� �Է��ϼ���: ");
    scanf("%d", &number);
    insertAtFront(&head, number);
    printf("������Ʈ�� ���� ����Ʈ: ");
    displayList(head);

    // ����Ʈ ����
    freeList(&head);
}
