
/*
 * utn.h
 *
 *  Created on: 7 may. 2020
 *      Author: leandro
 */

#ifndef UTN_H_
#define UTN_H_

/*
 * \brief Obtiene un numero, y valida si cumple los parametros, si no, descuenta 1 intento hasta llegar a los intentos
 * establecidos, tambien comprueba si los numeros son enteros mediante la funcion utn_getInt
 *
 * \param pResultado puntero a variable donde se escribira el valor ingresado en el caso de ser correcto.
 * \param mensaje puntero a cadena de caracteres con mensaje a imprimir antes de pedir los datos por consola.
 * \param mensajeError puntero a cadena de caracteres  con mensaje de error en el caso de que el dato ingresado no sea valido.
 * \param minimo valor minimo aceptado(inclusive)
 * \param maximo valor maximo aceptado(inclusive)
 * \param reintentos Cantidad de veces que se le volvera a pedir al usuario que ingrese un dato en caso de error.
 * \return retorna -1 si se queda sin reintentos y retorna 0 si salio todoo bien
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */

int isValidName(char* stringRecibido) ;
/**
 * \brief Verifica si la cadena ingresada es un numero valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
int isValidNumber(char* stringRecibido);
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
/**
 * \brief 	Imprime un sub menu de informes
 * \return Retorna el numero ingresado
 *
 */
int subMenuInformes();


#endif /* UTN_H_ */
