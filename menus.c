#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "submenus.h"
#include "validacao.h"

// Tela do menu inicial que mostra as principais coisas que podem ser colocados em um sistema de barbearia
int menu_inicial(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-------------------  S Y S T E M   B A R B E R S H O P  -------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                    1 - A G E N D A M E N T O S                            |\n");
    printf("|                    2 - C L I E N T E S                                    |\n");
    printf("|                    3 - T A B E L A   D E   P R E C O S                    |\n");
    printf("|                    4 - M A Q U I N A S                                    |\n");
    printf("|                    5 - S O B R E                                          |\n");
    printf("|                    0 - S A I R                                            |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

// Tela de agendamentos
int menu_agenda(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------  A G E N D A M E N T O S  ------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                 1 - H O R A R I O S   D I S P O N I V E I S               |\n");
    printf("|                 2 - P E S Q U I S A R                                     |\n");
    printf("|                 3 - A G E N D A R   H O R A R I O                         |\n");
    printf("|                 4 - E D I T A R                                           |\n");
    printf("|                 5 - C A N C E L A M E N T O                               |\n");
    printf("|                 0 - V O L T A R                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

// Tela de cadastro, pesquisa e exclusao de clientes
int menu_clientes(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - E D I T A R                                 |\n");
    printf("|                           5 - D E L E T A R                               |\n");
    printf("|                           0 - V O L T A R                                 |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

// Tela de cadastro, pesquisa e exclusao de precos de servicos
int menu_precos(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------  T A B E L A   D E   P R E C O S  --------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - E D I T A R                                 |\n");
    printf("|                           5 - D E L E T A R                               |\n");
    printf("|                           0 - V O L T A R                                 |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

// Tela de cadastro, pesquisa e exclusao de maquinas
int menu_maquinas(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  M A Q U I N A S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - E D I T A R                                 |\n");
    printf("|                           5 - D E L E T A R                               |\n");
    printf("|                           0 - V O L T A R                                 |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P C A O : ");
    scanf("%d", &resp);
    system("clear");

    return resp;
}

// Tela com informacoes sobre o projeto
int sobre(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-------------------------------  S O B R E  -------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|               Universidade Federal do Rio Grande do Norte                 |\n");
    printf("|               Campus Caico - 2023                                         |\n");
    printf("|               Bacharelado em Sistemas de Informacao - BSI                 |\n");
    printf("|               Disciplina: Programacao - Prof.: Flavius                    |\n");
    printf("|                                                                           |\n");
    printf("|                 O System BarberShop e um sistema voltado para             |\n");
    printf("|               gerenciar barbearias, criado para a materia de              |\n");
    printf("|               programacao do 2 periodo do curso de BSI na                 |\n");
    printf("|               UFRN campus de Caico.                                       |\n");
    printf("|                                                                           |\n");
    printf("|               Desenvolvedor: Arthur Azevedo                               |\n");
    printf("|               GitHub: https://github.com/arthurazvd                       |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nP R E S S I O N E   Q U A L Q U E R   T E C L A . . . ");
    scanf("%d", &resp);
    system("clear");
    return resp;
 
}

