// insertionSort.h

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열의 최대 크기 정의
#define MAX_ARRAY_SIZE 100

// insertionSort.c에 정의된 함수들의 프로토타입
void explainInsertionSort();
void printArray(int arr[], int size, int idx1, int idx2);
void showInsertionSort();
void performInsertionSort();
void InsertionSortMenu();

#endif // INSERTIONSORT_H
