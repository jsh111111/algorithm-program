#include "singlyLinkedList.h"
#include "allHeaders.h"

// �� ��� ����
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ����Ʈ�� ��� ����
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// �־��� Ű�� ���� ��� ����
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;
    
    // ��� ��尡 ������ ����� ���
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Ű�� ã�� ���� ��带 ����
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Ű�� ���� ��尡 ���� ���
    if (temp == NULL) return;

    // ��� ����
    prev->next = temp->next;
    free(temp);
}

// ����Ʈ ���
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
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

void singlyLinkedList() {
    system("cls");
    Node* head = NULL;  // �� ����Ʈ �ʱ�ȭ

    // ������ ���ڷ� ����Ʈ �۵� ���� �����ֱ�
    for (int i = 0; i < 10; i++) {
        insertNode(&head, i);
    }
    printf("����Ʈ: ");
    displayList(head);

    // ����� �Է��� ���� ���� �߰�
    int number;
    printf("����Ʈ�� �߰��� ���ڸ� �Է��ϼ���: ");
    scanf("%d", &number);
    insertNode(&head, number);
    printf("������Ʈ�� ����Ʈ: ");
    displayList(head);

    // ����Ʈ ����
    freeList(&head);
}
