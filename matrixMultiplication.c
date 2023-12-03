// matrixMultiplication.c

#include "matrixMultiplication.h"
#include "allHeaders.h"

void explainMatrixMultiplication() {
    printf("��� ������ �� ����� ���ϴ� �����Դϴ�.\n");
    printf("��� A�� ���� ������ ��� B�� ���� ������ ���ƾ� �մϴ�.\n");
    printf("��� ����� ũ��� ��� A�� ���� ������ ��� B�� ���� ������ �����ϴ�.\n");
}

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("����� ��Ҹ� �Է��ϼ���:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int A[rowsA][colsA], int rowsB, int colsB, int B[rowsB][colsB], int result[rowsA][colsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void performMatrixMultiplication() {
    int rowsA, colsA, rowsB, colsB;

    printf("ù ��° ����� ��� ���� ������ �Է��ϼ���: ");
    scanf("%d %d", &rowsA, &colsA);
    int A[rowsA][colsA];
    inputMatrix(rowsA, colsA, A);

    printf("�� ��° ����� ��� ���� ������ �Է��ϼ���: ");
    scanf("%d %d", &rowsB, &colsB);
    if (colsA != rowsB) {
        printf("��� ������ �����ϱ� ���� ù ��° ����� ���� ������ �� ��° ����� ���� ������ ���ƾ� �մϴ�.\n");
        return;
    }
    int B[rowsB][colsB];
    inputMatrix(rowsB, colsB, B);

    int result[rowsA][colsB];
    multiplyMatrices(rowsA, colsA, A, rowsB, colsB, B, result);

    printf("��� ���� ���:\n");
    displayMatrix(rowsA, colsB, result);
}

void matrixMultiplication() {
    explainMatrixMultiplication();
    performMatrixMultiplication();
}
