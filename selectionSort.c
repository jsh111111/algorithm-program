#include "selectionSort.h"
#include "allHeaders.h"

void explainSelectionSort() {
    system("cls");
    printf("���� ����(Selection Sort)�� ���������� ȿ�������� ���� ���� �˰������Դϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. �־��� ����Ʈ �߿��� �ּҰ��� ã���ϴ�.\n");
    printf("2. �� �ּҰ��� ����Ʈ�� �� �տ� ��ġ�� ���� ��ȯ�մϴ�.\n");
    printf("3. ����Ʈ�� ������ �κп� ���� �� ������ �ݺ��մϴ�.\n\n");
    printf("�� ������ ����Ʈ�� ��� ��ҿ� ���� �ݺ��ϸ� ������ �Ϸ�˴ϴ�.\n");
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

void showSelectionSort() {
    system("cls");
    int arr[10], i, j, min_idx, temp;
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
    for (i = 0; i < 9; i++) {
        min_idx = i;
        for (j = i+1; j < 10; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // ��ȯ ����
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        
        // �ܰ躰 �迭 ���� ���
        printf("�ܰ� %d: ", i + 1);
        printArray(arr, 10, i, min_idx);  // ������ printArray �Լ� ȣ��
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

void performSelectionSort() {
    system("cls");
    int n, i, j, min_idx, temp;
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
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        
        // �ܰ躰 �迭 ���� ���
        printf("�ܰ� %d: ", i + 1);
        printArray(arr, n, i, min_idx);  // ������ printArray �Լ� ȣ��
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

void selectionSortMenu() {
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
                explainSelectionSort();
                break;
            case 2:
                showSelectionSort();
                break;
            case 3:
                performSelectionSort();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}