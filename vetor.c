#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vetor {
  char* nomeArquivo; // Arquivo onde o vetor ta armazenado
  int tamanho;
} Vetor;

/**
 * Verifica se e possivel abrir o arquivo
 * */
FILE* abreArquivo(char* nomeArquivo) {
  FILE* f = fopen(nomeArquivo, "r");

  if (f == NULL) {
    printf("Arquivo inexistente..\n");
    exit(1);
  }

  return f;
}

void fechaArquivo(FILE* f) {
  if (f != NULL) fclose(f);
}

/**
 * Aloca a memória necessária para a estrutura do vetor
 * */
Vetor* criaVetor(char* arquivoVetor, int tamanho) {
  Vetor* v = (Vetor *) malloc(sizeof(Vetor));
  v->nomeArquivo = arquivoVetor;
  FILE* f = abreArquivo(v->nomeArquivo);

  v->tamanho = tamanho;

  fechaArquivo(f);

  return v;
}

/**
 * Retorna o valor dado uma posição do vetor
 * A funcão abre o arquivo e lê linha a linha
 * até a posição desejada
 * */
int getValorPos(Vetor* v, int p) {
  int valor;
  FILE* f = abreArquivo(v->nomeArquivo);

  int k = 0;
  while (fscanf(f, "%d", &valor) != EOF && k < p) {
    k++;
  }

  fechaArquivo(f);
  return valor;
}

/**
 * Retorna o tamanho do maior vetor
 * */
int getTamanho(Vetor* v) {
  return v->tamanho; 
}