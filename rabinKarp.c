// rabinKarp.c

#include "rabinKarp.h"
#include "allHeaders.h"

void explainRabinKarp() {
    printf("���-ī�� �˰������� ���ڿ� ��Ī�� �ؽ� �Լ��� ����ϴ� ����Դϴ�.\n");
    printf("������ �ؽð��� �ؽ�Ʈ�� �κ� ���ڿ��� �ؽð��� ���Ͽ� ��Ī ���θ� Ȯ���մϴ�.\n");
}

unsigned long hash(char* str, int len) {
    unsigned long hash = 0;
    for (int i = 0; i < len; ++i) {
        hash = hash * 256 + str[i];
        hash = hash % PRIME;
    }
    return hash;
}

void searchPattern(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);
    unsigned long patternHash = hash(pattern, M);
    unsigned long textHash = hash(text, M);

    for (int i = 0; i <= N - M; i++) {
        if (patternHash == textHash) {
            if (strncmp(text + i, pattern, M) == 0) {
                printf("������ �ε��� %d���� �߰ߵǾ����ϴ�.\n", i);
            }
        }

        if (i < N - M) {
            textHash = (textHash - text[i] * 256) * 256 + text[i + M];
            textHash = (textHash + PRIME) % PRIME;
        }
    }
}

void performRabinKarp() {
    char text[100], pattern[100];

    printf("�ؽ�Ʈ�� �Է��ϼ���: ");
    scanf("%s", text);
    printf("ã�� ������ �Է��ϼ���: ");
    scanf("%s", pattern);

    searchPattern(pattern, text);
}

void rabinKarp() {
    explainRabinKarp();
    performRabinKarp();
}
