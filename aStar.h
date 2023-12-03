// aStar.h

#ifndef A_STAR_H
#define A_STAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

#define MAX_NODES 100

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node node;
    double gCost;
    double hCost;
    double fCost;
    bool visited;
} AStarNode;

void explainAStar();
void initializeAStarNodes(AStarNode nodes[], int size);
void findAStarPath(AStarNode nodes[], int start, int end, int size);
void performAStar();
void aStar();

#endif
