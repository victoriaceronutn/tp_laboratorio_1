#include <stdio.h>
#include <stdlib.h>

#include <conio.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "otherFunctions.h"

/** \brief Carga los datos de los empleados.
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "r");
    int retorno = 0;
    if(pFile == NULL)
    {
        retorno = 1;
    }
    else
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "rb");
    int retorno;
    if(pFile == NULL)
    {
        printf("No se pudo cargar la esctructura...\n");
        retorno = 0;
        fclose(pFile);
    }
    else
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        retorno = 1;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee = employee_new();
    char auxID[51], auxName[51], auxHoursWorked[51], auxSalary[51];
    int i, retorno = 0, len, getId;
    len = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL)
    {
        getId = getInt("\nIngrese el id del nuevo empleado: ");
        itoa(getId, auxID, 10);
        for(i=0; i<len; i++)
        {
            newEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(getId == newEmployee->id)
            {
                printf("Id existente...\n");
                retorno = 1;
                break;
            }
        }
        if(getId != newEmployee->id)
        {
            getString("Ingrese nombre de Empleado: ", auxName);
            getString("Ingrese horas que trabajo: ", auxHoursWorked);
            getString("Ingrese salario de Empleado: ", auxSalary);
            newEmployee = employee_newParametros(auxID, auxName, auxHoursWorked, auxSalary);
            ll_add(pArrayListEmployee, newEmployee);
            printf("\n--Empleado dado de alta con exito--\n");
        }
    }
    return retorno;
}

/** \brief Modificar datos.
 *
 * \param
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = employee_new();
    int auxID, auxHoursWorked, auxSalary, i, len, option = 0, flag = 0;
    char  auxName[51];
    len = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL)
    {
        auxID = getInt("\nIngrese el id del empleado a modificar: ");
        for(i=0; i<len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(auxID == auxEmployee->id)
            {
                toString(auxEmployee);
                do
                {
                    option = getInt("\n1.Nombre\n2.Horas\n3.Salario\n4.Salir\nIngresar una opcion: ");
                    switch(option)
                    {
                        case 1:
                            getString("Ingrese nombre de Empleado: ", auxName);
                            employee_setNombre(auxEmployee, auxName);
                            break;
                        case 2:
                            auxHoursWorked = getInt("Ingrese horas que trabajo: ");
                            employee_setHorasTrabajadas(auxEmployee, auxHoursWorked);
                            break;
                        case 3:
                            auxSalary = getInt("Ingrese salario de Empleado: ");
                            employee_setSueldo(auxEmployee, auxSalary);
                            break;
                        case 4:
                            option = 4;
                            break;
                        default:
                            printf("Opcion incorrecta...\n");
                            break;
                    }
                }while(option != 4);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("Empleado no encontrado...\n");
        }
    }
    return 1;
}

/** \brief Baja de empleado.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxID,i,len, flag = 0;
    char option;
    Employee* auxEmployee;
    len= ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL)
    {
        auxID = getInt("Ingrese el id del empleado a dar de baja: ");
        for(i = 0; i < len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if( auxID == auxEmployee->id)
            {
                toString(auxEmployee);
                printf("Desea dar de baja?: ");
                option = getche();
                if(option == 's')
                {
                    ll_remove(pArrayListEmployee, i);
                    printf("\nEmpleado dado de baja\n");
                    employee_delete(auxEmployee);
                }
                else
                {
                    printf("El empleado no fue dado de baja\n");
                }
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0)
    {
        printf("Ese ID no existe...\n");
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i, len, auxID, auxHoursWorked, auxSalary, flag = 0;
    char auxName[51];
    Employee* auxEmployee;
    len = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL)
    {
        printf("---ID--------------NOMBRE--------------HORAS--------------SALARIO\n");
        for(i=0; i<len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &auxID);
            employee_getNombre(auxEmployee, auxName);
            employee_getHorasTrabajadas(auxEmployee, &auxHoursWorked);
            employee_getSueldo(auxEmployee, &auxSalary);
            printf("%5d %15s %20d %20d\n", auxID, auxName, auxHoursWorked, auxSalary);
        }
        flag = 1;
    }
    if(flag == 0)
    {
        printf("No se pudo cargar la lista...\n");
    }
    return 1;
}

/** \brief Ordenar empleados.
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int order, option;
    if(pArrayListEmployee != NULL)
    {
        option = getInt("\n1. Ordenar por ID\n2. Ordenar por Nombre\n3. Ordenar por Horas\n4. Ordenar por salario\nIngrese una opcion: ");
        order = getInt("\nOrdenamiento Ascendente [1] o Descendente[0]: ");
        switch(option)
        {
            case 1:
                ll_sort(pArrayListEmployee, employee_sortID, order);
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_sortName,order);
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_sortHours,order);
                break;
            case 4:
                ll_sort(pArrayListEmployee, employee_sortSalary,order);
                break;
            default:
                printf("Opcion Incorrecta...");
                break;
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmployee;
    int len;
    pFile = fopen(path,"w");
    len = ll_len(pArrayListEmployee);
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        for(int i = 1; i < len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFile,"%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        }
        printf("Datos guardados con exito. (txt)\n");
        fclose(pFile);
    }
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo...\n");
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmployee;
    int len;
    pFile = fopen(path,"wb");
    len = ll_len(pArrayListEmployee);
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        for(int i = 1; i < len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(auxEmployee, sizeof(Employee), 1, pFile);
        }
        printf("Datos guardados con exito.(binario)\n");
        fclose(pFile);
    }
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo...\n");
    }
    return 1;
}
