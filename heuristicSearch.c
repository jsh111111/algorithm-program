// heuristicSearch.c

#include "heuristicSearch.h"
#include "allHeaders.h"

void explainHeuristicSearch() {
    printf("�� Ž��(Heuristic Search)�� ���� �ذ��� ���� �޸���ƽ�� ����Ͽ� Ž�� ������ ����ȭ�ϴ� �˰������Դϴ�.\n");
    printf("�̴� ������ �� �߿��� ���� ���� ���̴� �ظ� �����Ͽ� ȿ�������� ������ �ذ��մϴ�.\n");
}

int findMinimum(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void performHeuristicSearch() {
    int size, arr[MAX_ARRAY_SIZE];

    printf("�迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &size);

    printf("�迭 ��Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int minValue = findMinimum(arr, size);
    printf("�ּҰ��� %d�Դϴ�.\n", minValue);
}

void heuristicSearch() {
    explainHeuristicSearch();
    performHeuristicSearch();
}
