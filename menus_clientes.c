#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "validacao.h"

// STRUCT

struct cliente{
    char cpf[12];
    char nome[100];
    char tel[12];
};

//  SUBTELAS CLIENTES
//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

int cli_lista(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct cliente novo;
    FILE *p;
    p = fopen("clientes", "a+b");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&novo, sizeof(struct cliente), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                printf("\nCPF [ %s ] ", novo.cpf);
                printf("\nNome [ %s ] ", novo.nome);
                printf("\nTelefone [ %s ] \n", novo.tel);
                printf("\n|---------------------------------------------------------------------------|\n");

            }
        }
    }

    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}

int cli_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  P E S Q U I S A  D E --------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}

//Salvamento em arquivo feito com base nos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=TqbnYUUdGjw&t=281s
int cli_cadas(){
    struct cliente novo;
    FILE *p;
    bool aux = true;
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");

    p = fopen("clientes", "a+b");
    if (p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf("Informe o nome do cliente: ");
        while(aux == true){
            scanf(" %99[^\n]", novo.nome);
            if(validarnome(novo.nome)){
                aux = false;
            }
            else{
                aux = true;
                printf("NOME INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
        printf("Informe o CPF do cliente: ");
        while(aux == false){
            scanf(" %11[^\n]", novo.cpf);
            if(validarCPF(novo.cpf)){
                aux = true;
            }
            else{
                aux = false;
                printf("CPF INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
        printf("Informe o Telefone do cliente: ");
        while(aux == true){
            scanf(" %11[^\n]", novo.tel);
            if(validartelefone(novo.tel)){
                aux = false;
            }
            else{
                aux = true;
                printf("TELEFONE INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }

        fwrite(&novo, sizeof(struct cliente), 1, p);
        if (ferror(p)){
            printf("\nERRO NA GRAVACAO\n");
        }
        else{
            printf("Gravacao OK\n");
        }
    fclose(p);
    }
    
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");
    scanf("%d", &resp);
    system("clear");
    return resp;
}

int cli_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int cli_del(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  D E L E T A R  -----------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}
