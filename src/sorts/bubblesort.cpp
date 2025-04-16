#include "bubblesort.h"
#include <cstdlib>
#include "../utils/console.h"

void BubbleSort::printInfo(int *vector, int &end, int &j, int &i) {
    printf("[");
    for (int k = 0; k < end; k++) {
        if (k == j) printf("\033[1;32m%d\033[0m", vector[k]);
        else if (k == j + 1) printf("\033[1;31m%d\033[0m", vector[k]);
        else if (k >= end - i) printf("\033[1;33m%d\033[0m", vector[k]);
        else printf("%d", vector[k]);
        if (k < end - 1) printf(" | ");
    }
    printf("]\n");
}

void BubbleSort::sort(int *vector, int *end) {
    int i, j, temp;
    Console::clean();
    for (i = 0; i < *end - 1; i++) {
        for (j = 0; j < *end - i - 1; j++) {
            printInfo(vector, *end, j, i);

            if (vector[j] > vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
                printInfo(vector, *end, j, i);
            }
        }
    }
    
    printf("Ordenação Bubble Sort concluída!\n\n");
    printf("Resultado final: ");
    Console::print(vector, end);
}