#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validacao.h"


//SUBMENUS DE AGENDA

int agendamento(){
    printf("Digite o ID do cliente: ");
    scanf("%d", &id);
    printf("Digite o Horário: ");
    scanf("%d", &hor);
}

//SUBMENUS DE CLIENTES

int cadas_cli(){
    char cpf[11];
    char nome[100];
    char tel[11];
    
    bool valid = false;
    while(valid = false){
        printf("Digite o CPF do cliente: ");
        fgets(cpf, sizeof(cpf), stdin); 
        cpf[strcspn(cpf, "\n")] = '\0';

        if(validarCPF(cpf)){
            printf("Digite o Nome do cliente: ");
            fgets(nome, sizeof(nome), stdin); 
            nome[strcspn(nome, "\n")] = '\0';

            if(validarnome(nome)){
                printf("Digite o Telefone do cliente: ");
                fgets(tel, sizeof(tel), stdin); 
                tel[strcspn(tel, "\n")] = '\0';

                if(validartelefone(tel)){
                    printf("Cliente Cadastrado!");
                    valid = true;
                    return 0;
                }
                else{
                    valid = false;
                } 
            }
            else{
                valid = false;
            }    
        }
        else{
            valid = false;
        }
    }

}

//SUBMENUS DE PRECOS


//SUBMENUS DE MAQUINAS