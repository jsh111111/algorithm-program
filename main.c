#include "allHeaders.h"

void sortAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls"); // ȭ���� �����ϰ� ����ϴ�.
        printf("���� �˰��� �޴�\n");
        printf("1: ���� ����\n");
        printf("2: ���� ����\n");
        printf("3: ���� ����\n");
        printf("4: ���� ����\n");
        printf("5: �� ����\n");
        printf("6: �� ����\n");
        printf("7: �� ����\n");
        printf("8: ��� ����\n");
        printf("9: ��� ����\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� ���� �˰����� ��ȣ�� �Է��ϼ���: ");
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
            // ���� �޴��� ���ư���
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause"); // ����ڰ� Ű�� �����⸦ ��ٸ��ϴ�.
    } while (choice != 0);
}

// Ʈ�� �˰��� ���� �޴� �Լ�
void treeAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls"); // ȭ���� �����ϰ� ����ϴ�.
        printf("Ʈ�� �˰��� �޴�\n");
        printf("1: ���� �˻� Ʈ��\n");
        printf("2: B-Ʈ��\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� Ʈ�� �˰����� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                system("cls");
                printf("���� �˻� Ʈ�� �޴�\n");
                printf("1: ����\n");
                printf("2: ��� ����\n");
                printf("3: ��� ����\n");
                printf("4: ��� �˻�\n");
                printf("5: Ʈ�� ��ȸ\n");
                printf("0: �޴��� ���ư���\n");
                printf("���ϴ� �۾��� ��ȣ�� �Է��ϼ���: ");
                scanf("%d", &choice);

                while (choice != 0)
                {
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        printf("���� �˻� Ʈ��(Binary Search Tree, BST)�� ������ ���� Ư¡�� ���� �ڷᱸ���Դϴ�.\n\n");

                        printf("1. �� ���� �ִ� �� ���� �ڽ��� ���� �� ������, �̸� ���� �ڽİ� ������ �ڽ��̶�� �մϴ�.\n");
                        printf("2. ���� �ڽ� ����� ���� �θ� ����� ������ �۾ƾ� �ϸ�, ������ �ڽ� ����� ���� �θ� ����� ������ Ŀ�� �մϴ�.\n");
                        printf("3. �� ����� ���� ���� Ʈ���� ������ ���� Ʈ�� ���� BST�Դϴ�.\n");
                        printf("4. �ߺ��� ��� ���� ������� �ʴ� BST�� ������, �� ��� ��� ���� ������ ���� �����ϴ�.\n");
                        printf("5. BST�� �������� ����, ����, �˻� �۾��� ȿ�������� ������ �� �ֵ��� ����Ǿ����ϴ�.\n\n");

                        printf("���� �˻� Ʈ���� �����ͺ��̽� �ý���, ���� �ý���, �˻� �˰��� ��� �θ� ���Ǵ� �߿��� �ڷᱸ�� �� �ϳ��Դϴ�.\n");

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
                        // Ʈ�� ��ȸ �Լ� ȣ��
                        break;
                    case 0:
                        // �޴��� ���ư���
                        break;
                    default:
                        printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
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
                printf("B-Ʈ�� �޴�\n");
                printf("1: ����\n");
                printf("2: ��� ����\n");
                printf("3: ��� ����\n");
                printf("4: ��� �˻�\n");
                printf("5: Ʈ�� ��ȸ\n");
                printf("0: �޴��� ���ư���\n");
                printf("���ϴ� �۾��� ��ȣ�� �Է��ϼ���: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    system("cls");
                    printf("B-Ʈ���� �����ͺ��̽� �� ���� �ý��ۿ��� ���Ǵ� ���� ���� �˻� Ʈ���� �����Դϴ�.\n\n");

                    printf("1. B-Ʈ���� ��� ���� ��尡 ���� ������ �ֵ��� �����˴ϴ�.\n");
                    printf("2. �� ���� �̸� ������ �ּ� �� �ִ� ������ �ڽ��� ���� �� �ֽ��ϴ�.\n");
                    printf("3. B-Ʈ���� ��� ���ο��� ���ĵ� Ű�� �迭�� �����Ͽ� ȿ������ �˻�, ����, ������ �����մϴ�.\n");
                    printf("4. �� ���� ���� Ű�� �ڽ� �����͸� ���� �� ������, Ű�� ���� ����� �ڽ� ������ �ϳ� �����ϴ�.\n");
                    printf("5. B-Ʈ���� Ʈ���� ������ �����ϱ� ���� ����, ���հ� ���� �籸��ȭ �۾��� �ڵ����� �����մϴ�.\n\n");

                    printf("B-Ʈ���� Ư¡���� ���� ��뷮 �����͸� �ٷ� �� ���� ������ �����մϴ�. ��ũ ����� �����ͺ��̽� �ý��ۿ��� �ε����� �����ϴ� �� �ַ� ���˴ϴ�.\n");

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
                    // �޴��� ���ư���
                    break;
                default:
                    printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
                }

                if (choice != 0)
                    system("pause");

            } while (choice != 0);
            break;

        case 0:
            // ���� �޴��� ���ư���
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause"); // ����ڰ� Ű�� �����⸦ ��ٸ��ϴ�.
    } while (choice != 0);
}

// �ؽ� ���̺� �˰��� ���� �޴� �Լ�
void hashTableAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls"); // ȭ���� �����ϰ� ����ϴ�.
        printf("�ؽ� ���̺� �˰��� �޴�\n");
        printf("1: �ؽ�\n");
        printf("2: �ؽ� �Լ�\n");
        printf("3: �浹 �ذ� ���\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ؽ� ���̺� �˰����� ��ȣ�� �Է��ϼ���: ");
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
            // ���� �޴��� ���ư���
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause"); // ����ڰ� Ű�� �����⸦ ��ٸ��ϴ�.
    } while (choice != 0);
}

// ���� ����Ʈ �� ���� ó�� �˰��� ���� �޴� �Լ�
void linkedListAndSetAlgorithmsMenu()
{
    int choice;
    do
    {
        system("cls"); // ȭ���� �����ϰ� ����ϴ�.
        printf("���� ����Ʈ �� ���� ó�� �˰��� �޴�\n");
        printf("1: ���� ���� ����Ʈ\n");
        printf("2: ���� ���� ����Ʈ\n");
        printf("3: ���� ���� ����Ʈ\n");
        printf("4: ���� ����\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� ���� ����Ʈ �Ǵ� ���� ó�� �˰����� ��ȣ�� �Է��ϼ���: ");
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
            // ���� ���� �Լ� ȣ��
            break;
        case 0:
            // ���� �޴��� ���ư���
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause"); // ����ڰ� Ű�� �����⸦ ��ٸ��ϴ�.
    } while (choice != 0);
}

// ���� ���α׷��� �˰��� ���� �޴� �Լ�
void dynamicProgrammingMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("���� ���α׷��� �˰��� �޴�\n");
        printf("1: �Ǻ���ġ ����\n");
        printf("2: ��� ���� ����\n");
        printf("3: ���� ���� �κ� ���� (LCS)\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� ���� ���α׷��� �˰����� ��ȣ�� �Է��ϼ���: ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}

// �׷��� �˰��� ���� �޴� �Լ�
void graphAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("�׷��� �˰��� �޴�\n");
        printf("1: �ʺ� �켱 Ž�� (BFS)\n");
        printf("2: ���� �켱 Ž�� (DFS)\n");
        printf("3: �ּ� ���� Ʈ�� (����, ũ�罺Į)\n");
        printf("4: ���� ����\n");
        printf("5: �ִ� ��� �˰���\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �׷��� �˰����� ��ȣ�� �Է��ϼ���: ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}

// ���ڿ� ��Ī �˰��� ���� �޴� �Լ�
void stringMatchingMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("���ڿ� ��Ī �˰��� �޴�\n");
        printf("1: ���丶Ÿ\n");
        printf("2: ���-ī��\n");
        printf("3: KMP\n");
        printf("4: ���̾�-����\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� ���ڿ� ��Ī �˰����� ��ȣ�� �Է��ϼ���: ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}

// ���� ���� Ʈ�� �˰��� ���� �޴� �Լ�
void stateSpaceTreeMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("���� ���� Ʈ�� �˰��� �޴�\n");
        printf("1: ���� ���� Ʈ��\n");
        printf("2: ��Ʈ��ŷ\n");
        printf("3: ���� �б�\n");
        printf("4: A-star\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� ���� ���� Ʈ�� �˰����� ��ȣ�� �Է��ϼ���: ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}

// �� Ž�� �˰��� ���� �޴� �Լ�
void searchAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("�� Ž�� �˰��� �޴�\n");
        printf("1: �� Ž�� �˰��� 1\n");
        printf("2: �� Ž�� �˰��� 2\n");
        // �߰����� �� Ž�� �˰����� ���⿡ ������ �� �ֽ��ϴ�.
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �� Ž�� �˰����� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            heuristicSearch();
            break;
        case 2:
            HeuristicSearchMax();
            break;
        // �߰����� case�� ���⿡ ������ �� �ֽ��ϴ�.
        case 0:
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}

// ������ �˰��� ���� �޴� �Լ�
void geneticAlgorithmsMenu()
{
    int choice;

    do
    {
        system("cls");
        printf("������ �˰��� �޴�\n");
        printf("1: ������ �˰��� 1\n");
        printf("2: ������ �˰��� 2\n");
        // �߰����� ������ �˰����� ���⿡ ������ �� �ֽ��ϴ�.
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� ������ �˰����� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            geneticAlgorithmMenu();
            break;
        case 2:
            // ������ �˰��� 2 �Լ� ȣ��
            break;
        // �߰����� case�� ���⿡ ������ �� �ֽ��ϴ�.
        case 0:
            return;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause");
    } while (choice != 0);
}

void mainMenu()
{
    int choice;

    do
    {
        system("cls"); // ȭ���� �����ϰ� ����ϴ� (Windows ����).
        printf("�˰��� �ÿ� ���α׷��� ���� ���� ȯ���մϴ�!\n");
        printf("1: ���� �˰���\n");
        printf("2: Ʈ��\n");
        printf("3: �ؽ� ���̺�\n");
        printf("4: ���� ����Ʈ �� ���� ó��\n");
        printf("5: ���� ���α׷���\n");
        printf("6: �׷��� �˰���\n");
        printf("7: ���ڿ� ��Ī\n");
        printf("8: ���� ���� Ʈ��\n");
        printf("9: �� Ž�� �˰���\n");
        printf("10: ������ �˰���\n");
        printf("0: ���α׷� ����\n");
        printf("���ϴ� ī�װ��� ��ȣ�� �Է��ϼ���: ");
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
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }

        system("pause"); // ����ڰ� Ű�� �����⸦ ��ٸ��ϴ�.
    } while (choice != 0);
}

int main()
{
    mainMenu();
    return 0;
}
