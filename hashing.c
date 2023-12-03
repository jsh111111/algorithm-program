#include "hashing.h"
#include "allHeaders.h"

// �ؽ� �Լ�
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// �ؽ� ���̺��� Ű�� �����ϴ� �Լ�
void insertKey(int hashTable[], int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;  // ���� ����� ���
    }
    hashTable[index] = key;
}

// �ؽ� ���̺� ��� �Լ�
void printHashTable(int hashTable[]) {
    printf("�ؽ� ���̺�:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("�ε��� %d: %d\n", i, hashTable[i]);
        } else {
            printf("�ε��� %d: ��� ����\n", i);
        }
    }
}

void explainHashing() {
    system("cls");
    printf("�ؽ��� �����͸� ȿ�������� �����ϱ� ���� ����Դϴ�.\n");
    printf("�ؽ� �Լ��� ����Ͽ� �����͸� �ؽ� ���̺��� �����ϰ� �˻��մϴ�.\n");
    printf("������ �ؽ� �Լ��� �浹 �ذ� ����� ����ϸ� ���� ������ ������ �����մϴ�.\n\n");
    system("pause");
}

void showHashingProcess() {
    system("cls");
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;  // �ؽ� ���̺� �ʱ�ȭ
    }

    printf("������ ���� 10���� �ؽ��Ͽ� �ؽ� ���̺��� �����ϴ� ������ �����ݴϴ�.\n");
    for (int i = 0; i < 10; i++) {
        int key = rand() % 100;  // 0���� 99 ������ ���� ����
        printf("����: %d\n", key);
        insertKey(hashTable, key);
        printHashTable(hashTable);
        printf("\n");
    }
    system("pause");
}

void performHashing() {
    system("cls");
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;  // �ؽ� ���̺� �ʱ�ȭ
    }

    int n, key;
    printf("������ Ű�� ������ �Է��ϼ���: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("������ Ű�� �Է��ϼ���: ");
        scanf("%d", &key);
        insertKey(hashTable, key);
        printHashTable(hashTable);
        printf("\n");
    }
    system("pause");
}

void hashingMenu() {
    int choice;
    do {
        system("cls");
        printf("�ؽ� �޴�\n");
        printf("1: �ؽ� ����\n");
        printf("2: �ؽ� ���� ����\n");
        printf("3: ����� �Է¿� ���� �ؽ�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainHashing();
                break;
            case 2:
                showHashingProcess();
                break;
            case 3:
                performHashing();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
        system("pause");
    } while (choice != 0);
}

