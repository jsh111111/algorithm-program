// geneticAlgorithm.h

#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 100
#define GENOME_LENGTH 10

typedef struct {
    int genome[GENOME_LENGTH];
    int fitness;
} Individual;

void explainGeneticAlgorithm();
void initializePopulation(Individual population[]);
void evaluateFitness(Individual population[]);
void performSelection(Individual population[], Individual newPopulation[]);
void performCrossover(Individual* parent1, Individual* parent2, Individual* offspring);
void performMutation(Individual* individual);
void performGeneticAlgorithm();
void geneticAlgorithmMenu();

#endif
