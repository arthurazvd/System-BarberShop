#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

int digite_opcao(){
    int resp;
    printf("\n                            >>  DIGITE A OPCAO : ");
    limparBuffer();
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int digite_volte(){
    int resp;
    printf("\n                     >> PRESSIONE QUALQUER TECLA ... <<");
    scanf("%d", &resp);
    system("clear");
    return resp;
}

int digite_zero(){
    int resp;
    printf("\n                     >> DIGITE 0 PARA VOLTAR : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}

int continuar(){
    int resp;
    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
    printf("\n                      >> DESEJA TENTAR NOVAMENTE? <<");
    
    printf("\n                 >> DIGITE "GRN"1"RESET" PARA "GRN"SIM"RESET" OU "RED"0"RESET" PARA "RED"NAO"RESET" : ");
    scanf("%d", &resp);

    return resp;
}