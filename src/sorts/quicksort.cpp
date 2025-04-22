#include "quicksort.h"
#include <cstdlib>
#include "../utils/console.h"

void QuickSort::printInfo(int *vector, int start, int end, int pivot) {
    printf("[");
    for (int k = 0; k < end; k++) {
        if (k == pivot) printf("\033[1;32m%d\033[0m", vector[k]);
        else if (k >= start && k <= end - 1) printf("\033[1;31m%d\033[0m", vector[k]);
        else printf("%d", vector[k]);
        if (k < end - 1) printf(" | ");
    }
    printf("]\n");
}

int QuickSort::partition(int *vector, int start, int end) {
    int pivot = vector[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (vector[j] < pivot) {
            i++;
            int temp = vector[i];
            vector[i] = vector[j];
            vector[j] = temp;
        }
    }
    int temp = vector[i + 1];
    vector[i + 1] = vector[end];
    vector[end] = temp;
    return (i + 1);
}

void QuickSort::quickSort(int *vector, int start, int end, int size) {
    if (start < end) {
        printInfo(vector, start, size, end);
        int pivot = partition(vector, start, end);
        printInfo(vector, start, size, pivot);

        quickSort(vector, start, pivot - 1, size);
        quickSort(vector, pivot + 1, end, size);
    }
}

void QuickSort::sort(int *vector, int *end) {
    Console::clean();
    quickSort(vector, 0, *end - 1, *end);

    printf("Ordenacao QuickSort concluida!\n\n");
    printf("Resultado final: ");
    Console::print(vector, end);
}
