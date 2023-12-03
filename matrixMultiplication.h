// matrixMultiplication.h

#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include <stdio.h>
#include <stdlib.h>

void explainMatrixMultiplication();
void inputMatrix(int rows, int cols, int matrix[rows][cols]);
void multiplyMatrices(int rowsA, int colsA, int A[rowsA][colsA], int rowsB, int colsB, int B[rowsB][colsB], int result[rowsA][colsB]);
void displayMatrix(int rows, int cols, int matrix[rows][cols]);
void performMatrixMultiplication();
void matrixMultiplication();

#endif
