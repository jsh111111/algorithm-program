#include "radixSort.h"
#include "allHeaders.h"

void explainRadixSort() {
    system("cls");
    printf("��� ����(Radix Sort)�� ���ڵ��� �ڸ������� �����ϴ� ����Դϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. ���� ���� �ڸ���(��: ���� �ڸ�)���� �����Ͽ� �� �ڸ����� ���� ������ �����մϴ�.\n");
    printf("2. ��� �ڸ����� ���� �� ������ �ݺ��մϴ�.\n\n");
    printf("��� ������ �񱳸� ������� ������, ������ ������ �������� �� ȿ�����Դϴ�.\n");
    system("pause");
}

void printArray(int arr[], int size, int exp) {
    for (int i = 0; i < size; i++) {
        if ((arr[i] / exp) % 10 != 0)  // ���� �ڸ����� 0�� �ƴ� ��� ����
            printf("[%d] ", arr[i]);
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void countSort(int arr[], int n, int exp) {
    int output[n]; // ��� �迭
    int i, count[10] = {0};

    // exp �ڸ����� �ش��ϴ� ���ڸ� ī��Ʈ
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // ���� ī��Ʈ�� ���
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // ���ĵ� ����� ��� �迭�� ����
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // ��� �迭�� ���� �迭 ���� �� ���� ���
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    printf("�ڸ��� %d�� ���� ���� ����: ", exp);
    printArray(arr, n, exp);
}

void radixSort(int arr[], int n) {
    // �迭���� �ִ밪 ã��
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // �ִ밪�� �ڸ����� ���� ��� ���� ����
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

void showRadixSort() {
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
    radixSort(arr, 10);
    clock_t end = clock();

    printf("\n���ĵ� �迭: ");
    printArray(arr, 10, -1);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void performRadixSort() {
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

    printf("������ �迭: ");
    printArray(arr, n, -1);
    printf("\n");

    clock_t start = clock();
    radixSort(arr, n);
    clock_t end = clock();

    printf("\n���ĵ� �迭: ");
    printArray(arr, n, -1);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void RadixSortMenu() {
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
                explainRadixSort();
                break;
            case 2:
                showRadixSort();
                break;
            case 3:
                performRadixSort();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}
