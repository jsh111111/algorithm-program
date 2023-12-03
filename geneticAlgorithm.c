// geneticAlgorithm.c

#include "geneticAlgorithm.h"
#include "allHeaders.h"

void explainGeneticAlgorithm() {
    printf("���� �˰������� �ڿ� ������ ������ ����Ͽ� ����ȭ ������ �ذ��ϴ� ����Դϴ�.\n");
    printf("����, ���� �� �������� ������ ���� ���ο� ������ �ظ� �����Ͽ� ������ ���� �ظ� ã�ư��ϴ�.\n");
}

void initializePopulation(Individual population[]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < GENOME_LENGTH; j++) {
            population[i].genome[j] = rand() % 2; // 0 �Ǵ� 1�� �ʱ�ȭ
        }
        population[i].fitness = 0;
    }
}

void evaluateFitness(Individual population[]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i].fitness = 0;
        for (int j = 0; j < GENOME_LENGTH; j++) {
            if (population[i].genome[j] == 1) {
                population[i].fitness++; // �ܼ� ����: 1�� ������ ���յ��� ���
            }
        }
    }
}

void performSelection(Individual population[], Individual newPopulation[]) {
    // ���� ������ ���� ������ ���� ����
    for (int i = 0; i < POPULATION_SIZE; i++) {
        int k = rand() % POPULATION_SIZE;
        newPopulation[i] = population[k];
    }
}

void performCrossover(Individual* parent1, Individual* parent2, Individual* offspring) {
    int crossoverPoint = rand() % GENOME_LENGTH;
    for (int i = 0; i < crossoverPoint; i++) {
        offspring->genome[i] = parent1->genome[i];
    }
    for (int i = crossoverPoint; i < GENOME_LENGTH; i++) {
        offspring->genome[i] = parent2->genome[i];
    }
}

void performMutation(Individual* individual) {
    int mutationPoint = rand() % GENOME_LENGTH;
    individual->genome[mutationPoint] = (individual->genome[mutationPoint] + 1) % 2; // 0�̸� 1��, 1�̸� 0���� ��ȯ
}

void performGeneticAlgorithm() {
    Individual population[POPULATION_SIZE];
    Individual newPopulation[POPULATION_SIZE];

    initializePopulation(population);
    evaluateFitness(population);

    for (int generation = 0; generation < 10; generation++) {
        performSelection(population, newPopulation);
        for (int i = 0; i < POPULATION_SIZE; i += 2) {
            performCrossover(&newPopulation[i], &newPopulation[i + 1], &population[i]);
            performCrossover(&newPopulation[i + 1], &newPopulation[i], &population[i + 1]);
        }
        for (int i = 0; i < POPULATION_SIZE; i++) {
            performMutation(&population[i]);
        }
        evaluateFitness(population);

        // ���뺰 ��� ��� (������)
        printf("���� %d: �ְ� ���յ� = %d\n", generation, population[0].fitness);
    }

    // ���� ��� ���
    printf("���� �ְ� ���յ�: %d\n", population[0].fitness);
}

void geneticAlgorithmMenu() {
    int choice;
    do {
        system("cls"); // �ܼ� ȭ���� Ŭ����
        printf("���� �˰����� �޴�\n");
        printf("1: ���� �˰����� ����\n");
        printf("2: ���� �˰����� �۵� ���� ����\n");
        printf("0: ���� �޴��� ���ư���\n");
        printf("���ϴ� �ɼ��� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explainGeneticAlgorithm(); // ���� �˰����� ����
                break;
            case 2:
                performGeneticAlgorithm(); // ���� �˰����� �۵� ���� ����
                break;
            case 0:
                return; // ���� �޴��� ���ư���
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
        system("pause"); // ����ڰ� Ű�� ���� ������ ȭ�� ����
    } while (choice != 0);
}
