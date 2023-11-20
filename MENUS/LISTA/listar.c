#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../UTILITARIOS/includes.h"

//Leitorres de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

//####################################### LISTAR CLIENTES #################################################
int cli_fil_nome(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct cliente novo;
    FILE *p;
    char nome_ip[100];
    bool aux = true;
    
    limparBuffer();
    printf("Informe o CPF do cliente: ");
    while(aux == true){
        scanf(" %99[^\n]", nome_ip);
        if(validarnome(nome_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("NOME INVALIDO ");
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
                if(strcmp(novo.nome,nome_ip)==0){
                    printf("\nCPF [ %s ] ", novo.cpf);
                    printf("\nNome [ %s ] ", novo.nome);
                    printf("\nTelefone [ %s ] \n", novo.tel);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }
            }
        }
        if(strcmp(novo.nome,nome_ip) != 0){
            printf("\nCLIENTE NAO ENCONTRADO");
            printf("\n|---------------------------------------------------------------------------|\n");
        }
    }
    fclose(p);
    digite_zero();
}

int cli_fil_tudo(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct cliente novo;
    FILE *p;
    p = fopen("ARQUIVOS/clientes", "rb");
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
    fclose(p);
    digite_zero();
}

//####################################### LISTAR HORARIOS #################################################
int agd_fil_data(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------  A G E N D A D O S  ---------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct horario nh;
    FILE *p;
    char data_ip[11];
    bool aux = true;
    
    limparBuffer();
    printf("Informe a DATA: ");
    while(aux == true){
        scanf(" %10[^\n]", data_ip);
        if(validardata(data_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("DATA INVALIDA");
            printf("\nDigite novamente: ");
        }
    }
    p = fopen("ARQUIVOS/horarios", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&nh, sizeof(struct horario), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if(strcmp(nh.data,data_ip)==0){
                    printf("\nCPF [ %s ] ", nh.cpf_cli);
                    printf("\nData [ %s ] ", nh.data);
                    printf("\nHora [ %s ] ", nh.hora);
                    printf("\nMinuto [ %s ] \n", nh.minuto);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }
            }
        }
        if(strcmp(nh.data,data_ip) != 0){
            printf("\nHORARIO NAO ENCONTRADO");
            printf("\n|---------------------------------------------------------------------------|\n");
        }
    }
    fclose(p);
    digite_zero();
}

int agd_fil_tudo(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------  A G E N D A D O S  ---------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct horario nh;
    FILE *p;
    p = fopen("ARQUIVOS/horarios", "a+b");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&nh, sizeof(struct horario), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                printf("\nCPF [ %s ] ", nh.cpf_cli);
                printf("\nData [ %s ] ", nh.data);
                printf("\nHora [ %s ] ", nh.hora);
                printf("\nMinuto [ %s ] \n", nh.minuto);
                printf("\n|---------------------------------------------------------------------------|\n");
            }
        }
    }
    fclose(p);
    digite_zero();
}

//####################################### LISTAR PRECOS #################################################

int pre_fil_serv(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|---------------------------  T A B E L A  D E  ----------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct precos pr;
    FILE *p;
    char serv_ip[25];
    bool aux = true;
    
    limparBuffer();
    printf("Informe o servico: ");
    while(aux == true){
        scanf(" %24[^\n]", serv_ip);

        if(validarnome(serv_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("SERVICO INVALIDO ");
            printf("\nDigite novamente: ");
        }
    }
    p = fopen("ARQUIVOS/precos", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&pr, sizeof(struct precos), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if(strcmp(pr.servico,serv_ip) == 0){
                    printf("\nID [ %s ] ", pr.id);
                    printf("\nServico [ %s ] ", pr.servico);
                    printf("\nPreco R$ [ %s ] \n", pr.preco);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }
            }
        }
        if(strcmp(pr.servico,serv_ip) != 0){
            printf("\nPRECO NAO ENCONTRADO");
            printf("\n|---------------------------------------------------------------------------|\n");
        }
    }
    fclose(p);
    digite_zero();
}

int pre_fil_tudo(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|---------------------------  T A B E L A  D E  ----------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct precos pr;
    FILE *p;
    p = fopen("ARQUIVOS/precos", "a+b");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&pr, sizeof(struct precos), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                printf("\nID [ %s ] ", pr.id);
                printf("\nServico [ %s ] ", pr.servico);
                printf("\nPreco R$ [ %s ] \n", pr.preco);
                printf("\n|---------------------------------------------------------------------------|\n");

            }
        }
    }

    fclose(p);
    digite_zero();
}
