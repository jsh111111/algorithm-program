// quickSort.h

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes for the functions defined in quickSort.c
void explainQuickSort();
void printArray(int arr[], int size);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void showQuickSort();
void performQuickSort();
void QuickSortMenu();

#endif // QUICKSORT_H
