#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char *argv[]) {
  Vetor* vetores[3];

  vetores[0] = criaVetor("V1", 100000);
  vetores[1] = criaVetor("V3", 100000);
  vetores[2] = criaVetor("V3", 100000);

  printf("Merging repeticao\n");
  mergingRepeticao(vetores, 3);
  
  // printf("Merging\n");
  // merging(vetores, 3);

  // printf("Matching\n");
  // matching(vetores, 3);
  
  return 0;
}
