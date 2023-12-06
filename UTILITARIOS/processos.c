#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "includes.h"

int processo_CPF(char *cpf_ip){
    int aux = true;
    while(aux == true){
        scanf(" %11[^\n]", cpf_ip);
        if(validarCPF(cpf_ip)){
            aux = false;
            return 1;
        }
        else{
            aux = true;
            printf("\n             >> "RED"CPF INVALIDO"RESET" <<\n");
            int continuar = des_continuar();
            if (continuar == 1){
                aux = true;
            }else{
                return 0;
            }
            printf("\n             >> Digite novamente: ");
        }
    }
}

int processo_Data(char *data){
    int aux = true;
    while(aux == true){
        printf("\nData: ");
        scanf(" %10[^\n]", data);

        if(validardata(data)){
            aux = false;
        }
        else{
            aux = true;
            printf("DATA INVALIDA ");
            int continuar = des_continuar();
            if (continuar == 1){
                aux = true;
            }else{
                return 0;
            }
            printf("\nDigite novamente: ");
        }
    }
}

int processo_Hora(char *hora){
    int aux = true;
    while(aux == true){
        printf("\nHora: ");
        scanf(" %5[^\n]", hora);
        if(validarhora(hora)){
            aux = false;
        }
        else{
            aux = true;
            printf("HORA INVALIDA ");
            int continuar = des_continuar();
            if (continuar == 1){
                aux = true;
            }else{
                return 0;
            }
            printf("\nDigite novamente: ");
        }
    }
}