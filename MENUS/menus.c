#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../UTILITARIOS/includes.h"

int tela_pri(){
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||  "CYN"═████═══██████══█████════████═══████══█████════████══██══██══██████══████══"BLU"  ||\n");
    printf("||  "CYN"═██══█══██══██══██═══█═══██══█══██════██═══█═══██════██══██══██══██══██══█═"BLU"  ||\n");
    printf("||  "CYN"═████═══██████══█████════████═══███═══█████════████══██████══██══██══████══"BLU"  ||\n");
    printf("||  "CYN"═██══█══██══██══██═══█═══██══█══██════██═══█═════██══██══██══██══██══██════"BLU"  ||\n");
    printf("||  "CYN"═████═══██══██══██════█══████═══████══██════█══████══██══██══██████══██════"BLU"  ||\n");

}


// Tela do menu inicial que mostra as principais coisas que podem ser colocados em um sistema de barbearia
int menu_inicial(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════" CYN " >> MENU PRINCIPAL << " BLU "════════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                           1 "CYN"- AGENDAMENTOS"BLU"                                    ||\n");
    printf("||                           2 "CYN"- CLIENTES"BLU"                                        ||\n");
    printf("||                           3 "CYN"- TABELA DE PRECOS"BLU"                                ||\n");
    printf("||                           4 "CYN"- MAQUINAS"BLU"                                        ||\n");
    printf("||                           5 "CYN"- SOBRE"BLU"                                           ||\n");
    printf("||                           0 "CYN"- SAIR"BLU"                                            ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);

    digite_opcao();
}

// Tela de agendamentos
int menu_agenda(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||══════════════════════════════" CYN " >> AGENDAMENTOS << " BLU "═════════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                            1 - "CYN"HORARIOS AGENDADOS"BLU"                             ||\n");
    printf("||                            2 - "CYN"PESQUISAR"BLU"                                      ||\n");
    printf("||                            3 - "CYN"AGENDAR"BLU"                                        ||\n");
    printf("||                            4 - "CYN"EDITAR"BLU"                                         ||\n");
    printf("||                            5 - "CYN"CANCELAR"BLU"                                       ||\n");
    printf("||                            0 - "CYN"VOLTAR"BLU"                                         ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);

    digite_opcao();
}

// Tela de cadastro, pesquisa e exclusao de clientes
int menu_clientes(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════════" CYN " >> CLIENTES << " BLU "═══════════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                                1 - "CYN"LISTAR"BLU"                                     ||\n");
    printf("||                                2 - "CYN"PESQUISAR"BLU"                                  ||\n");
    printf("||                                3 - "CYN"CADASTRAR"BLU"                                  ||\n");
    printf("||                                4 - "CYN"EDITAR"BLU"                                     ||\n");
    printf("||                                5 - "CYN"DELETAR"BLU"                                    ||\n");
    printf("||                                0 - "CYN"VOLTAR"BLU"                                     ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);

    digite_opcao();
}

// Tela de cadastro, pesquisa e exclusao de precos de servicos
int menu_precos(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════" CYN " >> TABELA DE PRECOS << " BLU "═══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                                1 - "CYN"LISTAR"BLU"                                     ||\n");
    printf("||                                2 - "CYN"PESQUISAR"BLU"                                  ||\n");
    printf("||                                3 - "CYN"CADASTRAR"BLU"                                  ||\n");
    printf("||                                4 - "CYN"EDITAR"BLU"                                     ||\n");
    printf("||                                5 - "CYN"DELETAR"BLU"                                    ||\n");
    printf("||                                0 - "CYN"VOLTAR"BLU"                                     ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);

    digite_opcao();
}

// Tela de cadastro, pesquisa e exclusao de maquinas
int menu_maquinas(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════════" CYN " >> MAQUINAS << " BLU "═══════════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                                1 - "CYN"LISTAR"BLU"                                     ||\n");
    printf("||                                2 - "CYN"PESQUISAR"BLU"                                  ||\n");
    printf("||                                3 - "CYN"CADASTRAR"BLU"                                  ||\n");
    printf("||                                4 - "CYN"EDITAR"BLU"                                     ||\n");
    printf("||                                5 - "CYN"DELETAR"BLU"                                    ||\n");
    printf("||                                0 - "CYN"VOLTAR"BLU"                                     ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    digite_opcao();
}

// Tela com informacoes sobre o projeto
int sobre(){
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||══════════════════════════════════" CYN " >> SOBRE << " BLU "════════════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                 "RESET"Universidade Federal do Rio Grande do Norte"BLU"                   ||\n");
    printf("||                 "CYN"Campus Caico - 2023"BLU"                                           ||\n");
    printf("||                 "CYN"Bacharelado em Sistemas de Informacao - "MAG"BSI"BLU"                   ||\n");
    printf("||                 "CYN"Disciplina: "MAG"Programacao - Prof.: Flavius"BLU"                      ||\n");
    printf("||                                                                               ||\n");
    printf("||                   "CYN"O System BarberShop e um sistema voltado para"BLU"               ||\n");
    printf("||                 "CYN"gerenciar barbearias, criado para a materia de"BLU"                ||\n");
    printf("||                 "CYN"programacao do 2 periodo do curso de BSI na"BLU"                   ||\n");
    printf("||                 "CYN"UFRN campus de Caico."BLU"                                         ||\n");
    printf("||                                                                               ||\n");
    printf("||                 "CYN"Desenvolvedor: "MAG"Arthur Azevedo"BLU"                                 ||\n");
    printf("||                 "CYN"GitHub: "MAG"https://github.com/arthurazvd"BLU"                         ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();
 
}

