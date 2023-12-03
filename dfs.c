// dfs.c

#include "dfs.h"
#include "allHeaders.h"

void explainDFS() {
    printf("���� �켱 Ž��(DFS)�� �׷������� ������ �ָ� �ִ� ������ ���� �湮�ϴ� ����Դϴ�.\n");
    printf("�� ��θ� ������ Ž���� �� �ٸ� ��θ� Ž���մϴ�. ��� �Ǵ� ������ ����Ͽ� ������ �� �ֽ��ϴ�.\n");
}

void DFS(int graph[MAX][MAX], bool visited[MAX], int startNode, int n) {
    visited[startNode] = true;
    printf("%d ", startNode);

    for (int i = 0; i < n; i++) {
        if (graph[startNode][i] && !visited[i])
            DFS(graph, visited, i, n);
    }
}

void performDFS() {
    int graph[MAX][MAX], n, startNode;
    bool visited[MAX] = {false};

    printf("�׷����� ���� ������ �Է��ϼ���: ");
    scanf("%d", &n);

    printf("�׷����� ���� ����� �Է��ϼ��� (0 �Ǵ� 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("���� ��带 �Է��ϼ���: ");
    scanf("%d", &startNode);

    printf("DFS Ž�� ����: ");
    DFS(graph, visited, startNode, n);
    printf("\n");
}

int DFS() {
    explainDFS();
    performDFS();
}
