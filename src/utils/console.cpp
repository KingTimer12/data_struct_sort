#include "console.h"
#include <iostream>
#include <cstdlib>

void Console::clean() {
    system(CLEAR);
}

void Console::pause() {
    std::cout << PAUSE_MSG << std::endl;
    std::cin.ignore();
    std::cin.get();
}

void Console::print(int *vector, int *end) {
    printf("[");
    for(int i = 0; i < *end; i++) {
        printf("%d", vector[i]);
        if (i < *end - 1) printf(" | ");
    }
    printf("]\n");
}