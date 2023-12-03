#include "bTreeSearch.h"
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

BTreeNode* searchBTree(BTreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }

    if (i < root->numKeys && key == root->keys[i]) {
        return root;  // Ű�� ã��
    }

    if (root->isLeaf) {
        return NULL;  // ���� ����̰� Ű�� ����
    }

    return searchBTree(root->children[i], key);  // ���� �ڽ� ���� �̵�
}

void printBTree(BTreeNode *node) {
    if (node != NULL) {
        // ���� �ڽ� ���
        printBTree(node->children[0]);

        // ���� ����� ��� Ű �� ���
        for (int i = 0; i < node->numKeys; i++) {
            printf("%d ", node->keys[i]);
            // ������ �ڽ� ��� (�ش� Ű�� ������)
            printBTree(node->children[i + 1]);
        }
    }
}

void explainBTreeSearch() {
    system("cls");
    printf("B-Ʈ�� �˻� ������ ������ �����ϴ�:\n\n");
    printf("1. �˻��� Ű�� �ִ� ��带 ã���ϴ�.\n");
    printf("2. ���� ����� Ű�� ���Ͽ� ������ �ڽ� ���� �̵��մϴ�.\n");
    printf("3. ���� ��忡 �����ϰų� Ű�� ã�� ������ �� ������ �ݺ��մϴ�.\n\n");
}

void showBTreeSearch() {
    system("cls");
    printf("B-Ʈ�� �˻� ���� (���� ����):\n\n");

    BTreeNode *root = NULL;
    int numbers[10];
    srand(time(0));

    printf("�����ϰ� ������ ��: ");
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 101;
        printf("%d ", numbers[i]);
        insertInBTree(&root, numbers[i]);
    }

    printf("\n\n�˻��� Ű: ");
    int searchKey;
    scanf("%d", &searchKey);

    BTreeNode *foundNode = searchBTree(root, searchKey);
    if (foundNode) {
        printf("Ű %d�� ã�ҽ��ϴ�.\n", searchKey);
    } else {
        printf("Ű %d�� ã�� �� �����ϴ�.\n", searchKey);
    }
}

void performBTreeSearch() {
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

    printf("\n�˻��� Ű: ");
    scanf("%d", &value);

    BTreeNode *foundNode = searchBTree(root, value);
    if (foundNode) {
        printf("Ű %d�� ã�ҽ��ϴ�.\n", value);
    } else {
        printf("Ű %d�� ã�� �� �����ϴ�.\n", value);
    }
}

void BTreeSearchMenu() {
    int choice;
    do {
        system("cls");
        printf("B-Ʈ�� �˻� �޴�\n");
        printf("1: ����\n");
        printf("2: �˻� ���� ����\n");
        printf("3: ����� �Է¿� ���� �˻�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainBTreeSearch();
                break;
            case 2:
                showBTreeSearch();
                break;
            case 3:
                performBTreeSearch();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
        system("pause");
    } while (choice != 0);
}
