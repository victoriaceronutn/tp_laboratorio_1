#include <stdio.h>
#include <stdlib.h>

#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* punteroEmployee;
    punteroEmployee = (Employee*) calloc(sizeof(Employee), 1);
    return punteroEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;
    int id, horasTrabajadas, sueldo;
    newEmployee = employee_new();
    if(newEmployee != NULL)
    {
        id = atoi(idStr);
        employee_setId(newEmployee, id);
        employee_setNombre(newEmployee, nombreStr);
        sueldo = atoi(sueldoStr);
        employee_setSueldo(newEmployee, sueldo);
        horasTrabajadas = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(newEmployee,horasTrabajadas);
    }

    return newEmployee;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this != NULL)
    {
        if(id > 0)
        {
            this->id = id;
            retorno = 1;
        }
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retornoisCorrect = 0;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        retornoisCorrect = 1;
    }

    return retornoisCorrect;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retornoisCorrect = 0;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retornoisCorrect = 1;
    }
    return retornoisCorrect;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;
    if(this != NULL)
    {
        if(sueldo > 0)
        {
            this->sueldo = sueldo;
            retorno = 1;
        }
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retornoisCorrect = 0;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retornoisCorrect = 1;
    }
    return retornoisCorrect;
}

void employee_delete(Employee* freeEmployee)
{
    if(freeEmployee != NULL)
    {
        free(freeEmployee);
    }
}

void toString(Employee* oneEmployee)
{
    printf("---ID-----------NOMBRE-----------HORAS-----------SALARIO\n");
	printf("%5d %15s %15d %15d\n", oneEmployee->id, oneEmployee->nombre, oneEmployee->horasTrabajadas, oneEmployee->sueldo);
}

int employee_sortID(void* employeeX, void* employeeY)
{
    int condicion,auxX, auxY;
    employee_getId(employeeX,&auxX);
    employee_getId(employeeY,&auxY);
        if(auxX > auxY)
        {
            condicion = 1;
        }
        else if(auxX == auxY)
        {
            condicion = 0;
        }
        else
        {
            condicion = -1;
        }

    return condicion;
}

int employee_sortHours(void* employeeX, void* employeeY)
{
    int condicion,auxX, auxY;
    employee_getHorasTrabajadas(employeeX,&auxX);
    employee_getHorasTrabajadas(employeeY,&auxY);
        if(auxX > auxY)
        {
            condicion = 1;
        }
        else if(auxX == auxY)
        {
            condicion = 0;
        }
        else
        {
            condicion = -1;
        }

    return condicion;
}

int employee_sortSalary(void* employeeX, void* employeeY)
{
    int condicion,auxX, auxY;
    employee_getSueldo(employeeX,&auxX);
    employee_getSueldo(employeeY,&auxY);
        if(auxX > auxY)
        {
            condicion = 1;
        }
        else if(auxX == auxY)
        {
            condicion = 0;
        }
        else
        {
            condicion = -1;
        }

    return condicion;
}

int employee_sortName(void* employeeX, void* employeeY)
{
    int condicion;
    char auxX[51], auxY[51];
    employee_getNombre(employeeX,auxX);
    employee_getNombre(employeeY,auxY);
        if(strcmp(auxX, auxY) > 0)
        {
            condicion = 1;
        }
        else if(strcmp(auxX, auxY) == 0)
        {
            condicion = 0;
        }
        else
        {
            condicion = -1;
        }

    return condicion;
}
