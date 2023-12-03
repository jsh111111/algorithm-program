// boyerMoore.c

#include "boyerMoore.h"
#include "allHeaders.h"

void explainBoyerMoore() {
    printf("���̾�-���� �˰������� ���ڿ� �˻����� ������ ���������� �˻��� �����ϴ� ����Դϴ�.\n");
    printf("���� ���� ��Ģ�� ����Ͽ� ����ġ�� �߻����� �� ������ ������ �̵���ŵ�ϴ�.\n");
}

void badCharHeuristic(char* str, int size, int badChar[MAX_CHAR]) {
    for (int i = 0; i < MAX_CHAR; i++)
        badChar[i] = -1;

    for (int i = 0; i < size; i++)
        badChar[(int) str[i]] = i;
}

void searchBoyerMoore(char* text, char* pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int badChar[MAX_CHAR];
    badCharHeuristic(pattern, m, badChar);

    int s = 0;  // s is shift of the pattern with respect to text
    while(s <= (n - m)) {
        int j = m - 1;

        while(j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            printf("������ �ؽ�Ʈ�� �ε��� %d���� �߰ߵǾ����ϴ�.\n", s);
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else
            s += max(1, j - badChar[text[s + j]]);
    }
}

void performBoyerMoore() {
    char text[100], pattern[100];

    printf("�ؽ�Ʈ�� �Է��ϼ���: ");
    scanf("%s", text);
    printf("ã�� ������ �Է��ϼ���: ");
    scanf("%s", pattern);

    searchBoyerMoore(text, pattern);
}

void boyerMoore() {
    explainBoyerMoore();
    performBoyerMoore();
}
