#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#include "utils/console.h"
#include "sorts/bubblesort.h"
#include "sorts/quicksort.h"
#include "sorts/selectionsort.h"

#define VECTOR_SIZE 10

void insert(int *vector, int *pos) {
    int key;
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &key);
    if (*pos >= VECTOR_SIZE) {
        printf("Vetor cheio!\n");
        return;
    }
    vector[(*pos)++] = key;
}

void sorting(int* vector, int* end) {
    int key;
    Console::clean();
    printf("Menu de Ordenacao:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Selection Sort\n");
    printf("0. Voltar\n");
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &key);

    if (key >= 1 && key <= 3) {
        clock_t inicio, fim;
        double tempo_total;

        inicio = clock();

        if (key == 1) BubbleSort::sort(vector, end); // 0.001312 segundos
        else if (key == 2) QuickSort::sort(vector, end); // 0.000499 segundos
        else if (key == 3) SelectionSort::sort(vector, end); //0.000883 segundos

        fim = clock();
        tempo_total = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        printf("Tempo de execucao: %.6f segundos\n", tempo_total);
    }
    else if (key == 0) return;
    else printf("Opção inválida!\n");
}

int main() {
    int opcao, end = VECTOR_SIZE;
    int vector[VECTOR_SIZE] = {42, 17, 89, 33, 61, 5, 27, 72, 94, 11};

    do {
        Console::clean();
        printf("Menu:\n");
        // printf("1. Inserir\n");
        printf("2. Imprimir\n");
        printf("3. Ordenar\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            // case 1:
            //     insert(vector, &end);
            //     break;
            case 2:
                Console::print(vector, &end);
                break;
            case 3:
                sorting(vector, &end);
                break;
            case 0:
                break;
            default:
                printf("Opcao inválida!\n");
                break;
        }
        if (opcao != 0) Console::pause();
    } while (opcao != 0);

    return 0;
}
