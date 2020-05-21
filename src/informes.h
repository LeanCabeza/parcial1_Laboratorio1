/*
 * informes.h
 *
 *  Created on: 17 may. 2020
 *      Author: leand
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int subMenuInformes();
/**
 * \brief Imprime una lista de préstamos activos con todos sus datos junto con el c.u.i.l. del cliente correspondiente.
 * \param arrayPrestamo Array de prestamos
 * \param tamPrestamo tamanio del array de prestamos
 * \param arrayCliente array de clientes
 * \param tamCliente tamanio del array de clientes
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int imprimirPrestamosYcuil(ePrestamos arrayPrestamo[], int tamPrestamo,eCliente arrayCliente[],int tamCliente);
/**
 * \brief Imprime la cantidad de préstamos de importe mayor a X , X OBLIGATORIAMENTE debe ser mayor a 1000
 * \param array Array de prestamos
 * \param tam tamanio del array de prestamos
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int prestamoMayorAmil(ePrestamos array[], int tam);
/**
 * \brief Imprime la cantidad de préstamos en estado activo que tiene un cliente
 * \param array Array de prestamos
 * \param tam tamanio del array de prestamos
 * \param idCliente id del cliente a analizar
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int cantidadPP(ePrestamos array[],int tam, int idCliente);
/**
 * \brief Imprime la cantidad de préstamos en estado saldado que tiene un cliente
 * \param array Array de prestamos
 * \param tam tamanio del array de prestamos
 * \param idCliente id del cliente a analizar
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int cantidadPPSaldados(ePrestamos* array,int tam, int idCliente);
/**
 * \brief Imprime al cliente que tiene mas prestamos activos
 * \param arrayPrestamo Array de prestamos
 * \param tamPrestamo tamanio del array de prestamos
 * \param arrayCliente array de clientes
 * \param tamCliente tamanio del array de clientes
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
void clienteMasPrestamosActivos(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[], int tamClientes);
/**
 * \brief Imprime al cliente que tiene mas prestamos saldados
 * \param arrayPrestamo Array de prestamos
 * \param tamPrestamo tamanio del array de prestamos
 * \param arrayCliente array de clientes
 * \param tamCliente tamanio del array de clientes
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
void clienteMasPrestamosSaldados(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[], int tamClientes);
/**
 * \brief Imprime todos los clientes
 * \param arrayPrestamo Array de prestamos
 * \param tamPrestamo tamanio del array de prestamos
 * \param arrayCliente array de clientes
 * \param tamCliente tamanio del array de clientes
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int imprimirClientes(ePrestamos arrayPrestamo[], int tamPrestamo,eCliente arrayCliente[],int tamCliente);
void cantidadPPGRAL(ePrestamos* array,int tam, int idCliente);
void clienteMasPrestamos(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[], int tamClientes);
int prestamos12CtasSaldados(ePrestamos array[], int tam);
int comparacionCtas(ePrestamos array[], int tam);

#endif /* INFORMES_H_ */
