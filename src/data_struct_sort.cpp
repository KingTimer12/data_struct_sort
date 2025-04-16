#include <stdio.h>
#include <stdlib.h>

#include "utils/console.h"
#include "sorts/bubblesort.h"

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
    printf("Menu de Ordenação:\n");
    printf("1. Bubble Sort\n");
    printf("0. Voltar\n");
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &key);
    
    if (key == 1) BubbleSort::sort(vector, end);
    else if (key == 0) return;
    else printf("Opção inválida!\n");
}

int main() {
    int opcao, end = 0;
    int vector[VECTOR_SIZE];
    
    do {
        Console::clean();
        printf("Menu:\n");
        printf("1. Inserir\n");
        printf("2. Imprimir\n");
        printf("3. Ordenar\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                insert(vector, &end);
                break;
            case 2:
                Console::print(vector, &end);
                break;
            case 3:
                sorting(vector, &end);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
        if (opcao != 0) Console::pause();
    } while (opcao != 0);
    
    return 0;
}
