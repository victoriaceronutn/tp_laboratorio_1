#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int x, i = 0;
    Employee* newEmployee = employee_new();
    char auxID[51], auxName[51], auxHoursWorked[51], auxSalary[51];
    if(pFile == NULL)
    {
        return 1;
    }
    do
    {
        x = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxName, auxHoursWorked, auxSalary);
        if(x == 4)
        {
            newEmployee = employee_newParametros(auxID, auxName, auxHoursWorked, auxSalary);
            ll_add(pArrayListEmployee, newEmployee);
            i++;
        }
        else
        {
            break;
        }
    }while(!feof(pFile));
    printf("Se cargaron %d datos de empleados (modo txt)\n", i);
    return 1;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i = 0;
    Employee auxEmployee;
    if(pFile == NULL)
    {
        return 1;
    }
    else
    {
         do
        {
            Employee* newEmployee = employee_new();
            employee_setId(newEmployee, auxEmployee.id);
            employee_setNombre(newEmployee, auxEmployee.nombre);
            employee_setHorasTrabajadas(newEmployee, auxEmployee.horasTrabajadas);
            employee_setSueldo(newEmployee, auxEmployee.sueldo);
            ll_add(pArrayListEmployee, newEmployee);
            fread(&auxEmployee,sizeof(Employee),1,pFile);
            i++;
        }while(!feof(pFile));
    }
    printf("Se cargaron %d datos de empleados (modo binario)\n", i);
    return 1;
}
