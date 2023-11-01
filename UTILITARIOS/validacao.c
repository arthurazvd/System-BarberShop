#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


//Função de validar nome - desenvolvido a partir do chatGPT - foi testada e aprovada
bool validarnome(char *nome) {
    if (nome == NULL || nome[0] == '\0') {
      return 0; // O nome está vazio
    }

    for (int i = 0; nome[i] != '\0'; i++) {
      if (!isalpha(nome[i]) && nome[i] != ' ') {
        return 0; // Caractere não é uma letra nem espaço
      }
    }

    return 1; // Nome válido
}


//Função de validar CPF - Creditos: https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3
int validarCPF(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0)){
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    }
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2){
            digito1 = 0;
        }
        else{
            digito1 = 11 - digito1;
        }
        if((cpf[9]-48) != digito1){
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        }
        ///digito 2--------------------------------------------------

            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2){
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }

      return 1;
  }
    


//Função de validar telefone
int validartelefone(char *telefone) {
  if (strlen(telefone) != 11) {
    return 0;
  }

  for (int i = 0; i < 11; i++) {
    if (!isdigit(telefone[i])) {
      return 0;
    }
  }

  return 1;
}

//Função para validar data - Desenvolvida com auxilio do Google Bard
int validardata(char *dia, char *mes, char *ano) {
  int dia_int, mes_int, ano_int;

  // Converte os ponteiros char para inteiros
  dia_int = atoi(dia);
  mes_int = atoi(mes);
  ano_int = atoi(ano);

  // Valida a data
  if (dia_int < 1 || dia_int > 31) {
    return 0;
  }
  if (mes_int < 1 || mes_int > 12) {
    return 0;
  }
  int bissexto;
  if (ano_int % 4 == 0 && ano_int % 100 != 0) {
    bissexto = 1;
  } else if (ano_int % 400 == 0) {
    bissexto = 1;
  } else {
    bissexto = 0;
  }
  if (mes_int == 2) {
    if (!bissexto) {
      if (dia_int > 28) {
        return 0;
      }
    } else {
      if (dia_int > 29) {
        return 0;
      }
    }
  }
  if (mes_int == 4 || mes_int == 6 || mes_int == 9 || mes_int == 11) {
    if (dia_int > 30) {
      return 0;
    }
  }

  return 1;
}

struct data {
  int dia;
  int mes;
  int ano;
};

//Função para validar hora - Desenvolvida com auxilio do Google Bard
int validarhora(char *hora, char *minuto) {
  // Valida a hora
  if (atoi(hora) < 0 || atoi(hora) > 23) {
    return 0;
  }

  if (atoi(minuto) < 0 || atoi(minuto) > 59) {
    return 0;
  }

  // Hora é válida
  return 1;
}

//Função para validar numeros - Desenvolvida com auxilio do Google Bard
int validarnumero(char *c) {
  // Valida se a string é composta apenas de números
  for (int i = 0; c[i] != '\0'; i++) {
    if (c[i] < '0' || c[i] > '9') {
      return 0;
    }
  }
  // String é composta apenas de números
  return 1;
}

