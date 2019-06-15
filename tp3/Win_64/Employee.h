#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea empleado nuevo.
 *
 * \return Employee*
 */
Employee* employee_new();

/** \brief Crea un empleado.
 * \param idStr char* Id como string
 * \param nombreStr char* nombre como string
 * \param horasTrabajadasStr char* horas como string
 * \param sueldoStr char*  sueldo como string
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/** \brief Hace un free.
 *
 * \param Employee*
 * \return void
 *
 */
void employee_delete(Employee*);

/** \brief Settea el id.
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Obtiene el id.
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Settea el nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief obtiene el nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Settea las horas que trabajo
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Obtiene las horas que trabajo
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Settea el sueldo
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief obtiene el sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Muestra los datos de un empleado
 *
 * \param oneEmployee Employee*
 * \return void
 *
 */
void toString(Employee* oneEmployee);

/** \brief ordena los Id
 *
 * \param employeeX void*
 * \param employeeY void*
 * \return int
 *
 */
int employee_sortID(void* employeeX, void* employeeY);
/** \brief Ordena los nombres
 *
 * \param employeeX void*
 * \param employeeY void*
 * \return int
 *
 */
int employee_sortName(void* employeeX, void* employeeY);
/** \brief ordena la hora
 *
 * \param employeeX void*
 * \param employeeY void*
 * \return int
 *
 */
int employee_sortHours(void* employeeX, void* employeeY);
/** \brief ordena los salarios
 *
 * \param employeeX void*
 * \param employeeY void*
 * \return int
 *
 */
int employee_sortSalary(void* employeeX, void* employeeY);


#endif // employee_H_INCLUDED
