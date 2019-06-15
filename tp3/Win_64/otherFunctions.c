#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "otherFunctions.h"


int getInt(char text[])
{
    int option;

    printf("%s",text);
    scanf("%d",&option);

    return option;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    gets(input);
}

int isNumber(char str[])
{
    int i = 0;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if(str[i]< '0' || str[i]> '9')
        {
            retorno = 0;
        }
        i++;
    }
    return retorno;
}

int isCero(char str[])
{
    int i = 0;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if(str[3] == '0')
        {
            retorno = 0;
        }
        i++;
    }
    return retorno;

}

int isAlphabeticalNum(char str[])
{
    int i=0;
    int retorno = 1;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] != '\0') && (str[i]< '0' || str[i]> '9'))
        {
            retorno = 0;
        }
        i++;
    }
    return retorno;
}

int showMainMenu()
{
    int option;

    option = getInt("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\nIngrese opcion: ");

    return option;
}


