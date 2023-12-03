#include "countingSort.h"
#include "allHeaders.h"

void explainCountingSort() {
    system("cls");
    printf("��� ����(Counting Sort)�� ���� �迭�� �����ϴ� �� ��� ����� �ƴ� �˰������Դϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. �Է� �迭�� �� ��Ұ� �� �� �����ϴ��� ī��Ʈ�մϴ�.\n");
    printf("2. ���� ī��Ʈ�� ����Ͽ� �� ��Ұ� ���ĵ� �迭���� ��� ��ġ�ؾ� �ϴ��� �����մϴ�.\n");
    printf("3. �Է� �迭�� ��ȸ�ϸ鼭 �� ��Ҹ� ���ĵ� �迭�� ��ġ�մϴ�.\n\n");
    printf("��� ������ �Է� �������� ������ �������� �� ȿ�����Դϴ�.\n");
    system("pause");
}

void printArray(int arr[], int size, int highlightIndex) {
    for (int i = 0; i < size; i++) {
        if (i == highlightIndex)
            printf("[%d] ", arr[i]);  // ������ ���
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void countingSort(int arr[], int size) {
    // �迭���� �ִ밪 ã��
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // ī��Ʈ �迭 �ʱ�ȭ
    int count[max + 1];
    memset(count, 0, (max + 1) * sizeof(int));

    // �� ��� ī��Ʈ
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // ���ĵ� �迭 ���� �� ���� ���
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            count[i]--;

            // ���� ���� ���
            printf("���� ���� (�ε��� %d): ", index);
            printArray(arr, size, index);

            index++;
        }
    }
}

void showCountingSort() {
    system("cls");
    int arr[10];
    srand(time(0));

    printf("������ �迭: ");
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;  // 0���� 99 ������ ���� ����
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    clock_t start = clock();
    countingSort(arr, 10);
    clock_t end = clock();

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void performCountingSort() {
    system("cls");
    int n;
    printf("������ ������ ������ �Է��ϼ��� (�ִ� 100): ");
    scanf("%d", &n);
    n = (n > 100) ? 100 : n;

    int arr[n];
    printf("������ ���ڵ��� �Է��ϼ���: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("�Էµ� �迭: ");
    printArray(arr, n, -1);
    printf("\n");

    clock_t start = clock();
    countingSort(arr, n);
    clock_t end = clock();

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void CountingSortMenu() {
    int choice;

    do {
        system("cls");
        printf("��� ���� �޴�\n");
        printf("1: ����\n");
        printf("2: �ܰ躰 �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �۵�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainCountingSort();
                break;
            case 2:
                showCountingSort();
                break;
            case 3:
                performCountingSort();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}