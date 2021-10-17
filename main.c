#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char *argv[]) {
  Vetor* vetores[3];

  vetores[0] = criaVetor("V1", 9);
  vetores[1] = criaVetor("V2", 5);
  vetores[2] = criaVetor("V1", 8);

  mergingRepeticao(vetores, 3);
  
  return 0;
}
