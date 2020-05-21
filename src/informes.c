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
		printf("5-Imprimir cliente con nro de PP activos\n\n");
		printf("6-Imprimir cliente con mas prestamos\n\n");
		printf("7-Cantidad de PP en 12 ctas SALDADOS\n\n");
		printf("8-Cantidad de PP en *X* ctas ACTIVOS\n\n");
		printf("9-Salir\n\n");
		scanf("%d",&opcion);
		return opcion;
}

int cantidadPP(ePrestamos* array,int tam, int idCliente)
{
	int cantidad=0;
	int i;
	if(array!=NULL && tam >0 && idCliente>=0)
	{
		for(i=0; i<tam; i++)
		{
			if((array[i].isEmpty==0) && (array[i].idCliente==idCliente)&& (array[i].estado==1)) // estado 1 son los pp activos
			{
				cantidad++;
			}

		}
	}
return cantidad;
}

int imprimirClientes(ePrestamos arrayPrestamo[], int tamPrestamo,eCliente arrayCliente[],int tamCliente)
{
	int retorno = -1;
	int i;
	int j;
	int nro;

	if(arrayPrestamo != NULL && tamPrestamo>0 && arrayCliente != NULL && tamCliente>0)
	{
		for(i=0;i<tamPrestamo;i++)
		{
			/*if(arrayPrestamo[i].isEmpty == 1)
			{
				printf("Se altero el flujo del bucle porque isEmpty == 1 ");
				continue;
			}*/
			if(arrayPrestamo[i].estado == 1 )
			{
				for(j=0;j<tamCliente;j++)
				{
					/*if( arrayCliente[j].isEmpty == 1)
						continue;*/
					if(arrayPrestamo[i].idCliente == arrayCliente[j].id)
					{
						nro = arrayPrestamo[i].idCliente ;
						printf("\nNombre: %s"
								"\nApellido: %s"
								"\nCuil Cliente:%d",
								arrayCliente[j].nombre,
								arrayCliente[j].apellido,
								arrayCliente[j].cuil);

								printf("\nPP Activos : %d \n",cantidadPP(arrayPrestamo,tamPrestamo,nro));


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
	int i; // para recorrer prestamos
	int j; // para recorrer clientes

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
				//printf("\n[DEBUG]valida que el estado este en 1 que es activo \n");

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
								"\nCuil Cliente:%d"
								"\n---------------",
								arrayPrestamo[i].idPrestamo,
								arrayPrestamo[i].idCliente,
								arrayPrestamo[i].importe,
								arrayPrestamo[i].cantidadDeCuotas,
								arrayCliente[j].cuil);
								if (arrayPrestamo[i].estado == 1)
								{
									printf("\nEstado : activo\n");
									} else if (arrayPrestamo[i].estado == 2)
									{
									printf("\nEstado : saldado\n");
									}

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
				if ( (array[i].importe > montoIngresado) && (array[i].estado == 1))
				{
					printf("\n\nID PP: %d"
							"\nImporte del PP: %d\n -----------------",
							array[i].idPrestamo,
							array[i].importe);
				}
			}
			ret = 0;
		}
	}
	return ret;
}


int cantidadPPSaldados(ePrestamos* array,int tam, int idCliente)
{
	int cantidad=0;
	int i;
	if(array!=NULL && tam >0 && idCliente>=0)
	{
		for(i=0; i<tam; i++)
		{
			if((array[i].isEmpty==0) && (array[i].idCliente==idCliente)&& (array[i].estado==2)) // estado dos son los pp saldados
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

	if( (arrayClientes!= NULL) && (tamClientes>0) && (arrayPrestamos!=NULL) && (tamPrestamos>0))
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

int cantidadPPGRAL(ePrestamos* array,int tam, int idCliente)
{
	int cantidad=0;
	int i;
	if(array!=NULL && tam >0 && idCliente>=0)
	{
		for(i=0; i<tam; i++)
		{
			if((array[i].isEmpty==0) && (array[i].idCliente==idCliente)&& ((array[i].estado==2) || (array[i].estado==1))) // estado dos son los pp saldados
			{
				cantidad++;
			}

		}
	}
return cantidad;
}


void clienteMasPrestamos(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[], int tamClientes)
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
				cantidad=cantidadPPGRAL(arrayPrestamos,tamPrestamos,nro); // esto es lo unico que cambia con respecto a la anterior
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
		printf("El empleado con mas prestamos es  :");
		mostrarClientePorId(arrayClientes, tamClientes,posCliente);
	}
	else
	{
		printf("\nNo hay ningun cliente al menos un prestamo.  \n");
	}
}

// PRESTAMOS EN 12 CTAS SALDADOS


int prestamos12CtasSaldados(ePrestamos array[], int tam)
{
	int ret = -1;
	int i;
	int cantidad = 0 ;

	if(array != NULL && tam > 0)
	{
			{
			for (i = 0; i < tam; i++) {
				if (array[i].isEmpty == 1)
					continue;
				if ( (array[i].estado == 2) && array[i].cantidadDeCuotas == 12 )
				{
				 cantidad ++ ;
				}
			}
			printf("\nLa cantidad de PP que hay en 12 ctas es : %d\n",cantidad);
			ret = 0;
		}
	}
	return ret;
}

// Préstamos por cuotas: Se ingresará la cantidad de cuotas y se imprimirán la cantidad de préstamos activos con esa cantidad de cuotas.

int comparacionCtas(ePrestamos array[], int tam)
{
	int ret = -1;
	int ctasIngresadas;
	int i;
	int cantidad= 0;

	if(array != NULL && tam > 0)
	{
			fflush(stdin);
			if (utn_getNumero(&ctasIngresadas,"\nIngrese la cantidad de ctas ","\nError , monto ingresado no valido",1,190,5)==0)
				fflush(stdin);
			{
			for (i = 0; i < tam; i++) {
				if (array[i].isEmpty == 1)
					continue;
				if ( (array[i].cantidadDeCuotas == ctasIngresadas) && (array[i].estado == 1))
				{
					cantidad ++ ;
				}
			}
			printf("La cantidad de PP que hay en 12 ctas es : %d \n",cantidad);
			ret = 0;
		}
	}
	return ret;
}

#endif /* INFORMES_C_ */
