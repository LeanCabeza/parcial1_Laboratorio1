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
	int isEmpty;

} eCliente;

int inicializarCliente(eCliente cliente[], int tam);
int buscarEmptyCliente(eCliente array[], int size, int* posicion);
int nuevoCliente(eCliente* list, int len, int id, char nombre[],char apellido[],int cuil);
int altaCliente(eCliente* array,int len,int* idCont);
int findClienteById(int id , eCliente array[],int tam);
void mostrarCliente(eCliente cliente);
int mostrarClientePorId(eCliente array[], int size,int idBuscado);
int mostrarTodosLosClientes(eCliente array[], int size);
int bajaCliente(eCliente array[],int tam);
int modificarCliente(eCliente array[],int tam);


#endif /* CLIENTE_H_ */
