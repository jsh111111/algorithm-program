// bfs.h

#ifndef BFS_H
#define BFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q);
bool isQueueEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);

void explainBFS();
void BFS(int graph[MAX][MAX], int startNode, int n);
void performBFS();
void BFS();

#endif
