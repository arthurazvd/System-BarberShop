#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


//desenvolvido a partir do chatGPT - foi testada e aprovada
bool validarnome(char *nome) {
    if (nome == NULL || nome[0] == '\0') {
        return false; // O nome está vazio
    }

    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return false; // Caractere não é uma letra nem espaço
        }
    }

    return true; // Nome válido
}