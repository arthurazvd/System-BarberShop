#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../UTILITARIOS/includes.h"

//Leitorres de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

//####################################### LISTAR CLIENTES #################################################

// Adaptado de: Gabriel Canuto - Github: https://github.com/gabrielygor
void cli_fil_alfa(void) {
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||══════════════════" CYN " >> LISTA DE CLIENTES EM ORDEM ALFABETICA << " BLU "════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);

    FILE *p;
    Cliente* novocli; 
    Cliente* lista; 
    p = fopen("ARQUIVOS/clientes", "rb");
    if (p == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1); 
    }

    lista = NULL;
    novocli = (Cliente*)malloc(sizeof(Cliente));

    if (novocli == NULL) {
        printf("Erro de alocacao de memoria\n");
        exit(1); 
    }

    while (fread(novocli, sizeof(Cliente), 1, p) == 1) { 
        novocli->prox = NULL;  

        if ((lista == NULL) || (strcmp(novocli->nome, lista->nome) < 0)) {  
            novocli->prox = lista;
            lista = novocli; 
        } else {  
            Cliente* ant = lista; 
            Cliente* atual = lista->prox;  
            while ((atual != NULL) && strcmp(atual->nome, novocli->nome) < 0) {   
                ant = atual;  
                atual = atual->prox; 
            }
            ant->prox = novocli;  
            novocli->prox = atual;  
        }

        novocli = (Cliente*)malloc(sizeof(Cliente));
        if (novocli == NULL) {
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }
    }

    fclose(p);

    novocli = lista;  
    printf(BLU "\n||═════════════════════════||═════════════════════════||═════════════════════════||\n");
    printf("||  "MAG"CPF"BLU"                    ||  "MAG"NOME"BLU"                   ||  "MAG"TELEFONE"BLU"               ||\n" );
    printf("||═════════════════════════||═════════════════════════||═════════════════════════||\n" RESET);
    while (novocli != NULL) { 
        printf(BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||\n"RESET, novocli->cpf, novocli->nome, novocli->tel);
        printf(BLU"||═════════════════════════||═════════════════════════||═════════════════════════||\n"RESET);
        
        novocli = novocli->prox;  
    }

    novocli = lista;  
    while (lista != NULL) {
        lista = lista->prox;  
        free(novocli); 
        novocli = lista;
    }
    digite_zero();
}

int cli_fil_nome(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════" CYN " >> LISTA DE CLIENTES POR NOME << " BLU "═════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct cliente novo;
    FILE *p;
    char nome_ip[100];
    bool aux = true;
    
    printf("\n             >> "CYN"Informe o NOME do cliente: "RESET);
    while(aux == true){
        scanf(" %99[^\n]", nome_ip);
        if(validarnome(nome_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("             >> "RED"NOME INVALIDO"RESET" << ");
            int continuar = des_continuar();
            if (continuar == 1){
                aux = true;
            }else{
                return 0;
            }
            printf("\nDigite novamente: ");
        }
    }
    printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);

    p = fopen("ARQUIVOS/clientes", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf(BLU "\n||═════════════════════════||═════════════════════════||═════════════════════════||\n");
        printf("||  "MAG"CPF"BLU"                    ||  "MAG"NOME"BLU"                   ||  "MAG"TELEFONE"BLU"               ||\n" );
        printf("||═════════════════════════||═════════════════════════||═════════════════════════||\n" RESET);

        while(fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if(novo.status == 1){
                    if(strcmp(novo.nome,nome_ip)==0){
                        printf(BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||\n"RESET, novo.cpf, novo.nome, novo.tel);
                        printf(BLU"||═════════════════════════||═════════════════════════||═════════════════════════||\n"RESET);
                    }
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

int cli_fil_tudo(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════" CYN " >> LISTA DE CLIENTES << " BLU "══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct cliente novo;
    FILE *p;
    p = fopen("ARQUIVOS/clientes", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf(BLU "\n||═════════════════════════||═════════════════════════||═════════════════════════||\n");
        printf("||  "MAG"CPF"BLU"                    ||  "MAG"NOME"BLU"                   ||  "MAG"TELEFONE"BLU"               ||\n" );
        printf("||═════════════════════════||═════════════════════════||═════════════════════════||\n" RESET);
        while(fread(&novo, sizeof(struct cliente), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                
                if (novo.status == 1)
                {
                    printf(BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||\n"RESET, novo.cpf, novo.nome, novo.tel);
                    printf(BLU"||═════════════════════════||═════════════════════════||═════════════════════════||\n"RESET);
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

//####################################### LISTAR HORARIOS #################################################
int agd_fil_data(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════" CYN " >> HORARIOS AGENDADOS << " BLU "═════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct horario nh;
    struct cliente nc;
    FILE *p;

    char data_ip[11];
    bool aux = true;
    
    printf("\n             >> "CYN"Informe a DATA a agendar (Formato: XX/XX/XXXX): "RESET);
    while(aux == true){
        scanf(" %10[^\n]", data_ip);
        if(validardata(data_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("DATA INVALIDA");
            int continuar = des_continuar();
            if (continuar == 1){
                aux = true;
            }else{
                return 0;
            }
            printf("\nDigite novamente: ");
        }
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
                if(strcmp(nh.data,data_ip)==0){
                    printf("\n             >> "CYN"CLIENTE"RESET" <<");
                    printf("\n             >> CPF: "MAG"%s"RESET"", nh.cpf_cli);
                    print_cli(nh.cpf_cli);
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

int agd_fil_tudo(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||════════════════════════════" CYN " >> HORARIOS AGENDADOS << " BLU "═════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct horario nh;
    FILE *p;
    p = fopen("ARQUIVOS/horarios", "a+b");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&nh, sizeof(struct horario), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                printf("\n             >> "CYN"CLIENTE"RESET" <<");
                printf("\n             >> CPF: "MAG"%s"RESET"", nh.cpf_cli);
                print_cli(nh.cpf_cli);
                printf("\n             >> "CYN"AGENDA"RESET" <<");
                printf("\n             >> Data: "MAG"%s"RESET"", nh.data);
                printf("\n             >> Hora: "MAG"%s"RESET"", nh.hora);
                print_id(nh.id_preco);
                printf(BLU"\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
            }
        }
    }
    fclose(p);
    digite_zero();
}

//####################################### LISTAR PRECOS #################################################

int pre_fil_serv(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════" CYN " >> TABELA DE PRECOS << " BLU "══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct precos pr;
    FILE *p;
    char serv_ip[25];
    bool aux = true;
    
    printf("\n             >> "CYN"Informe o servico: "RESET);
    while(aux == true){
        scanf(" %24[^\n]", serv_ip);

        if(validarnome(serv_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("SERVICO INVALIDO ");
            int continuar = des_continuar();
            if (continuar == 1){
                aux = true;
            }else{
                return 0;
            }
            printf(BLU "\n||═══════════════════════════════════════════════════════════════════════════════||\n"RESET);
            printf("\n             >> "RED"Digite novamente: "RESET);
        }
    }
    p = fopen("ARQUIVOS/precos", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf(BLU "\n||═════════════════════════||═════════════════════════||═════════════════════════||\n");
        printf("||  "MAG"ID"BLU"                     ||  "MAG"SERVICO"BLU"                ||  "MAG"PRECO"BLU"                  ||\n" );
        printf("||═════════════════════════||═════════════════════════||═════════════════════════||\n" RESET);
        while(fread(&pr, sizeof(struct precos), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if (pr.status == 1)
                {
                    if(strcmp(pr.servico,serv_ip) == 0){
                    printf(BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||\n"RESET, pr.id, pr.servico, pr.preco);
                    printf(BLU"||═════════════════════════||═════════════════════════||═════════════════════════||\n"RESET);    
                    }                
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

int pre_fil_tudo(){
    tela_pri();
    printf(BLU "||═══════════════════════════════════════════════════════════════════════════════||\n");
    printf("||═════════════════════════════" CYN " >> TABELA DE PRECOS << " BLU "══════════════════════════||\n" );
    printf("||═══════════════════════════════════════════════════════════════════════════════||\n" RESET);
    struct precos pr;
    FILE *p;
    p = fopen("ARQUIVOS/precos", "a+b");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        printf(BLU "\n||═════════════════════════||═════════════════════════||═════════════════════════||\n");
        printf("||  "MAG"ID"BLU"                     ||  "MAG"SERVICO"BLU"                ||  "MAG"PRECO"BLU"                  ||\n" );
        printf("||═════════════════════════||═════════════════════════||═════════════════════════||\n" RESET);
        while(fread(&pr, sizeof(struct precos), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if (pr.status == 1)
                {
                    printf(BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||  "RESET"%-20s   "BLU"||\n"RESET, pr.id, pr.servico, pr.preco);
                    printf(BLU"||═════════════════════════||═════════════════════════||═════════════════════════||\n"RESET);
                }
            }
        }
    }

    fclose(p);
    digite_zero();
}

int print_id(char *id){
  struct precos pr;
  FILE *p;
  bool aux = true;
      
  p = fopen("ARQUIVOS/precos", "rb");
  if(p == NULL){
      printf("Erro ao abrir arquivo\n!");
      exit(1);
  }
  else{
    while(fread(&pr, sizeof(struct precos), 1, p) && !feof(p)){
      if(ferror(p)){
      printf("\nERRO NA LEITURA\n");
      }
      else{
          {
            if(strcmp(pr.id,id) == 0){
              printf("\n             >> Servico: "MAG"%s"RESET"", pr.servico);
              printf("\n             >> Preco: "MAG"R$ %s,00"RESET"\n", pr.preco);
          }
        }
      }
    }
  }
  fclose(p);
}

int print_cli(char *cpf){
    struct cliente novo;
    FILE *p;
    char cpf_ip[12];
    bool aux = true;
    p = fopen("ARQUIVOS/clientes", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\n             >> "RED"ERRO NA LEITURA"RESET" <<\n");
            }
            else{
                if(strcmp(novo.cpf,cpf)==0){
                    printf("\n             >> Nome: "MAG"%s"RESET"", novo.nome);
                    printf("\n             >> Telefone: "MAG"%s"RESET"\n", novo.tel);
                }
            }
        }
    }
    fclose(p);
}

char *pes_cli_nome(char *cpf){
    struct cliente novo;
    FILE *p;
    char cpf_ip[12];
    bool aux = true;
    char *name;
    p = fopen("ARQUIVOS/clientes", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\n             >> "RED"ERRO NA LEITURA"RESET" <<\n");
            }
            else{
                if(strcmp(novo.cpf,cpf)==0){
                    name = novo.nome;
                    return name;
                }
            }
        }
    }
    fclose(p);
}

char *pes_cli_tel(char *cpf){
    struct cliente novo;
    FILE *p;
    char cpf_ip[12];
    bool aux = true;
    char *telefone;
    p = fopen("ARQUIVOS/clientes", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&novo, sizeof(struct cliente), 1, p) && !feof(p)){
            if(ferror(p)){
            printf("\n             >> "RED"ERRO NA LEITURA"RESET" <<\n");
            }
            else{
                if(strcmp(novo.cpf,cpf)==0){
                    telefone = novo.tel;
                    return telefone;
                }
            }
        }
    }
    fclose(p);
}