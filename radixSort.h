// radixSort.h

#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes for the functions defined in radixSort.c
void explainRadixSort();
void printArray(int arr[], int size, int exp);
void countSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
void showRadixSort();
void performRadixSort();
void RadixSortMenu();

#endif // RADIXSORT_H
