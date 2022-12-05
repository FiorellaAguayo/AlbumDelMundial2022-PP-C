#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "inputs.h"

void validarPosicion(char string[])
{
	while((strcmp(string, "Delantero") != 0) && (strcmp(string, "Mediocampista") != 0) && (strcmp(string, "Defensor") != 0) && (strcmp(string, "Arquero") != 0))
	{
		getString(string, "Error. Ingrese la posici�n del jugador (delantero, mediocampista, defensor o arquero): ");
		validateCharacter(string);
		firstCapitalChar(string);
	}
}

void validarEquipo(char string[])
{
	while((strcmp(string, "Argentina") != 0) && (strcmp(string, "Inglaterra") != 0) && (strcmp(string, "Brasil") != 0) && (strcmp(string, "Portugal") != 0) && (strcmp(string, "Brasil") != 0) && (strcmp(string, "Portugal") != 0))
	{
		getString(string, "Error. Ingrese equipo correcto (Argentina, Inglaterra, Brasil, Portugal o Alemania): ");
		validateCharacter(string);
		firstCapitalChar(string);
	}
}

void encabezadoFigurita_1()
{
	printf("\n===============================================================================================================================================================================================");
	printf("\n| id   | nombre del jugador      | posicion       | equipo     | director tecnico             | altura   | peso     | a�o de ingreso | fecha de nacimiento | club             |estado dorada  |");
	printf("\n===============================================================================================================================================================================================");
}

void encabezadoFigurita_2()
{
	printf("\n===========================================================");
	printf("\n| nombre del jugador      | posici�n       | equipo       |");
	printf("\n===========================================================");
}
