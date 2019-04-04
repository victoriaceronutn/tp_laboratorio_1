#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED


/** \brief Permite sumar dos numeros.
 * \param int x =float A, 1er operando para sumar.
 * \param int y =float B, 2do operando para sumar.
 * \return retorna el resultado de la suma.
 */
int suma(float x, float y);

/** \brief Permite restar dos numeros.
 * \param int x =float A, 1er operando para restar.
 * \param int y =float B, 2do operando para restar.
 * \return retorna el resultado de la resta.
 */
int restar(float x, float y);

/** \brief Permite dividir dos numeros,
 * verificar que el dividendo no sea cero.
 * \param int x= float A, divisor.
 * \param int y= float B, dividendo.
 * \return retorna el resultado de la división.
 */
float division(float x, float y);

/** \brief Permite multiplicar dos numeros.
 *
 * \param int x =float A.
 * \param int y =float B.
 * \return retorna el resultado de la multiplicación.
 */
int multiplicacion(float x, float y);

/** \brief Permite calcular la factorizacion de
 *estos dos numeros.
 * \param int x =float A.
 * \param int y =float B.
 * \return retorna el factorial de los dos números.
 */
double factorial(float x);


#endif // BIBLIOTECA_H_INCLUDED
