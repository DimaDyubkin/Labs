#include "headern.h"

bool IsSeparator(char c, const char* separators) {
    for (int i = 0; separators[i] != '\0'; ++i) {
        if (c == separators[i]) {
            return true;
        }
    }
    return false;
}

bool IsStrictlyIncreasing(const char* word) {
    if (word[0] == '\0') return false;
    for (int i = 1; word[i] != '\0'; ++i) {
        if (word[i] <= word[i - 1]) {
            return false;
        }
    }
    return true;
}

void FindLongestIncreasingWords(const char* str, const char* separators, char* result) {
    char buffer[MAX_LENGTH + 1]{};
    char longestWords[MAX_LENGTH + 1]{};
    int maxLength{};
    int pos{};

    while (str[pos] != '\0') {
        while (str[pos] != '\0' && IsSeparator(str[pos], separators)) {
            pos++;
        }

        int wordStart = pos;
        while (str[pos] != '\0' && !IsSeparator(str[pos], separators)) {
            pos++;
        }

        int wordLength = pos - wordStart;
        if (wordLength > 0) {
            strncpy(buffer, &str[wordStart], wordLength);
            buffer[wordLength] = '\0';

            if (IsStrictlyIncreasing(buffer)) {
                if (wordLength > maxLength) {
                    maxLength = wordLength;
                    strcpy(longestWords, buffer);
                    strcat(longestWords, " ");
                }
                else if (wordLength == maxLength) {
                    if (strlen(longestWords) + wordLength + 1 <= MAX_LENGTH) {
                        strcat(longestWords, buffer);
                        strcat(longestWords, " ");
                    }
                }
            }
        }
    }

    if (strlen(longestWords)) {
        longestWords[strlen(longestWords) - 1] = '\0';
    }

    strcpy(result, longestWords);
}