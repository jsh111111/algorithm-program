// branchAndBound.c

#include "branchAndBound.h"
#include "allHeaders.h"

void explainBranchAndBound() {
    printf("���� �б�(Branch and Bound)�� ����ȭ ������ �ذ��ϱ� ���� �˰���������, Ž�� �������� �������� �κ��� ����ġ���Ͽ� Ž�� ������ ���Դϴ�.\n");
    printf("�� ����� ��Ʈ��ŷ�� ����������, ����ȭ ������ �� Ưȭ�Ǿ� �ֽ��ϴ�. ���� ���, 0-1 �賶 �������� ���� �� �ֽ��ϴ�.\n");
}

// ���⿡ ���� �б� �˰������� �̿��� 0-1 �賶 ������ �ذ� ����� �����մϴ�.
void knapsackBranchAndBound(int n, Item items[], int W) {
    // ���� ����
}

void performBranchAndBound() {
    int n, W;
    Item items[MAX_ITEMS];

    printf("������ ������ �Է��ϼ���: ");
    scanf("%d", &n);

    printf("�� �������� ��ġ�� ���Ը� �Է��ϼ���:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("�賶�� �ִ� ���Ը� �Է��ϼ���: ");
    scanf("%d", &W);

    knapsackBranchAndBound(n, items, W);
}

void branchAndBound() {
    explainBranchAndBound();
    performBranchAndBound();
}
