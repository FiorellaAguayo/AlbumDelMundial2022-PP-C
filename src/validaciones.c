#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int getValidInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do{
		if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos > 0)
		{
			printf("%s", pMensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", pMensajeError);
				reintentos--;
			}
		}
	}while(reintentos >= 0);
	return retorno;
}

int getValidFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float bufferInt;

	do{
		if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos > 0)
		{
			printf("%s", pMensaje);
			fflush(stdin);
			scanf("%f", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", pMensajeError);
				reintentos--;
			}
		}
	}while(reintentos >= 0);
	return retorno;
}

int getString(char* cadena, char* mensaje)
{
    int retorno = -1;
    if(cadena != NULL && mensaje != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(cadena);
        retorno = 0;
    }
    return retorno;
}

int validateCharacter(char string[])
{
    int i = 0;
    int error = 0;
    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if(string[i] != ' ' && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
            {
                error= -1;

                while(error < 0)
                {
                    printf("ERROR, Se debe ingresar letras unicamente: ");
                    fflush(stdin);
                    gets(string);
                    error = 0;
                    i = 0;
                }
            }
            i++;
        }
    }
    return error;
}

int firstCapitalChar(char name[])
{
	int i = 0;
	int error = -1;
	if(name != NULL)
	{
		strlwr(name);
		name[0] = toupper(name[0]);

		while(name[i] != '\0')
		{
		   if(name [i] == ' ')
		   {
			   name [i + 1] = toupper(name[i+1]);
		   }
		   i++;
		}
		    //puts(name);
	  error = 0;
	}
    return error;
}

void validarPosicion(char string[])
{
	while((strcmp(string, "Delantero") != 0) && (strcmp(string, "Mediocampista") != 0) && (strcmp(string, "Defensor") != 0) && (strcmp(string, "Arquero") != 0))
	{
		getString(string, "Error. Ingrese posición del jugador (delantero, mediocampista, defensor, arquero): ");
		validateCharacter(string);
		firstCapitalChar(string);
	}
}

int getChar(char* caracter, char* mensaje)
{
	int retorno = -1;
	if(caracter != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", caracter);
		retorno = 0;
	}
	return retorno;
}

int getInt(int* pResultado, char* pMensaje)
{
    int retorno = -1;
    int bufferInt;
	if(pResultado != NULL && pMensaje != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);
		scanf("%d", &bufferInt);
		*pResultado = bufferInt;
		retorno = 0;
	}
	return retorno;
}

int getOnlyInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	int numero;
	while(reintentos > 0)
	{
		printf(mensaje);
		fflush(stdin);
		if(scanf("%d", &numero) == 1)
		{
			if(numero <= maximo && numero >= minimo)
			{
				break;
			}
		}
		reintentos--;
		printf(mensajeError);
	}

	if(reintentos == 0)
	{
		retorno=-1;
	}
	else
	{
		retorno = 0;
		*pResultado = numero;
	}
	return retorno;
}
