#include "headers.h"
#include <stdlib.h>
#include <stdio.h>

struct vetor
{
    int a;
    int b;
};

Vetor * criar_vetor(int a, int b)
{
    Vetor *v = (Vetor *) malloc(sizeof(Vetor));
    v->a = a;
    v->b = b;
    return v;
}
void remover_vetor(Vetor **v)
{
}
void setar_vetor(Vetor *v, int a, int b)
{

}
void obter_vetor(Vetor *v, int *a, int *b)
{
}
Vetor *somar_vetores(Vetor *v1, Vetor *v2)
{
}
Vetor *subtrair_vetores(Vetor *v1, Vetor *v2)
{
}
void mostrar_vetor(Vetor *v)
{
    printf("(%d,%d)", v->a, v->b);
}
int produto_escalar(Vetor *v1, Vetor *v2)
{
}
void produto_escalar_por_vetor(Vetor *v, int k)
{
}