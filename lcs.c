// lcs.c

#include "lcs.h"
#include "allHeaders.h"

void explainLCS() {
    printf("���� ���� �κм���(LCS)�� �� ���������� ���� �� �κ� ������ ã�� �����Դϴ�.\n");
    printf("�� �κ� ������ �������� ���ҵ��� ���� ������ ����������, �ݵ�� �������� �ʿ�� �����ϴ�.\n");
}

void findLCS(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1];

    // LCS ���� ���
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // LCS ���� �� ���
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("���� ���� �κм���: %s\n", lcs);
}

void performLCS() {
    char X[100], Y[100];
    printf("ù ��° ���ڿ��� �Է��ϼ���: ");
    scanf("%s", X);
    printf("�� ��° ���ڿ��� �Է��ϼ���: ");
    scanf("%s", Y);

    findLCS(X, Y, strlen(X), strlen(Y));
}

void LCS() {
    explainLCS();
    performLCS();
}
