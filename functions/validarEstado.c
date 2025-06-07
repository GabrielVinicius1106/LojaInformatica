#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Lista das UFs válidas
const char* UFs[] = {
    "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA",
    "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN",
    "RS", "RO", "RR", "SC", "SP", "SE", "TO"
};

int validarUF(const char* uf) {
    for (int i = 0; i < 27; i++) {
        if (strcmp(uf, UFs[i]) == 0) {
            return 1;  // Válido
        }
    }
    return 0;  // Inválido
}

void lerUF(char* uf, size_t tamanho) {
    int valido = 0;
    while (!valido) {
        printf("\n Insira a UF (sigla com 2 letras): ");
        fgets(uf, tamanho, stdin);

        // Remove '\n' se existir
        uf[strcspn(uf, "\n")] = '\0';

        // Converte para MAIÚSCULO
        for (int i = 0; uf[i]; i++) {
            uf[i] = toupper(uf[i]);
        }

        if (strlen(uf) != 2) {
            printf("\n Erro: A sigla deve ter exatamente 2 letras. Insira novamente. \n");
            printf(" ------------------------------------------------------------- \n");
            continue;
        }

        if (validarUF(uf)) {
            valido = 1;
        } else {
            printf("\n Erro: UF invalida. Insira novamente. \n");
            printf(" ------------------------------------------------------------- \n");
        }
    }
}