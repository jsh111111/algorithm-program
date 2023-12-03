#include "allHeaders.h"

void sortAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls"); // 화면을 깨끗하게 지웁니다.
        printf("정렬 알고리즘 메뉴\n");
        printf("1: 선택 정렬\n");
        printf("2: 버블 정렬\n");
        printf("3: 삽입 정렬\n");
        printf("4: 병합 정렬\n");
        printf("5: 퀵 정렬\n");
        printf("6: 힙 정렬\n");
        printf("7: 쉘 정렬\n");
        printf("8: 기수 정렬\n");
        printf("9: 계수 정렬\n");
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 정렬 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertionSortMenu();
            break;
        case 2:
            bubbleSortMenu();
            break;
        case 3:
            selectionSortMenu();
            break;
        case 4:
            mergeSortMenu();
            break;
        case 5:
            QuickSortMenu();
            break;
        case 6:
            HeapSortMenu();
            break;
        case 7:
            shellSortMenu();
            break;
        case 8:
            RadixSortMenu();
            break;
        case 9:
            CountingSortMenu();
            break;
        
        case 0:
            // 메인 메뉴로 돌아가기
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause"); // 사용자가 키를 누르기를 기다립니다.
    } while (choice != 0);
}

// 트리 알고리즘 선택 메뉴 함수
void treeAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls"); // 화면을 깨끗하게 지웁니다.
        printf("트리 알고리즘 메뉴\n");
        printf("1: 이진 검색 트리\n");
        printf("2: B-트리\n");
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 트리 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                system("cls");
                printf("이진 검색 트리 메뉴\n");
                printf("1: 설명\n");
                printf("2: 노드 삽입\n");
                printf("3: 노드 삭제\n");
                printf("4: 노드 검색\n");
                printf("5: 트리 순회\n");
                printf("0: 메뉴로 돌아가기\n");
                printf("원하는 작업의 번호를 입력하세요: ");
                scanf("%d", &choice);

                while (choice != 0)
                {
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        printf("이진 검색 트리(Binary Search Tree, BST)는 다음과 같은 특징을 가진 자료구조입니다.\n\n");

                        printf("1. 각 노드는 최대 두 개의 자식을 가질 수 있으며, 이를 왼쪽 자식과 오른쪽 자식이라고 합니다.\n");
                        printf("2. 왼쪽 자식 노드의 값은 부모 노드의 값보다 작아야 하며, 오른쪽 자식 노드의 값은 부모 노드의 값보다 커야 합니다.\n");
                        printf("3. 각 노드의 왼쪽 하위 트리와 오른쪽 하위 트리 역시 BST입니다.\n");
                        printf("4. 중복된 노드 값을 허용하지 않는 BST도 있으며, 이 경우 모든 노드는 고유한 값을 가집니다.\n");
                        printf("5. BST는 데이터의 삽입, 삭제, 검색 작업을 효율적으로 수행할 수 있도록 설계되었습니다.\n\n");

                        printf("이진 검색 트리는 데이터베이스 시스템, 파일 시스템, 검색 알고리즘 등에서 널리 사용되는 중요한 자료구조 중 하나입니다.\n");

                        break;
                    case 2:
                        BSTInsertionMenu();
                        break;
                    case 3:
                        BSTDeletionMenu();
                        break;
                    case 4:
                        BSTSearchMenu();
                        break;
                    case 5:
                        // 트리 순회 함수 호출
                        break;
                    case 0:
                        // 메뉴로 돌아가기
                        break;
                    default:
                        printf("잘못된 선택입니다. 다시 시도해주세요.\n");
                    }

                    if (choice != 0)
                        system("pause");
                }
            } while (choice != 0);
            break;

        case 2:
            do
            {
                system("cls");
                printf("B-트리 메뉴\n");
                printf("1: 설명\n");
                printf("2: 노드 삽입\n");
                printf("3: 노드 삭제\n");
                printf("4: 노드 검색\n");
                printf("5: 트리 순회\n");
                printf("0: 메뉴로 돌아가기\n");
                printf("원하는 작업의 번호를 입력하세요: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    system("cls");
                    printf("B-트리는 데이터베이스 및 파일 시스템에서 사용되는 균형 이진 검색 트리의 일종입니다.\n\n");

                    printf("1. B-트리는 모든 리프 노드가 같은 레벨에 있도록 유지됩니다.\n");
                    printf("2. 각 노드는 미리 정해진 최소 및 최대 범위의 자식을 가질 수 있습니다.\n");
                    printf("3. B-트리는 노드 내부에서 정렬된 키의 배열을 유지하여 효율적인 검색, 삽입, 삭제를 지원합니다.\n");
                    printf("4. 각 노드는 여러 키와 자식 포인터를 가질 수 있으며, 키의 수는 노드의 자식 수보다 하나 적습니다.\n");
                    printf("5. B-트리는 트리의 균형을 유지하기 위해 분할, 병합과 같은 재구조화 작업을 자동으로 수행합니다.\n\n");

                    printf("B-트리의 특징으로 인해 대용량 데이터를 다룰 때 높은 성능을 발휘합니다. 디스크 기반의 데이터베이스 시스템에서 인덱스를 구성하는 데 주로 사용됩니다.\n");

                    break;
                case 2:
                    BTreeInsertionMenu();
                    break;
                case 3:
                    BTreeDeletionMenu();
                    break;
                case 4:
                    BTreeSearchMenu();
                    break;
                case 0:
                    // 메뉴로 돌아가기
                    break;
                default:
                    printf("잘못된 선택입니다. 다시 시도해주세요.\n");
                }

                if (choice != 0)
                    system("pause");

            } while (choice != 0);
            break;

        case 0:
            // 메인 메뉴로 돌아가기
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause"); // 사용자가 키를 누르기를 기다립니다.
    } while (choice != 0);
}

// 해시 테이블 알고리즘 선택 메뉴 함수
void hashTableAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls"); // 화면을 깨끗하게 지웁니다.
        printf("해시 테이블 알고리즘 메뉴\n");
        printf("1: 해싱\n");
        printf("2: 해시 함수\n");
        printf("3: 충돌 해결 기법\n");
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 해시 테이블 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            hashingMenu();
            break;
        case 2:
            hashFunction();
            break;
        case 3:
            collisionResolution();
            break;
        case 0:
            // 메인 메뉴로 돌아가기
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause"); // 사용자가 키를 누르기를 기다립니다.
    } while (choice != 0);
}

// 연결 리스트 및 집합 처리 알고리즘 선택 메뉴 함수
void linkedListAndSetAlgorithmsMenu()
{
    int choice;
    do
    {
        system("cls"); // 화면을 깨끗하게 지웁니다.
        printf("연결 리스트 및 집합 처리 알고리즘 메뉴\n");
        printf("1: 단일 연결 리스트\n");
        printf("2: 이중 연결 리스트\n");
        printf("3: 원형 연결 리스트\n");
        printf("4: 집합 연산\n");
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 연결 리스트 또는 집합 처리 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            singlyLinkedList();
            break;
        case 2:
            doubleLinkedList();
            break;
        case 3:
            circularLinkedlist();
            break;
        case 4:
            // 집합 연산 함수 호출
            break;
        case 0:
            // 메인 메뉴로 돌아가기
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause"); // 사용자가 키를 누르기를 기다립니다.
    } while (choice != 0);
}

// 동적 프로그래밍 알고리즘 선택 메뉴 함수
void dynamicProgrammingMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("동적 프로그래밍 알고리즘 메뉴\n");
        printf("1: 피보나치 수열\n");
        printf("2: 행렬 곱셈 순서\n");
        printf("3: 최장 공통 부분 순서 (LCS)\n");
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 동적 프로그래밍 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            performFibonacci();
            break;
        case 2:
            matrixMultiplication();
            break;
        case 3:
            LCS();
            break;
        case 0:
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause");
    } while (choice != 0);
}

// 그래프 알고리즘 선택 메뉴 함수
void graphAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("그래프 알고리즘 메뉴\n");
        printf("1: 너비 우선 탐색 (BFS)\n");
        printf("2: 깊이 우선 탐색 (DFS)\n");
        printf("3: 최소 신장 트리 (프림, 크루스칼)\n");
        printf("4: 위상 정렬\n");
        printf("5: 최단 경로 알고리즘\n");
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 그래프 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            BFS();
            break;
        case 2:
            DFS();
            break;
        case 3:
            MST();
            break;
        case 4:
            performTopologicalSort();
            break;
        case 5:
            shortestPath();
            break;
        case 0:
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause");
    } while (choice != 0);
}

// 문자열 매칭 알고리즘 선택 메뉴 함수
void stringMatchingMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("문자열 매칭 알고리즘 메뉴\n");
        printf("1: 오토마타\n");
        printf("2: 라빈-카프\n");
        printf("3: KMP\n");
        printf("4: 보이어-무어\n");
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 문자열 매칭 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            stringMatchingAutomata();
            break;
        case 2:
            rabinKarp();
            break;
        case 3:
            KMP();
            break;
        case 4:
            boyerMoore();
            break;
        case 0:
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause");
    } while (choice != 0);
}

// 상태 공간 트리 알고리즘 선택 메뉴 함수
void stateSpaceTreeMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("상태 공간 트리 알고리즘 메뉴\n");
        printf("1: 상태 공간 트리\n");
        printf("2: 백트래킹\n");
        printf("3: 한정 분기\n");
        printf("4: A-star\n");
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 상태 공간 트리 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            stateSpaceTree();
            break;
        case 2:
            backtracking();
            break;
        case 3:
            branchAndBound();
            break;
        case 4:
            aStar();
            break;
        case 0:
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause");
    } while (choice != 0);
}

// 해 탐색 알고리즘 선택 메뉴 함수
void searchAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("해 탐색 알고리즘 메뉴\n");
        printf("1: 해 탐색 알고리즘 1\n");
        printf("2: 해 탐색 알고리즘 2\n");
        // 추가적인 해 탐색 알고리즘을 여기에 나열할 수 있습니다.
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 해 탐색 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            heuristicSearch();
            break;
        case 2:
            HeuristicSearchMax();
            break;
        // 추가적인 case를 여기에 구현할 수 있습니다.
        case 0:
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause");
    } while (choice != 0);
}

// 유전자 알고리즘 선택 메뉴 함수
void geneticAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("유전자 알고리즘 메뉴\n");
        printf("1: 유전자 알고리즘 1\n");
        printf("2: 유전자 알고리즘 2\n");
        // 추가적인 유전자 알고리즘을 여기에 나열할 수 있습니다.
        printf("0: 메인 메뉴로 돌아가기\n");
        printf("원하는 유전자 알고리즘의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            geneticAlgorithmMenu();
            break;
        case 2:
            // 유전자 알고리즘 2 함수 호출
            break;
        // 추가적인 case를 여기에 구현할 수 있습니다.
        case 0:
            return;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause");
    } while (choice != 0);
}

void mainMenu()
{
    int choice;

    do
    {
        system("cls"); // 화면을 깨끗하게 지웁니다 (Windows 기준).
        printf("알고리즘 시연 프로그램에 오신 것을 환영합니다!\n");
        printf("1: 정렬 알고리즘\n");
        printf("2: 트리\n");
        printf("3: 해시 테이블\n");
        printf("4: 연결 리스트 및 집합 처리\n");
        printf("5: 동적 프로그래밍\n");
        printf("6: 그래프 알고리즘\n");
        printf("7: 문자열 매칭\n");
        printf("8: 상태 공간 트리\n");
        printf("9: 해 탐색 알고리즘\n");
        printf("10: 유전자 알고리즘\n");
        printf("0: 프로그램 종료\n");
        printf("원하는 카테고리의 번호를 입력하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            sortAlgorithmsMenu();
            break;
        case 2:
            treeAlgorithmsMenu();
            break;
        case 3:
            hashTableAlgorithmsMenu();
            break;
        case 4:
            linkedListAndSetAlgorithmsMenu();
            break;
        case 5:
            dynamicProgrammingMenu();
            break;
        case 6:
            graphAlgorithmsMenu();
            break;
        case 7:
            stringMatchingMenu();
            break;
        case 8:
            stateSpaceTreeMenu();
            break;
        case 9:
            searchAlgorithmsMenu();
            break;
        case 10:
            geneticAlgorithmsMenu();
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }

        system("pause"); // 사용자가 키를 누르기를 기다립니다.
    } while (choice != 0);
}

int main()
{
    mainMenu();
    return 0;
}
