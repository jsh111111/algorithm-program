// branchAndBound.h

#ifndef BRANCH_AND_BOUND_H
#define BRANCH_AND_BOUND_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    int weight;
    int value;
} Item;

void explainBranchAndBound();
void knapsackBranchAndBound(int n, Item items[], int W);
void performBranchAndBound();
void branchAndBound();

#endif
