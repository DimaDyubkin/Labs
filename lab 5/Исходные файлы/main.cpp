#include "headern.h"

int main() {
    int size;
    int* arr = CreateArray(size);
    if (!arr) return 1;

    int mode;
    std::cout << "Input method:\n1 - Manual\n2 - Random\nChoice: ";
    std::cin >> mode;

    if (mode == 1) {
        FillArrayManual(arr, size);
    }
    else if (mode == 2) {
        FillArrayRandom(arr, size);
    }
    else {
        std::cout << "Invalid input mode.\n";
        delete[] arr;
        return 1;
    }

    PrintArray(arr, size);

    delete[] arr;
    return 0;
}
