#include "headern.h"
    
int main() {
    try {
        std::string input, delimiters;
        std::cout << "Enter the line: ";
        std::getline(std::cin, input);
        std::cout << "Enter the separators: ";
        std::getline(std::cin, delimiters);

        std::cout << "The longest words: " << FindLongestIncreasingWords(input, delimiters) << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Mistake: " << e.what() << "\n";
    }
}
