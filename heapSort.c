#include "heapSort.h"
#include "allHeaders.h"

void explainHeapSort() {
    system("cls");
    printf("�� ����(Heap Sort)�� ���� �� �ڷᱸ���� �̿��� ���� ����Դϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. �־��� �迭�� ���� ������ �����մϴ�.\n");
    printf("2. ������ �ִ밪(�Ǵ� �ּҰ�)�� �����ϰ� �迭�� ���� ��ġ�մϴ�.\n");
    printf("3. ���� ũ�⸦ ���̰� 2�� ������ �ݺ��մϴ�.\n\n");
    printf("�� ������ ������ �޸� ȿ������ ���� ����Դϴ�.\n");
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

void heapify(int arr[], int n, int i, int size) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int swapIdx = -1;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        swapIdx = largest;

        // ��ȯ ������ �����Ͽ� ���
        printf("��ȯ �ܰ� (i=%d, largest=%d): ", i, largest);
        printArray(arr, size, i, swapIdx);

        heapify(arr, n, largest, size);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, n);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // ��ȯ �ܰ� ���
        printf("���� �� �迭 �籸��: ");
        printArray(arr, n, 0, i);

        heapify(arr, i, 0, n);
    }
}

void showHeapSort() {
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
    heapSort(arr, 10);
    clock_t end = clock();

    printf("\n���ĵ� �迭: ");
    printArray(arr, 10, -1, -1);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void performHeapSort() {
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
    heapSort(arr, n);
    clock_t end = clock();

    printf("\n���ĵ� �迭: ");
    printArray(arr, n, -1, -1);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void HeapSortMenu() {
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
                explainHeapSort();
                break;
            case 2:
                showHeapSort();
                break;
            case 3:
                performHeapSort();
                break;
            case 0:
                return;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}