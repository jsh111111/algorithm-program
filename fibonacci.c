// fibonacci.c

#include "fibonacci.h"
#include "allHeaders.h"

// �Ǻ���ġ ������ ���� ������ �����ϴ� �Լ�
void explainFibonacci() {
    printf("�Ǻ���ġ ������ �� ���ڰ� �ٷ� �� �� ������ ���� �����Դϴ�.\n");
    printf("���� ���, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ���� �Ǻ���ġ �����Դϴ�.\n");
}

// �Ǻ���ġ ������ ����ϴ� �Լ�
int calculateFibonacci(int n) {
    if (n <= 1)
        return n;
    return calculateFibonacci(n - 1) + calculateFibonacci(n - 2);
}

// Ư�� ���ڱ����� �Ǻ���ġ ������ �����ִ� �Լ�
void showFibonacciSequence(int n) {
    printf("�Ǻ���ġ ���� (n = %d): ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", calculateFibonacci(i));  // ������ �κ�
    }
    printf("\n");
}


// ����ڿ��� ������ �����ϰ� �ش� ���ÿ� ���� �۵��ϴ� �Լ�
void performFibonacci() {
    int choice, n;

    do {
        printf("\n�Ǻ���ġ ���� ���α׷�\n");
        printf("1. �Ǻ���ġ ���� ����\n");
        printf("2. ������ ���� 10���� �Ǻ���ġ ���� ����\n");
        printf("3. ����� �Է� ������ �Ǻ���ġ ���� ���\n");
        printf("0. ���α׷� ����\n");
        printf("����: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                explainFibonacci();
                break;
            case 2:
                showFibonacciSequence(10);
                break;
            case 3:
                printf("�Ǻ���ġ ������ ����� ���ڸ� �Է��ϼ���: ");
                scanf("%d", &n);
                showFibonacciSequence(n);
                break;
            case 0:
                printf("���α׷��� �����մϴ�.\n");
                return;  // ������ �����ϱ� ���� return�� ���
            default:
                printf("�߸��� �����Դϴ�.\n");
        }
    } while (choice != 0);
}
