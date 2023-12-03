// stateSpaceTree.c

#include "stateSpaceTree.h"
#include "allHeaders.h"

void explainStateSpaceTree() {
    printf("���� ���� Ʈ���� ������ ��� ���¸� Ʈ�� ���·� ��Ÿ�� ������ �ظ� ã�� ����Դϴ�.\n");
    printf("�̴� �ַ� ��Ʈ��ŷ �˰������ �Բ� ���Ǹ�, ��� ������ �ظ� �õ��ϸ鼭 �ذ� �� �� ���� ��츦 ���⿡ �����մϴ�.\n");
}

void findCombinations(int arr[], int n, int sum, int* solution, int step, int currentSum) {
    if (currentSum == sum) {
        printf("���� %d�� ����: ", sum);
        for (int i = 0; i < step; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        return;
    }

    if (step >= n || currentSum > sum) {
        return;
    }

    // ���� ��Ҹ� �����ϴ� ���
    solution[step] = arr[step];
    findCombinations(arr, n, sum, solution, step + 1, currentSum + arr[step]);

    // ���� ��Ҹ� �������� �ʴ� ���
    findCombinations(arr, n, sum, solution, step + 1, currentSum);
}

void performStateSpaceTree() {
    int n, sum;
    printf("�迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &n);

    int arr[n];
    printf("�迭 ��Ҹ� �Է��ϼ���: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("ã���� �ϴ� ���� �Է��ϼ���: ");
    scanf("%d", &sum);

    int solution[n];
    findCombinations(arr, n, sum, solution, 0, 0);
}

void stateSpaceTree() {
    explainStateSpaceTree();
    performStateSpaceTree();
}
