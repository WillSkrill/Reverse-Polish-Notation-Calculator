#include "pilha.h"


int main()
{

    setlocale(LC_ALL, "Portuguese");

    // Cria Pilha vazia
    Pilha *p = cria_pilha();

    int verifica = 1;
    float resultado = 0.0;
    char expressao[TAM1];

    // Printa mensagem inicial
    system("cls");
    yellow();
    printf("        Calculadora de expressões\n");
    reset();
    printf("   Digite 'manual' para ver instruções\n\n ");
    system("pause");
    system("cls");

    yellow();
    printf("________________________________________________\n\n\n");
    reset();

    for (;;)
    {
        // Reseta string "expressao"
        memset(expressao, '\0', sizeof(expressao));

        yellow();
        printf("Digite uma expressão:  ");
        reset();

        // Recebe input de string
        fgets(expressao, 33 * sizeof(char), stdin);
        // Retira "\n" da string
        expressao[strcspn(expressao, "\n")] = 0;

        // Se usuário digitar sair ou não teclar nada
        if ((strcmp(expressao, "\000") == 0) || (strcmp(expressao, "sair") == 0))
        {
            // Fecha programa
            return 0;
        }

        // Caso usuário digite 'manual' para ver as instruções do programa
        else if (strcmp(expressao, "manual") == 0)
        {
            // Printa instruções
            system("cls");
            yellow();
            printf(". Por favor, utilize 'espaço' entre os operadores e operandos.\n");
            reset();
            printf("  Exemplo: 'A B - C *'\n\n");
            yellow();
            printf(". Aperte 'enter' sem nenhum input ou digite 'sair' para fechar o programa.\n\n\n  ");
            reset();
            system("pause");
            system("cls");
        }

        // Caso o usuário digite uma expressão
        else
        {
            // Resolve expressão e retorna resultado
            resultado = resolve_expressao(p, expressao, &verifica);

            // Caso operação tenha sido um sucesso
            if (verifica != 0)
            {
                // Printa resultado
                printf("\nO resultado da operação é:  ");
                green();
                printf("%.3f\n\n", resultado);
                reset();
                yellow();
                printf("________________________________________________\n\n\n");
                reset();
            }

            // Caso operação tenha falhado (Caso tenha divisão por 0)
            else
            {
                red();
                printf("\nImpossível resolver divisão com 0!\n\n");
                reset();

                yellow();
                printf("________________________________________________\n\n\n");
                reset();
            }

            // Reseta verificador
            verifica = 1;
        }
    }
}
