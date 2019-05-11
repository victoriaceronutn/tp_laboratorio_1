
/** \brief pide numero y devuelve resultado
 *
 * \param mensaje
 * \return numero
 */
int getInt (char mensaje[]);

/** \brief pide numero y devuelve resultado
 *
 * \param mensaje
 * \return numero
 */
float getFloat (char mensaje[]);

/** \brief Solicita caracter y devuelve el resultado
 * \param mensaje
 * \return caracter ingresado.
 */
char getChar(char mensaje[]);

/** \brief Hace mayusculas la primer letra del dato.
 * \param caracter[] char string ,modificado.
 * \return (void)
 */
void stringToUpper(char caracter[]);

/** \brief Verifica si es numerico.
 *
 * \param str Array con cadena.
 * \return 1= numero, 0= si no lo es
 */
int numeric (char str[]);

/** \brief Verifica si el valor tiene solo numeros.
 *
 * \param str Array con cadena.
 * \return 1= numero,guiones, 0= si no lo es
 */
int contValor (char str[]);

/** \brief Verifica si el valor solo tiene letras.
 *
 * \param str Array con cadena.
 * \return 1= numero y letras, 0= si no lo es
 */
int onlyLetter (char str[]);

/** \brief solo letras y numeros.
 *
 * \param str Array con cadena.
 * \return 1= numero y letras, 0= si no lo es
 */
int isAlphaNumeric (char str[]);
