#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTOR_SIZE 10

#ifdef _WIN32
    #define CLEAR "cls"
    #define PAUSE_MSG "Pressione qualquer tecla para continuar..."
#else
    #define CLEAR "clear"
    #define PAUSE_MSG "Pressione ENTER para continuar..."
#endif

void print(int *vector, int *end) {
    printf("[");
    for(int i = 0; i < *end; i++) {
        printf("%d", vector[i]);
        if (i < *end - 1) printf(" | ");
    }
    printf("]\n");
}

void clearConsole() {
    system(CLEAR);
}

void pauseConsole() {
    printf("\n%s", PAUSE_MSG);
    getchar();
    if (getchar() != '\n');
}

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

void bubbleSort(int *vector, int *end) {
    int i, j, temp;
    clearConsole();
    for (i = 0; i < *end - 1; i++) {
        for (j = 0; j < *end - i - 1; j++) {
            printf("[");
            for (int k = 0; k < *end; k++) {
                if (k == j) printf("\033[1;32m%d\033[0m", vector[k]);
                else if (k == j + 1) printf("\033[1;31m%d\033[0m", vector[k]);
                else if (k >= *end - i) printf("\033[1;33m%d\033[0m", vector[k]);
                else printf("%d", vector[k]);
                if (k < *end - 1) printf(" | ");
            }
            printf("]\n");

            if (vector[j] > vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
                printf("[");
                for (int k = 0; k < *end; k++) {
                    if (k == j) printf("\033[1;31m%d\033[0m", vector[k]);
                    else if (k == j + 1) printf("\033[1;32m%d\033[0m", vector[k]);
                    else if (k >= *end - i) printf("\033[1;33m%d\033[0m", vector[k]);
                    else printf("%d", vector[k]);
                    if (k < *end - 1) printf(" | ");
                }
                printf("]\n");
            }
        }
    }
    
    printf("Ordenação Bubble Sort concluída!\n\n");
    printf("Resultado final: ");
    print(vector, end);
}

void sorting(int* vector, int* end) {
    int key;
    clearConsole();
    printf("Menu de Ordenação:\n");
    printf("1. Bubble Sort\n");
    printf("0. Voltar\n");
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &key);
    
    if (key == 1) bubbleSort(vector, end);
    else if (key == 0) return;
    else printf("Opção inválida!\n");
}

int main(int argc, char **argv) {
    int opcao, end = 0;
    int vector[VECTOR_SIZE];
    
    do {
        clearConsole();
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
                print(vector, &end);
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
        if (opcao != 0) pauseConsole();
    } while (opcao != 0);
    
    return 0;
}
