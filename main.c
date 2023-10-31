#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "menus_horario.h"
#include "menus_clientes.h"
#include "menus_precos.h"
#include "menus_maquinas.h"

int main(){
    
    system("clear");

    int resp = menu_inicial();
    int resp2;

    while(resp != 0){
        switch (resp)
        {

        // AGENDAMENTOS
        case 1:
            resp2 = menu_agenda();
            switch (resp2)
            {
            case 1:
                agd_horario();
                
                system("clear");
                break;
            case 2:
                agd_pesquisa();
                
                system("clear");
                break;
            case 3:
                agd_agendar();
                
                system("clear");
                break;
            case 4:
                agd_edit();
                
                system("clear");
                break;
            case 5:
                agd_cancelamento();
                
                system("clear");
                break;
            default:
                resp = menu_inicial();
            }
            break;

        // CLIENTES
        case 2:
            resp2 = menu_clientes();
            switch (resp2)
            {
            case 1:
                cli_lista();
                
                system("clear");
                break;
            case 2:
                cli_pesquisa();
                
                system("clear");
                break;
            case 3:
                cli_cadas();
                
                system("clear");
                break;
            case 4:
                cli_edit();
                
                system("clear");
                break;
            case 5:
                cli_del();
                
                system("clear");
                break;
            default:
                resp = menu_inicial();
            }
            break;

        // PREÇOS
        case 3:
            resp2 = menu_precos();
            switch (resp2)
            {
            case 1:
                pre_lista();
                
                system("clear");
                break;
            case 2:
                pre_pesquisa();
                
                system("clear");
                break;
            case 3:
                pre_cadas();
                
                system("clear");
                break;
            case 4:
                pre_edit();
                
                system("clear");
                break;
            case 5:
                pre_del();
                
                system("clear");
                break;
            default:
                resp = menu_inicial();
            }
            break;

        // MAQUINAS
        case 4:
            resp2 = menu_maquinas();
            switch (resp2)
            {
            case 1:
                maq_lista();
                system("clear");
                break;
            case 2:
                maq_pesquisa();
                system("clear");
                break;
            case 3:
                maq_cadas();
                system("clear");
                break;
            case 4:
                maq_edit();
                system("clear");
                break;
            case 5:
                maq_del();
                system("clear");
                break;
            default:
                resp = menu_inicial();
            }
            break;

        // SOBRE
        case 5:
            resp2 = sobre();
            resp = menu_inicial();
            break;

        default:
            resp = menu_inicial();
        }

    }
}