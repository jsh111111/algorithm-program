// topologicalSort.h

#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void explainTopologicalSort();
void topologicalSort(int graph[MAX][MAX], int n);
void performTopologicalSort();

#endif
