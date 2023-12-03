#include "bTreeDeletion.h"
#include "allHeaders.h"

BTreeNode* createBTreeNode(int isLeaf) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }
    newNode->isLeaf = isLeaf;
    newNode->numKeys = 0;
    for (int i = 0; i <= MAX_KEYS; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insertInBTree(BTreeNode **root, int key) {
    if (*root == NULL) {
        *root = createBTreeNode(1); // ���� ���� �ʱ�ȭ
    }

    BTreeNode *r = *root;
    if (r->numKeys == MAX_KEYS) {
        BTreeNode *s = createBTreeNode(0);
        *root = s;
        s->children[0] = r;
        splitChild(s, 0, r);
        insertNonFull(s, key);
    } else {
        insertNonFull(r, key);
    }
}

void splitChild(BTreeNode *parent, int index, BTreeNode *child) {
    BTreeNode *newChild = createBTreeNode(child->isLeaf);
    newChild->numKeys = MAX_KEYS / 2;

    // �� �ڽ� ��忡 Ű �̵�
    for (int i = 0; i < MAX_KEYS / 2; i++) {
        newChild->keys[i] = child->keys[i + MAX_KEYS / 2 + 1];
    }

    // ���� ��尡 �ƴ� ��� �ڽ� �̵�
    if (!child->isLeaf) {
        for (int i = 0; i <= MAX_KEYS / 2; i++) {
            newChild->children[i] = child->children[i + MAX_KEYS / 2 + 1];
        }
    }

    child->numKeys = MAX_KEYS / 2;

    // �θ� ��忡 �� �ڽ� ��� ����
    for (int i = parent->numKeys; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newChild;

    // �θ� ��忡 Ű �̵�
    for (int i = parent->numKeys - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = child->keys[MAX_KEYS / 2];
    parent->numKeys++;
}

void insertNonFull(BTreeNode *node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // ���� ����� ���
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // ���� ��尡 �ƴ� ���
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;

        if (node->children[i]->numKeys == MAX_KEYS) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

void deleteFromBTree(BTreeNode **root, int key) {
    // TODO: B-Ʈ������ Ű ���� ������ �����ϼ���.
    // �� ���ÿ����� ������ ���� ������ �����մϴ�.
    // ���� B-Ʈ�������� �� ������ ��츦 ó���ؾ� �մϴ�.

    if (*root == NULL) {
        printf("Ű %d�� Ʈ���� �������� �ʽ��ϴ�.\n", key);
        return;
    }

    // ���� ��忡�� Ű ������ �����մϴ�.
    // ���� ��忡���� ���� ������ �̺��� �ξ� �����մϴ�.
    BTreeNode *node = *root;
    int i = 0;
    while (i < node->numKeys && key > node->keys[i]) {
        i++;
    }

    if (i < node->numKeys && key == node->keys[i]) {
        // Ű�� ã�ҽ��ϴ�. ������ �����մϴ�.
        for (int j = i; j < node->numKeys - 1; j++) {
            node->keys[j] = node->keys[j + 1];
        }
        node->numKeys--;
    } else {
        printf("Ű %d�� Ʈ���� �������� �ʽ��ϴ�.\n", key);
    }
}

void printBTree(BTreeNode *node, int level) {
    if (node == NULL) return;

    printf("Level %d: ", level);
    for (int i = 0; i < node->numKeys; i++) {
        printf("%d ", node->keys[i]);
    }
    printf("\n");

    for (int i = 0; i <= node->numKeys; i++) {
        printBTree(node->children[i], level + 1);
    }
}

void explainBTreeDeletion() {
    system("cls");
    printf("B-Ʈ�� ���� ������ ������ �����ϴ�:\n\n");
    printf("1. ������ Ű�� �ִ� ��带 ã���ϴ�.\n");
    printf("2. ��尡 ���� �����, Ű�� ���� �����մϴ�.\n");
    printf("3. ��尡 ���� �����, ���� ���̽��� ���� ó���մϴ�.\n");
    printf("   - Ű�� ���� Ű�� ���� �ڽ� ��忡�� ��ü�� Ű�� ã�� ��ü�մϴ�.\n");
    printf("   - �ʿ��� ��� �ڽ� ������ �����ϰų� ��迭�մϴ�.\n\n");
}

void showBTreeDeletion() {
    system("cls");
    printf("B-Ʈ�� ���� ���� (���� ����):\n\n");

    BTreeNode *root = NULL;
    int numbers[10];
    srand(time(0));

    printf("�����ϰ� ������ ��: ");
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 101;
        printf("%d ", numbers[i]);
        insertInBTree(&root, numbers[i]);
    }
    printf("\n");

    printBTree(root, 0);  // Level 0���� ����
    printf("\n");

    // ������ Ű ���� (��: ó�� ������ ���� ù ��° ��)
    printf("������ Ű: %d\n", numbers[0]);
    deleteFromBTree(&root, numbers[0]);
    printBTree(root, 0);
    printf("\n");
}

void performBTreeDeletion() {
    system("cls");
    BTreeNode *root = NULL;
    int n, value;

    printf("������ ���� ������ �Է��ϼ��� (�ִ� 100��): ");
    scanf("%d", &n);
    n = (n > 100) ? 100 : n;

    printf("������ ���� �Է��ϼ��� (0~10000 ������ ����):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertInBTree(&root, value);
    }

    printBTree(root, 0);  // Level 0���� ����
    printf("\n");

    printf("������ Ű�� �Է��ϼ���: ");
    scanf("%d", &value);
    deleteFromBTree(&root, value);

    printBTree(root, 0);
    printf("\n");
}

void BTreeDeletionMenu() {
    int choice;
    do {
        system("cls");
        printf("B-Ʈ�� ���� �޴�\n");
        printf("1: ����\n");
        printf("2: �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �۵�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainBTreeDeletion();
                break;
            case 2:
                showBTreeDeletion();
                break;
            case 3:
                performBTreeDeletion();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
        system("pause");
    } while (choice != 0);
}
