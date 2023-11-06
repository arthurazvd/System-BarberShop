#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"

// STRUCT

struct horario{
    char cpf_cli[12];
    char data[11];
    char hora[3];
    char minuto[3];
};

//  SUBTELAS AGENDAMENTO

//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

int agd_horario(){
    struct horario nh;
    FILE *p;
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------  A G E N D A D O S  ---------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
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

    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}

int agd_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  P E S Q U I S A  ----------------------------|\n");
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
int agd_agendar(){
    
    struct horario nh;
    FILE *p;
    bool aux = true;    
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  A G E N D A R  -----------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");

    p = fopen("ARQUIVOS/horarios", "a+b");
    if (p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf("Informe o CPF do cliente: ");
        while(aux == true){
            scanf(" %11[^\n]", nh.cpf_cli);
            if(validarCPF(nh.cpf_cli)){
                aux = false;
            }
            else{
                aux = true;
                printf("CPF INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
        printf("Informe o data a agendar ");
        //aqui ele vai ter que validar se aquele horario está disponivel 
        while(aux == false){
            printf("\nData: ");
            scanf(" %10[^\n]", nh.data);

            if(validardata(nh.data)){
                aux = true;
            }
            else{
                aux = false;
                printf("DATA INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
        printf("Informe o hora a agendar ");
        //aqui ele vai ter que validar se aquele horario está disponivel 
        while(aux == true){
            printf("\nHora: ");
            scanf(" %3[^\n]", nh.hora);
            printf("Minuto: ");
            scanf(" %3[^\n]", nh.minuto);
            if(validarhora(nh.hora, nh.minuto)){
                aux = false;
            }
            else{
                aux = true;
                printf("HORA INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
    }
    fwrite(&nh, sizeof(struct horario), 1, p);
        if (ferror(p)){
            printf("\nERRO NA GRAVACAO\n");
        }
        else{
            printf("Gravacao OK\n");
        }
    fclose(p);
    
    printf("|---------------------------------------------------------------------------|\n");


    int resp;
    printf("\nD I G I T E   0   P A R A   V O L T A R : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int agd_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|-----------------------------  H O R A R I O  -----------------------------|\n");
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

int agd_cancelamento(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C A N C E L A R  ----------------------------|\n");
    printf("|-----------------------------  H O R A R I O  -----------------------------|\n");
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
