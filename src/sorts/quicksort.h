#pragma once

#include <iostream>

namespace QuickSort {
    void printInfo(int *vector, int start, int end, int pivot);
    int partition(int *vector, int start, int end);
    void quickSort(int *vector, int start, int end, int size);
    void sort(int *vector, int *end);
};