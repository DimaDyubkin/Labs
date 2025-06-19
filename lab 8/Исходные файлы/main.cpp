#include "headern.h"

int main() {
    std::cout << "Select module:\n1. Double array\n2. Student array\nChoice: ";
    int moduleChoice;
    std::cin >> moduleChoice;

    if (moduleChoice == 1) { 
        std::cout << "\nDouble array module selected.\n";
        std::cout << "Select input mode:\n"
            << "1. Data from file -> output to console\n"
            << "2. Data from console -> output to file\n"
            << "3. Data from file -> output to file\n"
            << "Choice: ";
        int inputMode;
        std::cin >> inputMode;

        double* arr = nullptr;
        int n = 0;

        if (inputMode == 1 || inputMode == 3) {
            std::string inFile;
            std::cout << "Enter input file name: ";
            std::cin >> inFile;
            if (!ReadDoubleArrayFromFile(inFile, arr, n)) {
                return 1;
            }
        }
        else if (inputMode == 2) {
            InputDoubleArrayConsole(arr, n);
            if (!arr)
                return 1;
        }
        else {
            std::cout << "Invalid input mode.\n";
            return 1;
        }

        std::cout << "Unsorted array:\n";
        PrintDoubleArray(arr, n);

        std::cout << "Select sorting algorithm:\n"
            << "1. Quick sort by descending fractional digit count\n"
            << "2. Insertion sort\n"
            << "3. Selection sort\n"
            << "4. Merge sort\n"
            << "5. Bubble sort (improved)\n"
            << "Choice: ";
        int sortMethod;
        std::cin >> sortMethod;

        bool ascending = true;
        if (sortMethod >= 2 && sortMethod <= 5) {
            std::cout << "Select order:\n1. Ascending\n2. Descending\nChoice: ";
            int order;
            std::cin >> order;
            ascending = (order == 1);
        }

        switch (sortMethod) {
        case 1:
            QuickSortCustom(arr, 0, n - 1);
            break;
        case 2:
            InsertionSort(arr, n, ascending);
            break;
        case 3:
            SelectionSort(arr, n, ascending);
            break;
        case 4:
            MergeSort(arr, n, ascending);
            break;
        case 5:
            BubbleSort(arr, n, ascending);
            break;
        default:
            std::cout << "Invalid sorting method.\n";
            delete[] arr;
            return 1;
        }

        std::cout << "Sorted array:\n";
        PrintDoubleArray(arr, n);

        if (inputMode == 2 || inputMode == 3) {
            std::string outFile;
            std::cout << "Enter output file name: ";
            std::cin >> outFile;
            WriteDoubleArrayToFile(outFile, arr, n);
            std::cout << "Sorted array written to file '" << outFile << "'.\n";
        }

        delete[] arr;
    }
    else if (moduleChoice == 2) {
        std::cout << "\nStudent array module selected.\n";
        Student* students = nullptr;
        int studentCount = 0;
        InputStudents(students, studentCount);
        if (!students)
            return 1;
        std::cout << "Select sorting order for students by average grade:\n"
            << "1. Ascending\n2. Descending\nChoice: ";
        int order;
        std::cin >> order;
        bool asc = (order == 1);
        SortStudentsByAverage(students, studentCount, asc);
        std::cout << "Sorted student list:\n";
        PrintStudents(students, studentCount);
        delete[] students;
    }
    else {
        std::cout << "Invalid module choice.\n";
        return 1;
    }
    return 0;
}
