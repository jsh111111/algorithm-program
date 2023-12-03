#include "shellSort.h"
#include "allHeaders.h"

void explainShellSort() {
    system("cls");
    printf("�� ����(Shell Sort)�� ���� ������ �Ϲ�ȭ�� �����Դϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. ū �������� �����Ͽ� ���� ������ �ٿ����� �κ� ����Ʈ�� ���� �����մϴ�.\n");
    printf("2. ���������� ������ 1�� �� ��ü �迭�� ���� ���� ������ �����մϴ�.\n\n");
    printf("�� ������ �߰� ������ ũ�⸦ ���� �迭�� ���� ȿ������ �� �ֽ��ϴ�.\n");
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

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            // �� ���ݿ� ���� ���� ���� ���
            printf("���� %d, ���� ����: ", gap);
            printArray(arr, n, j, i);
        }
    }
}

void showShellSort() {
    system("cls");
    int arr[10];
    srand(time(0));

    printf("������ �迭: ");
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    clock_t start = clock();
    shellSort(arr, 10);
    clock_t end = clock();

    printf("\n���ĵ� �迭: ");
    printArray(arr, 10, -1, -1);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void performShellSort() {
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
    printArray(arr, n, -1, -1);
    printf("\n");

    clock_t start = clock();
    shellSort(arr, n);
    clock_t end = clock();
    
    printf("\n���ĵ� �迭: ");
    printArray(arr, n, -1, -1);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void shellSortMenu() {
    int choice;

    do {
        system("cls");
        printf("�� ���� �޴�\n");
        printf("1: ����\n");
        printf("2: �ܰ躰 �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �۵�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainShellSort();
                break;
            case 2:
                showShellSort();
                break;
            case 3:
                performShellSort();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}
