#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hardcodeo.h"
#define VACIO 0
#define OCUPADO 1

int hardcodearFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas, int *id)
{
	int todoOk = -1;

	char nombreCargado[10][50] =
	{
	{ "Zonda" },
	{ "Damaris" },
	{ "Jethro" },
	{ "Maisey" },
	{ "Caritta" },
	{ "Waldemar" },
	{ "Lacie" },
	{ "Andriana" },
	{ "Peg" },
	{ "Gerhardt" } };
	char posicionCargada[10][15] =
	{
	{ "Delantero" },
	{ "Defensor" },
	{ "Delantero" },
	{ "Arquero" },
	{ "Mediocampista" },
	{ "Arquero" },
	{ "Defensor" },
	{ "Mediocampista" },
	{ "Defensor" },
	{ "Arquero" } };
	int equipoCargado[10] =
	{ 1000, 1001, 1001, 1004, 1000, 1002, 1003, 1004, 1003, 1003 };
	float alturaCargada[10] =
	{ 2.51, 2.44, 1.14, 1.59, 1.59, 1.2, 2.81, 2.64, 2.02, 1.22 };
	float pesoCargado[10] =
	{ 87.05, 73.73, 93.16, 51.57, 88.56, 101.03, 93.67, 81.89, 96.82, 42.8 };
	int anioIngresoCargado[10] =
	{ 2017, 2015, 2020, 2000, 2000, 2003, 2018, 2022, 2019, 2020 };
	int fechaDiaCargado[10] =
	{ 03, 05, 25, 26, 21, 12, 7, 3, 9, 12 };
	int fechaMesCargado[10] =
	{ 02, 03, 04, 05, 06, 07, 03, 10, 11 };
	int fechaAnioCargado[10] =
	{ 2000, 2003, 1993, 2000, 2003, 1994, 1997, 1999, 1991, 2001 };
	int estadoCargado[10] =
	{ OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO };

	if (arrayFiguritas != NULL && tamFiguritas > 0 && id != NULL)
	{
		for (int i = 0; i < tamFiguritas; i++)
		{
			if (estadoCargado[i] == OCUPADO)
			{
				arrayFiguritas[i].idFigurita = *id;
				(*id)++;

				strcpy(arrayFiguritas[i].nombreJugador, nombreCargado[i]);
				strcpy(arrayFiguritas[i].posicion, posicionCargada[i]);

				arrayFiguritas[i].equipo.id = equipoCargado[i];
				arrayFiguritas[i].altura = alturaCargada[i];
				arrayFiguritas[i].peso = pesoCargado[i];
				arrayFiguritas[i].anioIngreso = anioIngresoCargado[i];
				arrayFiguritas[i].fechaNacimiento.dia = fechaDiaCargado[i];
				arrayFiguritas[i].fechaNacimiento.mes = fechaMesCargado[i];
				arrayFiguritas[i].fechaNacimiento.anio = fechaAnioCargado[i];
				arrayFiguritas[i].estado = estadoCargado[i];
			}
			else
			{
				break;
			}
		}
		todoOk = 0;
	}
	return todoOk;
}

int hardcodearDoradas(eFiguritas arrayFiguritas[], eFiguritas arrayDoradas[], int tamFiguritas, int *id)
{
	int todoOk = -1;

	char nombreCargado[5][50] =
	{
	{ "El Diego(DORADA)" },
	{ "Ronaldo(DORADA)" },
	{ "Pirlo(DORADA)" },
	{ "Gianluigi(DORADA)" },
	{ "Zidane(DORADA)" } };
	char posicionCargada[5][15] =
	{
	{ "Delantero" },
	{ "Delantero" },
	{ "Mediocampista" },
	{ "Arquero" },
	{ "Delantero" } };
	int equipoCargado[5] =
	{ 1000, 1001, 1001, 1004, 1000 };
	float alturaCargada[5] =
	{ 1.51, 1.90, 1.14, 1.59, 2.00 };
	float pesoCargado[5] =
	{ 87.05, 73.73, 93.16, 51.57, 88.56 };
	int anioIngresoCargado[5] =
	{ 1990, 1995, 1993, 1876, 1989 };
	int fechaDiaCargado[5] =
	{ 07, 21, 30, 12, 15 };
	int fechaMesCargado[5] =
	{ 02, 03, 04, 05, 06 };
	int fechaAnioCargado[5] =
	{ 2000, 2003, 1993, 2000, 2003 };
	int estadoCargado[5] =
	{ OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO };

	if (arrayFiguritas != NULL && tamFiguritas > 0 && id != NULL)
	{
		for (int i = 0; i < tamFiguritas; i++)
		{
			if (estadoCargado[i] == OCUPADO)
			{
				arrayFiguritas[i].idFigurita = *id;
				(*id)++;

				strcpy(arrayFiguritas[i].nombreJugador, nombreCargado[i]);
				strcpy(arrayFiguritas[i].posicion, posicionCargada[i]);

				arrayFiguritas[i].equipo.id = equipoCargado[i];
				arrayFiguritas[i].altura = alturaCargada[i];
				arrayFiguritas[i].peso = pesoCargado[i];
				arrayFiguritas[i].anioIngreso = anioIngresoCargado[i];
				arrayFiguritas[i].fechaNacimiento.dia = fechaDiaCargado[i];
				arrayFiguritas[i].fechaNacimiento.mes = fechaMesCargado[i];
				arrayFiguritas[i].fechaNacimiento.anio = fechaAnioCargado[i];
				arrayFiguritas[i].estado = estadoCargado[i];

			}
			else
			{
				break;
			}
		}
		todoOk = 0;
	}
	return todoOk;
}
