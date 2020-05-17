/*
 * cliente.c
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
#define NOMBRE_LEN 51


int inicializarCliente(eCliente cliente[], int tam)
{
	int retorno=-1;
	    if(cliente!= NULL && tam>0)
	    {
	        for(;tam>0;tam--)
	        {
	        	cliente[tam-1].isEmpty=1;
	        }
	        retorno=0;
	    }
	    return retorno;
}


int buscarEmptyCliente(eCliente array[], int size, int* posicion)
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

int nuevoCliente(eCliente* list, int len, int id, char nombre[],char apellido[],int cuil)
{
	int retorno = -1;
	if(list!=NULL && len>0 && id>0 && nombre!=NULL && apellido!=NULL && cuil>0)
	{
		list[id].id = id;
	    strcpy(list[id].nombre, nombre);
	    strcpy(list[id].apellido, apellido);
	    list[id].cuil = cuil;
	    list[id].isEmpty = 0;

	    retorno = 0;
	}
 return retorno;
}

int altaCliente(eCliente* array,int len,int* idCont)
{
	int retorno=-1;
	int posicion;
	int auxId;
	char auxNombre[51];
	char auxApellido[51];
	int auxCuil;

	if(array!=NULL && len>0)
	{
		if(buscarEmptyCliente(array,len,&posicion) == -1)
		{
			printf("\nNo hay mas lugar para recibir altas.\n");
		}
		else
		{
			(*idCont)++;
			auxId = *idCont;
			fflush(stdin);
			utn_getName("\nIngrese el Nombre : ","\nError en el nombre ",1,51,3,auxNombre);
			fflush(stdin);
			utn_getName("\nIngrese el Apellido: ","\nError en el apellido",1,51,3,auxApellido);
			fflush(stdin);
			utn_getNumero(&auxCuil,"Ingrese el Cuil: ", "\nERROR: CUIL INCORRECTO\n",1000,500000,5);
			fflush(stdin);
			nuevoCliente(array,len,auxId,auxNombre,auxApellido,auxCuil);
		}
	}

	return retorno;
}


int findClienteById(int id , eCliente array[],int tam)
{
	// Busca un alumno por legajo , compara que no este vacio (OSEA QUE TENGA ALGO CARGADO PREVIAMENTE) y luego evalua si es igual
	// al numero de legajo que le ingrese
	int indice = -1;
	for (int i = 0 ; i < tam ; i++)
	{
		if (array[i].isEmpty == 0 && array[i].id == id)
		{
			indice = i;
			break;
		}
	}
	return indice ;
}


void mostrarCliente(eCliente cliente)
{
		printf("%d   %s    %s       %d   \n\n",
		cliente.id,
		cliente.nombre,
		cliente.apellido,
		cliente.cuil
		);
	}


int mostrarClientePorId(eCliente array[], int size,int idBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0 && idBuscado>=0)
    {
        for(i=0;i<size;i++)
        {
        	if(array[i].isEmpty== 1)
        		continue;
            if(array[i].id==idBuscado )
            {
            	 printf("\n******************************************************\n "
            			 "ID: %d"
            			 "\nNombre: %s\n"
            			 "\nApellido: %s\n"
            			 "\nCuil: %d\n",
            	        array[i].id,array[i].nombre,array[i].apellido,array[i].cuil);
            }
            	 else
                printf("\nEste ID no existe.\n");
        }
        retorno=0;
    }
    return retorno;
}


int mostrarTodosLosClientes(eCliente array[], int size)
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
				printf(
						"\n******************************************************\n "
								"ID: %d"
								"\nNombre: %s\n"
								"\nApellido: %s\n"
								"\nCuil: %d\n",
								array[i].id, array[i].nombre,	array[i].apellido, array[i].cuil);
		}
        retorno=0;
    	}
    }
    return retorno;
    }


int bajaCliente(eCliente array[],int tam )
{
	int todoOk = 0 ;
	int indice ;
	int id;
	char confirma ;

	system("cls");
	printf("**** BAJA EMPLEADO ***/ \n \n");

	printf("Ingrese ID :");
	scanf("%d",&id);

	indice = findClienteById(id,array,tam);

	if (indice == -1)
	{
		printf("\n No tenemos registrado ese ID \n");
		system("pause");
	}else {
		mostrarCliente( array[indice]);
		printf("\nConfirma eliminacion s/n ? :");
		fflush(stdin);
		scanf("%c",&confirma);
		if(confirma =='s')
		{
			array[indice].isEmpty = 1 ;
			printf("\n\n Se ha eliminado el empleado \n");
			todoOk = 1 ;
		}
		else
		{
			printf("\n\n Se ha cancelado la baja \n");
		}
		system("pause");
	}
	return todoOk;
}



int modificarCliente(eCliente array[],int tam)
{
	int todoOk = 0 ;
	int indice ;
	int id ;
	int opcion;

	system("cls");
	printf("****Modificar Empleado **** \n\n");

	printf("Ingrese el ID : ");
	scanf("%d",&id);

	indice = findClienteById(id,array,tam);

	if (indice == -1)
	{
		printf("\n No tenemos registrado ese id \n");
		system("pause");
	}
	else
	{
		mostrarCliente(array[indice]);
		printf("Modificar \n\n");
		printf("1-Nombre \n");
		printf("2-Apellido \n");
		printf("3-Cuil \n");

		printf("Ingrese Opcion");
		scanf("%d",&opcion);

		if(opcion == 1 )
		{
			utn_getName("\nIngrese Nombre del empleado: : ","\nError nombre invalido\n",1,51,5,array[indice].nombre);
			printf("Se actualizo el Nombre ");
			todoOk = 1 ;
		}
		else if (opcion == 2)
		{
			utn_getName("\nIngrese Apellido del empleado: ","\nError apellido invalido\n",1,51,5,array[indice].apellido);
			printf("Se actualizo el Apellido ");
			todoOk = 1;
		}else if (opcion == 3)
		{
			utn_getNumero(&array[indice].cuil,"\nIngrese el Salario del empleado: ","\nError salario invalido \n",1,1215752191,5);
			todoOk = 1;
		}
		else
		{
			printf("\nNo ingresaste una opcion Valida\n");
		}
		system("pause");
	}
	return todoOk ;
	}









