#include "collisionResolution.h"
#include "allHeaders.h"

// 해시 함수
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// 새 노드 생성 (체이닝)
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// 해시 테이블 초기화
void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        chainingHashTable[i] = NULL;
        linearProbingHashTable[i] = -1;
    }
}

// 체이닝을 이용한 삽입
void insertWithChaining(int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);
    newNode->next = chainingHashTable[index];
    chainingHashTable[index] = newNode;
}

// 선형 조사법을 이용한 충돌 해결 (삽입)
void insertWithLinearProbing(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (linearProbingHashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("해시 테이블이 가득 찼습니다.\n");
            return;
        }
    }
    linearProbingHashTable[index] = key;
}

// 해시 테이블 출력 (체이닝)
void printChainingHashTable() {
    printf("체이닝 해시 테이블:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("인덱스 %d: ", i);
        Node* temp = chainingHashTable[i];
        while (temp) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// 해시 테이블 출력 (선형 조사법)
void printLinearProbingHashTable() {
    printf("선형 조사법 해시 테이블:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (linearProbingHashTable[i] != -1) {
            printf("인덱스 %d: %d\n", i, linearProbingHashTable[i]);
        } else {
            printf("인덱스 %d: 비어 있음\n", i);
        }
    }
}

void explainCollisionResolution() {
    system("cls");
    printf("해시 테이블에서 충돌은 두 개 이상의 키가 동일한 인덱스에 매핑될 때 발생합니다.\n");
    printf("충돌 해결 기법은 이러한 충돌을 처리하는 방법을 말합니다.\n\n");
    printf("1. 선형 조사법(Linear Probing): 충돌이 발생하면, 연속적인 위치를 탐색하여 빈 슬롯을 찾습니다.\n");
    printf("2. 체이닝(Chaining): 각 인덱스에 연결 리스트를 사용하여 여러 키를 저장할 수 있습니다.\n\n");
    system("pause");
}

void showCollisionResolutionProcess() {
    system("cls");
    initializeHashTable();
    srand(time(0));  // 난수 초기화

    printf("임의의 숫자 10개를 해시 테이블에 저장하는 과정을 보여줍니다 (선형 조사법 사용):\n");
    for (int i = 0; i < 10; i++) {
        int key = rand() % 50;  // 0에서 49 사이의 난수 생성
        printf("선형 조사법 삽입: %d\n", key);
        insertWithLinearProbing(key);
        printLinearProbingHashTable();
        printf("\n");

        printf("체이닝 삽입: %d\n", key);
        insertWithChaining(key);
        printChainingHashTable();
        printf("\n");
    }
    system("pause");
}

void collisionResolution() {
    int choice;
    do {
        system("cls");
        printf("충돌 해결 기법 메뉴\n");
        printf("1: 충돌 해결 기법 설명\n");
        printf("2: 충돌 해결 과정 보기\n");
        printf("0: 이전 메뉴로 돌아가기\n");
        printf("원하는 옵션의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainCollisionResolution();
                break;
            case 2:
                showCollisionResolutionProcess();
                break;
            case 0:
                return;
            default:
                printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }
        system("pause");
    } while (choice != 0);
}
