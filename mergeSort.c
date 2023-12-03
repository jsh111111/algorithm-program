#include "mergeSort.h"
#include "allHeaders.h"

void explainMergeSort()
{
    system("cls");
    printf("���� ����(Merge Sort)�� ���� ���� ����� ����ϴ� ȿ������ ���� �˰������Դϴ�.\n");
    printf("�� �˰������� ������ ���� �۵��մϴ�:\n");
    printf("1. �迭�� �� �κ����� �����ϴ�.\n");
    printf("2. �� �κ��� ��������� �����մϴ�.\n");
    printf("3. ���ĵ� �� �κ��� �����Ͽ� ������ ���ĵ� �迭�� ����ϴ�.\n\n");
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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // ���� ���� ���� �� ���� ���
    printf("���� ��: ");
    printArray(arr + l, r - l + 1);

    // �ӽ� �迭���� �����Ͽ� ���� �迭�� ����
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ������ ��ҵ��� ���� �迭�� ����
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // ���� ���� �� ���� ���
    printf("���� ��: ");
    printArray(arr + l, r - l + 1);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void showMergeSort()
{
    system("cls");
    int arr[10];
    srand(time(0)); // ���� �ʱ�ȭ

    printf("������ �迭: ");
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 101;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    clock_t start = clock();
    mergeSort(arr, 0, 9);
    clock_t end = clock();
    printf("\n���ĵ� �迭: ");
    printArray(arr, 10);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void performMergeSort()
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
    printf("\n");

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("\n���ĵ� �迭: ");
    printArray(arr, n);

    printf("\n���� �ð�: %f ��\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
}

void mergeSortMenu()
{
    int choice;

    do
    {
        system("cls"); // ȭ���� �����ϰ� ����ϴ�.
        printf("���� ���� �޴�\n");
        printf("1: ����\n");
        printf("2: �ܰ躰 �۵� ���� ����\n");
        printf("3: ����� �Է¿� ���� �۵�\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            explainMergeSort();
            break;
        case 2:
            showMergeSort();
            break;
        case 3:
            performMergeSort();
            break;
        case 0:
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}