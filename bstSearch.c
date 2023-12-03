#include "bstSearch.h"
#include "allHeaders.h"

Node* searchNode(Node* node, int key) {
    if (node == NULL || node->key == key)
        return node;

    if (key < node->key)
        return searchNode(node->left, key);
    else
        return searchNode(node->right, key);
}

void explainBSTSearch() {
    system("cls");
    printf("���� �˻� Ʈ�������� ��� �˻� ������ ������ �����ϴ�:\n\n");
    printf("1. �˻��� Ű ���� ���� ��带 ã�� ���� Ʈ���� ��Ʈ���� �����մϴ�.\n");
    printf("2. ���� ����� Ű�� �˻��� Ű�� ���մϴ�.\n");
    printf("3. �˻��� Ű�� ���� ����� Ű���� ������ ���� �ڽ�����, ũ�� ������ �ڽ����� �̵��մϴ�.\n");
    printf("4. �� ������ �ݺ��Ͽ� �˻��� Ű ���� ���� ��带 ã�ų� ��尡 ���� ��� �˻��� �����մϴ�.\n\n");
}

void showBSTSearch() {
    system("cls");
    printf("BST �˻� ���� (���� ����):");

    Node *root = NULL;
    int numbers[10], searchKey;
    srand(time(0));  // ���� �ʱ�ȭ

    printf("�����ϰ� ������ ��: ");
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 101;  // 0���� 100 ������ ���� ����
        root = insertNode(root, numbers[i]);
        printf("%d ", numbers[i]);
    }

    searchKey = numbers[rand() % 10];  // ������ Ű ����
    printf("\n\n�˻��� Ű: %d", searchKey);

    Node* result = searchNode(root, searchKey);
    if (result != NULL) {
        printf("Ű '%d'�� �߰ߵǾ����ϴ�.\n", searchKey);
    } else {
        printf("Ű '%d'�� Ʈ���� �������� �ʽ��ϴ�.\n", searchKey);
    }
}

void performBSTSearch() {
    system("cls");
    int n, value, searchKey;
    Node *root = NULL;

    printf("������ ���� ������ �Է��ϼ��� (�ִ� 100��): ");
    scanf("%d", &n);
    n = (n > 100) ? 100 : n;  // �ִ� 100���� ����

    printf("������ ���� �Է��ϼ��� (0~10000 ������ ����):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\n�˻��� Ű�� �Է��ϼ���: ");
    scanf("%d", &searchKey);

    Node* result = searchNode(root, searchKey);
    if (result != NULL) {
        printf("Ű '%d'�� �߰ߵǾ����ϴ�.\n", searchKey);
    } else {
        printf("Ű '%d'�� Ʈ���� �������� �ʽ��ϴ�.\n", searchKey);
    }
}

void BSTSearchMenu() {
    int choice;
    do {
        system("cls");
        printf("���� �˻� Ʈ�� �˻� �޴�\n");
        printf("1: ����\n");
        printf("2: �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �۵�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainBSTSearch();
                break;
            case 2:
                showBSTSearch();
                break;
            case 3:
                performBSTSearch();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
        system("pause");
    } while (choice != 0);
}


