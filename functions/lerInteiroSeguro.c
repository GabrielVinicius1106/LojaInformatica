#include <stdio.h>
#include "lerInteiroSeguro.h"

int lerInteiroSeguro() {
    char buffer[100];
    int valor;
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            
            // Tenta converter string para inteiro
            if (sscanf(buffer, "%d", &valor) == 1) {
                return valor;
            } else {
                return 0;
            }
        }
    }
}

