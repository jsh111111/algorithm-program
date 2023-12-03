#ifndef HASHING_H
#define HASHING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10

int hashFunction(int key);
void insertKey(int hashTable[], int key);
void printHashTable(int hashTable[]);
void explainHashing();
void showHashingProcess();
void performHashing();
void hashingMenu();

#endif // HASHING_H
