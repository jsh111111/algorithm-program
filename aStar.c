// aStar.c

#include "aStar.h"
#include "allHeaders.h"

void explainAStar() {
    printf("A* (A-star) �˰������� �ִ� ��� ������ �ذ��ϱ� ���� �޸���ƽ ��� Ž�� �˰������Դϴ�.\n");
    printf("f(n) = g(n) + h(n)�� �ּ�ȭ�Ͽ� ��ǥ �������� ���� ��θ� ã���ϴ�.\n");
    printf("g(n)�� ���� ���κ��� ��� n������ ���� ���, h(n)�� n���� ��ǥ �������� ���� ����Դϴ�.\n");
}

// ���⿡ A* �˰����� ���� �Լ� ����
void initializeAStarNodes(AStarNode nodes[], int size) {
    // ���� ����
}

void findAStarPath(AStarNode nodes[], int start, int end, int size) {
    // ���� ����
}

void performAStar() {
    AStarNode nodes[MAX_NODES];
    int size, start, end;

    printf("����� ������ �Է��ϼ���: ");
    scanf("%d", &size);

    printf("����� ��ġ(x, y)�� �Է��ϼ���:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &nodes[i].node.x, &nodes[i].node.y);
    }

    printf("���� ���� ��ǥ ����� �ε����� �Է��ϼ���: ");
    scanf("%d %d", &start, &end);

    initializeAStarNodes(nodes, size);
    findAStarPath(nodes, start, end, size);
}

void aStar() {
    explainAStar();
    performAStar();
}
