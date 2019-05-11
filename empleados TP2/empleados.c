#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"


int initEmployees(Employee* list, int len)
{
    int retornar;
    int i;
    if(list != NULL)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty= 0;
        }
        retornar= 0;
    }
    else
    {
        retornar= -1;
    }
    return retornar;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    return -1;
}

int addEmployeesModificado(Employee* paramEmployee,int len)
{
    int i;
    int id;
    int sector;
    int retorno= -1;
    float salary;
    char auxSalary[50];
    char auxSector[50];

    i= getSpace(paramEmployee, len);
    id= NextId(paramEmployee, len);

    if(i>=0)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(paramEmployee[i].name);

        while(onlyLetter(paramEmployee[i].name) == 0)
        {
            printf("ERROR, vuelva a ingresar: ");
            fflush(stdin);
            gets(paramEmployee[i].name);
        }
        stringToUpper(paramEmployee[i].name);


        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(paramEmployee[i].lastName);

        while(onlyLetter(paramEmployee[i].lastName) == 0)
        {
            printf("ERROR, vuelva a ingresar: ");
            fflush(stdin);
            gets(paramEmployee[i].lastName);
        }
        stringToUpper(paramEmployee[i].lastName);


        printf("Ingrese salario: ");
        fflush(stdin);
        gets(auxSalary);

        while(numeric(auxSalary) == 0)
        {
            printf("ERROR, vuelva a ingresar: ");
            fflush(stdin);
            gets(auxSalary);
        }
        salary=atoi(auxSalary);
        paramEmployee[i].salary=salary;


        printf("Ingrese sector: ");
        fflush(stdin);
        gets(auxSector);

        while(numeric(auxSector)==0)
        {
            printf("ERROR, vuelva a ingresar: ");
            fflush(stdin);
            gets(auxSector);
        }
        sector= atoi(auxSector);
        paramEmployee[i].sector= sector;

        paramEmployee[i].isEmpty =1;
        paramEmployee[i].id =id;

        retorno =0;

        printf("\n se cargo.\n");
    }
    else
    {
        printf("\n no hay espacio.\n");
    }
    return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1 && list[i].id==id)
        {
            return i;
        }//end if
    }//end for
    return -1;
}


int removeEmployee(Employee* paramEmployee, int len)
{
    int i;
    int idPers;
    int opcion;
    printEmployees(paramEmployee, len);

    printf("\nIngrese el id del empleado que quiera dar de baja.\n");
    scanf("%d",&idPers);

    for(i=0; i<len; i++)
    {
        if(idPers==paramEmployee[i].id)
        {
            printf("Desea dar de baja? Ingrese(0-s/1-n)\n");
            scanf("%d",&opcion);

            if (opcion == 0)
            {
                paramEmployee[i].isEmpty = 0;
                paramEmployee[i].id= 0;
                printf("Se ha dado de baja.\n");
                break;
            }
            else if (opcion == 1)
            {
                printf("No se ha dado de baja.\n");
                break;
            }
            else
            {
                printf("Error. Ingrese una opcion valida.\n");
                break;
            }
        }
    }
}


int sortEmployees(Employee* paramEmployee, int len, int order)
{
    Employee auxEmployee;
    int i;
    int j;

    char auxOpcion[50];
    int opcion;

    printf("\n Como quiere la orden de la lista?\n");
    printf(" 1) Por apellido.\n");
    printf(" 2) Por sector.\n");

    printf("\n elija opcion: ");
    fflush(stdin);
    gets(auxOpcion);

    while(numeric(auxOpcion)==0)
    {
        printf("ERROR, vuelva a ingresar: ");
        fflush(stdin);
        gets(auxOpcion);
    }
    opcion=atoi(auxOpcion);

    if(opcion==1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(paramEmployee[i].lastName,paramEmployee[j].lastName) > order)
                {
                    auxEmployee=paramEmployee[i];
                    paramEmployee[i]=paramEmployee[j];
                    paramEmployee[j]=auxEmployee;
                }
            }
        }
    }
    else if(opcion==2)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(paramEmployee[i].sector > paramEmployee[j].sector)
                {
                    auxEmployee=paramEmployee[i];
                    paramEmployee[i]=paramEmployee[j];
                    paramEmployee[j]=auxEmployee;
                }
            }
        }
    }
    else
    {
        printf("ERROR, vuelva ");
    }
}


void employeeOnly(Employee paramEmployee)
{
    printf("%d -- %10s %15s %20f %10d\n\n", paramEmployee.id, paramEmployee.name, paramEmployee.lastName,
            paramEmployee.salary, paramEmployee.sector);
}


int printEmployees(Employee* paramEmployee, int len)
{
    printf("\n\n ID -- \t NAME \t\t LASTNAME \t SALARY \t\t SECTOR\n\n");

    int i;
    for(i=0; i<len; i++)
    {
        if (paramEmployee[i].isEmpty == 1)
        {
            employeeOnly(paramEmployee[i]);
        }
    }
}


int getSpace(Employee* paramEmployee, int len)
{
    int index= -1;
    int i;
    for (i=0; i<len; i++)
    {
        if (paramEmployee[i].isEmpty == 0)
        {
            index= i;
            break;
        }
    }
    return index;
}


int NextId(Employee* paramEmployee, int len)
{
    int retorno= 0;
    int i;
    if(len > 0 && paramEmployee != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(paramEmployee[i].isEmpty == 1)
            {
                if(paramEmployee[i].id > retorno)
                {
                    retorno = paramEmployee[i].id;
                }
            }
        }
    }
    return retorno+1;
}


void initEmployeesWithData(Employee* paramEmployee, int len)
{
    int id[5] = {4,6,9,1,7};
    char name[5][51] = {"Alejandro","Leonardo","Lautaro","sandra","Sofia"};
    char lastName[5][51] = {"Rodriguez","Gomez","Espinoza","Fernez","Sanchez"};
    float salary[5] = {2300,3460,5800,6000,6700};
    int sector[5] = {3,6,10,25,30};

    int i;
    for (i=0; i<5; i++)
    {
        paramEmployee[i].id = id[i];
        strcpy(paramEmployee[i].name, name[i]);
        strcpy(paramEmployee[i].lastName, lastName[i]);
        paramEmployee[i].salary = salary[i];
        paramEmployee[i].sector = sector[i];
        paramEmployee[i].isEmpty = 1;
    }
}


int modificationEmployee(Employee* paramEmployee, int len)
{

    int index;
    char auxId[20];
    int id;
    int rt;
    int retorno= -2;

    if(len>0 && paramEmployee!=NULL)
    {
        retorno=-1;
        printEmployees(paramEmployee, len);
        printf("Ingrese el ID: ");
        fflush(stdin);
        gets(auxId);
        while(numeric(auxId)==0)
        {
            printf("Error. Se ha ingresado una opcion invalida: ");
            fflush(stdin);
            gets(auxId);
        }
        id=atoi(auxId);
        index=findEmployeeById(paramEmployee, len, id);

        if(index>=0)
        {
            rt=menuModificado(paramEmployee, index);
            retorno=rt;
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}


int menuModificado(Employee* paramEmployee, int index)
{
    int opcion;
    int sector;
    int retorno=-1;
    char auxOpcion[30];
    char auxName[30];
    char auxLastName[30];
    char auxSalary[30];
    char auxSector[30];
    float salary;

    printf("\n ¿que quiere modificar?\n");
    printf(" 1) nombre.\n");
    printf(" 2) apellido.\n");
    printf(" 3) salario.\n");
    printf(" 4) sector.\n");

    printf("Elija una opcion: ");
    fflush(stdin);
    gets(auxOpcion);

    while(numeric(auxOpcion)==0)
    {
        printf("Error. Se ha ingresado una opcion invalida: ");
        fflush(stdin);
        gets(auxOpcion);
    }
    opcion=atoi(auxOpcion);

    if(opcion>=1&&opcion<=6)
    {
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre:");
            fflush(stdin);
            gets(auxName);
            while(onlyLetter(auxName)==0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxName);
            }
            stringToUpper(auxName);
            strcpy(paramEmployee[index].name, auxName);
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        case 2:
            printf("Ingrese el nuevo apellido:");
            fflush(stdin);
            gets(auxLastName);
            while(onlyLetter(auxLastName)==0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxLastName);
            }
            stringToUpper(auxLastName);
            strcpy(paramEmployee[index].lastName, auxLastName);
            printf("\n\nSe ha realizado la modificacion.\n\n");
            retorno=index;
            break;

        case 3:
            printf("Ingrese el nuevo salario:");
            fflush(stdin);
            gets(auxSalary);
            while(numeric(auxSalary)==0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxSalary);
            }

            salary = atoi(auxSalary);
            paramEmployee[index].salary = salary;
            printf("\n\nSe ha modificado.\n\n");
            retorno=index;
            break;

        case 4:
            printf("Ingrese el nuevo sector:");
            fflush(stdin);
            gets(auxSector);
            while(numeric(auxSector)==0)
            {
                printf("Error. Se ha ingresado una opcion invalida: ");
                fflush(stdin);
                gets(auxSector);
            }
            sector = atoi(auxSector);
            paramEmployee[index].sector = sector;
            printf("\n\nSe ha modificado.\n\n");
            retorno=index;
            break;

        default:
            printf("\n ERROR, ingrese una opcion valida.\n");
            return -2;
            break;
        }
    }
    else
    {
        printf("\nError. Se ha ingresado una opcion invalida.\n");
        return -2;
    }
    return retorno;
}
