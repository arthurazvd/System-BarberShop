#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "validacao.h"

// STRUCTS
struct horario{
    char cpf_cli[12];
    char dia[3];
    char mes[3];
    char ano[5];
    char hora[3];
    char minuto[3];
};

struct cliente{
    char cpf[12];
    char nome[100];
    char tel[12];
};

struct precos{
    char id[10];
    char servico[25];
    char preco[10];
};

struct maquinas{
    char id[10];
    char nome[20];
};

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

int agd_agendar(){
    
    struct horario nh;
    bool aux = true;    
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-----------------------------  A G E N D A R  -----------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
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
        printf("\nDia: ");
        scanf(" %2[^\n]", nh.dia);
        printf("Mes: ");
        scanf(" %2[^\n]", nh.mes);
        printf("Ano: ");
        scanf(" %4[^\n]", nh.ano);
        if(validardata(nh.dia, nh.mes, nh.ano)){
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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}
int cli_cadas(){
    struct cliente novo;
    bool aux = true;
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|-----------------------------  C L I E N T E  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");

    printf("Informe o nome do cliente: ");
    while(aux == true){
        scanf(" %99[^\n]", novo.nome);
        if(validarnome(novo.nome)){
            aux = false;
        }
        else{
            aux = true;
            printf("NOME INVALIDO ");
            printf("\nDigite novamente: ");
        }
    }
    printf("Informe o CPF do cliente: ");
    while(aux == false){
        scanf(" %11[^\n]", novo.cpf);
        if(validarCPF(novo.cpf)){
            aux = true;
        }
        else{
            aux = false;
            printf("CPF INVALIDO ");
            printf("\nDigite novamente: ");
        }
    }
    printf("Informe o Telefone do cliente: ");
    while(aux == true){
        scanf(" %11[^\n]", novo.tel);
        if(validartelefone(novo.tel)){
            aux = false;
        }
        else{
            aux = true;
            printf("TELEFONE INVALIDO ");
            printf("\nDigite novamente: ");
        }
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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");
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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}

int pre_cadas(){

    struct precos p;
    bool aux = true;
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("Informe o ID do servico: ");
        while(aux == true){
            scanf(" %9[^\n]", p.id);
            if(validarnumero(p.id)){
                aux = false;
            }
            else{
                aux = true;
                printf("ID INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
        printf("Informe o servico: ");
        while(aux == false){
            scanf(" %24[^\n]", p.servico);
            if(validarnome(p.servico)){
                aux = true;
            }
            else{
                aux = false;
                printf("SERVICO INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
        printf("Informe o preco: ");
        while(aux == true){
            scanf(" %9[^\n]", p.preco);
            if(validarnumero(p.preco)){
                aux = false;
            }
            else{
                aux = true;
                printf("PRECO INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
    printf("|---------------------------------------------------------------------------|\n");

    
    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}

int maq_cadas(){

    struct maquinas maq;
    bool aux = true;
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------------  C A D A S T R O  D E  -------------------------|\n");
    printf("|-----------------------------  M A Q U I N A  -----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("Informe o ID da maquina: ");
        while(aux == true){
            scanf(" %9[^\n]", maq.id);
            if(validarnumero(maq.id)){
                aux = false;
            }
            else{
                aux = true;
                printf("ID INVALIDO ");
                printf("\nDigite novamente: ");
            }
        }
    printf("Informe a maquina: ");
    scanf(" %19[^\n]", maq.nome);
    printf("|---------------------------------------------------------------------------|\n");

    
       
    int resp;
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

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
    printf("\nD I G I T E   0   P A R A  V O L T A R : ");

    scanf("%d", &resp);
    system("clear");

    return resp;
}
