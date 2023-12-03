// mst.c

#include "mst.h"
#include "allHeaders.h"

void explainMST() {
    printf("�ּ� ���� Ʈ��(MST)�� �׷����� ��� ������ �ּ� ����ġ�� �����ϴ� �κ� �׷����Դϴ�.\n");
    printf("���� �˰������ ũ�罺Į �˰������� MST�� ã�� �� ���� ����Դϴ�.\n");
}

void prim(int graph[MAX][MAX], int n) {
    int no_edge;            // edge count
    bool selected[MAX] = {false};
    no_edge = 0;
    selected[0] = true;

    int x;  // row number
    int y;  // col number

    printf("Edge : Weight\n");

    while (no_edge < n - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, graph[x][y]);
        selected[y] = true;
        no_edge++;
    }
}

int find(int i, int parent[]) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j, int parent[]) {
    int a = find(i, parent);
    int b = find(j, parent);
    parent[a] = b;
}

void kruskal(EdgeList el, int n) {
    int parent[MAX];
    EdgeList spanlist;

    int i, j, k;
    int total = 0;
    for (i = 0; i < n; i++)
        parent[i] = i;

    i = 0; j = 0;
    while (i < n-1) {
        int a = find(el.edges[j].u, parent);
        int b = find(el.edges[j].v, parent);
        if (a != b) {
            spanlist.edges[i] = el.edges[j];
            total += el.edges[j].weight;
            union1(a, b, parent);
            i++;
        }
        j++;
    }

    printf("Minimum cost = %d\n", total);
    for (i = 0; i < n - 1; i++) {
        printf("%d - %d : %d\n", spanlist.edges[i].u, spanlist.edges[i].v, spanlist.edges[i].weight);
    }
}

void performMST() {
    int graph[MAX][MAX], n, choice;
    EdgeList el;

    printf("�׷����� ���� ������ �Է��ϼ���: ");
    scanf("%d", &n);

    // �׷��� �Ǵ� ���� ����Ʈ �Է� �ޱ�
    // ...

    printf("1: ���� �˰�����\n2: ũ�罺Į �˰�����\n����: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            prim(graph, n);
            break;
        case 2:
            kruskal(el, n);
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
    }
}

void MST() {
    explainMST();
    performMST();
}
