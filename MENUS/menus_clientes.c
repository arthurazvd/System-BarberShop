#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"

//  SUBTELAS CLIENTES

//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s
int cli_lista(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════" CYN " >> LISTAR CLIENTES << " BLU "═══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                         1 "CYN"- LISTAR EM ORDEM ALFABETICA"BLU"                        ||\n");
    printf("||                         2 "CYN"- LISTAR POR NOME"BLU"                                   ||\n");
    printf("||                         3 "CYN"- LISTAR TUDO"BLU"                                       ||\n");
    printf("||                         0 "CYN"- VOLTAR"BLU"                                            ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);

    switch(digite_opcao()){
        case 1:
            cli_fil_alfa();
            break;
        case 2:
            cli_fil_nome();
            break;
        case 3:
            cli_fil_tudo();
            break;
    }
}

int cli_pesquisa(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═══════════════════════════" CYN " >> PESQUISA DE CLIENTE << " BLU "═════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct cliente novo;
    FILE *p;
    char cpf_ip[12];
    
    printf("\n             >> "CYN"Informe o CPF do cliente: "RESET);
    if(processo_CPF(cpf_ip)==0){
        return 0;
    }

    p = fopen("ARQUIVOS/clientes", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if(novo.status == 1){
                    if(strcmp(novo.cpf,cpf_ip)==0){
                        printf("\n             >> CPF: "MAG"%s"RESET"", novo.cpf);
                        printf("\n             >> NOME: "MAG"%s"RESET"", novo.nome);
                        printf("\n             >> TELEFONE: "MAG"%s"RESET"\n", novo.tel);
                        printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

                    }
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

//Salvamento em arquivo feito com base nos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=TqbnYUUdGjw&t=281s
int cli_cadas(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═══════════════════════════" CYN " >> CADASTRO DE CLIENTE << " BLU "═════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct cliente novo;
    FILE *p;

    p = fopen("ARQUIVOS/clientes", "a+b");
    if (p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf("             >> "CYN"Informe o CPF do cliente: "RESET);
        if(processo_CPF_CAD(novo.cpf)==0){
            return 0;
        }
        
        limparBuffer();
        printf("             >> "CYN"Informe o NOME do cliente: "RESET);
        if(processo_Nome(novo.nome)==0){
            return 0;
        }
        printf("             >> "CYN"Informe o TELEFONE do cliente: "RESET);
        if(processo_Tel(novo.tel)==0){
            return 0;
        }
        novo.status = 1;

        fwrite(&novo, sizeof(struct cliente), 1, p);
        if (ferror(p)){
            printf("             >> "RED"ERRO NA GRAVAÇÃO"RESET" <<");
        }
        else{
            printf("             >> "GRN"GRAVAÇÃO OK"RESET" <<");
        }
    fclose(p);
    }
    
    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();

}

int cli_edit(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════" CYN " >> EDICAO DE CLIENTE << " BLU "══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct cliente novo;
    FILE *p;
    char cpf_ip[12];
    bool aux = true;

    p = fopen("ARQUIVOS/clientes", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }

    printf("\n             >> "CYN"Informe o CPF do cliente a ser editado: "RESET);
    while(aux == true){
        scanf(" %11[^\n]", cpf_ip);
        if(validarCPF(cpf_ip)){
            if (checkcli(cpf_ip))
            {
                aux = false;
            }
            else{
                aux = true;
                char text[50] = "             >> "RED"CPF NAO CADASTRADO"RESET" << ";
                if (processo_Continuar(text)==0){
                    return 0;
                }
            }
        }
        else{
            aux = true;
            char text[50] = "             >> "RED"CPF INVALIDO"RESET" << ";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }

    while (fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)) {
        if (strcmp(novo.cpf, cpf_ip) == 0) {
            limparBuffer();
            printf("             >> "CYN"Informe o NOME do cliente: "RESET);
            if(processo_Nome(novo.nome)==0){
                return 0;
            }

            limparBuffer();
            printf("             >> "CYN"Informe o TELEFONE do cliente: "RESET);
            if(processo_Tel(novo.tel)==0){
                return 0;
            }

            fseek(p, -sizeof(struct cliente), SEEK_CUR);
            fwrite(&novo, sizeof(struct cliente), 1, p);
            printf("             >> "GRN"Cliente EDITADO com sucesso"RESET" <<\n");

            break;
        }
    }
    fclose(p);
    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();

}

int cli_del(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═══════════════════════════" CYN " >> DELETACAO DE CLIENTE << " BLU "════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct cliente novo;
    FILE *p;
    char cpf_ip[12];
    bool aux = true;

    printf("\n             >> "CYN"Informe o CPF do cliente a ser deletado: "RESET);
    while(aux == true){
        scanf(" %11[^\n]", cpf_ip);
        if(validarCPF(cpf_ip)){
            if (checkcli(cpf_ip))
            {
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
            aux = true;
            char text[50] = "             >> "RED"CPF INVALIDO"RESET" << \n";
            if (processo_Continuar(text)==0){
                return 0;
            }
        }
    }

    p = fopen("ARQUIVOS/clientes", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }

    while (fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)) {

        if (strcmp(novo.cpf, cpf_ip) == 0) {
            limparBuffer();

            novo.status = 0;

            fseek(p, -sizeof(struct cliente), SEEK_CUR);
            fwrite(&novo, sizeof(struct cliente), 1, p);

            printf("             >> "GRN"Cliente DELETADO com sucesso"RESET" <<\n");
            break;
        }
    }
    fclose(p);
    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();

}
