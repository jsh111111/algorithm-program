// backtracking.c

#include "backtracking.h"
#include "allHeaders.h"

void explainBacktracking() {
    printf("��Ʈ��ŷ�� �ذ�å���� �̾��� ���ɼ��� ���� ��� ��� �ڷ� ���ư�(Backtrack) �ٸ� ������ ��θ� Ž���ϴ� �˰������Դϴ�.\n");
    printf("�� ����� ����, ����ȭ ���� � �θ� ���˴ϴ�. ���� ���, N-Queens �������� ��Ʈ��ŷ�� ����� �� �ֽ��ϴ�.\n");
}

bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    // ���� ����
}

bool solveNQueensUtil(int board[MAX][MAX], int col, int n) {
    // ���� ����
}

void printSolution(int board[MAX][MAX], int n) {
    // ���� ����
}

void solveNQueens(int n) {
    int board[MAX][MAX] = {0};

    if (!solveNQueensUtil(board, 0, n)) {
        printf("�ذ�å�� �������� �ʽ��ϴ�.\n");
        return;
    }

    printSolution(board, n);
}

void performBacktracking() {
    int n;
    printf("N-Queens ������ N ���� �Է��ϼ���: ");
    scanf("%d", &n);

    solveNQueens(n);
}

void backtracking() {
    explainBacktracking();
    performBacktracking();
}
