#include "headern.h"

int* CreateArray(int& size) {
    std::cout << "Enter number of elements: ";
    std::cin >> size;
    if (size <= 0) {
        std::cout << "Invalid size.\n";
        return nullptr;
    }

    int* arr = new(std::nothrow) int[size];
    if (!arr) {
        std::cout << "Memory allocation failed.\n";
        return nullptr;
    }

    return arr;
}

void FillArrayManual(int* arr, int size) {
    std::cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void FillArrayRandom(int* arr, int size) {
    int minVal, maxVal;
    std::cout << "Enter lower and upper bounds: ";
    std::cin >> minVal >> maxVal;

    if (minVal > maxVal) {
        std::cout << "Invalid bounds.\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (maxVal - minVal + 1) + minVal;
    }
}

void PrintArray(const int* arr, int size) {
    std::cout << "Array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}