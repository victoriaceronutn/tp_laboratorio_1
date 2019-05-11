#include <stdio.h>
#include <stdlib.h>
#include "input.h"


int getInt (char mensaje[])
{
    int auxInt;
    printf("%s", mensaje);
    scanf("%d", &auxInt);
    return auxInt;
}


char getChar (char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}


float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}

void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0; i<largo; i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}


int numeric(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int contValor(char str[])
{
    int i=0;
    int contadorGuiones = 0;
    while (str[i] != '\0')
    {
        if ((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if (str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if (contadorGuiones==1)
        return 1;
    return 0;
}


int onlyLetter(char str[])
{
    int i=0;
    while (str[i]!='\0')
    {
        if((str[i] != ' ') && (str[i]<'a' || str[i]>'z') &&
           (str[i]<'A' || str[i]>'Z'))
            return 0;
        i++;
    }
    return 1;
}


int isAlphaNumeric(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i]< 'a' || str[i]>'z') &&
           (str[i]< 'A' || str[i]>'Z') && (str[i]<'0' || str[i]>'9'))
            return 0;
        i++;
    }
    return 1;
}
