#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

struct Student {
    std::string firstName;
    std::string lastName;
    int course;
    std::string group;
    int grades[5];
};

void InputDoubleArrayConsole(double*& arr, int& n);

bool ReadDoubleArrayFromFile(const std::string& filename, double*& arr, int& n);

void PrintDoubleArray(const double* arr, int n);

void WriteDoubleArrayToFile(const std::string& filename, const double* arr, int n);

int CountFractionDigits(double x);

void QuickSortCustom(double arr[], int left, int right);

void InsertionSort(double arr[], int n, bool ascending);

void SelectionSort(double arr[], int n, bool ascending);

void Merge(double arr[], int left, int mid, int right, bool ascending);

void MergeSortRec(double arr[], int left, int right, bool ascending);

void MergeSort(double arr[], int n, bool ascending);

void BubbleSort(double arr[], int n, bool ascending);

double AverageGrade(const Student& s);

void InputStudents(Student*& students, int& n);

void PrintStudents(const Student* students, int n);

void SortStudentsByAverage(Student* students, int n, bool ascending);
