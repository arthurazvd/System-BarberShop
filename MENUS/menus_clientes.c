#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"


//  SUBTELAS CLIENTES

//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s
int cli_lista(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                    1 - L I S T A R  P O R  N O M E                        |\n");
    printf("|                    2 - L I S T A R  T U D O                               |\n");
    printf("|                    0 - V O L T A R                                        |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    switch(digite_opcao()){
        case 1:
            cli_fil_nome();
            break;
        case 2:
            cli_fil_tudo();
            break;
    }
}

int cli_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  P E S Q U I S A  D E --------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct cliente novo;
    FILE *p;
    char cpf_ip[12];
    bool aux = true;
    
    limparBuffer();
    printf("Informe o CPF do cliente: ");
    while(aux == true){
        scanf(" %11[^\n]", cpf_ip);
        if(validarCPF(cpf_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("CPF INVALIDO ");
            printf("\nDigite novamente: ");
        }
    }
    p = fopen("ARQUIVOS/clientes", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if(strcmp(novo.cpf,cpf_ip)==0){
                    printf("\nCPF [ %s ] ", novo.cpf);
                    printf("\nNome [ %s ] ", novo.nome);
                    printf("\nTelefone [ %s ] \n", novo.tel);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }
            }
        }
        if(strcmp(novo.cpf,cpf_ip) != 0){
            printf("\nCLIENTE NAO ENCONTRADO");
            printf("\n|---------------------------------------------------------------------------|\n");
        }
    }
    fclose(p);
    digite_zero();
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

    p = fopen("ARQUIVOS/clientes", "a+b");
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

    digite_zero();

}

int cli_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct cliente novo;
    FILE *p;
    char cpf_ip[12];
    bool aux = true;

    printf("\nInforme o CPF do cliente a ser editado: ");
    while(aux == true){
        scanf(" %11[^\n]", cpf_ip);
        if(validarCPF(cpf_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("CPF INVALIDO ");
            printf("\nDigite novamente: ");
        }
    }

    p = fopen("ARQUIVOS/clientes", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }

    while (fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)) {

        if (strcmp(novo.cpf, cpf_ip) == 0) {
            limparBuffer();
            printf("Informe o nome do cliente: ");
            while(aux == false){
                scanf(" %99[^\n]", novo.nome);
                if(validarnome(novo.nome)){
                    aux = true;
                }
                else{
                    aux = false;
                    printf("NOME INVALIDO ");
                    printf("\nDigite novamente: ");
                }
            }
            limparBuffer();
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

            fseek(p, -sizeof(struct cliente), SEEK_CUR);
            fwrite(&novo, sizeof(struct cliente), 1, p);

            break;
        }
    }
    fclose(p);
    printf("|---------------------------------------------------------------------------|\n");

    digite_zero();

}

int cli_del(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  D E L E T A R  -----------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct cliente novo;
    FILE *p, *p_temp;
    char cpf_ip[12];
    bool aux = true;

    printf("\nInforme o CPF do cliente a ser deletado: ");
    while(aux == true){
        scanf(" %11[^\n]", cpf_ip);
        if(validarCPF(cpf_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("CPF INVALIDO ");
            printf("\nDigite novamente: ");
        }
    }

    p = fopen("ARQUIVOS/clientes", "rb");
    p_temp = fopen("ARQUIVOS/clientes_temp", "wb");
    if (p == NULL || p_temp == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    } else {
        while (fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)) {
            if (strcmp(novo.cpf, cpf_ip) != 0) {
                fwrite(&novo, sizeof(struct cliente), 1, p_temp);
            }
        }
        fclose(p);
        fclose(p_temp);

        remove("ARQUIVOS/clientes");
        rename("ARQUIVOS/clientes_temp", "ARQUIVOS/clientes");

        printf("Cliente deletado com sucesso!\n");
    }
    printf("|---------------------------------------------------------------------------|\n");

    digite_zero();

}
