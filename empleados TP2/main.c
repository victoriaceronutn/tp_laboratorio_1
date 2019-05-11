
// alumna: Angeles Victoria Cerón.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#define E 50

int main()
{
    int i;
    int estadoInicializacionDeEmpleados;
    int acumuladorSalario;
    int contadorSalario;
    int contadorSalariosMayorAlPromedio;
    int validarNuevoEmployee;
    float promedioSalario;
    char opcion;
    Employee myEmployees[E];
    estadoInicializacionDeEmpleados = initEmployees(myEmployees, E);

    if(estadoInicializacionDeEmpleados == 0)
    {
        printf("inicializacion lista.\n");
    }
    else
    {
        printf("Error de inicializacion.");
    }

    initEmployeesWithData(myEmployees, E);

    system("pause");
    system("cls");

    do
    {
        printf(" 1) ALTA DE EMPLEADO. \n");
        printf(" 2) MODIFICAR EMPLEADO. \n");
        printf(" 3) BAJA DE EMPLEADO. \n");
        printf(" 4) MOSTRAR LISTADO. \n");
        printf(" 5) INFORMAR PROMEDIOS. \n");
        printf(" 6) SaLIR. \n");
        printf("\n  Elija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);
        while (opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='6')
        {
            printf("ERROR, vuelva a ingresar.\n\n");
            printf("Elija opcion: ");
            fflush(stdin);
            scanf("%c", &opcion);
        }

        switch(opcion)
        {
        case '1':
            validarNuevoEmployee = addEmployeesModificado(myEmployees, E);
            break;

        case '2':
            modificationEmployee(myEmployees, E);
            break;

        case '3':
            removeEmployee(myEmployees, E);
            break;

        case '4':
            sortEmployees(myEmployees, E, 0);
            printEmployees(myEmployees, E);
            break;

        case '5':
            contadorSalario = 0;
            acumuladorSalario = 0;
            contadorSalariosMayorAlPromedio = 0;
            promedioSalario = 0;

            for (i=0; i<E; i++)
            {
                if (myEmployees[i].isEmpty == 1)
                {
                    acumuladorSalario = myEmployees[i].salary + acumuladorSalario;
                    contadorSalario++;
                }
            }
            promedioSalario=(acumuladorSalario/contadorSalario);
            for (i=0; i<E; i++)
            {
                if (myEmployees[i].isEmpty == 1 && myEmployees[i].salary > promedioSalario)
                {
                    contadorSalariosMayorAlPromedio++;
                }
            }
            printEmployees(myEmployees, E);
            printf("El promedio es: %f\n", promedioSalario);
            printf("Los empleados con alto sueldo promedio son: %d\n", contadorSalariosMayorAlPromedio);
            break;

        case '6':
            opcion='6';
            printf("saliendo \n");
            break;

        default:
            printf("Error. Elija una opcion valida.\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!='6');

    return 0;
}
