#include "pilha.h"

//////////////////////////////////////
/////////////DEFINE CORES/////////////
//////////////////////////////////////

void red()
{
  printf("\033[1;31m");
}

void green()
{
  printf("\033[0;32m");
}

void yellow()
{
  printf("\033[1;33m");
}

void reset()
{
  printf("\033[0m");
}


//////////////////////////////////////
////////////FILTRA FLOAT//////////////
//////////////////////////////////////

float filtraFloat()
{
    char triagem[TAM2];
    float num_float;

    fgets(triagem, sizeof triagem, stdin);

    num_float = atof(triagem);

    return num_float;

}
