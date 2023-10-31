#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void salvar_dados(void *dados, const char *nome_arquivo, const char *tipo_arquivo) {
  // Abre o arquivo para gravação.
  FILE *arquivo = fopen(nome_arquivo, tipo_arquivo);
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo '%s'.\n", nome_arquivo);
    return;
  }

  // Percorre os campos do struct.
  for (int i = 0; i < sizeof(dados) / sizeof(char *); i++) {
    // Escreve o campo no arquivo.
    fwrite(dados, sizeof(char), strlen((char *)dados), arquivo);
  }

  // Fecha o arquivo.
  fclose(arquivo);
}

void recuperar_dados(char *nome_arquivo) {
  FILE *arquivo = fopen(nome_arquivo, "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
    return;
  }

  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    printf("%s\n", linha);
  }

  fclose(arquivo);
}