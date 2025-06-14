#include "headern.h"

int main() {
    const int MAX_SIZE = 20;
    int32_t** mtr;
    int32_t rows{}, colms{};
    bool chose{ false };
    mtr = new int32_t * [MAX_SIZE];
    for (int32_t i{ 0 }; i < MAX_SIZE; ++i) {
        mtr[i] = new int32_t[MAX_SIZE];
    }

    for (int32_t i{ 0 }; i < MAX_SIZE; ++i) {
         delete mtr[i];
    }
    delete[]mtr;
    return 0;
