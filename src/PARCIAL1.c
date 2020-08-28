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
#include "informes.h"
#define QTY_CLIENTES 5
#define QTY_PRESTAMOS 5

int main(void) {
	setbuf(stdout,NULL);
	eCliente cliente[QTY_CLIENTES];
	ePrestamos prestamos[QTY_PRESTAMOS];
	int respuesta ;
	int opcion;
	int legajo = 0  ;
	int legajoPP = 0;
	char salirSub;
	inicializarCliente(cliente,QTY_CLIENTES);
	inicializarPrestamo(prestamos,QTY_PRESTAMOS);

		printf("\nBienvenido , que tarea desea Realizar??\n");
			do
				{
					respuesta = utn_getNumero(&opcion,  "\n1-Operar con Clientes "
														"\n2-Operar con Prestamos "
														"\n3-Menu de Informes"
														"\n4-Salir\n",
														"\nERROR, las opciones validas estan del 1 al 4\n",1,4,5 );
					if(respuesta == 0 )
					{
						switch(opcion)
						{
							case 1:
								do {
									switch (subMenuClientes()) {
									case 1:
										altaCliente(cliente,QTY_CLIENTES,&legajo);
										printf("\nEl cliente fue dado de alta\n");
										break;
									case 2:
										bajaCliente(cliente, QTY_CLIENTES);
										printf("\nSe realizo la baja\n");
										break;
									case 3 :
										modificarCliente(cliente, QTY_CLIENTES);
										printf("\nSe modifico el cliente\n");
										break;
									case 4:
										imprimirClientes(prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES);
										break;
									case 5:
										printf("\nConfirma Salida s/n  ?");
										fflush(stdin);
										salirSub = getchar();
										break;
									default:
										printf("Opcion Invalida");
									}
									system("pause");
								} while (salirSub == 'n');
								break;
							case 2:
								do {
									switch (subMenuPrestamos()) {
									case 1:
										altaPrestamo (prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES,&legajoPP);
										break;
									case 2:
										saldarPrestamo( prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES);
										break;
									case 3:
										reanudarPrestamo( prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES);
										break;
									case 4:
										printf("\nConfirma Salida s/n ?");
										fflush(stdin);
										salirSub = getchar();
										break;
									default:
										printf("Opcion Invalida");
									}
									system("pause");
								} while (salirSub == 'n');
								break;

							case 3 :
									do {
										switch (subMenuInformes()) {
										case 1:
											clienteMasPrestamosActivos(prestamos, QTY_PRESTAMOS,cliente, QTY_CLIENTES);
											break;
										case 2:
											clienteMasPrestamosSaldados(prestamos, QTY_PRESTAMOS,cliente, QTY_CLIENTES);
											break;
										case 3 :
											imprimirPrestamosYcuil(prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES);
											break;
										case 4:
											prestamoMayorAmil(prestamos,QTY_PRESTAMOS);
											break;
										case 5 :
											imprimirClientes(prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES);
											break;
										case 6 :
											clienteMasPrestamos(prestamos,QTY_PRESTAMOS,cliente,QTY_CLIENTES);
											break;
										case 7:
											prestamos12CtasSaldados(prestamos,QTY_PRESTAMOS);
											break;
										case 8:
											comparacionCtas(prestamos,QTY_PRESTAMOS);
											break;
										case 9:
											printf("\nConfirma Salida s/n ?");
											fflush(stdin);
											salirSub = getchar();
											break;
										default:
											printf("Opcion Invalida");
										}
										system("pause");
									} while (salirSub == 'n');
									break;
							case 4:
								printf("\n***Hasta luego***\n");
								break;
						}
					}
						}while(opcion != 4);
			return 0;
			}



