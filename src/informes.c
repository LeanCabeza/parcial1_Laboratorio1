/*
 * informes.c
 *
 *  Created on: 17 may. 2020
 *      Author: leand
 */

#ifndef INFORMES_C_
#define INFORMES_C_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "cliente.h"
#include "prestamo.h"


int subMenuInformes()
{
	int opcion ;
	system("cls");
		printf("1-Cliente con mas prestamos Activos \n\n");
		printf("2-Cliente con mas prestamos Saldados \n\n");
		printf("3-Imprimir prestamos con cuil del cliente \n\n");
		printf("4-Prestamos mayores a x NUM (x>1000)\n\n");
		printf("5-Salir\n\n");
		scanf("%d",&opcion);
		return opcion;
}


int imprimirClientes(ePrestamos arrayPrestamo[], int tamPrestamo,eCliente arrayCliente[],int tamCliente)
{
	int retorno = -1;
	int i;
	int j;

	if(arrayPrestamo != NULL && tamPrestamo>0 && arrayCliente != NULL && tamCliente>0)
	{
		for(i=0;i<tamPrestamo;i++)
		{
			if(arrayPrestamo[i].isEmpty == 1)
			{
				//printf("\n [DEBUG] valida que el esEmpty este en 1");
				continue;
			}
			if(arrayPrestamo[i].estado == 1 ) // ESTADO 2 ES SALDADO , ESTADO 1 ES ACTIVO // ESTADO 0 ES INACTIVO
			{
			//printf("\n[DEBUG]valida que el estado este en 1\n");
				for(j=0;j<tamCliente;j++)
				{
					if( arrayCliente[j].isEmpty == 1)
						continue;
					if(arrayPrestamo[i].idCliente == arrayCliente[j].id)
					{

						printf("\nID: %d"
								"\nNombre: %s"
								"\nApellido: %s"
								"\nCuil: %d"
								"\nID Prestamo: %d"
								"\nEstado:%d"
								"\n---------------",
								arrayCliente[j].id,
								arrayCliente[j].nombre,
								arrayCliente[j].apellido,
								arrayCliente[j].cuil,
								arrayPrestamo[i].idPrestamo,
								arrayPrestamo[i].estado);

					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}


int imprimirPrestamosYcuil(ePrestamos arrayPrestamo[], int tamPrestamo,eCliente arrayCliente[],int tamCliente)
{
	int retorno = -1;
	int i;
	int j;

	if(arrayPrestamo != NULL && tamPrestamo>0 && arrayCliente != NULL && tamCliente>0)
	{
		for(i=0;i<tamPrestamo;i++)
		{
			if(arrayPrestamo[i].isEmpty == 1)
			{
				//printf("\n [DEBUG] valida que el esEmpty este en 1");
				continue;
			}
			if(arrayPrestamo[i].estado == 1 ) // ESTADO 2 ES SALDADO , ESTADO 1 ES ACTIVO // ESTADO 0 ES INACTIVO
			{
			//printf("\n[DEBUG]valida que el estado este en 1\n");
				for(j=0;j<tamCliente;j++)
				{
					if( arrayCliente[j].isEmpty == 1)
						continue;
					if(arrayPrestamo[i].idCliente == arrayCliente[j].id)
					{
						printf("\nID PP: %d"
								"\nID CLIENTE: %d"
								"\nImporte del PP: %d"
								"\nCantidad de Cuotas: %d"
								"\nEstado : %d"
								"\nCuil Cliente:%d"
								"\n---------------",
								arrayPrestamo[i].idPrestamo,
								arrayPrestamo[i].idCliente,
								arrayPrestamo[i].importe,
								arrayPrestamo[i].cantidadDeCuotas,
								arrayPrestamo[i].estado,
								arrayCliente[j].cuil);

					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int prestamoMayorAmil(ePrestamos array[], int tam)
{
	int ret = -1;
	int montoIngresado;
	int i;

	if(array != NULL && tam > 0)
	{
			if (utn_getNumero(&montoIngresado,"\nIngrese un monto mayor a 1000: ","\nError , monto ingresado no valido",1000,100000,5)==0)
			{
			for (i = 0; i < tam; i++) {
				if (array[i].isEmpty == 1)
					continue;
				if (array[i].importe > montoIngresado && array[i].estado == 1)
				{
					printf("\n\nID PP: %d"
							"\nImporte del PP: %d\n -----------------", array[i].idPrestamo,
							array[i].importe);
				}
			}
			ret = 0;
		}
	}
	return ret;
}


int cantidadPP(ePrestamos* array,int tam, int idCliente)
{
	int cantidad=0;
	int i;
	if(array!=NULL && tam >0 && idCliente>=0)
	{
		for(i=0; i<tam; i++)
		{
			if((array[i].isEmpty==0) && (array[i].idCliente==idCliente)&& (array[i].estado==1))
			{
				cantidad++;
			}

		}
	}
return cantidad;
}

int cantidadPPSaldados(ePrestamos* array,int tam, int idCliente)
{
	int cantidad=0;
	int i;
	if(array!=NULL && tam >0 && idCliente>=0)
	{
		for(i=0; i<tam; i++)
		{
			if((array[i].isEmpty==0) && (array[i].idCliente==idCliente)&& (array[i].estado==2))
			{
				cantidad++;
			}

		}
	}
return cantidad;
}
void clienteMasPrestamosActivos(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[], int tamClientes)

{
	int i;
	int nro;
	int maxPrestamos;
	int cantidad;
	int posCliente;
	int flag=0;

	if(arrayClientes!= NULL && tamClientes>0 && arrayPrestamos!=NULL && tamPrestamos>0)
	{
		for(i=0; i<tamClientes; i++)
		{
			if(arrayClientes[i].isEmpty==0)
			{
				nro =arrayClientes[i].id ;
				cantidad=cantidadPP(arrayPrestamos,tamPrestamos,nro);
				if(flag==0 || cantidad>maxPrestamos)
				{
					maxPrestamos=cantidad;
					posCliente=i;
					flag=1;
				}
			}
		}
	}

	if(maxPrestamos>0)
	{
		printf("El que tiene mas PP activos es :");
		mostrarClientePorId(arrayClientes, tamClientes,posCliente);
	}
	else
	{
		printf("\nNo hay ningun cliente  con prestamos activos , por favor da de alta un prestamo\n");
	}
}

void clienteMasPrestamosSaldados(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[], int tamClientes)
{
	int i;
	int nro;
	int maxPrestamos;
	int cantidad;
	int posCliente;
	int flag=0;

	if(arrayClientes!= NULL && tamClientes>0 && arrayPrestamos!=NULL && tamPrestamos>0)
	{
		for(i=0; i<tamClientes; i++)
		{
			if(arrayClientes[i].isEmpty==0)
			{
				nro =arrayClientes[i].id ;
				cantidad=cantidadPPSaldados(arrayPrestamos,tamPrestamos,nro);
				if(flag==0 || cantidad>maxPrestamos)
				{
					maxPrestamos=cantidad;
					posCliente=i;
					flag=1;
				}
			}
		}
	}
	if(maxPrestamos>0)
	{
		printf("El que tiene mas PP saldados es :");
		mostrarClientePorId(arrayClientes, tamClientes,posCliente);
	}
	else
	{
		printf("\nNo hay ningun cliente con un prestamo saldado  \n");
	}
}



#endif /* INFORMES_C_ */
