// heapSort.h

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열의 최대 크기를 정의합니다.
#define MAX_ARRAY_SIZE 100

// heapSort.c에 정의된 함수들의 프로토타입입니다.
void explainHeapSort();
void printArray(int arr[], int size, int idx1, int idx2);
void heapify(int arr[], int n, int i, int size);
void heapSort(int arr[], int n);
void showHeapSort();
void performHeapSort();
void HeapSortMenu();

#endif // HEAPSORT_H
