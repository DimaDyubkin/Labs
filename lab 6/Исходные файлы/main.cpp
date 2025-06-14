#include "headern.h"

int main() {

    char input[MAX_LENGTH + 1];
    char separators[MAX_LENGTH + 1];
    char result[MAX_LENGTH + 1];


    std::cout << "Enter the line: ";
    std::cin.getline(input, MAX_LENGTH);
    std::cout << "Enter the delimiter characters: ";
    std::cin.getline(separators, MAX_LENGTH);

    FindLongestIncreasingWords(input, separators, result);

    if (strlen(result) == 0) {
        std::cout << "There are no words that satisfy the condition, or it is impossible to solve the problem.\n";
    }
    else {
        std::cout << "The longest words with increasing codes: \n" << result;
    }

    return 0;
}