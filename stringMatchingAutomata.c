// stringMatchingAutomata.c

#include "stringMatchingAutomata.h"
#include "allHeaders.h"

void explainStringMatchingAutomata() {
    printf("���ڿ� ��Ī ���丶Ÿ�� �־��� ������ ã�� ���� ���� ���� ���̺��� ����ϴ� �˰������Դϴ�.\n");
    printf("�� ���´� ������ �κ� ���ڿ��� ��Ÿ����, ���� �Է¿� ���� ���� ���·� ���̵˴ϴ�.\n");
}

void buildTransitionTable(char* pattern, int table[][MAX_CHAR]) {
    int len = strlen(pattern);
    for (int state = 0; state <= len; ++state) {
        for (int x = 0; x < MAX_CHAR; ++x) {
            int nextState = 0;
            for (int ns = state; ns >= 0; --ns) {
                if (pattern[ns - 1] == x) {
                    nextState = ns;
                    break;
                }
            }
            table[state][x] = nextState;
        }
    }
}

void searchPattern(char* text, char* pattern) {
    int lenPattern = strlen(pattern);
    int lenText = strlen(text);

    int table[lenPattern + 1][MAX_CHAR];
    buildTransitionTable(pattern, table);

    int state = 0;
    for (int i = 0; i < lenText; i++) {
        state = table[state][text[i]];
        if (state == lenPattern) {
            printf("������ �ؽ�Ʈ�� �ε��� %d���� �߰ߵǾ����ϴ�.\n", i - lenPattern + 1);
        }
    }
}

void performStringMatchingAutomata() {
    char text[100], pattern[100];

    printf("�ؽ�Ʈ�� �Է��ϼ���: ");
    scanf("%s", text);
    printf("ã�� ������ �Է��ϼ���: ");
    scanf("%s", pattern);

    searchPattern(text, pattern);
}

void stringMatchingAutomata() {
    explainStringMatchingAutomata();
    performStringMatchingAutomata();
}
