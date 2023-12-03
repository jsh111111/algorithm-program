// topologicalSort.c

#include "topologicalSort.h"
#include "allHeaders.h"

void explainTopologicalSort() {
    printf("���� ������ ���⼺ �׷������� �� ������ ���⼺�� ������� �ʵ��� ������� �����ϴ� ���� ����Դϴ�.\n");
    printf("�� ������ DAG(Directed Acyclic Graph)���� ���� �����մϴ�.\n");
}

void topologicalSort(int graph[MAX][MAX], int n) {
    int inDegree[MAX] = {0}, stack[MAX], top = -1;

    // ��� ������ ���� ���� ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }

    // ���� ������ 0�� ������ ���ÿ� ����
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            stack[++top] = i;
        }
    }

    // ���� ���� ����
    while (top != -1) {
        int curr = stack[top--];
        printf("%d ", curr);

        // ���� �������� ����ϴ� ��� ���� ����
        for (int i = 0; i < n; i++) {
            if (graph[curr][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

void performTopologicalSort() {
    int graph[MAX][MAX], n;

    printf("�׷����� ���� ������ �Է��ϼ���: ");
    scanf("%d", &n);

    printf("�׷����� ���� ����� �Է��ϼ��� (0 �Ǵ� 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("���� ���� ���: ");
    topologicalSort(graph, n);
}