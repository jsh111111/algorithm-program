#include "hashFunction.h"
#include "allHeaders.h"

// ������ �ؽ� �Լ� ����
int simpleHashFunction(int key) {
    return key % 100;  // ����: 100���� ���� ������ ��ȯ
}

// �ؽ� �Լ��� ���� ����
void explainHashFunction() {
    system("cls");
    printf("�ؽ� �Լ��� Ű�� �ؽ� ���̺��� �ε����� ��ȯ�ϴ� �Լ��Դϴ�.\n");
    printf("�Ϲ������� �ؽ� �Լ��� ���� ����� ���� ��� ������ ����մϴ�.\n");
    printf("��: ������ ���� �ؽ� �Լ��� Ű�� ������ ���ڷ� ���� �������� ����մϴ�.\n\n");
    system("pause");
}

// ������ �� 10���� �ؽ� �Լ� �۵� ���� �����ֱ�
void showHashFunctionProcess() {
    system("cls");
    srand(time(0)); // ���� �ʱ�ȭ

    printf("������ ���� 10���� �ؽ� �Լ� �۵� ������ �����ݴϴ�:\n");
    for (int i = 0; i < 10; i++) {
        int key = rand() % 100;  // 0���� 99 ������ ���� ����
        int hashValue = simpleHashFunction(key);
        printf("Ű: %d, �ؽ� ��: %d\n", key, hashValue);
    }
    system("pause");
}

// ����� �Է¿� ���� �ؽ� �� ���
void performUserInputHashing() {
    system("cls");
    int n, key;

    printf("�ؽ��� Ű�� ������ �Է��ϼ���: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("�ؽ��� Ű�� �Է��ϼ���: ");
        scanf("%d", &key);

        int hashValue = simpleHashFunction(key);
        printf("Ű: %d, �ؽ� ��: %d\n", key, hashValue);
    }
    system("pause");
}

void hashFunction() {
    int choice;
    do {
        system("cls");
        printf("�ؽ� �Լ� �޴�\n");
        printf("1: �ؽ� �Լ� ����\n");
        printf("2: �ؽ� �Լ� �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �ؽ�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainHashFunction();
                break;
            case 2:
                showHashFunctionProcess();
                break;
            case 3:
                performUserInputHashing();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
    } while (choice != 0);
}
