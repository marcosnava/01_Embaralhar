//
// Created by nava on 16/02/23.
//

#ifndef INC_01_EMBARALHAR_PILHA_H
#define INC_01_EMBARALHAR_PILHA_H

// Constantes

enum{
    PL_TAMANHO = 52,
    PL_VAZIO = 0
};

// Variáveis
extern int pilha[PL_TAMANHO];
extern int posicao;

// Protótipos
int push(int dado);
int pop(int *valor);
void flush();

#endif //INC_01_EMBARALHAR_PILHA_H
