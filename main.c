#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Tela inicial do sistema que aparecerá assim for iniciado
int tela_inicial(){ 

    printf("                                                                                                                                     \n");   
    printf("                                                                                                                                     \n");   
    printf("                                                                                ..################        ##                         \n");   
    printf("                                                    ##########  ####  ########--##  ##  ##  --  ####    ####                         \n");   
    printf("                                                    ##  ##  ##  ##    ##        ##      ####    ####  ##  ##            ::####       \n");   
    printf("                            ##                      ####      ####    ######    ##    --##      ##  ####  ##            ########     \n");   
    printf("                          ######                        ##    ##          ##    ##    MM##########      ####            ########     \n");   
    printf("                            ####@@##              ##    ##    ##    ##  ####  ####--                                    ######       \n");   
    printf("                              ########            ######      ####                @@######################                ####       \n");   
    printf("                                  ######                              ##########..##############################        ########     \n");   
    printf("                                    ######                    ####  ####  MM--##########                    ##      ################ \n");   
    printf("                                      ##  ##++                ####      ########..              ########                             \n");   
    printf("                                                          ..      --########        ##########    ##MM  ####        @@############   \n");   
    printf("                    ##############################            ########              ####          ####  ####        @@MMMM           \n");   
    printf("                        ####################          ##########        ########    ####          ####  ####        MM        ####   \n");   
    printf("                                            ############            ######  ####    ####  ##      ######            MM  ##########   \n");  
    printf("                      ::################@@                ######      ####  ####    ####  ##      ####  ##          @@@@######..     \n");   
    printf("                                                      ####    ####    ####  ##      ####          ####  ####        @@##             \n");   
    printf("                        ##########          ##..        ##    ####    ##########    ####    ##    ####  ####        MM      ::MMMM   \n");   
    printf("                          ####  ####        ####        ##    ##      ####    ##    ####  ..##    ####    ####      MMMMMMMMMMMMMM   \n");   
    printf("                          ####  ####      ######        ##  ##        ####    ##    ####                            @@MMMMMMMM       \n");   
    printf("                          ####  ####      ######        ##  ####      ####  ##                                      @@MM             \n");   
    printf("                          ######::        ##  ####      ##    ##@@    ######            ########################    MM      ######   \n");   
    printf("                          ####  ####      ##  ####      ##--  ####              @@############..        ########    MM############   \n");   
    printf("                          ####  ####    ##########      ##MM  ####          ########        mm    ######            @@@@######       \n");   
    printf("                          ####  ####    ##      ##    ######          ########        ####  ##    ##  ##    ######  @@@@             \n");   
    printf("      ##..MM##            ####  ####    ##    ####++            ########  ##  ##  ##  @@##  ##    ##  ##    ##  ##  MM      ::MMMM   \n");   
    printf("    ##        ##        ::@@##                            ##########  ##      ##      @@######    ##  ##    ##  ##--MM############   \n");   
    printf("              ####                            ..##########    ##  ##            ####  ####  ##    ##  ##    ####mm                   \n");  
    printf("    ##        ##############################..                              MM##  ##  ####  ##    ##  ##    ##      ################ \n");  
    printf("    ####    ##++          ##########  ################################        ######  ####  ##    ######    ##        ############   \n");  
    printf("        ##                ##  ####################++                                                                    ########     \n");  
    printf("        ##            ########                                                                                            ##         \n");  
    printf("      ########    ####                                                                                                               \n");  
    printf("    ##        ####                                                                                                                   \n");  
    printf("    @@        ##                                                                                                                     \n");   
    printf("    MM                                                                                                                               \n");   
    printf("    ##      ##                                                                                                                       \n");   
    printf("  ########                                                                                                                           \n");   
    printf("                                                                                                                                     \n");
    printf("                                                                                                                                     \n");   

    system("pause");
    system("cls");
    return 0;
}

// Tela do menu inicial que mostra as principais coisas que podem ser colocados em um sistema de barbearia
int menu_inicial(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-------------------  S Y S T E M   B A R B E R S H O P  -------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                    1 - A G E N D A M E N T O S                            |\n");
    printf("|                    2 - C L I E N T E S                                    |\n");
    printf("|                    3 - T A B E L A   D E   P R E Ç O S                    |\n");
    printf("|                    4 - M Á Q U I N A S                                    |\n");
    printf("|                    5 - S O B R E                                          |\n");
    printf("|                    0 - S A I R                                            |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

// Tela de agendamentos
int menu_agenda(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------  A G E N D A M E N T O S  ------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                 1 - H O R Á R I O S   D I S P O N Í V E I S               |\n");
    printf("|                 2 - P E S Q U I S A R                                     |\n");
    printf("|                 3 - A G E N D A R   H O R Á R I O                         |\n");
    printf("|                 4 - C A N C E L A M E N T O                               |\n");
    printf("|                 0 - V O L T A R                                           |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

// Tela de cadastro, pesquisa e exclusão de clientes
int menu_clientes(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - D E L E T A R                               |\n");
    printf("|                           0 - V O L T A R                                 |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

// Tela de cadastro, pesquisa e exclusão de preços de serviços
int menu_precos(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------  T A B E L A   D E   P R E Ç O S  --------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - D E L E T A R                               |\n");
    printf("|                           0 - V O L T A R                                 |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

// Tela de cadastro, pesquisa e exclusão de máquinas
int menu_maquinas(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  M Á Q U I N A S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - D E L E T A R                               |\n");
    printf("|                           0 - V O L T A R                                 |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

// Tela com informações sobre o projeto
int sobre(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-------------------------------  S O B R E  -------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|               Universidade Federal do Rio Grande do Norte                 |\n");
    printf("|               Campus Caicó - 2023                                         |\n");
    printf("|               Bacharelado em Sistemas de Informação - BSI                 |\n");
    printf("|               Disciplina: Programação - Prof.: Flavius                    |\n");
    printf("|                                                                           |\n");
    printf("|                 O System BarberShop é um sistema voltado para             |\n");
    printf("|               gerenciar barbearias, criado para a materia de              |\n");
    printf("|               programação do 2° periodo do curso de BSI na                |\n");
    printf("|               UFRN campus de Caicó.                                       |\n");
    printf("|                                                                           |\n");
    printf("|               Desenvolvedor: Arthur Azevêdo                               |\n");
    printf("|               GitHub: https://github.com/arthurazvd                       |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    printf("\nP R E S S I O N E   Q U A L Q U E R   T E C L A . . . ");
    system("pause > NULL");
    system("cls");
 

    return 0;
}


// Função MAIN onde está toda a logica que deixa as telas interligadas
int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    system("MODE con cols=230 lines=50");
    system("title System BarberShop");
    tela_inicial();
    int resp = menu_inicial();
    int resp2;
    
    while(resp != 0){
        if(resp == 1){
            resp2 = menu_agenda();
            if(resp2 == 1){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 2){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 3){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 4){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else{
                resp = menu_inicial();
            }
        }

        else if(resp == 2){
            resp2 = menu_clientes();
            if(resp2 == 1){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 2){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 3){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 4){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else{
                resp = menu_inicial();
            }
        }

        else if(resp == 3){
            resp2 = menu_precos();
            if(resp2 == 1){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 2){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 3){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 4){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else{
                resp = menu_inicial();
            }
        }

        else if(resp == 4){
            resp2 = menu_maquinas();
            if(resp2 == 1){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 2){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 3){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else if(resp2 == 4){
                printf("EM DESENVOLVIMENTO\n");
                system("pause");
                system("cls");
            }
            else{
                resp = menu_inicial();
            }
        }

        else if(resp == 5){
            resp2 = sobre();
            resp = menu_inicial();
        }
    }
}
