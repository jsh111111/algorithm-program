#include "quickSort.h"
#include "allHeaders.h"

void explainQuickSort() {
    system("cls");
    printf("�� ����(Quick Sort)�� ���� ���� ����� ����ϴ� ȿ������ ���� �˰������Դϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. �迭���� �ǹ�(pivot)�� �����մϴ�.\n");
    printf("2. �ǹ��� �������� �迭�� �� �κ����� �����ϴ�: �ǹ����� ���� ��ҵ�� �ǹ����� ū ��ҵ�.\n");
    printf("3. �� �κ��� ��������� �����մϴ�.\n\n");
    printf("�� ������ ��������� �ſ� ���� ������ ��������, �־��� ��� �ð� ���⵵�� O(n^2)�� �� �� �ֽ��ϴ�.\n");
    system("pause");
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // �ǹ� ����
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // ���� �� �迭 ���� ���
        printf("�ǹ� = %d, �κ� ����: ", arr[pi]);
        printArray(arr + low, high - low + 1);

        // ��� ȣ��
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void showQuickSort()
{
    system("cls");
    int arr[10];
    srand(time(0));

    printf("������ �迭: ");
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 101;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    clock_t start = clock();
    quickSort(arr, 0, 9);
    clock_t end = clock();

    quickSort(arr, 0, 9);

    printf("���ĵ� �迭: ");
    printArray(arr, 10);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void performQuickSort()
{
    system("cls");
    int n;
    printf("������ ������ ������ �Է��ϼ��� (�ִ� 100): ");
    scanf("%d", &n);
    n = (n > 100) ? 100 : n;

    int arr[n];
    printf("������ ���ڵ��� �Է��ϼ���: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("������ �迭: ");
    printArray(arr, n);

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("���ĵ� �迭: ");
    printArray(arr, n);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void QuickSortMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("�� ���� �޴�\n");
        printf("1: ����\n");
        printf("2: �ܰ躰 �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �۵�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            explainQuickSort();
            break;
        case 2:
            showQuickSort();
            break;
        case 3:
            performQuickSort();
            break;
        case 0:
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}