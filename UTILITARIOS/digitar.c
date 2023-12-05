#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digite_opcao(){
    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int digite_volte(){
    int resp;
    printf("\nP R E S S I O N E   Q U A L Q U E R   T E C L A . . . ");
    scanf("%d", &resp);
    system("clear");
    return resp;
}

int digite_zero(){
    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}

int continuar(){
    int resp;
    printf("\n|---------------------------------------------------------------------------|\n");
    printf("\nD E S E J A   T E N T A R   N O V A M E N T E ? ");
    printf("\nD I G I T E   1   P A R A   S I M   O U   0   P A R A   N A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}