// mergeSort.h

#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// mergeSort.c에 정의된 함수들의 프로토타입입니다.
void explainMergeSort();
void printArray(int arr[], int size);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void showMergeSort();
void performMergeSort();
void mergeSortMenu();

#endif // MERGESORT_H
