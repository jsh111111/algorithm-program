// dfs.h

#ifndef DFS_H
#define DFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void explainDFS();
void DFS(int graph[MAX][MAX], bool visited[MAX], int startNode, int n);
void performDFS();

#endif
