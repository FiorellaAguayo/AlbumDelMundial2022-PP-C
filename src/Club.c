#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Club.h"

int cargaDeClubs(eClub arrayClubs[], int tamClubs)
{
	int todoOk = -1;

	int idClub[10] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	char nombre[10][30] = { {"Boca Juniors"}, {"River Plate"}, {"Liverpool"}, {"Chelsea"}, {"Leverkusen"}, {"Colonia"}, {"FC Oporto"}, {"Lisboa"}, {"Santos FC"}, {"Corinthias"}};
	char entrenador[10][30] = { {"Hugo Ibarra"}, {"Martin Demichellis"}, {"Jurgen Klopp"}, {"Graham Potter"}, {"Xabi Alonso"}, {"Steffen Baumgart"}, {"Sergio Conceicao"},  {"Ruben Amorim"}, {"Orlando Ribeiro"}, {"Vítor Pereira"} };
	int anioFundacion[10] = {1905, 1901, 1892, 1905, 1904, 1948, 1893, 1906, 1912, 1910};

	if(arrayClubs != NULL && tamClubs)
	{
		for(int i = 0; i < tamClubs; i++)
		{
			arrayClubs[i].id = idClub[i];
			strcpy(arrayClubs[i].nombre, nombre[i]);
			strcpy(arrayClubs[i].entrenador, entrenador[i]);
			arrayClubs[i].anioFundacion = anioFundacion[i];
		}
		printf("\nClubs cargados con exito.\n");
		todoOk = 0;
	}
	return todoOk;
}

void mostrarUnClub(eClub unClub)
{
	printf("\n| %-5d | %-22s | %-23s | %-18d |", unClub.id, unClub.nombre, unClub.entrenador, unClub.anioFundacion);
	printf("\n|------------------------------------------------------------------------------|");
}

int listarClubs(eClub arrayClubs[], int tamClubs)
{
	int todoOk = -1;
	if(arrayClubs != NULL)
	{
		printf("\n                          *** Listado de Clubs ***                              ");
		printf("\n================================================================================");
		printf("\n| id    | nombre                 | entrenador              | anio de fundacion |");
		printf("\n|==============================================================================|");

		for(int i = 0; i < tamClubs; i++)
		{
			mostrarUnClub(arrayClubs[i]);
		}
		todoOk = 0;
	}
	return todoOk;
}
