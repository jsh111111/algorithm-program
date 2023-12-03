// rabinKarp.h

#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <stdio.h>
#include <string.h>

#define PRIME 101

void explainRabinKarp();
unsigned long hash(char* str, int len);
void searchPattern(char* pattern, char* text);
void performRabinKarp();
void rabinKarp();

#endif
