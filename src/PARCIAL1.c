/*
 ============================================================================
 Name        : PARCIAL1.c
 Author      : LeandroCabeza
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "cliente.h"
#include "prestamo.h"
#define QTY_CLIENTES 50
#define QTY_PRESTAMOS 50

int main(void) {
	setbuf(stdout,NULL);
	eCliente cliente[QTY_CLIENTES];
	ePrestamos prestamos[QTY_PRESTAMOS];
	int respuesta ;
	int opcion;
	int legajo = 0  ;
	int legajoPP = 0;
	inicializarCliente(cliente,QTY_CLIENTES);
	inicializarPrestamo(prestamos,QTY_PRESTAMOS);

		printf("\nBienvenido al operador de cliente , que tarea desea Realizar??\n");
			do
				{
					respuesta = utn_getNumero(&opcion,  "\n1-Alta Cliente "
														"\n2-Baja Cliente "
														"\n3-Modificar Cliente"
														"\n4-Crear nuevo Prestamo"
														"\n5-Saldar Prestamo\n"
														"\n6-Salir\n",
														"\nERROR, las opciones validas estan del 1 al 6\n",1,6,5 );

					if(respuesta == 0 )
					{
						switch(opcion)
						{
							case 1:
								altaCliente(cliente,QTY_CLIENTES,&legajo);
								printf("\nEl cliente fue dado de alta\n");
								break;
							case 2:
								bajaCliente(cliente, QTY_CLIENTES);
								printf("\nSe realizo la baja\n");
								break;
							case 3:
								modificarCliente(cliente, QTY_CLIENTES);
								printf("\nSe modifico el cliente\n");
								break;
							case 4:
							    altaPrestamo (prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES,&legajoPP);
								break;
							case 5:
								saldarPrestamo( prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES);
								break;
							case 6:
								printf("\n***Hasta luego***\n");
								break;

						}
					}
						}while(opcion != 6);
			return 0;
			}



