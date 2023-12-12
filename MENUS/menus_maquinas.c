#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"

//  SUBTELAS MAQUINAS
//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson : https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

int maq_lista(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════"CYN" >> LISTA DE MAQUINAS << "BLU"══════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

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
                printf("\n||═══════════════════════════════════════════════════════════════════════════════||");
                printf("\n||               ID               ||                  %s             ", maq.id);
                printf("\n||               NOME             ||                  %s             ", maq.nome);
                printf("\n||═══════════════════════════════════════════════════════════════════════════════||");

                printf(BLU"\n\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

            }
        }
    }

    fclose(p);
    digite_zero();
}

int maq_pesquisa(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═══════════════════════════"CYN" >> PESQUISA DE MAQUINA << "BLU"═════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    struct maquinas maq;
    FILE *p;
    char id_maq[10];
    bool aux = true;
    
    limparBuffer();
    printf("\n             >> "CYN"Informe o ID da maquina: "RESET);
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
                    printf(BLU"\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}
//Salvamento em arquivo feito com base nos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=TqbnYUUdGjw&t=281s

int maq_cadas(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═══════════════════════════"CYN" >> CADASTRO DE MAQUINA << "BLU"═════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    struct maquinas maq;
    FILE *p;
    bool aux = true;

    p = fopen("ARQUIVOS/maquinas", "a+b");
    if (p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf("\n             >> "CYN"Informe o ID da maquina: "RESET);
        if(processo_ID_MAQ(maq.id)==0){
            return 0;
        }

        printf("Informe a maquina: ");
        scanf(" %19[^\n]", maq.nome);
        fwrite(&maq, sizeof(struct maquinas), 1, p);
            if (ferror(p)){
                printf("             >> "RED"ERRO NA GRAVAÇÃO"RESET" <<");
            }
            else{
                printf("             >> "GRN"GRAVAÇÃO OK"RESET" <<");
            }
        fclose(p);
    }
    printf(BLU"\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
    digite_zero();
}

int maq_edit(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════"CYN" >> EDITAR MAQUINA << "BLU"════════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    struct maquinas maq;
    FILE *p;
    char id_maq[10];
    bool aux = true;

    printf("\n             >> "CYN"Informe o ID da maquina a ser editada: "RESET);
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

                printf("\n             >> "GRN"MAQUINA EDITADA COM SUCESSO"RESET" <<");
            }
        }
        if (strcmp(maq.id, id_maq) != 0) {
            printf("\n             >> "RED"MAQUINA NAO ENCONTRADA"RESET" <<");
        }
    }
    fclose(p);
    printf(BLU"\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();
}

int maq_del(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════"CYN" >> DELETAR MAQUINA << "BLU"═══════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    struct maquinas maq;
    FILE *p, *p_temp;
    char id_maq[10];
    bool aux = true;

    printf("\n             >> "CYN"Informe o ID da maquina a ser deletada: "RESET);
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

        printf("\n             >> "GRN"MAQUINA DELETADA COM SUCESSO"RESET" <<");
    }
    printf(BLU"\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
    digite_zero();
}