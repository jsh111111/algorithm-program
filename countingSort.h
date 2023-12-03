// countingSort.h

#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 정렬할 숫자의 최대 개수
#define MAX_SORT_SIZE 100

// countingSort.c에 정의된 함수들의 프로토타입
void explainCountingSort();
void printArray(int arr[], int size, int highlightIndex);
void countingSort(int arr[], int size);
void showCountingSort();
void performCountingSort();
void CountingSortMenu();

#endif // COUNTINGSORT_H
