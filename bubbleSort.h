// bubbleSort.h

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열의 최대 크기 정의
#define MAX_ARRAY_SIZE 100

// bubbleSort.c에서 정의한 함수들의 프로토타입
void explainBubbleSort();
void printArray(int arr[], int size, int idx1, int idx2);
void showBubbleSort();
void performBubbleSort();
void bubbleSortMenu();

#endif // BUBBLESORT_H
