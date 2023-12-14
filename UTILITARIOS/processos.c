#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "includes.h"

int processo_CPF(char *cpf_ip){
    bool aux = true;
    while(aux == true){
        scanf(" %11[^\n]", cpf_ip);
        if(validarCPF(cpf_ip)){
            aux = false;
            return 1;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"CPF INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
}

int processo_CPF_HOR(char *cpf_ip){
    bool aux = true;
    while(aux == true){
    if (processo_CPF(cpf_ip)){
            if (checkcli(cpf_ip)){
                aux = false;
            }
            else{
                aux = true;
                char text[50] = "             >> "RED"CPF NAO CADASTRADO"RESET" << \n";
                if (processo_Continuar(text)==0){
                    return 0;
                }
            }
        }
        else{
            return 0;
        }
    }
    return 1;   
}

int processo_CPF_CAD(char *cpf_ip){
    bool aux = true;
    while(aux == true){
        scanf(" %11[^\n]", cpf_ip);
        if(validarCPF(cpf_ip)){
            if (checkcli(cpf_ip))
            {
                aux = true;
                char text[50] = "             >> "RED"CPF JA CADASTRADO"RESET" << \n";
                    if (processo_Continuar(text)==0){
                    return 0;
                    }
            }
            else{
                aux = false;
            }
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"CPF INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
    return 1;
}

int processo_Data(char *data){
    bool aux = true;
    while(aux == true){
        scanf(" %10[^\n]", data);

        if(validardata(data)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"DATA INVALIDA"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
}

int processo_Hora(char *hora){
    bool aux = true;
    while(aux == true){
        scanf(" %5[^\n]", hora);
        if(validarhora(hora)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"HORA INVALIDA"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
}

int processo_Nome(char *nome){
    bool aux = true;
    while(aux == true){
        scanf(" %99[^\n]", nome);
        if(validarnome(nome)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"NOME INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
    return 1;
}

int processo_Tel(char *tel){
    bool aux = true;
    while(aux == true){
        scanf(" %11[^\n]", tel);
        if(validartelefone(tel)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"TELEFONE INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
    return 1;

}

int processo_ID_PRE(char *id){
    bool aux = true;
    while(aux == true){
        scanf(" %3[^\n]", id);
        if(validarnumero(id)){
            if (checkidpre(id))
            {
                aux = false;
            }
            else{
                aux = true;
            }
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"ID INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
    return 1;
}

int processo_ID_PRE_CAD(char *id){
    bool aux = true;
    while(aux == true){
        scanf(" %9[^\n]", id);
        if(validarnumero(id)){
            if (checkidpre(id))
            {
                aux = true;
                char text[50] = "             >> "RED"ID JA CADASTRADO"RESET" << \n";
                if (processo_Continuar(text)==0){
                    return 0;
                }
            }
            else{
                aux = false;
            }
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"ID INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
    return 1;
}

int processo_Servico(char *serv){
    bool aux = true;
    while(aux == true){
        scanf(" %24[^\n]", serv);
        if(validarnome(serv)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"SERVICO INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
}

int processo_Preco(char *preco){
    bool aux = true;
    while(aux == true){
        scanf(" %9[^\n]", preco);
        if(validarnumero(preco)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"PRECO INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
}

int processo_ID_MAQ(char *id){
    bool aux = true;
    while(aux == true){
        scanf(" %9[^\n]", id);

        if(validarnumero(id)){
            aux = false;
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"ID INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }
}

int processo_Continuar(char *text){
    printf("%s", text);
        int continuar = des_continuar();
        if (continuar == 1){
            printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
            printf("\n             >> "RED"Digite novamente: "RESET);
            return 1;
        }else{
            return 0;
        }
}