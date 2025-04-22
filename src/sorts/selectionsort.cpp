#include "selectionsort.h"
#include <cstdlib>
#include "../utils/console.h"

void SelectionSort::printInfo(int *vector, int &end, int &j, int &i) {
    printf("[");
    for (int k = 0; k < end; k++) {
        if (k == i) printf("\033[1;32m%d\033[0m", vector[k]);
        else if (k == j) printf("\033[1;31m%d\033[0m", vector[k]);
        else if (k >= end - i) printf("\033[1;33m%d\033[0m", vector[k]);
        else printf("%d", vector[k]);
        if (k < end - 1) printf(" | ");
    }
    printf("]\n");
}

void SelectionSort::sort(int *vector, int *end) {
    int i, j, min_idx, temp;
    Console::clean();

    for (i = 0; i < *end - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < *end; j++) {
            printInfo(vector, *end, j, min_idx);
            if (vector[j] < vector[min_idx]) min_idx = j;
        }

        if (min_idx != i) {
            temp = vector[i];
            vector[i] = vector[min_idx];
            vector[min_idx] = temp;
            printInfo(vector, *end, min_idx, i);
        }
    }

    printf("Ordenacao Selection Sort concluida!\n\n");
    printf("Resultado final: ");
    Console::print(vector, end);
}
