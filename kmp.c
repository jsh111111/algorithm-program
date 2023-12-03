// kmp.c

#include "kmp.h"
#include "allHeaders.h"

void explainKMP() {
    printf("KMP(Knuth-Morris-Pratt) �˰������� ���ڿ� �˻����� ���ʿ��� �񱳸� ���̱� ���� ������ �κ� ��ġ ���̺��� ����մϴ�.\n");
    printf("�� ���̺��� ���� ������ �ݺ��Ǵ� �κ��� Ȱ���Ͽ� ���ڿ� �˻��� ȿ������ ���Դϴ�.\n");
}

void computeLPSArray(char* pattern, int M, int* lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPsearch(char* text, char* pattern) {
    int N = strlen(text);
    int M = strlen(pattern);
    int lps[M];

    computeLPSArray(pattern, M, lps);

    int i = 0;  // index for text[]
    int j = 0;  // index for pattern[]
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("������ �ؽ�Ʈ�� �ε��� %d���� �߰ߵǾ����ϴ�.\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

void performKMP() {
    char text[100], pattern[100];

    printf("�ؽ�Ʈ�� �Է��ϼ���: ");
    scanf("%s", text);
    printf("ã�� ������ �Է��ϼ���: ");
    scanf("%s", pattern);

    KMPsearch(text, pattern);
}

void KMP() {
    explainKMP();
    performKMP();
}
