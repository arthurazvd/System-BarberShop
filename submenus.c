#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validacao.h"


//SUBMENUS DE AGENDA

void agendamento(int id, int hor){
    printf("Digite o ID do cliente: ");
    scanf("%d", &id);
    printf("Digite o Horário: ");
    scanf("%d", &hor);
}

//SUBMENUS DE CLIENTES

void cadas_cli(int id, char nome, int cpf, int tel){
    printf("Digite o ID: ");
    scanf("%d", &id);
    printf("Digite o Nome do Cliente: ");
    scanf("%c", &nome);
    printf("Digite o CPF do Cliente: ");
    scanf("%d", &cpf);
    printf("Digite o Telefone do Cliente: ");
    scanf("%d", &tel);

}

//SUBMENUS DE PRECOS


//SUBMENUS DE MAQUINAS