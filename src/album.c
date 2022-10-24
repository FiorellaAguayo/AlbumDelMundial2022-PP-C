#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "album.h"
#include "figuritas.h"

#define VACIO 0
#define LLENO 1
#define PEGADO 2
#define REPETIDA 3
#define ES_DORADA 4

int comprarFiguritasRandoms(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos, eAlbum album, eFiguritas arrayRepetidas[],
		int tamRepetidas, eFiguritas arrayDoradas[], int tamDoradas, int *precioAcumulado)
{
	int todoOk = -1;
	int indice;
	int minimo = 1;
	int maximo = 10;
	int contadorFiguritas = 5;
	int flagRepetidas = 1;
	int flagDoradas = 1;
	int precio = 170;

	static int figuritasTotales = 0;

	if (arrayFiguritas != NULL && tamFiguritas > 0 && arrayEquipos != NULL && tamEquipos > 0)
	{
		srand(time(0));

		printf("\n******************************************************************************************");
		printf("\n*********************** PAQUETE DE FIGURITAS VENDIDO CON ÉXITO ***************************");
		printf("\n******************************************************************************************");
		printf("\nA usted le han tocado las siguientes figuritas...\n");

		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------");
		printf("\n| id   | nombre del jugador  | posición       | equipo     | director tecnico  | altura   | peso     | año de ingreso | fecha de nacimiento  ");
		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------");

		int indiceAlbumFigurita;
		int indiceRepetidas;
		int indiceDoradas;
		static int cont = 0;

		for (int i = 0; i < contadorFiguritas; i++)
		{
			indice = (rand() % (maximo - minimo + 1)) + minimo;

			indiceDoradas = (rand() % (5 - 1 + 1)) + minimo;

			indiceAlbumFigurita = buscarIdsFiguritasEnAlbum(album);
			indiceRepetidas = buscarEspacioLibre(arrayRepetidas, tamRepetidas);

			if (arrayFiguritas[indice].estado == LLENO || arrayFiguritas[indice].estado == PEGADO || arrayFiguritas[indice].estado == REPETIDA)
			{
				figuritasTotales++;
				if (figuritasTotales == 10 && flagDoradas == 1)
				{
					album.idFigurita[indiceAlbumFigurita] = arrayDoradas[indiceDoradas].idFigurita;
					arrayDoradas[indiceDoradas].estado = ES_DORADA;
					arrayFiguritas[indiceDoradas].estado = PEGADO;
					if(arrayFiguritas[indiceDoradas].estado == PEGADO)
					{
						cont++;
					}

					printf("FIGURITA PEGADA %d", cont);
					figuritasTotales = 0;
					flagDoradas = 0;
					mostrarUnaFigurita(arrayDoradas[indiceDoradas], arrayEquipos, tamEquipos);
					contadorFiguritas--;
				}

				mostrarUnaFigurita(arrayFiguritas[indice], arrayEquipos, tamEquipos);

				// PEGO FIGURITAS
				if (buscarIdsFig(album, arrayFiguritas[indice].idFigurita) != 0)
				{
					album.idFigurita[indiceAlbumFigurita] = arrayFiguritas[indice].idFigurita;
					arrayFiguritas[indice].estado = PEGADO;

					if(arrayFiguritas[indice].estado == PEGADO)
					{
						cont++;
					}
					printf("FIGURITA PEGADA %d", cont);

				}
				else
				{
					if (flagRepetidas)
					{
						arrayRepetidas[indiceRepetidas] = arrayFiguritas[indice];
						arrayRepetidas[indiceRepetidas].estado = REPETIDA;
					}

				}

			}
			else
			{
				i--;
			}

		}

		if (!flagRepetidas)
		{
			printf("\n\nLe tocaron figuritas repetidas");
		}
		if (!flagDoradas)
		{
			printf("\n\nFelicitaciones, le ha tocado una dorada!");
		}
		*precioAcumulado += precio;


	}
	todoOk = 0;

	return todoOk;
}

void inicializarAlbum(eAlbum album)
{
	album.estado = VACIO;
}

int inicializarIdsFiguritasEnAlbum(eAlbum album)
{
	int todoOk = -1;

	for (int i = 0; i < 55; i++)
	{
		album.idFigurita[i] = VACIO;
		todoOk = 0;
	}

	return todoOk;
}

int buscarIdsFiguritasEnAlbum(eAlbum album)
{
	int espacioLibre = -1;

	for (int i = 0; i < 55; i++)
	{
		if (album.idFigurita[i] == VACIO)
		{
			espacioLibre = i;
			break;
		}
	}

	return espacioLibre;
}

int buscarIdsFig(eAlbum album, int id)
{
	int todoOk = -1;

	for (int i = 0; i < 55; i++)
	{
		if (album.idFigurita[i] == id)
		{
			return 0;
		}
	}

	return todoOk;
}

int mostrarFiguritasPegadas(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos, int criterio, eFiguritas arrayDoradas[])
{
	int todoOk = -1;
	int flag = 0;
	char printA[30];

	if (criterio == 2)
	{
		strcpy(printA, "pegadas");
	}
	else if (criterio == 3)
	{
		strcpy(printA, "repetidas");
	}
	else
	{
		strcpy(printA, "doradas");

	}

	if (arrayFiguritas != NULL && tamFiguritas > 0 && arrayEquipos != NULL && tamEquipos > 0)
	{
		printf("\n========== listado de figuritas %s ==================", printA);
		printf("\n----------------------------------------------------------");
		printf("\n| nombre del jugador  | posición       | equipo           ");
		printf("\n----------------------------------------------------------");

		for (int i = 0; i < tamFiguritas; i++)
		{
			if (arrayFiguritas[i].estado == criterio)
			{
				mostrarUnaFiguritaPegada(arrayFiguritas[i], arrayEquipos, tamEquipos);
				flag = 1;
			}
		}
		printf("\n");

		if (!flag)
		{
			printf("No se ingresaron figuritas.\n");
		}

		todoOk = 0;
	}

	return todoOk;
}

void mostrarUnaFiguritaPegada(eFiguritas unaFigurita, eEquipo arrayEquipos[], int tamEquipo)
{
	char descripcion[51];
	char directorTecnico[51];

	cargarDatosDeEquipoPorID(arrayEquipos, tamEquipo, unaFigurita.equipo.id, descripcion, directorTecnico);

	printf("\n| %-19s | %-14s | %s ", unaFigurita.nombreJugador, unaFigurita.posicion, descripcion);
}
