#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


//Função de validar nome - desenvolvido a partir do chatGPT - foi testada e aprovada
bool validarnome(char *nome) {
    if (nome == NULL || nome[0] == '\0') {
        return false; // O nome está vazio
    }

    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return false; // Caractere não é uma letra nem espaço
        }
    }

    return true; // Nome válido
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
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
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
int validardata(int dia, int mes, int ano) {
  if (dia < 1 || dia > 31) {
    return 0;
  }
  if (mes < 1 || mes > 12) {
    return 0;
  }
  int bissexto;
  if (ano % 4 == 0 && ano % 100 != 0) {
    bissexto = 1;
  } else if (ano % 400 == 0) {
    bissexto = 1;
  } else {
    bissexto = 0;
  }
  if (mes == 2) {
    if (!bissexto) {
      if (dia > 28) {
        return 0;
      }
    } else {
      if (dia > 29) {
        return 0;
      }
    }
  }
  if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
    if (dia > 30) {
      return 0;
    }
  }

  return 1;
}
