// mst.h

#ifndef MST_H
#define MST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define INF 9999

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    Edge edges[MAX];
    int n;
} EdgeList;

void explainMST();
void prim(int graph[MAX][MAX], int n);
void kruskal(EdgeList el, int n);
void performMST();
void MST();

#endif
