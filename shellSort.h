// shellSort.h

#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes for the functions defined in shellSort.c
void explainShellSort();
void printArray(int arr[], int size, int idx1, int idx2);
void shellSort(int arr[], int n);
void showShellSort();
void performShellSort();
void shellSortMenu();

#endif // SHELLSORT_H
