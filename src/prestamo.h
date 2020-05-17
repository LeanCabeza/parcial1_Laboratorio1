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

int inicializarPrestamo(ePrestamos prestamo[], int tam);
int buscarEmptyPrestamo(ePrestamos array[], int size, int* posicion);
int nuevoPrestamo(ePrestamos list[], int len, int idPrestamo , int idCliente , int importe , int cantidadDeCuotas , int estado);
int altaPrestamo(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[],int tamClientes,int* idCont);
int findPrestamoById(int id , ePrestamos array[],int tam);
void mostrarPrestamo(ePrestamos prestamo);
int mostrarPrestamoPorId(ePrestamos array[], int size,int idBuscado);
int mostrarTodosLosPrestamos(ePrestamos array[], int size);
int saldarPrestamo(ePrestamos arrayPrestamo[],eCliente arrayCliente[],int tamCliente, int tamPrestamo);

#endif /* PRESTAMO_H_ */
