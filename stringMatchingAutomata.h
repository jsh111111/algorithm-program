// stringMatchingAutomata.h

#ifndef STRING_MATCHING_AUTOMATA_H
#define STRING_MATCHING_AUTOMATA_H

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

void explainStringMatchingAutomata();
void buildTransitionTable(char* pattern, int table[][MAX_CHAR]);
void searchPattern(char* text, char* pattern);
void performStringMatchingAutomata();
void stringMatchingAutomata();

#endif
