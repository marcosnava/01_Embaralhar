//
// Created by nava on 16/02/23.
//

#include "pilha.h"

// Variáveis
int pilha[PL_TAMANHO];
int posicao = 0;

BOOLEAN push(int dado)
{
    if(posicao == PL_TAMANHO) // Se a pilha estiver cheia
    {
        return FALSE;
    }

    pilha[posicao] = dado;
    posicao++;

    return TRUE;
}

BOOLEAN pop(int *valor)
{
    if(posicao == PL_VAZIO)
    {
        return FALSE;
    }

    posicao--;
    *valor = pilha[posicao];

    return TRUE;
}

void flush()
{
    posicao = 0;
}