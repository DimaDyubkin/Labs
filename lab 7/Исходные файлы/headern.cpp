#include "headern.h"

bool IsIncreasingOrder(std::string word) {
    for (size_t i{ 1 }; i < word.size(); ++i)
    {
        if (word[i] <= word[i - 1])
        {
            return false;
        }
        else {
            return true;
        }
    }
}

std::string FindLongestIncreasingWords(std::string input, std::string delimiters) {
    std::string longestWords, temp;
    size_t maxLength{ 0 };
    for (char check : input + delimiters)
    {
        if (delimiters.find(check) != std::string::npos)
        {
            if (!temp.empty() && IsIncreasingOrder(temp))
            {
                if (temp.size() > maxLength)
                {
                    longestWords = temp;
                    maxLength = temp.size();
                }
                else
                {
                    if (temp.size() == maxLength) {
                        longestWords += " " + temp;
                    }
                }
            }
            temp.clear();
        }
        else
        {
            temp += check;
        }
    }

    return longestWords.empty() ? "No matching words were found." : longestWords;
}