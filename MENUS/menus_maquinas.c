#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"

//  SUBTELAS MAQUINAS
//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson : https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

int maq_lista(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  M A Q U I N A S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct maquinas maq;
    FILE *p;
    p = fopen("ARQUIVOS/maquinas", "a+b");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&maq, sizeof(struct maquinas), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                printf("\nID [ %s ] ", maq.id);
                printf("\nNome [ %s ] \n", maq.nome);
                printf("\n|---------------------------------------------------------------------------|\n");

            }
        }
    }

    fclose(p);
    digite_zero();
}

int maq_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  P E S Q U I S A  D E --------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct maquinas maq;
    FILE *p;
    char id_maq[10];
    bool aux = true;
    
    limparBuffer();
    printf("Informe o ID da maquina: ");
    if(processo_ID_MAQ(maq.id)==0){
        return 0;
    }

    p = fopen("ARQUIVOS/maquinas", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&maq, sizeof(struct maquinas), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if(strcmp(maq.id,id_maq) == 0){
                    printf("\nID [ %s ] ", maq.id);
                    printf("\nNome [ %s ] \n", maq.nome);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}
//Salvamento em arquivo feito com base nos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=TqbnYUUdGjw&t=281s

int maq_cadas(){

    struct maquinas maq;
    FILE *p;
    bool aux = true;
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    p = fopen("ARQUIVOS/maquinas", "a+b");
    if (p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf("Informe o ID da maquina: ");
        if(processo_ID_MAQ(maq.id)==0){
            return 0;
        }

        printf("Informe a maquina: ");
        scanf(" %19[^\n]", maq.nome);
        fwrite(&maq, sizeof(struct maquinas), 1, p);
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

int maq_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");

    struct maquinas maq;
    FILE *p;
    char id_maq[10];
    bool aux = true;

    printf("\nInforme o ID da máquina a ser editada: ");
    while(aux == true){
        scanf(" %9[^\n]", id_maq);

        if(validarnumero(id_maq)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"ID INVALIDO"RESET" << ";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }


    p = fopen("ARQUIVOS/maquinas", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    } else {
        while (fread(&maq, sizeof(struct maquinas), 1, p) && !feof(p)) {
            if (strcmp(maq.id, id_maq) == 0) {

                printf("Informe a nova máquina: ");
                scanf(" %19[^\n]", maq.nome);
                maq.nome[strcspn(maq.nome, "\n")] = '\0';

                fseek(p, -sizeof(struct maquinas), SEEK_CUR);
                fwrite(&maq, sizeof(struct maquinas), 1, p);

                printf("Máquina editada com sucesso!\n");
            }
        }
        if (strcmp(maq.id, id_maq) != 0) {
            printf("Máquina não encontrada!\n");
        }
    }
    fclose(p);
    printf("|---------------------------------------------------------------------------|\n");

    digite_zero();
}

int maq_del(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  D E L E T A R  -----------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct maquinas maq;
    FILE *p, *p_temp;
    char id_maq[10];
    bool aux = true;

    printf("\nInforme o ID da maquina a ser deletado: ");
    while(aux == true){
        scanf(" %9[^\n]", id_maq);

        if(validarnumero(id_maq)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"ID INVALIDO"RESET" << ";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }


    p = fopen("ARQUIVOS/maquinas", "rb");
    p_temp = fopen("ARQUIVOS/maquinas_temp", "wb");
    if (p == NULL || p_temp == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    } else {
        while (fread(&maq, sizeof(struct maquinas), 1, p) && !feof(p)) {
            if (strcmp(maq.id, id_maq) != 0) {
                fwrite(&maq, sizeof(struct maquinas), 1, p_temp);
            }
        }
        fclose(p);
        fclose(p_temp);

        remove("ARQUIVOS/maquinas");
        rename("ARQUIVOS/maquinas_temp", "ARQUIVOS/maquinas");

        printf("Maquina deletada com sucesso!\n");
    }
    printf("|---------------------------------------------------------------------------|\n");
    digite_zero();
}