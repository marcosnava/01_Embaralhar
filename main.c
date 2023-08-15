#include <stdio.h>
#include "pilha.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

enum{
    NAO_SELECIONADA = 0,
    OP_EMBARALHAR,
    OP_DAR_CARTA,
    OP_SAIR,
    TOTAL_CARTAS = 52,
    OUROS = 0,
    COPAS = 1,
    PAUS = 2,
    ESPADAS = 3
};

struct carta {
    int numero;
    int naipe;
    int sorteada;
} cartas[TOTAL_CARTAS];

// Protótipos
void geraBaralho();
void embaralhar();
int sorteado(int posicao);
void imprimeCarta(int posicao);
void imprimeValor(int valor, int lado);
int menu();

int main() {
    int opcao = NAO_SELECIONADA;
    int deuCerto;
    int posicao;

    while(opcao != OP_SAIR)
    {
        opcao = menu();

        switch (opcao) {
            case OP_EMBARALHAR:
                geraBaralho();
                embaralhar();
                break;
            case OP_DAR_CARTA:
                deuCerto = pop(&posicao);
                if(!deuCerto)
                {
                    printf("Nao tem mais cartas!\n");
                }
                else
                {
                    imprimeCarta(posicao);
                }
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao inválida!\n");
        }
    }

    return 0;
}

int menu()
{
    int retorno = 0;

    printf("1 - Embaralhar\n");
    printf("2 - Dar Carta\n");
    printf("3 - Sair\n");

    printf("Digite a sua opcao: ");
    scanf("%d", &retorno);

    return retorno;
}

void geraBaralho()
{
    int naipe = 0;
    int numero = 0;
    int carta = 0;

    flush();

    for(naipe = OUROS; naipe <= ESPADAS; naipe++)
    {
        for(numero = 1; numero < 14; numero++)
        {
            cartas[carta].naipe = naipe;
            cartas[carta].numero = numero;
            cartas[carta].sorteada = FALSE;
            carta++;
        }
    }
}

void embaralhar()
{
    int i;
    int v;
    int deuCerto;

    srand(time(NULL));

    for(i=0; i< 52; i++)
    {
        do {
            v = rand() % 52;
        } while(!sorteado(v));

        cartas[v].sorteada = TRUE;
        deuCerto = push(v);
        if(!deuCerto)
        {
            printf("Estouro de pilha!\n");
        }
    }
}

int sorteado(int posicao)
{
    if(cartas[posicao].sorteada)
    {
        return FALSE;
    }

    return TRUE;
}

void imprimeCarta(int posicao)
{
    printf("+---------+\n");
    imprimeValor(cartas[posicao].numero, TRUE);
    printf("|         |\n");
    if(cartas[posicao].naipe == OUROS)
    {
        printf("|  Ouros  |\n");
    }
    else if(cartas[posicao].naipe == PAUS)
    {
        printf("|  Paus   |\n");
    }
    else if(cartas[posicao].naipe == ESPADAS)
    {
        printf("| Espadas |\n");
    }
    else if(cartas[posicao].naipe == COPAS)
    {
        printf("|  Copas  |\n");
    }
    printf("|         |\n");
    imprimeValor(cartas[posicao].numero, FALSE);
    printf("+---------+\n");
}

void imprimeValor(int valor, int lado)
{
    char esquerda[6];
    char direita[6];

    if(lado)
    {
        strcpy(esquerda, "");
        strcpy(direita, "     ");
    }
    else
    {
        strcpy(esquerda, "     ");
        strcpy(direita, "");
    }
    if(valor == 1) {
        printf("| %sA %s |\n", esquerda, direita);
    }
    else if(valor == 11)
    {
        printf("| %sJ %s |\n", esquerda, direita);
    }
    else if(valor == 12)
    {
        printf("| %sQ %s |\n", esquerda, direita);
    }
    else if(valor == 13)
    {
        printf("| %sK %s |\n", esquerda, direita);
    }
    else
    {
        printf("| %s%2d%s |\n", esquerda, valor, direita);
    }
}