#include "bstInsertion.h"
#include "allHeaders.h"

int lastInsertedKey = -1;  // ���������� ���Ե� ����� Ű�� �����ϴ� ���� ����

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }

    return node;
}

void printTreeInOrder(Node* node) {
    if (node != NULL) {
        printTreeInOrder(node->left);
        if (node->key == lastInsertedKey) {
            printf("[%d] ", node->key);  // ���Ե� ��� ����
        } else {
            printf("%d ", node->key);
        }
        printTreeInOrder(node->right);
    }
}

void printTree(Node* node) {
    printTreeInOrder(node);
    printf("\n");
}

void explainBSTInsertion() {
    system("cls");
    printf("���� �˻� Ʈ�������� ���� ������ ������ �����ϴ�:\n\n");

    printf("1. ���ο� ��带 Ʈ���� ��Ʈ���� �����Ͽ� ������ ��ġ�� ã���ϴ�.\n");
    printf("2. ���� ��庸�� ������ ���� ������ ��������, ũ�� ���������� �̵��մϴ�.\n");
    printf("3. ��� �ִ� ������ ��ġ�� �� ��带 �����մϴ�.\n");
    printf("4. �� ������ Ʈ���� �Ӽ��� �����ϸ鼭 �� ��带 ������ �� �ִ� ��ġ�� ã�� ������ �ݺ��˴ϴ�.\n\n");

}

void showBSTInsertion() {
    system("cls");
    printf("���� �˻� Ʈ�� �۵� ���� (���� ���� ����):");

    Node *root = NULL;
    int numbers[10];
    srand(time(0));  // ���� �ʱ�ȭ

    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 101;  // 0���� 100 ������ ���� ����
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    for (int i = 0; i < 10; i++) {
        lastInsertedKey = numbers[i];
        root = insertNode(root, numbers[i]);
        printf("���� ��: ");
        printTree(root);  // BST�� ���� ���� ���
    }
}

void performBSTInsertion() {
    system("cls");
    int n, value;
    Node *root = NULL;
    printf("������ ���� ������ �Է��ϼ��� (�ִ� 100��): ");
    scanf("%d", &n);
    n = (n > 100) ? 100 : n;  // �ִ� 100���� ����

    printf("������ ���ڵ��� �Է��ϼ��� (0~10000 ������ ����): \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        value = (value < 0) ? 0 : (value > 10000) ? 10000 : value;  // �Է� ���� ����
        lastInsertedKey = value;
        root = insertNode(root, value);
        printf("���� ��: ");
        printTree(root);  // BST�� ���� ���� ���
    }
}

void BSTInsertionMenu() {
    int choice;
    do {
        system("cls");
        printf("���� �˻� Ʈ�� ���� �޴�\n");
        printf("1: ����\n");
        printf("2: �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �۵�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainBSTInsertion();
                break;
            case 2:
                showBSTInsertion();
                break;
            case 3:
                performBSTInsertion();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
        system("pause");
    } while (choice != 0);
}

//int main() {
//    BSTInsertionMenu();
//    return 0;
//}
