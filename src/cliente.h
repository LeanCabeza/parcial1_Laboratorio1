/*
 * cliente.h
 *
 *  Created on: 15 may. 2020
 *      Author: leand
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct {
	int id;
	char nombre[50];
	char apellido[51];
	int cuil;
	int cantidadPP;
	int isEmpty;

} eCliente;

int subMenuClientes();
/**
 * \brief  Inicializar el array , poniendo un 1 en todos los isEmpty
 * \param empleados array de empleados
 * \param tam tamanio del array.
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 */
int inicializarCliente(eCliente cliente[], int tam);
/**
 * \brief Busca la primer posicion del array libre.
 * \param empleado array de empleados
 * \param tam tamanio del array de empleados
 * \return Retorna el indice de la posicion libre.
 */
int buscarEmptyCliente(eCliente array[], int size, int* posicion);
/**
 * \brief Carga un nuevo Cliente
 * \param array de prestamos
 * \param tamanio del array
 * \param id id del cliente
 * \param nombre nombre del cliente
 * \param apellido apellido del cliente
 * \param cuil cuil del cliente
 * \return Retorna un cliente con los datos cargados.
 */
int nuevoCliente(eCliente* list, int len, int id, char nombre[],char apellido[],int cuil);
/**
 * \brief Da de alta un cliente
 * \param arrayPrestamos Array de prestamos
 * \param len tamanio del array de prestamos
 * \param idCont id del cliente
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 */
int altaCliente(eCliente* array,int len,int* idCont);
/**
 * \brief Busca un cliente por ID y retorna la posicion en la que se lo encontro
 * \param arrayPrestamos Array de clientes
 * \param id id que debe buscar
 * \param tam tamanio del array de clientes
 * \return Retorna la posicion del cliente
 */
int findClienteById(int id , eCliente array[],int tam);
/**
 * \brief Muesta un cliente ingresado por parametros
 * \param prestamo Array de prestamos
 * \return no retorna nada.
 */
void mostrarCliente(eCliente cliente);
/**
 * \brief Muestra un cliente por su ID
 * \param array array de empleados
 * \param size tamanio del array
 * \param idBuscado id del empleado a ser mostrado
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int mostrarClientePorId(eCliente array[], int size,int idBuscado);
/**
 * \brief Muestra todos los clientes
 * \param array array de clientes
 * \param size tamanio del array
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 */
int mostrarTodosLosClientes(eCliente array[], int size);
/**
 * \brief Da de baja un cliente
 * \param empleados Array de clientes a ser actualizado
 * \param tam tamanio del array de clientes
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 */
int bajaCliente(eCliente array[],int tam);
/**
 * \brief Modifica los datos de un clientes seleccionado por su ID
 * \param empleados Array de clientes a ser actualizado
 * \param tam tamanio del array de empleados
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 */
int modificarCliente(eCliente array[],int tam);
/**
 * \brief Busca un empleado por su ID y retorna si lo encontro
 * \param id id del empleado a buscar
 * \param empleados array de empleados
 * \param tam tamanio del array
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 */
int buscarIdCliente(eCliente array[], int size, int valorBuscado, int* posicion);

#endif /* CLIENTE_H_ */
