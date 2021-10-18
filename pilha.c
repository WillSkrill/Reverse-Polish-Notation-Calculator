#include "pilha.h"

//////////////////////////////////////
///////////CRIA PILHA VAZIA///////////
//////////////////////////////////////

Pilha *cria_pilha()
{
    // Cria e aloca mem�ria para struct Pilha
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    // Aponta ponteiro "primeiro" para NULL
    p->primeiro = NULL;
    // Retorna Pilha
    return p;
}


//////////////////////////////////////
///////INSERE NOVO N� NO TOPO/////////
//////////////////////////////////////

void insere_pilha(Pilha *p, float novo_item)
{
    // Cria novo n�
    No *novo_no = (No*) malloc(sizeof(No));
    // Insere item na struct no
    novo_no->item = novo_item;
    // Aponta variavel "proximo" para variavel primeiro da struct Pilha p
    novo_no->proximo = p->primeiro;
    // Variavel primeiro da struct pilha, aponta para novo n�
    p->primeiro = novo_no;
}


//////////////////////////////////////
//////////RETIRA N� DO TOPO///////////
//////////////////////////////////////

float retira_pilha(Pilha *p)
{
    // Cria struct n� auxiliar
    No *aux;
    float item;

    // Se pila for vazia, retorna 0
    if (pilha_verifica(p))
    {
        return 0;
    }

    // Aponta struct auxiliar para primeiro n� da pilha
    aux = p->primeiro;
    // Guarda item do n� atual
    item = aux->item;
    // Primeiro n� da lista passa a ser o pr�ximo
    p->primeiro = aux->proximo;

    // Libera n� atual
    free(aux);

    // Retorna item do n� retirado
    return item;
}


//////////////////////////////////////
/////VERIFICA SE PILHA EST� VAZIA/////
//////////////////////////////////////

int pilha_verifica(Pilha* p)
{
    // Se Pilha for vazia, returna 1
    if(p->primeiro == NULL)
    {
        return 1;
    }

    // Retorna 0 caso Pilha n�o esteja vazia
    return 0;
}


//////////////////////////////////////
//////FAZ OPERA��ES MATEM�TICAS///////
//////////////////////////////////////

float operacao(float operando1, float operando2, char operador)
{
    // Verifica qual o operador
    // E faz opera��o com os antigos 2 �ltimos itens da pilha
    switch(operador)
    {
        case '+':
            return (operando1 + operando2);
          break;

        case '-':
            return (operando1 - operando2);
          break;

        case '*':
            return (operando1 * operando2);
          break;

        case '/':
            return (operando1 / operando2);
          break;

        default:
           return 0.0;
          break;
    }
}


//////////////////////////////////////
/////RESOLVE EXPRESS�O DIGITADA///////
//////////////////////////////////////

float resolve_expressao(Pilha *p, char *expressao, int *verifica)
{
    char *pt;
    float operando1, operando2, resultado, valor;

    // Aponta ponteiro pt para 'express�o' e armazena todos caracteres antes de espa�o (' ')
    pt = strtok(expressao, " ");

    // Repete at� chegar no final da string expressao
    while(pt != NULL)
    {
        // Caso char atual seja um operador
        if ((pt[0] == '+') || (pt[0] == '-') || (pt[0] == '*') || (pt[0] == '/'))
        {
            // Libera �ltimo n� da fila e armazena seu item em 'operando1'
            operando1 = retira_pilha(p);
            // Libera �ltimo n� da fila e armazena seu item em 'operando2'
            operando2 = retira_pilha(p);

            // Caso opera��o seja uma divis�o por 0
            if ((operando1 == 0) && (pt[0] == '/'))
            {
                // Modifica verificador do main para 0
                *verifica = 0;

                // Libera pilha completamente excluindo n� por n�
                pilha_libera(p);

                // Retorna 0
                return(0);
            }

            // Envia operandos e operador para receber resultado da opera��o
            resultado = operacao(operando2, operando1, pt[0]);

            // Insere resultado anterior no topo da pilha
            insere_pilha(p, resultado);
        }

        // Caso char atual n�o seja um operador
        else
        {
            // Printa operando
            printf("%s: ", pt);

            // Recebe valor (via input) de operando
            valor = filtraFloat();
            // Insere valor recebido no topo da pilha
            insere_pilha(p, valor);
        }

        // Ponteiro pt aponta para pr�ximos chars da string antes de espa�o (' ')
        pt = strtok(NULL, " ");
    }

    // Recebe resultado final e apaga n� da pilha
    resultado = retira_pilha(p);

    // Libera pilha completamente excluindo n� por n�, para caso sobre operandos na pilha
    pilha_libera(p);

    // Retorna resultado final
    return resultado;

}


//////////////////////////////////////
//REMOVE TODOS OS N�S E RESETA PILHA//
//////////////////////////////////////

void pilha_libera (Pilha *p)
{
    // Cria dois n�s auxiliares
    // Aux2 aponta para topo da pilha
    No *aux, *aux2 = p->primeiro;

    // Repete enquanto pilha n�o estiver vazia
    while (aux2 != NULL)
    {
        // aux aponta para pr�ximo da pilha (um n� antes do topo)
        aux = aux2->proximo;
        // Remove aux2 que apontava para o topo da pilha
        free(aux2);
        // aux2 aponta para novo topo da pilha
        aux2 = aux;
    }

    // Reseta ponteiro dentro de Pilha *p
    p->primeiro = NULL;
}


