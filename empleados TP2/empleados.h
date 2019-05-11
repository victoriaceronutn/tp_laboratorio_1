#include "input.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;

/** \brief indica que arrays esta lleno
 * flag (isEmpty), si es verdadero.
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \return
 *
 */
int initEmployees(Employee* list, int len);

/** \brief se le agrega la funcion, add employees.
 *
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \return
 *
 */
int addEmployeesModificado(Employee*,int);

/** \brief encontar un empleado de id y retornarlo
 *
 * \param
 * \param len int Array (length)
 * \param int id
 * \return Return employee index
 *
 */
int findEmployeeById(Employee* list, int len, int id);

/** \brief Remover Employee de Id
 *y poner "isEmpty" (lleno) en la bandera(flag).
 * \param
 * \param len int Array (length)
 * \param id int
 * \return int Return
 *
 */
int removeEmployee(Employee*, int);

/** \brief (Sort)para array del empleado, argument order:UP-DOWN orden.
 *
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \param order int[1]UP - int[0]DOWN
 * \return int Return
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief (print)copia el contenido de arrays empleado
 *
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \return int Return
 *
 */
void employeeOnly(Employee);

/** \brief (print)copia el contenido de arrays empleado
 *
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \return int Return
 *
 */
int printEmployees(Employee* list, int len);

/** \brief getSpace, tener espacio en arrays.
 *
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \return int Return
 *
 */
int getSpace (Employee*, int);

/**
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * tener (get) el primer index.
 * return primer index
 */
int siguienteId(Employee*, int);

/** \brief initialize employees.
 *
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \return (void)
 *
 */
void initEmployeesWithData(Employee* paramEmployee, int );

/** \brief empleados modificados
 *
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \return int>a =0 pudo modificar y
 * -1 no modificacion.
 */
int modificationEmployee(Employee*, int);

/** \brief menú modificado
 *
 * \param employee* para array del empleado (employee)
 * \param len int Array (length)
 * \return int>a =0 pudo modificar y
 * -1 no modificacion.
 */
int menuModificado(Employee*, int);

