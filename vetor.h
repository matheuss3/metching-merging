#ifndef _VETOR_H
#define _VETOR_H

typedef char* Vetor;

Vetor* criaVetor(char* arquivoVetor, int tamanho);

int getValorPos(Vetor* v, int p);

int getTamanho(Vetor* v);

#endif