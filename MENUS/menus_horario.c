#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"

//  SUBTELAS AGENDAMENTO

//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

int agd_horario(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------  A G E N D A D O S  ---------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                    1 - L I S T A R  P O R  D A T A                        |\n");
    printf("|                    2 - L I S T A R  T U D O                               |\n");
    printf("|                    0 - V O L T A R                                        |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    switch(digite_opcao()){
        case 1:
            agd_fil_data();
            break;
        case 2:
            agd_fil_tudo();
            break;
    }
}

int agd_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  P E S Q U I S A  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct horario nh;
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
                if(strcmp(nh.cpf_cli,cpf_ip)==0){
                    printf("\nCPF [ %s ] ", nh.cpf_cli);
                    printf("\nData [ %s ] ", nh.data);
                    printf("\nHora [ %s ] ", nh.hora);
                    printf("\nMinuto [ %s ] \n", nh.minuto);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }
            }
        }
        if(strcmp(nh.cpf_cli,cpf_ip) != 0){
            printf("\nHORARIO NAO ENCONTRADO");
            printf("\n|---------------------------------------------------------------------------|\n");
        }
    }
    fclose(p);
    digite_zero();
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

    digite_zero();
}

int agd_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|-----------------------------  H O R A R I O  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct horario nh;    
    FILE *p;
    char cpf_ip[12];
    bool aux = true;

    printf("\nInforme o CPF do cliente a ter horario editado: ");
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

    p = fopen("ARQUIVOS/horarios", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }

    while (fread(&nh, sizeof(struct horario), 1, p) && !feof(p)) {

        if (strcmp(nh.cpf_cli, cpf_ip) == 0) {
            printf("Informe o data a agendar ");
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

            fseek(p, -sizeof(struct horario), SEEK_CUR);
            fwrite(&nh, sizeof(struct horario), 1, p);

            break;
        }
    }
    fclose(p);
    printf("|---------------------------------------------------------------------------|\n");

    digite_zero();
}

int agd_cancelamento(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C A N C E L A R  ----------------------------|\n");
    printf("|-----------------------------  H O R A R I O  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct horario nh;
    FILE *p, *p_temp;
    char cpf_ip[12];
    bool aux = true;

    printf("\nInforme o CPF do cliente a ter horario cancelado: ");
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

    p = fopen("ARQUIVOS/horarios", "rb");
    p_temp = fopen("ARQUIVOS/horarios_temp", "wb");
    if (p == NULL || p_temp == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    } else {
        while (fread(&nh, sizeof(struct horario), 1, p) && !feof(p)) {
            if (strcmp(nh.cpf_cli, cpf_ip) != 0) {
                fwrite(&nh, sizeof(struct horario), 1, p_temp);
            }
        }
        fclose(p);
        fclose(p_temp);

        remove("ARQUIVOS/horarios");
        rename("ARQUIVOS/horarios_temp", "ARQUIVOS/horarios");

        printf("Horario cancelado com sucesso!\n");
    }
    printf("|---------------------------------------------------------------------------|\n");

    digite_zero();
}
