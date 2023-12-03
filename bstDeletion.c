#include "bstDeletion.h"
#include "allHeaders.h"

Node* deleteNode(Node* node, int key) {
    if (node == NULL) return node;

    // Ű�� ���� ���� �Ǵ� ������ �ڽ����� �̵�
    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        // ��带 �����ؾ� �ϴ� ���
        if (node->left == NULL) {
            Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            free(node);
            return temp;
        }

        // �� �ڽ��� ��� �ִ� ���
        Node* temp = findMinNode(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}

Node* findMinNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void explainBSTDeletion() {
    system("cls");
    printf("���� �˻� Ʈ�������� ��� ���� ������ ������ �����ϴ�:\n\n");
    printf("1. ������ ��带 ã���ϴ�.\n");
    printf("2. ������ ��尡 �ڽ��� ���� ���, �ܼ��� ��带 �����մϴ�.\n");
    printf("3. �� ���� �ڽĸ� �ִ� ���, ��带 �ڽ����� ��ü�մϴ�.\n");
    printf("4. �� ���� �ڽ��� ���� ���, ������ ���� Ʈ������ ���� ���� ���� ã�� ������ ���� ��ü�� ��, �ش� ��带 �����մϴ�.\n\n");
}

void showBSTDeletion() {
    system("cls");
    printf("BST ���� ����:\n\n");

    Node *root = NULL;
    int numbers[10];
    srand(time(0));  // ���� �ʱ�ȭ

    printf("�����ϰ� ������ ��: ");
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 101;  // 0���� 100 ������ ���� ����
        root = insertNode(root, numbers[i]);
        printf("%d ", numbers[i]);
    }
    printf("\n\n���� BST:\n");
    printTree(root);

    // ������ �� ����
    for (int i = 0; i < 3; i++) {  // ù ������ ���� �����մϴ�.
        printf("\n'%d'�� �����մϴ�.\n", numbers[i]);
        root = deleteNode(root, numbers[i]);
        printTree(root);
    }
}

void performBSTDeletion() {
    system("cls");
    int n, value, deleteValue;
    Node *root = NULL;

    printf("������ ���� ������ �Է��ϼ��� (�ִ� 100��): ");
    scanf("%d", &n);
    n = (n > 100) ? 100 : n;  // �ִ� 100���� ����

    printf("������ ���� �Է��ϼ��� (0~10000 ������ ����):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }
    printf("\n���� BST:\n");
    printTree(root);

    printf("\n������ ���� �Է��ϼ���: ");
    scanf("%d", &deleteValue);
    root = deleteNode(root, deleteValue);
    printf("\n'%d' ���� �� BST:\n", deleteValue);
    printTree(root);
}

void BSTDeletionMenu() {
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
                explainBSTDeletion();
                break;
            case 2:
                showBSTDeletion();
                break;
            case 3:
                performBSTDeletion();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
        system("pause");
    } while (choice != 0);
}
