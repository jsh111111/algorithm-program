// shortestPath.h

#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void explainShortestPath();
void dijkstra(int graph[MAX][MAX], int startNode, int n);
void floydWarshall(int graph[MAX][MAX], int n);
void performShortestPath();
void shortestPath();

#endif
