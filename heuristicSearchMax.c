// heuristicSearchMax.c

#include "heuristicSearchMax.h"
#include "allHeaders.h"

void explainHeuristicSearchMax() {
    printf("�� Ž��(Heuristic Search)�� ���� �ذ��� ���� �޸���ƽ�� ����Ͽ� Ž�� ������ ����ȭ�ϴ� �˰������Դϴ�.\n");
    printf("�� ���������� �־��� �迭 ������ �ִ밪�� �޸���ƽ ������� ã���ϴ�.\n");
}

int findMaximum(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void performHeuristicSearchMax() {
    int size, arr[MAX_ARRAY_SIZE];

    printf("�迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &size);

    printf("�迭 ��Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int maxValue = findMaximum(arr, size);
    printf("�ִ밪�� %d�Դϴ�.\n", maxValue);
}

void HeuristicSearchMax() {
    explainHeuristicSearchMax();
    performHeuristicSearchMax();
}
