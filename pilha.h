#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM1 33 // Define tamanho m�ximo da express�o recebida
#define TAM2 32 // Define tamanho m�ximo para fun��o filtraFloat()

// Struct n�
typedef struct no {
    float item;
    struct no *proximo;
} No;

//Struct pilha
typedef struct pilha {
    No *primeiro;
} Pilha;

Pilha *cria_pilha(); // Cria pilha vazia
void insere_pilha(Pilha *p, float novo_item); // Insere novo n� no topo da pilha
int pilha_verifica(Pilha* p); // Verifica se pilha est� vazia
float retira_pilha(Pilha *p); // Retirar n� do topo da pilha
float operacao(float operando1, float operando2, char operador); // Faz opera��o entre operandos rescebidos
float resolve_expressao(Pilha *p, char *expressao, int *verifica); // Inicia calculadora
void pilha_libera (Pilha *p); // Libera todos os n�s da pilha

// Filtra float
float filtraFloat();

// Define cores
void red();
void green();
void yellow();
void reset();


#endif // PILHA_H_INCLUDED
