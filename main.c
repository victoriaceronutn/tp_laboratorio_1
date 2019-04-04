#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    float a=0;
    float b=0;
    int opcion=0;
    int operacion=0;

    //VARIABLES
    float sumar;
    float resta;
    float dividir;
    float multiplicar;
    int factorialA;
    int factorialB;

    printf("Elija una de las siguientes opciones\n");

    do
    {
        printf("1.Ingresar 1er operando(A=x)\n");
        printf("2.Ingresar 2do operando(B=y)\n");
        printf("3.Calcular todas las operaciones\n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1: //INGRESE A
                printf("\n Ingrese un numero: ");
                scanf("%f",&a);
                fflush(stdin);
                break;

            case 2: //INGRESE B
                printf("\n Ingrese otro numero: ");
                scanf("%f",&b);
                fflush(stdin);
                break;

            case 3: //OPCIONES
                sumar=suma(a,b);
                resta=restar(a,b);
                dividir=division(a,b);
                multiplicar=multiplicacion(a,b);
                factorialA=factorial(a);
                factorialB=factorial(b);
                operacion = 1;
                break;

            case 4: //OPERACIONES
                if ( operacion == 1 )
                {
                    printf("\n1.El resultado de A+B es: %f", sumar);
                    printf("\n2. El resultado de A-B es: %f", resta);
                    if (b == 0)
                    {
                        printf("\n3. No es posible dividir por cero");
                    }
                    else
                    {
                        printf("\n3. El resultado de A/B es: %f", dividir);
                    }
                    printf("\n4. El resultado de A*B es: %f", multiplicar );


                    if ( a < 0 && b < 0 )
                    {
                            printf("\n 5.el factorial de un numero negativo en A y B no existe\n");
                    }
                    else
                    {
                        if (a<0 && b>=0)
                        {
                            printf("\n 5.Ingreso un numero negativo que en A no se puede cumplir. El factorial de B es %d\n", factorialB);
                        }
                        else
                        {
                            if (a>= 0 && b<0)
                            {
                                printf("\n 5.El factorial de A es %d y el factorial negativo en B no se cumple.\n", factorialA);
                            }
                            else
                            {
                                printf("\n5. El factorial de A es: %d y El factorial de B es %d\n", factorialA, factorialB);
                                break;
                            }

                        }

                     }

            case 5://SALIR
                break;
                default:
                    printf("\nERROR, vuelva a ingresar\n\n");
                    break;

              }
              system("pause");
              system("cls");//"refresca la pantalla".

        }

      }while(opcion!=5);
       return 0;

}

