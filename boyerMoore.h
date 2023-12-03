// boyerMoore.h

#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR 256

void explainBoyerMoore();
void badCharHeuristic(char* str, int size, int badChar[MAX_CHAR]);
void searchBoyerMoore(char* text, char* pattern);
void performBoyerMoore();
void boyerMoore();

#endif
