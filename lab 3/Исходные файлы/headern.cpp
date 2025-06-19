#include "headern.h"

void InputArray(double arr[], int& n) {
    std::cout << "Enter array size (1-" << MaxSize << "): ";
    std::cin >> n;
    if (n < 1 || n > MaxSize) {
        std::cout << "Invalid array size.\n";
        exit(1);
    }

    std::cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}

double SumOfOddIndex(const double arr[], int n) {
    double sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}

bool ProductBetweenNegatives(const double arr[], int n, double& result) {
    int firstNeg = -1, lastNeg = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            if (firstNeg == -1) firstNeg = i;
            lastNeg = i;
        }
    }

    if (firstNeg != -1 && lastNeg != -1 && firstNeg < lastNeg - 1) {
        result = 1;
        for (int i = firstNeg + 1; i < lastNeg; ++i) {
            result *= arr[i];
        }
        return true;
    }
    return false;
}

void CompressArray(double arr[], int n) {
    int writeIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (std::fabs(arr[i]) > 1) {
            arr[writeIndex++] = arr[i];
        }
    }
    for (int i = writeIndex; i < n; ++i) {
        arr[i] = 0;
    }
}

void PrintArray(const double arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}