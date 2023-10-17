#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "validacao.h"


//#################################################################
//  SUBTELAS DOS MENUS
//#################################################################

//  SUBTELAS AGENDAMENTO

int agd_horario(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|-------------------------  D I S P O N O V E I S  -------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
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
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int agd_agendar(){
    struct horario{
        char cpf_cli[11];
        char data[6];
        char hora[4];
    }
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  A G E N D A R  -----------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
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
    printf("\nD I G I T E   A   O P C A O : ");
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
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

//  SUBTELAS CLIENTES

int cli_lista(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int cli_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  P E S Q U I S A  D E --------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}
int cli_cadas(){
    
    struct cliente{
        char cpf[11];
        char nome[100];
        char tel[11];
    }
    
    bool valid = false;
    while(valid = false){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    }
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");
    scanf("%d", &resp);
    system("clear");
    return resp;
}

int cli_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int cli_del(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  D E L E T A R  -----------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

//  SUBTELAS TABELA DE PRECOS

int pre_lista(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|---------------------------  T A B E L A  D E  ----------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int pre_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  P E S Q U I S A  D E --------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int pre_cadas(){
    struct precos{
        char id[10];
        char servico[25];
        char preco[10];
    }
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int pre_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int pre_del(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  D E L E T A R  -----------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

//  SUBTELAS MAQUINAS

int maq_lista(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  M A Q U I N A S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int maq_pesquisa(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  P E S Q U I S A  D E --------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int maq_cadas(){
    struct maquinas{
        char id[10];
        char nome[20];
    }
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int maq_edit(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------------  E D I T A R  ------------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

int maq_del(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  D E L E T A R  -----------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}
