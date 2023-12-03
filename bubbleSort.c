#include "bubbleSort.h"
#include "allHeaders.h"

void explainBubbleSort() {
    system("cls");
    printf("���� ����(Bubble Sort)�� ������ �� ��Ҹ� ���Ͽ� �����ϴ� ����Դϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. �迭�� ù ��° ��Һ��� �����Ͽ� ������ ��Ҹ� ���մϴ�.\n");
    printf("2. ���� ������ �߸��Ǿ� �ִٸ�, �� ����� ��ġ�� ��ȯ�մϴ�.\n");
    printf("3. �迭�� ������ �� ������ �ݺ��մϴ�.\n");
    printf("4. �迭�� ��� ��Ұ� �ùٸ� ������ �� ������ 1-3�ܰ踦 �ݺ��մϴ�.\n\n");
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

void showBubbleSort() {
    system("cls");
    int arr[10], i, j, temp;
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
        for (j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // ��ȯ ����
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                printf("�ܰ� %d-%d: ", i + 1, j + 1);
                printArray(arr, 10, j, j + 1);  // ������ printArray �Լ� ȣ��
            }
        }
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


void performBubbleSort() {
    system("cls");
    int n, i, j, temp;
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
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("�ܰ� %d: ", i + 1);
        printArray(arr, n, -1, -1);  // ������ printArray �Լ� ȣ��
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

void bubbleSortMenu() {
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
                explainBubbleSort();
                break;
            case 2:
                showBubbleSort();
                break;
            case 3:
                performBubbleSort();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}
