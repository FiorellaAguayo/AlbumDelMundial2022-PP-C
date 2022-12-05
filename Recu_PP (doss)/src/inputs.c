#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

static int validarEntero(char pEnteroAValidar[]);
static int pideDato(char *cadena);

int imprimeMensaje(char mensaje[])
{
	int todoOk = -1;
	if (mensaje != NULL)
	{
		printf(mensaje);
		todoOk = 0;
	}
	return todoOk;
}


int getValidChar(char* caracter, char* mensaje, char* mensajeError, char letra1, char letra2, int reintentos)
{
	int retorno = -1;
	char letra;
	do{
		if(caracter != NULL && mensaje != NULL && mensajeError != NULL && reintentos > 0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &letra);
			if(letra == letra1 || letra == letra2)
			{
				*caracter = letra;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}
	}while(reintentos >= 0);
	return retorno;
}

static int pideDato(char *cadena)
{
	if (cadena != NULL)
	{

		char buffer[256];
		fflush(stdin);
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer) - 1] = '\0';
		strcpy(cadena, buffer);
		return 0;
	}

	return -1;
}

static int validarEntero(char pEnteroAValidar[])
{
	int todoOk = 1;

	if (strlen(pEnteroAValidar) > 0)
	{
		for (int i = 0; i < strlen(pEnteroAValidar); i++)
		{
			if (isdigit(pEnteroAValidar[i]) == 0)
			{
				if (i == 0 && pEnteroAValidar[0] == '-')
				{
					todoOk = 1;

				}
				else
				{
					todoOk = 0;
				}
			}
		}
	}
	else
	{
		todoOk = 0;
	}

	return todoOk;
}

int pedirEntero(int *enteroValidado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int todoOk = 0;

	if (enteroValidado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo)
	{
		char auxEntero[150];
		imprimeMensaje(mensaje);
		pideDato(auxEntero);

		while (validarEntero(auxEntero) == 0 || atoi(auxEntero) > maximo || atoi(auxEntero) < minimo)
		{
			imprimeMensaje(mensaje);
			pideDato(auxEntero);
		}

		*enteroValidado = atoi(auxEntero);
		todoOk = 1;
	}
	return todoOk;
}


//Pedir cadena de caracteres
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

int pedirCadena(char cadena[], char mensaje[], char mensajeError[], int max)
{
	int todoOk = -1;

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		char auxString[256];
		imprimeMensaje(mensaje);
		pideDato(auxString);

		while (strlen(auxString) > max || soloLetras(auxString) == 0 || auxString[0] == 00)
		{
			imprimeMensaje(mensajeError);
			pideDato(auxString);
		}
		strcpy(cadena, auxString);
		ordenarCadena(cadena);

		todoOk = 0;
	}
	return todoOk;
}

//Validar primer letras mayusculo
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

//Validar todas letras
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

int pedirFlotante(float *numFloat, char mensaje[], char mensajeError[], float min, float max)
{
	int todoOk = -1;

	if (numFloat != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		char auxFlotante[150];
		imprimeMensaje(mensaje);
		pideDato(auxFlotante);

		while (validarEntero(auxFlotante) == 0 || atof(auxFlotante) > max || atof(auxFlotante) < min)
		{
			imprimeMensaje(mensaje);
			pideDato(auxFlotante);
		}

		*numFloat = atof(auxFlotante);
		todoOk = 1;
	}
	return todoOk;
}

int soloLetras(char cadena[])
{
	int soloHayLetras = 1;
	int i = 0;

	if (cadena != NULL)
	{
		while (cadena[i] != '\0')
		{
			if (cadena[i] != ' ' && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
			{
				soloHayLetras = 0;
			}
			i++;
		}
	}
	return soloHayLetras;
}

int ordenarCadena(char cadena[])
{
	int todoOk = -1;

	if (cadena != NULL)
	{
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);

		for (int i = 0; cadena[i] != '\0'; i++)
		{
			if (cadena[i] == ' ')
				cadena[i + 1] = toupper(cadena[i + 1]);
		}
		todoOk = 0;
	}
	return todoOk;
}

int pedirCaracter(char *charValidado, char mensaje[], char mensajeError[], char primerChar, char segundoChar)
{
	int todoOk = -1;
	char auxChar;

	if (mensaje != NULL && mensajeError != NULL)
	{
		imprimeMensaje(mensaje);
		fflush(stdin);
		scanf("%c", &auxChar);

		while (auxChar != primerChar && auxChar != segundoChar)
		{
			imprimeMensaje(mensajeError);
			fflush(stdin);
			scanf("%c", &auxChar);
		}

		*charValidado = auxChar;
		todoOk = 1;
	}
	return todoOk;
}
