#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipo.h"

int cargaDeEquipos(eEquipo arrayEquipos[], int tamEquipos)
{
	int todoOk = -1;

	int idEquipo[5] =
	{ 1000, 1001, 1002, 1003, 1004 };
	char descripcion[5][20] =
	{
	{ "Argentina" },
	{ "Inglaterra" },
	{ "Alemania" },
	{ "Portugal" },
	{ "Brasil" } };
	char directorTecnico[5][50] =
	{
	{ "Lionel Scaloni" },
	{ "Gareth Southgate" },
	{ "Hansi Flick" },
	{ "Fernando Manuel Costa Santos" },
	{ "Adenor Leonardo Bacchi" } };

	if (arrayEquipos != NULL && tamEquipos)
	{
		for (int i = 0; i < tamEquipos; i++)
		{
			arrayEquipos[i].id = idEquipo[i];
			strcpy(arrayEquipos[i].descripcion, descripcion[i]);
			strcpy(arrayEquipos[i].directorTecnico, directorTecnico[i]);
		}
		todoOk = 0;
	}
	return todoOk;
}

void mostrarUnEquipo(eEquipo unEquipo)
{
	printf("\n| %-5d | %-12s | %-29s |", unEquipo.id, unEquipo.descripcion, unEquipo.directorTecnico);
	printf("\n|------------------------------------------------------|");
}

int listarEquipos(eEquipo arrayEquipos[], int tamEquipos)
{
	int todoOk = -1;
	if (arrayEquipos != NULL && tamEquipos)
	{
		printf("\n             *** Listado de Equipos ***                 ");
		printf("\n========================================================");
		printf("\n| id    | descripcion  | director tecnico              |");
		printf("\n|======================================================|");
		for (int i = 0; i < tamEquipos; i++)
		{
			mostrarUnEquipo(arrayEquipos[i]);
		}
		todoOk = 0;
	}
	return todoOk;
}

int buscarEquipoPorID(eEquipo equipos[], int tamEquipos, int id)
{
	int indice = -1;

	if (equipos != NULL && tamEquipos > 0)
	{
		for (int i = 0; i < tamEquipos; i++)
		{
			if (equipos[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}
