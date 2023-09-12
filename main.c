#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main(){
    system("MODE con cols=230 lines=50");
    system("title System BarberShop");
    tela_inicial();
    int resp = menu_inicial();
    int resp2;
    
    while(resp != 0){
        switch (resp)
        {
        case 1:
            resp2 = menu_agenda();
            switch (resp2)
            {
            case 1:
                agd_horario();
                system("pause");
                system("cls");
                break;
            case 2:
                agd_pesquisa();
                system("pause");
                system("cls");
                break;
            case 3:
                agd_agendar();
                system("pause");
                system("cls");
                break;
            case 4:
                agd_cancelamento();
                system("pause");
                system("cls");
                break;
            default:
                resp = menu_inicial();
            }
            break;

        case 2:
            resp2 = menu_clientes();
            switch (resp2)
            {
            case 1:
                cli_lista();
                system("pause");
                system("cls");
                break;
            case 2:
                cli_pesquisa();
                system("pause");
                system("cls");
                break;
            case 3:
                cli_cadas();
                system("pause");
                system("cls");
                break;
            case 4:
                cli_del();
                system("pause");
                system("cls");
                break;
            default:
                resp = menu_inicial();
            }
            break;

        case 3:
            resp2 = menu_clientes();
            switch (resp2)
            {
            case 1:
                pre_lista();
                system("pause");
                system("cls");
                break;
            case 2:
                pre_pesquisa();
                system("pause");
                system("cls");
                break;
            case 3:
                pre_cadas();
                system("pause");
                system("cls");
                break;
            case 4:
                pre_del();
                system("pause");
                system("cls");
                break;
            default:
                resp = menu_inicial();
            }
            break;

        case 4:
            resp2 = menu_clientes();
            switch (resp2)
            {
            case 1:
                maq_lista();
                system("pause");
                system("cls");
                break;
            case 2:
                maq_pesquisa();
                system("pause");
                system("cls");
                break;
            case 3:
                maq_cadas();
                system("pause");
                system("cls");
                break;
            case 4:
                maq_del();
                system("pause");
                system("cls");
                break;
            default:
                resp = menu_inicial();
            }
            break;

        case 5:
            resp2 = sobre();
            resp = menu_inicial();
            break;

        default:
            resp = menu_inicial();
        }

    }
}