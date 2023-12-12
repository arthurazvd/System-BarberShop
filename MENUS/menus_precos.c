#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"

//  SUBTELAS TABELA DE PRECOS
//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

int pre_lista(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|---------------------------  T A B E L A  D E  ----------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                 1 - L I S T A R  P O R  S E R V I C O                     |\n");
    printf("|                 2 - L I S T A R  T U D O                                  |\n");
    printf("|                 0 - V O L T A R                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    switch(digite_opcao()){
        case 1:
            pre_fil_serv();
            break;
        case 2:
            pre_fil_tudo();
            break;
    }
}

int pre_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  P E S Q U I S A  D E --------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct precos pr;
    FILE *p;
    char id_pre[10];
    bool aux = true;
    
    limparBuffer();
    p = fopen("ARQUIVOS/precos", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }

    printf("Informe o ID do servico: ");
    if(processo_ID_PRE(pr.id)==0){
        return 0;
    }

    while(fread(&pr, sizeof(struct precos), 1, p) && !feof(p)){
        if(ferror(p)){
        printf("\nERRO NA LEITURA\n");
        }
        else{
            if (pr.status == 1){
                if(strcmp(pr.id,id_pre) == 0){
                    printf("\nID [ %s ] ", pr.id);
                    printf("\nServico [ %s ] ", pr.servico);
                    printf("\nPreco R$ [ %s ] \n", pr.preco);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }                
            }
        }
    }
    fclose(p);
    digite_zero();
}
//Salvamento em arquivo feito com base nos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=TqbnYUUdGjw&t=281s

int pre_cadas(){

    
    struct precos pr;
    FILE *p;
    bool aux = true;
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");

    p = fopen("ARQUIVOS/precos", "a+b");
    if (p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf("Informe o ID do servico: ");
        if(processo_ID_PRE_CAD(pr.id)==0){
            return 0;
        }

        printf("Informe o servico: ");
        if(processo_Servico(pr.servico)==0){
            return 0;
        }

        printf("Informe o preco: ");
        if(processo_Preco(pr.preco)==0){
            return 0;
        }

        pr.status = 1;

        fwrite(&pr, sizeof(struct precos), 1, p);
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

int pre_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct precos pr;
    FILE *p;
    char id_pre[10];
    bool aux = true;

    p = fopen("ARQUIVOS/precos", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);

    }

    printf("\nInforme o ID do servico a ser editado: ");
    while(aux == true){
        scanf(" %9[^\n]", id_pre);
        if(validarnumero(id_pre)){
            if (checkidpre(id_pre))
            {
                aux = false;
            }
            else{
                aux = true;
                char text[50] = "             >> "RED"ID JA CADASTRADO"RESET" << ";
                if (processo_Continuar(text)==0){
                    return 0;
                }
            }
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"ID INVALIDO"RESET" << ";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
    while (fread(&pr, sizeof(struct precos), 1, p) && !feof(p)) {
        if (strcmp(pr.id, id_pre) == 0) {
            printf("Informe o novo servico: ");
            if(processo_Servico(pr.servico)==0){
                return 0;
            }

            printf("Informe o novo preco: ");
            if(processo_Preco(pr.preco)==0){
                return 0;
            }

            fseek(p, -sizeof(struct precos), SEEK_CUR);
            fwrite(&pr, sizeof(struct precos), 1, p);

            printf("Preco editado com sucesso!\n");
        }
    }
    if (strcmp(pr.id, id_pre) != 0) {
        printf("Preco nao encontrado!\n");
    }
    fclose(p);
    printf("|---------------------------------------------------------------------------|\n");

    digite_zero();

}

int pre_del(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  D E L E T A R  -----------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct precos pr;
    FILE *p;
    char id_pre[10];
    bool aux = true;

    printf("\nInforme o ID do servico a ser deletado: ");
    while(aux == true){
        scanf(" %9[^\n]", id_pre);
        if(validarnumero(id_pre)){
            if (checkidpre(id_pre))
            {
                aux = false;
            }
            else{
                aux = true;
                char text[50] = "             >> "RED"ID JA CADASTRADO"RESET" << ";
                if (processo_Continuar(text)==0){
                    return 0;
                }
            }
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"ID INVALIDO"RESET" << ";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }

    p = fopen("ARQUIVOS/precos", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    } else {
        while (fread(&pr, sizeof(struct precos), 1, p) && !feof(p)) {
            if (strcmp(pr.id, id_pre) == 0) {

                pr.status = 0;

                fseek(p, -sizeof(struct precos), SEEK_CUR);
                fwrite(&pr, sizeof(struct precos), 1, p);

                printf("Preco deletado com sucesso!\n");
            }
        }
        if (strcmp(pr.id, id_pre) != 0) {
            printf("Preco nao encontrado!\n");
        }
    }
    fclose(p);
    printf("|---------------------------------------------------------------------------|\n");

    digite_zero();

}
