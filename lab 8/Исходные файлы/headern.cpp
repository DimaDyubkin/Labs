#include "headern.h"

void InputDoubleArrayConsole(double*& arr, int& n) {
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Invalid size.\n";
        arr = nullptr;
        return;
    }
    arr = new double[n];
    std::cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

bool ReadDoubleArrayFromFile(const std::string& filename, double*& arr, int& n) {
    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cout << "Failed to open file: " << filename << "\n";
        return false;
    }
    n = 0;
    double tmp;
    while (infile >> tmp) {
        n++;
    }
    if (n == 0) {
        std::cout << "No data in file.\n";
        infile.close();
        return false;
    }
    arr = new double[n];
    infile.clear();
    infile.seekg(0, std::ios::beg);
    for (int i = 0; i < n; i++) {
        infile >> arr[i];
    }
    infile.close();
    return true;
}

void PrintDoubleArray(const double* arr, int n) {
    std::cout << "Array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void WriteDoubleArrayToFile(const std::string& filename, const double* arr, int n) {
    std::ofstream outfile(filename.c_str());
    if (!outfile) {
        std::cout << "Failed to open file for writing: " << filename << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        outfile << arr[i] << " ";
    }
    outfile << "\n";
    outfile.close();
}

int CountFractionDigits(double x) {
    double frac = fabs(x) - floor(fabs(x));
    int count = 0;
    const double eps = 1e-9;
    while (frac > eps && count < 15) {
        frac *= 10;
        frac -= floor(frac);
        count++;
    }
    return count;
}

void QuickSortCustom(double arr[], int left, int right) {
    if (left >= right)
        return;
    double pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (CountFractionDigits(arr[i]) > CountFractionDigits(pivot))
            i++;
        while (CountFractionDigits(arr[j]) < CountFractionDigits(pivot))
            j--;
        if (i <= j) {
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSortCustom(arr, left, j);
    if (i < right)
        QuickSortCustom(arr, i, right);
}

void InsertionSort(double arr[], int n, bool ascending) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        if (ascending) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(double arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        int target = i;
        for (int j = i + 1; j < n; j++) {
            if (ascending) {
                if (arr[j] < arr[target])
                    target = j;
            }
            else {
                if (arr[j] > arr[target])
                    target = j;
            }
        }
        double temp = arr[i];
        arr[i] = arr[target];
        arr[target] = temp;
    }
}

void Merge(double arr[], int left, int mid, int right, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    double* L = new double[n1];
    double* R = new double[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (ascending ? (L[i] <= R[j]) : (L[i] >= R[j])) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void MergeSortRec(double arr[], int left, int right, bool ascending) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSortRec(arr, left, mid, ascending);
    MergeSortRec(arr, mid + 1, right, ascending);
    Merge(arr, left, mid, right, ascending);
}

void MergeSort(double arr[], int n, bool ascending) {
    MergeSortRec(arr, 0, n - 1, ascending);
}

void BubbleSort(double arr[], int n, bool ascending) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (ascending ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1])) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

double AverageGrade(const Student& s) {
    double sum = 0;
    for (int i = 0; i < 5; i++)
        sum += s.grades[i];
    return sum / 5.0;
}

void InputStudents(Student*& students, int& n) {
    std::cout << "Enter number of students: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Invalid number.\n";
        students = nullptr;
        return;
    }
    students = new Student[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Student " << i + 1 << ":\n";
        std::cout << "  First name: ";
        std::cin >> students[i].firstName;
        std::cout << "  Last name: ";
        std::cin >> students[i].lastName;
        std::cout << "  Course: ";
        std::cin >> students[i].course;
        std::cout << "  Group: ";
        std::cin >> students[i].group;
        std::cout << "  Enter 5 grades: ";
        for (int j = 0; j < 5; j++) {
            std::cin >> students[i].grades[j];
        }
    }
}

void PrintStudents(const Student* students, int n) {
    std::cout << "Student list:\n";
    for (int i = 0; i < n; i++) {
        double avg = AverageGrade(students[i]);
        std::cout << students[i].firstName << " " << students[i].lastName
            << ", Course: " << students[i].course
            << ", Group: " << students[i].group
            << ", Average grade: " << avg << "\n";
    }
}

void SortStudentsByAverage(Student* students, int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        int target = i;
        for (int j = i + 1; j < n; j++) {
            if (ascending) {
                if (AverageGrade(students[j]) < AverageGrade(students[target]))
                    target = j;
            }
            else {
                if (AverageGrade(students[j]) > AverageGrade(students[target]))
                    target = j;
            }
        }
        Student temp = students[i];
        students[i] = students[target];
        students[target] = temp;
    }
}
