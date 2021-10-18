#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

/**
 * Verifica se todos os vetores já foram
 * completamente percorridos
 * */
int fimTodosVetores(int iteradores[], Vetor* vetores[], int qtdVetores) {
  for (int i = 0; i < qtdVetores; i++) {
    if (iteradores[i] < getTamanho(vetores[i])) {
      return 0;
    }
  }

  return 1;
}

/**
 * Verifica que algum vetor foi finalizado
 * */
int fimAlgumVetor(int iteradores[], Vetor* vetores[], int qtdVetores) {
  for (int i = 0; i < qtdVetores; i++) {
    if (iteradores[i] >= getTamanho(vetores[i])) {
      return 1;
    }
  }

  return 0;
}

/**
 * Avança todos os iteradores dos vetores informados
 * */
void avancaIteradores(int iteradores[], int qtdIteradores) {
  for (int i = 0; i < qtdIteradores; i++) {
    iteradores[i]++;
  }
}

/**
 * Avança o iterador do vetor que está com o menor valor
 * no momento em que é chamada
 * */
void avancaMenorIterador(int iteradores[], Vetor* vetores[], int qtdVetores) {
  int posMenor = 0;

  for (int i = 0; i < qtdVetores; i++) {
    if (getTamanho(vetores[posMenor]) <= iteradores[posMenor] ||
      (getValorPos(vetores[posMenor], iteradores[posMenor]) > getValorPos(vetores[i], iteradores[i]) &&
        getTamanho(vetores[i]) > iteradores[posMenor])) {
      posMenor = i;
    }
  }

  iteradores[posMenor]++;
}

/**
 * Faz verifica se todos os vetores tem valores iguais
 * de acordo com a posição dos seus iteradores no momento em que é chamada
 * */
int match(int iteradores[], Vetor* vetores[], int qtdVetores) {
  int valor = getValorPos(vetores[0], iteradores[0]);

  for (int i = 0; i < qtdVetores; i++) {
    if (getTamanho(vetores[i]) <= iteradores[i] || 
      valor != getValorPos(vetores[i], iteradores[i])) {
      return 0;
    }
  }

  return 1;
}

/**
 * Faz o matching de n vetores é necessário a criação 
 * de n iteradores, 1 por vetor
 * */
void matching(Vetor* vetores[], int qtdVetores) {
  int iteradores[qtdVetores];
  
  for (int i = 0; i < qtdVetores; i++) {
    iteradores[i] = 0;
  }

  while(!fimAlgumVetor(iteradores, vetores, qtdVetores)) {
    if (match(iteradores, vetores, qtdVetores)) {
      printf("%d\n", getValorPos(vetores[0], iteradores[0]));
      avancaIteradores(iteradores, qtdVetores);
    } else {
      avancaMenorIterador(iteradores, vetores, qtdVetores);
    }
  }
}

/**
 * Dentre os n vetores retorna o menor valor de acordo com a posição 
 * dos iteradores e avança a posição do iterador do respectivo vetor
 * */
int menorValor(int iteradores[], Vetor* vetores[], int qtdVetores) {
  int valor = getValorPos(vetores[0], iteradores[0]);
  int posMenor = 0;

  for (int i = 0; i < qtdVetores; i++) {
    // printf("tamanho v%d - %d --- iterador = %d\n", i, getTamanho(vetores[i]), iteradores[i]);
    if ((getTamanho(vetores[i]) > iteradores[i] &&
      valor > getValorPos(vetores[i], iteradores[i])) ||
      getTamanho(vetores[posMenor]) <= iteradores[posMenor]) {
      valor = getValorPos(vetores[i], iteradores[i]);
      posMenor = i;
    }
  }
  iteradores[posMenor]++;
  // printf("V%d - %d\n", posMenor, valor);
  return valor;
}

/**
 * Realiza o merging total dos valores dos vetores
 * */
void mergingRepeticao(Vetor* vetores[], int qtdVetores) {
  int iteradores[qtdVetores];
  
  for (int i = 0; i < qtdVetores; i++) {
    iteradores[i] = 0;
  }

  while(!fimTodosVetores(iteradores, vetores, qtdVetores)) {
    int menor = menorValor(iteradores, vetores, qtdVetores);
    printf("%d\n", menor);
  }
}

/**
 * Realiza o merging (união) os valores dos vetores
 * */
void merging(Vetor* vetores[], int qtdVetores) {
  int iteradores[qtdVetores];
  
  for (int i = 0; i < qtdVetores; i++) {
    iteradores[i] = 0;
  }

  int ultimoPrintado = 0;
  int qtdPrintado = 0;

  while(!fimTodosVetores(iteradores, vetores, qtdVetores)) {
    int menor = menorValor(iteradores, vetores, qtdVetores);
    if (qtdPrintado == 0 || ultimoPrintado != menor) {
      printf("%d\n", menor);
      ultimoPrintado = menor;
      qtdPrintado++;
    }
  }
}