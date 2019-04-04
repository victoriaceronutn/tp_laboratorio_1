#include <stdio.h>

int suma(float x, float y)
{
    int suma=x+y;
    return suma;
}

int restar(float x, float y)
{
    int restar=x-y;
    return restar;
}

float division(float x, float y)
{
    float division=x/y;
    return division;
}

int multiplicacion(float x, float y)
{
    int multiplicacion=x*y;
    return multiplicacion;
}

float factorial(float x)
{
    int i;
    int contador = 1;
    for ( i = 1; i <= x; i++)
    {
        contador = contador*i;
    }
    return contador;
}

