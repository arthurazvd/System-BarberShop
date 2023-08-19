#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

int menu_agenda(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|------------------------  A G E N D A M E N T O S  ------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                 1 - H O R Á R I O S   D I S P O N Í V E I S               |\n");
    printf("|                 2 - P E S Q U I S A R                                     |\n");
    printf("|                 3 - A G E N D A R   H O R Á R I O                         |\n");
    printf("|                 4 - C A N C E L A M E N T O                               |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

int menu_clientes(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - D E L E T A R                               |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

int menu_precos(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|--------------------  T A B E L A   D E   P R E Ç O S  --------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - D E L E T A R                               |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

int menu_maquinas(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  M Á Q U I N A S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|                           1 - L I S T A R                                 |\n");
    printf("|                           2 - P E S Q U I S A R                           |\n");
    printf("|                           3 - C A D A S T R O                             |\n");
    printf("|                           4 - D E L E T A R                               |\n");
    printf("|                                                                           |\n");
    printf("|---------------------------------------------------------------------------|\n");

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}

int sobre(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|-------------------------------  S O B R E  -------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
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

    int resp;
    printf("\nD I G I T E   A   O P Ç Ã O : ");
    scanf("%d", &resp);
    system("cls");

    return resp;
}
int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu_inicial();
}
