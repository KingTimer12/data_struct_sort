#pragma once

#ifdef _WIN32
    #define CLEAR "cls"
    #define PAUSE_MSG "Pressione qualquer tecla para continuar..."
#else
    #define CLEAR "clear"
    #define PAUSE_MSG "Pressione ENTER para continuar..."
#endif

namespace Console {
    void clean();
    void pause();
    void print(int *vector, int *end);
};
