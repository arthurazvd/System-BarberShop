#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../UTILITARIOS/includes.h"

//Leitorres de arquivos adaptado dos slides e nessa video aula do Professor Romerson: https://www.youtube.com/watch?v=nJrENSVTF94&t=3s

//####################################### LISTAR CLIENTES #################################################
int cli_fil_nome(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct cliente novo;
    FILE *p;
    char nome_ip[100];
    bool aux = true;
    
    limparBuffer();
    printf("Informe o nome do cliente: ");
    while(aux == true){
        scanf(" %99[^\n]", nome_ip);
        if(validarnome(nome_ip)){
            aux = false;
        }
        else{
            aux = true;
            printf("NOME INVALIDO ");
            int continuar = des_continuar();
            if (continuar == 1){
                aux = true;
            }else{
                return 0;
            }
            printf("\nDigite novamente: ");
        }
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
                    if(strcmp(novo.nome,nome_ip)==0){
                        printf("\nCPF [ %s ] ", novo.cpf);
                        printf("\nNome [ %s ] ", novo.nome);
                        printf("\nTelefone [ %s ] \n", novo.tel);
                        printf("\n|---------------------------------------------------------------------------|\n");
                    }
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

int cli_fil_tudo(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  C L I E N T E S  ----------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct cliente novo;
    FILE *p;
    p = fopen("ARQUIVOS/clientes", "rb");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&novo, sizeof(struct cliente), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if (novo.status == 1)
                {
                    printf("\nCPF [ %s ] ", novo.cpf);
                    printf("\nNome [ %s ] ", novo.nome);
                    printf("\nTelefone [ %s ] \n", novo.tel);

                    printf("\n|---------------------------------------------------------------------------|\n");
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

//####################################### LISTAR HORARIOS #################################################
int agd_fil_data(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------  A G E N D A D O S  ---------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct horario nh;
    FILE *p;
    char data_ip[11];
    bool aux = true;
    
    limparBuffer();
    printf("Informe a DATA: ");
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
                    printf("\nCLIENTE");
                    printf("\nCPF [ %s ] ", nh.cpf_cli);
                    print_cli(nh.cpf_cli);
                    printf("\nAGENDA");
                    printf("\nData [ %s ] ", nh.data);
                    printf("\nHora [ %s ] ", nh.hora);
                    printf("\nMinuto [ %s ]", nh.minuto);
                    print_id(nh.id_preco);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

int agd_fil_tudo(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|----------------------------  H O R A R I O S  ----------------------------|\n");
    printf("|---------------------------  A G E N D A D O S  ---------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
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
                printf("\nCLIENTE");
                printf("\nCPF [ %s ] ", nh.cpf_cli);
                print_cli(nh.cpf_cli);
                printf("\nAGENDA");
                printf("\nData [ %s ] ", nh.data);
                printf("\nHora [ %s ] ", nh.hora);
                printf("\nMinuto [ %s ]", nh.minuto);
                print_id(nh.id_preco);
                printf("\n|---------------------------------------------------------------------------|\n");
            }
        }
    }
    fclose(p);
    digite_zero();
}

//####################################### LISTAR PRECOS #################################################

int pre_fil_serv(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|---------------------------  T A B E L A  D E  ----------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct precos pr;
    FILE *p;
    char serv_ip[25];
    bool aux = true;
    
    limparBuffer();
    printf("Informe o servico: ");
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
            printf("\nDigite novamente: ");
        }
    }
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
                if (pr.status == 1)
                {
                    if(strcmp(pr.servico,serv_ip) == 0){
                    printf("\nID [ %s ] ", pr.id);
                    printf("\nServico [ %s ] ", pr.servico);
                    printf("\nPreco R$ [ %s ] \n", pr.preco);
                    printf("\n|---------------------------------------------------------------------------|\n");
                }                }
            }
        }
    }
    fclose(p);
    digite_zero();
}

int pre_fil_tudo(){
    printf("|---------------------------------------------------------------------------|\n");
    printf("|---------------------------  T A B E L A  D E  ----------------------------|\n");
    printf("|------------------------------  P R E C O S  ------------------------------|\n");
    printf("|---------------------------------------------------------------------------|\n");
    struct precos pr;
    FILE *p;
    p = fopen("ARQUIVOS/precos", "a+b");
    if(p == NULL){
        printf("Erro ao abrir arquivo\n!");
        exit(1);
    }
    else{
        while(fread(&pr, sizeof(struct precos), 1, p)){
            if(ferror(p)){
            printf("\nERRO NA LEITURA\n");
            }
            else{
                if (pr.status == 1)
                {
                    printf("\nID [ %s ] ", pr.id);
                    printf("\nServico [ %s ] ", pr.servico);
                    printf("\nPreco R$ [ %s ] \n", pr.preco);
                    printf("\n|---------------------------------------------------------------------------|\n");
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
          if (pr.status == 1)
          {
            if(strcmp(pr.id,id) == 0){
              printf("\nServico [ %s ]\n", pr.servico);
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
      printf("\nERRO NA LEITURA\n");
      }
      else{
        if(strcmp(novo.cpf,cpf)==0){
            printf("\nNome [ %s ] ", novo.nome);
            printf("\nTelefone [ %s ] \n", novo.tel);
        }
      }
    }
  }
  fclose(p);
}
