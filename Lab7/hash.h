#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int hashf(char* str, int baseNum, int tableSize);
int colCount(char** arr, int baseNum, int tableSize);
char** parse(char* file);
int* profiling(char** book, int* baseNum, int* tableSize);
