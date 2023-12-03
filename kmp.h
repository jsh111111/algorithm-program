// kmp.h

#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include <string.h>

void explainKMP();
void KMPsearch(char* text, char* pattern);
void computeLPSArray(char* pattern, int M, int* lps);
void performKMP();
void KMP();

#endif
