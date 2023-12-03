// bfs.c

#include "bfs.h"
#include "allHeaders.h"

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isQueueEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            // Queue reset
            initQueue(q);
        }
    }
    return item;
}

void explainBFS() {
    printf("�ʺ� �켱 Ž��(BFS)�� �׷������� ����� ������ ���ʴ�� Ž���ϴ� ����Դϴ�.\n");
    printf("ť�� ����Ͽ� �����ϸ�, ���� ���κ��� ����� ��带 �켱������ �湮�ϰ� �ָ� ������ ��带 ���߿� �湮�մϴ�.\n");
}

void BFS(int graph[MAX][MAX], int startNode, int n) {
    Queue q;
    initQueue(&q);
    bool visited[MAX] = {false};

    visited[startNode] = true;
    enqueue(&q, startNode);

    printf("BFS Ž�� ����: ");

    while (!isQueueEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void performBFS() {
    int graph[MAX][MAX], n, startNode;

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

    BFS(graph, startNode, n);
}

void BFS() {
    explainBFS();
    performBFS();
}
