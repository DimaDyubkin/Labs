#include "headern.h"


void FillArray(double* array, int32_t size, bool useRandom)
{
    if (useRandom)
    {
        double LowerLimit{}, UpperLimit{};
        std::cout << "Enter interval (Lower Upper): ";
        std::cin >> LowerLimit >> UpperLimit;

        if (LowerLimit > UpperLimit)
        {
            std::swap(LowerLimit, UpperLimit);
        }

        if (LowerLimit == UpperLimit)
        {
            std::swap(LowerLimit, UpperLimit);
        }

        for (int32_t i{}; i < size; ++i)
        {
            array[i] = LowerLimit + (static_cast<double>(rand()) / RAND_MAX) * (UpperLimit - LowerLimit);
        }
    }
    else
    {
        std::cout << "Enter elements of array: ";
        for (int32_t i{}; i < size; ++i)
        {
            std::cin >> array[i];
        }
    }
}