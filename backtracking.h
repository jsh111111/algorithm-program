// backtracking.h

#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void explainBacktracking();
bool isSafe(int board[MAX][MAX], int row, int col, int n);
bool solveNQueensUtil(int board[MAX][MAX], int col, int n);
void printSolution(int board[MAX][MAX], int n);
void solveNQueens(int n);
void performBacktracking();
void backtracking();

#endif
