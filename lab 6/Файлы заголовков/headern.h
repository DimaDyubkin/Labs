#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>

const int MAX_LENGTH = 300;

bool IsSeparator(char, const char*);

bool IsStrictlyIncreasing(const char* word);

void FindLongestIncreasingWords(const char* str, const char* separators, char* result);