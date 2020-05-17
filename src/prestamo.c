/*
 * prestamo.c
 *
 *  Created on: 15 may. 2020
 *      Author: Leandro Cabeza
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "cliente.h"
#include "prestamo.h"

int inicializarPrestamo(ePrestamos prestamo[], int tam)
{
	int retorno=-1;
	    if(prestamo!= NULL && tam>0)
	    {
	        for(;tam>0;tam--)
	        {
	        	prestamo[tam-1].isEmpty=1;
	        }
	        retorno=0;
	    }
	    return retorno;
}


int buscarEmptyPrestamo(ePrestamos array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno ;
}

int findPrestamoById(int id , ePrestamos array[],int tam)
{
	// Busca un PRESTAMO por id , compara que no este vacio (OSEA QUE TENGA ALGO CARGADO PREVIAMENTE) y luego evalua si es igual
	// al numero de legajo que le ingrese
	int indice = -1;
	for (int i = 0 ; i < tam ; i++)
	{
		if (array[i].isEmpty == 0 && array[i].idPrestamo == id)
		{
			indice = i;
			break;
		}
	}
	return indice ;
}





int nuevoPrestamo(ePrestamos list[], int len, int idPrestamo , int idCliente , int importe , int cantidadDeCuotas , int estado)
{
	int retorno = -1;
	if(list!=NULL && len>0 && idPrestamo>0 && idCliente>0 && idPrestamo>0 && importe>0 && cantidadDeCuotas>0 )
	{
		list[idPrestamo].idPrestamo =idPrestamo ;
		list[idPrestamo].idCliente =idCliente ;
		list[idPrestamo].importe = importe;
		list[idPrestamo].cantidadDeCuotas = cantidadDeCuotas;
		list[idPrestamo].estado = 1 ;
	    list[idPrestamo].isEmpty = 0;

	    retorno = 0;
	}
 return retorno;
}


int altaPrestamo(ePrestamos arrayPrestamos[],int tamPrestamos,eCliente arrayClientes[],int tamClientes,int* idCont)
{
	int retorno=-1;
	int posicion;
	int auxIdPrestamo;
	int auxIdCliente;
	int auxImporte;
	int auxCantidadDeCuotas;
	int auxEstado = 1;
	int idIngresado ;
	int siguientePosicion ;

	if(arrayPrestamos!=NULL && tamPrestamos>0)
	{
		if(buscarEmptyPrestamo(arrayPrestamos,tamPrestamos,&posicion) == -1)
		{
			printf("\nNo hay mas lugar para recibir altas.\n");
		}
		else
		{
			(*idCont)++;
			auxIdPrestamo = *idCont;
			fflush(stdin);
			mostrarTodosLosClientes( arrayClientes,tamClientes);

			utn_getNumero(&idIngresado,"\nIngrese el id Cliente que solicitara el PP :","\nERROR\n",1,500,5);

			if(buscarIdCliente(arrayClientes,tamClientes,idIngresado,&siguientePosicion)==-1)
			        	{
			        		printf("\nNo Existe ese Id\n");
			        	}else{

			auxIdCliente = idIngresado ;
			fflush(stdin);
			utn_getNumero(&auxImporte,"\nIngrese el IMPORTE del pp:\n ", "\nERROR: Importe Incorrecto\n",1,500000,5);
			fflush(stdin);
			utn_getNumero(&auxCantidadDeCuotas,"\nIngrese la cantidad de Cuotas:\n ", "\nERROR: Cantidad de Cuotas Incorrecto \n",1,160,5);
			fflush(stdin);
			nuevoPrestamo(arrayPrestamos,tamPrestamos,auxIdPrestamo,auxIdCliente,auxImporte,auxCantidadDeCuotas,auxEstado);
			printf("El numero Identificador de tu prestamo es : %d  su estado es ACTIVO ",auxIdPrestamo);
			}
		}
	}

	return retorno;
}



void mostrarPrestamo(ePrestamos prestamo)
{
		printf("%d          %d             %d            %d            %d    \n\n",
		prestamo.idPrestamo,
		prestamo.idCliente,
		prestamo.importe,
		prestamo.cantidadDeCuotas,
		prestamo.estado
		);
	}


int mostrarPrestamoPorId(ePrestamos array[], int size,int idBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0 && idBuscado>=0)
    {
        for(i=0;i<size;i++)
        {
        	if(array[i].isEmpty== 1)
        		continue;
            if(array[i].idPrestamo==idBuscado )
            {
            	 printf("\n******************************************************\n "
            			 "ID PRESTAMO: %d"
            			 "\nID CLIENTE: %d\n"
            			 "\nImporte del PP: %d\n"
            			 "\nCantidad de cuotas del PP: %d\n"
            			 "\nEstado: %d\n",
            	        array[i].idCliente,array[i].idPrestamo,array[i].importe,array[i].cantidadDeCuotas,array[i].estado);
            }
            	 else
                printf("\nEste ID no existe.\n");
        }
        retorno=0;
    }
    return retorno;
}


int mostrarTodosLosPrestamos(ePrestamos array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0 )
    {
    	for(i=0;i<size;i++)
    	{
    		if(array[i].isEmpty==1)
    		{
    			continue;
    		}
    		else
    		{
    			 printf("\n******************************************************\n "
    			            			 "ID PRESTAMO: %d"
    			            			 "\nID CLIENTE: %d\n"
    			            			 "\nImporte del PP: %d\n"
    			            			 "\nCantidad de cuotas del PP: %d\n"
    			            			 "\nEstado: %d\n",
    			            	        array[i].idPrestamo,
										array[i].idCliente,
										array[i].importe,
										array[i].cantidadDeCuotas,
										array[i].estado);
		}
        retorno=0;
    	}
    }
    return retorno;
    }


int buscarIdPrestamo(ePrestamos array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPrestamo==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int saldarPrestamo(ePrestamos array[],int tam,eCliente arrayClientes[],int tamClientes)
{
	int todoOk = 0 ;
	int indice ;
	int id ;
	char opcion;
	int nroCliente;

	system("cls");
	printf("****SALDAR PRESTAMO **** \n\n");
	fflush(stdin);
	printf("Ingrese el ID : ");
	scanf("%d",&id);

	indice =  findPrestamoById(id ,array, tam);

	if (indice == -1)
	{
		printf("\n No tenemos registrado ese id \n");
		system("pause");
	}
	else
	{
		printf("\n ID PP      ID CLIENTE   IMPORTE     CANT. DE CTAS   ESTADO    \n ");
		mostrarPrestamo(array[indice]);
		nroCliente = array[indice].idCliente;
		mostrarClientePorId( arrayClientes,tamClientes,nroCliente);
		fflush(stdin);
		printf("\nConfirma el pago s/n ? :");
		scanf("%c",&opcion);
		if(opcion =='s')
				{
					array[indice].estado = 2 ;
					printf("\n\n Se ha Saldado el PP \n");
					todoOk = 1 ;
				}
				else
				{
					printf("\n\n Se ha cancelaDO EL pago \n");
				}
				system("pause");
			}

	return todoOk ;
	}


