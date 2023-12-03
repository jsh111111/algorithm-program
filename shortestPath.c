// shortestPath.c

#include "shortestPath.h"
#include "allHeaders.h"

void explainShortestPath() {
    printf("�ִ� ��� �˰������� �׷������� �� ���� ���� �ִ� ��θ� ã�� �˰������Դϴ�.\n");
    printf("���ͽ�Ʈ�� �˰������� �� �������� �ٸ� ��� ���������� �ִ� ��θ� ã���ϴ�.\n");
    printf("�÷��̵�-���� �˰������� ��� ���� �� ���� �ִ� ��θ� ã���ϴ�.\n");
}

void dijkstra(int graph[MAX][MAX], int startNode, int n) {
    // ���� ����
}

void floydWarshall(int graph[MAX][MAX], int n) {
    // ���� ����
}

void performShortestPath() {
    int graph[MAX][MAX], n, choice, startNode;

    printf("�׷����� ���� ������ �Է��ϼ���: ");
    scanf("%d", &n);

    printf("�׷����� ���� ����� �Է��ϼ��� (���Ѵ�� 99999�� �Է�):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("1: ���ͽ�Ʈ�� �˰�����\n2: �÷��̵�-���� �˰�����\n����: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("���� ������ �Է��ϼ���: ");
            scanf("%d", &startNode);
            dijkstra(graph, startNode, n);
            break;
        case 2:
            floydWarshall(graph, n);
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
    }
}

void shortestPath() {
    explainShortestPath();
    performShortestPath();
}
