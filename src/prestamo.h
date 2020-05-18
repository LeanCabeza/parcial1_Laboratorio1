/*
 * prestamo.h
 *
 *  Created on: 15 may. 2020
 *      Author: leand
 */

#ifndef PRESTAMO_H_
#define PRESTAMO_H_

typedef struct {
	int idPrestamo;
	int idCliente;
	int importe;
	int cantidadDeCuotas;
	int estado;
	int isEmpty;
} ePrestamos;

int subMenuPrestamos();
/**
 * \brief  Inicializar el array , poniendo un 1 en todos los isEmpty
 * \param empleados array de empleados
 * \param tam tamanio del array.
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 */
int inicializarPrestamo(ePrestamos prestamo[], int tam);
/**
 * \brief Busca la primer posicion del array libre.
 * \param empleado array de empleados
 * \param tam tamanio del array de empleados
 * \return Retorna el indice de la posicion libre.
 */
int buscarEmptyPrestamo(ePrestamos array[], int size, int* posicion);
/**
 * \brief Carga un nuevo Prestamo
 * \param array de prestamos
 * \param tamanio del array
 * \param idPrestamo id del prestamo
 * \param idCliente id del cliente
 * \param importe importe del pp
 * \param cantidadDeCuotas La cantidad de cuotas
 * \param estado estado del pp
 * \return Retorna un pp con los datos cargados.
 */
int nuevoPrestamo(ePrestamos list[], int len, int idPrestamo , int idCliente , int importe , int cantidadDeCuotas , int estado);
/**
 * \brief Da de alta un pp en una posicion del array
 * \param arrayPrestamos Array de prestamos
 * \param tamPrestamos tamanio del array de prestamos
 * \param arrayClientes array de clientes
 * \param tamClientes tamanio del array de clientes
 * \param idCont id del empleado
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int altaPrestamo(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[],int tamClientes,int* idCont);
/**
 * \brief Busca un prestamo por ID
 * \param arrayPrestamos Array de prestamos
 * \param id id que debe buscar
 * \param tam tamanio del array de prestamos
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int findPrestamoById(int id , ePrestamos array[],int tam);
/**
 * \brief Muesta un pp ingresado por parametros
 * \param prestamo Array de prestamos
 * \return no retorna nada.
 *
 */
void mostrarPrestamo(ePrestamos prestamo);
/**
 * \brief Busca un prestamo por ID y luego lo imprime en pantalla
 * \param arrayPrestamos Array de prestamos
 * \param tam tamanio del array de prestamos
 * \param id id que debe buscar
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int mostrarPrestamoPorId(ePrestamos array[], int size,int idBuscado);
/**
 * \brief Muesta todos los prestamos de un arrray
 * \param tam tamanio del array de prestamos
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int mostrarTodosLosPrestamos(ePrestamos array[], int size);
/**
 * \brief Cambia el estado de un pp
 * \param arrayPrestamos Array de prestamos
 * \param tamPrestamos tamanio del array de prestamos
 * \param arrayClientes array de clientes
 * \param tamClientes tamanio del array de clientes
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int saldarPrestamo(ePrestamos array[],int tam,eCliente arrayClientes[],int tamClientes);
/**
 * \brief Cambia el estado de un pp
 * \param arrayPrestamos Array de prestamos
 * \param tamPrestamos tamanio del array de prestamos
 * \param arrayClientes array de clientes
 * \param tamClientes tamanio del array de clientes
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int reanudarPrestamo(ePrestamos array[],int tam,eCliente arrayClientes[],int tamClientes);
#endif /* PRESTAMO_H_ */
