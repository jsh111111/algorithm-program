#include "insertionSort.h"
#include "allHeaders.h"

void explainInsertionSort() {
    system("cls");
    printf("���� ����(Insertion Sort)�� �� ��Ҹ� ������ ��ġ�� �����ϴ� ������� �����մϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. �迭�� �� ��° ��Һ��� �����Ͽ� ���� ��Ҹ� ���캾�ϴ�.\n");
    printf("2. �� ��Ҹ� ������ ��ҵ�� ���Ͽ� ������ ��ġ�� �����մϴ�.\n");
    printf("3. �迭�� ��� ��ҿ� ���� �� ������ �ݺ��մϴ�.\n\n");
    system("pause");
}

void printArray(int arr[], int size, int idx1, int idx2) {
    for (int i = 0; i < size; i++) {
        if (i == idx1 || i == idx2)
            printf("[%d] ", arr[i]);  // ��ȯ�Ǵ� ��� ����
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void showInsertionSort() {
    system("cls");
    int arr[10], i, j, key;
    srand(time(0)); // ���� �ʱ�ȭ

    // ������ ���� 10�� ����
    printf("������ �迭: ");
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 101;  // 0���� 100 ������ ���� ����
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    clock_t start = clock();
    // ���� ���� �˰����� ����
    for (i = 1; i < 10; i++) {
        key = arr[i];
        j = i - 1;

        // key�� ���ĵ� �κ��� ������ ��ġ�� ����
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // �ܰ躰 �迭 ���� ���
        printf("�ܰ� %d: ", i);
        printArray(arr, 10, j + 1, i);
    }
    clock_t end = clock();

    // ���ĵ� �迭 ���
    printf("\n���ĵ� �迭: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void performInsertionSort() {
    system("cls");
    int n, i, j, key;
    printf("������ ������ ������ �Է��ϼ��� (�ִ� 100): ");
    scanf("%d", &n);
    n = (n > 100) ? 100 : n;  // �ִ� 100���� ����

    int arr[n];
    printf("������ ���ڵ��� �Է��ϼ��� (0~10000 ������ ����): \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr[i] = (arr[i] < 0) ? 0 : (arr[i] > 10000) ? 10000 : arr[i];  // �Է� ���� ����
    }

    // �迭 ���
    printf("������ �迭: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start = clock();
    // ���� ���� �˰����� ����
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // �ܰ躰 �迭 ���� ���
        printf("�ܰ� %d: ", i);
        printArray(arr, n, j + 1, i);
    }
    clock_t end = clock();

    // ���ĵ� �迭 ���
    printf("���ĵ� �迭: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void InsertionSortMenu() {
    int choice;

    do {
        system("cls");  // ȭ���� �����ϰ� ����ϴ�.
        printf("���� ���� �޴�\n");
        printf("1: ����\n");
        printf("2: �ܰ躰 �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �۵�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainInsertionSort();
                break;
            case 2:
                showInsertionSort();
                break;
            case 3:
                performInsertionSort();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}