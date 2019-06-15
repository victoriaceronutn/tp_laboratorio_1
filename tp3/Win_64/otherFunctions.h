#ifndef OTHERFUNCTIONS_H_INCLUDED
#define OTHERFUNCTIONS_H_INCLUDED

/** \brief mensaje y pide un ejemplo
 *
 * \param [] char cadena para escribir el mensaje.
 * \return int retorna el numero guardado
 *
 */
int getInt(char []);
/** \brief mensaje.
 *
 * \param [] char cadena del mensaje
 * \param [] char texto guardado
 * \return void
 *
 */
void getString(char [], char []);
/** \brief verifica si es un numero
 *
 * \param [] char cadena a analizar
 * \return int 0 si no es numero y 1 si es numero
 */
int isNumber(char []);
/** \brief verifica si hay un 0 a la izquier de una cifra de 3
 *
 * \param [] char cadena a analizar
 * \return int 0 si tiene el cero y 1 si no lo tiene
 *
 */
int isCero(char []);
/** \brief verifica si tiene numeros como letras
 * \param [] char cadena a analizar
 * \return int 0 si no es letra ni numero y 1 si es letra y numero
 *
 */
int isAlphabeticalNum(char []);

/** \brief Muestra las opciones de menu
 *
 * \return int opcion elegida
 */
int showMainMenu();
#endif // OTHERFUNCTIONS_H_INCLUDED
