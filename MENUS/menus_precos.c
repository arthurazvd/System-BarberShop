#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"

//  SUBTELAS TABELA DE PRECOS
//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

int pre_lista(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════" CYN " >> TABELA DE PRECOS << " BLU "══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                            1 "CYN"- LISTAR POR SERVICO"BLU"                             ||\n");
    printf("||                            2 "CYN"- LISTAR TUDO"BLU"                                    ||\n");
    printf("||                            0 "CYN"- VOLTAR"BLU"                                         ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

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
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════" CYN " >> PESQUISA DE PRECO << " BLU "══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
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

    printf("\n             >> "CYN"Informe o ID do servico: "RESET);
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
                    printf("\n             >> ID: "MAG"%s"RESET"", pr.id);
                    printf("\n             >> Servico: "MAG"%s"RESET"", pr.servico);
                    printf("\n             >> Preco R$: "MAG"%s"RESET" \n", pr.preco);
                    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
                }                
            }
        }
    }
    fclose(p);
    digite_zero();
}
//Salvamento em arquivo feito com base nos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=TqbnYUUdGjw&t=281s

int pre_cadas(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════" CYN " >> CADASTRO DE PRECO << " BLU "══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct precos pr;
    FILE *p;
    bool aux = true;
    p = fopen("ARQUIVOS/precos", "a+b");
    if (p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf("\n             >> "CYN"Informe o ID do servico: "RESET);
        if(processo_ID_PRE_CAD(pr.id)==0){
            return 0;
        }

        printf("\n             >> "CYN"Informe o Servico: "RESET);
        if(processo_Servico(pr.servico)==0){
            return 0;
        }

        printf("\n             >> "CYN"Informe o Preco: "RESET);
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
        
    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();
}

int pre_edit(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═══════════════════════════════" CYN " >> EDITAR PRECO << " BLU "════════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct precos pr;
    FILE *p;
    char id_pre[10];
    bool aux = true;

    p = fopen("ARQUIVOS/precos", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);

    }

    printf("\n             >> "CYN"Informe o ID do servico a ser editado: "RESET);
    while(aux == true){
        scanf(" %9[^\n]", id_pre);
        if(validarnumero(id_pre)){
            if (checkidpre(id_pre))
            {
                aux = false;
            }
            else{
                aux = true;
                char text[50] = "             >> "RED"ID NAO CADASTRADO"RESET" << ";
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
            printf("\n             >> "CYN"Informe o NOVO Servico: "RESET);
            if(processo_Servico(pr.servico)==0){
                return 0;
            }

            printf("\n             >> "CYN"Informe o NOVO Preco: "RESET);
            if(processo_Preco(pr.preco)==0){
                return 0;
            }

            fseek(p, -sizeof(struct precos), SEEK_CUR);
            fwrite(&pr, sizeof(struct precos), 1, p);

            printf("\n             >> "GRN"PRECO EDITADO COM SUCESSO"RESET" <<");
        }
    }
    if (strcmp(pr.id, id_pre) != 0) {
        printf("\n             >> "RED"PRECO NAO ENCONTRADO"RESET" <<");
    }
    fclose(p);
    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();

}

int pre_del(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═══════════════════════════════" CYN " >> DELETAR PRECO << " BLU "═══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct precos pr;
    FILE *p;
    char id_pre[10];
    bool aux = true;

    printf("\n             >> "CYN"Informe o ID do servico a ser deletado: "RESET);
    while(aux == true){
        scanf(" %9[^\n]", id_pre);
        if(validarnumero(id_pre)){
            if (checkidpre(id_pre))
            {
                aux = false;
            }
            else{
                aux = true;
                char text[50] = "             >> "RED"ID NAO CADASTRADO"RESET" << ";
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

                printf("\n             >> "GRN"PRECO DELETADO COM SUCESSO"RESET" <<");
            }
        }
        if (strcmp(pr.id, id_pre) != 0) {
            printf("\n             >> "RED"PRECO NAO ENCONTRADO"RESET" <<");
        }
    }
    fclose(p);
    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();

}
