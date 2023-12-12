#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../UTILITARIOS/includes.h"

//  SUBTELAS AGENDAMENTO

//Leitor de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

int agd_horario(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═══════════════════════════"CYN" >> HORARIOS AGENDADOS << "BLU"══════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||                                                                               ||\n");
    printf("||                           1 - "CYN"LISTAR POR DATA"BLU"                                 ||\n");
    printf("||                           2 - "CYN"LISTAR TUDO"BLU"                                     ||\n");
    printf("||                           0 - "CYN"VOLTAR"BLU"                                          ||\n");
    printf("||                                                                               ||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    switch(digite_opcao()){
        case 1:
            agd_fil_data();
            break;
        case 2:
            agd_fil_tudo();
            break;
    }
}

int agd_pesquisa(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════"CYN" >> PESQUISA DE HORARIO << "BLU"════════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
    struct horario nh;
    FILE *p;
    char cpf_ip[12];
    bool aux = true;
    
    limparBuffer();
    printf("\n             >> Informe o CPF do cliente: ");

    if (processo_CPF(cpf_ip)==0){
        return 0;
    }

    p = fopen("ARQUIVOS/horarios", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&nh, sizeof(struct horario), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if(strcmp(nh.cpf_cli,cpf_ip)==0){
                    printf("\n             >> "CYN"CLIENTE"RESET" <<");
                    printf("\n             >> CPF: "MAG"%s"RESET"", nh.cpf_cli);
                    print_cli(cpf_ip);
                    printf("\n             >> "CYN"AGENDA"RESET" <<");
                    printf("\n             >> Data: "MAG"%s"RESET"", nh.data);
                    printf("\n             >> Hora: "MAG"%s"RESET"", nh.hora);
                    print_id(nh.id_preco);
                    printf(BLU"\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

//Salvamento em arquivo feito com base nos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=TqbnYUUdGjw&t=281s
int agd_agendar(){
    
    struct horario nh;
    FILE *p;
    bool aux = true;    
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════"CYN" >> AGENDAR HORARIO << "BLU"═══════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    p = fopen("ARQUIVOS/horarios", "a+b");
    if (p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf("Informe o CPF do cliente: ");
        if(processo_CPF_HOR(nh.cpf_cli)==0){
            return 0;
        }

        printf("Informe a data a agendar ");
        //aqui ele vai ter que validar se aquele horario está disponivel 
        if(processo_Data(nh.data)==0){
            return 0;
        }
        printf("Informe a hora a agendar ");
        //aqui ele vai ter que validar se aquele horario está disponivel 
        if(processo_Hora(nh.hora)==0){
            return 0;
        }

        printf("Informe o ID do serviço ");
        //aqui ele vai ter que validar se aquele horario está disponivel 
        if(processo_ID_PRE(nh.id_preco)==0){
            return 0;
        }
    }
    fwrite(&nh, sizeof(struct horario), 1, p);
        if (ferror(p)){
            printf("\nERRO NA GRAVACAO\n");
        }
        else{
            printf("Gravacao OK\n");
        }
    fclose(p);
    
    printf(BLU"||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();
}

int agd_edit(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════"CYN" >> EDITAR HORARIO << "BLU"════════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
    struct horario nh;    
    FILE *p;
    char cpf_ip[12];
    bool aux = true;

    printf("\nInforme o CPF do cliente a ter horario editado: ");
    while(aux == true){
    if (processo_CPF(cpf_ip)){
            if (checkcli(cpf_ip)){
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
            return 0;
        }
    }

    p = fopen("ARQUIVOS/horarios", "rb+");
    if (p == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }

    while (fread(&nh, sizeof(struct horario), 1, p) && !feof(p)) {

        if (strcmp(nh.cpf_cli, cpf_ip) == 0) {
            printf("Informe o data a agendar ");
            if(processo_Data(nh.data)==0){
                return 0;
            }

            printf("Informe o hora a agendar ");
            if(processo_Hora(nh.hora)==0){
                return 0;
            }

            fseek(p, -sizeof(struct horario), SEEK_CUR);
            fwrite(&nh, sizeof(struct horario), 1, p);

            break;
        }
    }
    fclose(p);
    printf(BLU"||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();
}

int agd_cancelamento(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════"CYN" >> CANCELAR HORARIO << "BLU"════════════════════════════||\n");
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
    struct horario nh;
    FILE *p, *p_temp;
    char cpf_ip[12];
    bool aux = true;

    printf("\nInforme o CPF do cliente a ter horario cancelado: ");
    
    while(aux == true){
    if (processo_CPF(cpf_ip)){
            if (checkcli(cpf_ip)){
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
            return 0;
        }
    }

    p = fopen("ARQUIVOS/horarios", "rb");
    p_temp = fopen("ARQUIVOS/horarios_temp", "wb");
    if (p == NULL || p_temp == NULL) {
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    } else {
        while (fread(&nh, sizeof(struct horario), 1, p) && !feof(p)) {
            if (strcmp(nh.cpf_cli, cpf_ip) != 0) {
                fwrite(&nh, sizeof(struct horario), 1, p_temp);
            }
        }
        fclose(p);
        fclose(p_temp);

        remove("ARQUIVOS/horarios");
        rename("ARQUIVOS/horarios_temp", "ARQUIVOS/horarios");

        printf("Horario cancelado com sucesso!\n");
    }
    printf(BLU"||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    digite_zero();
}