#include <stdio.h>
#include <stdlib.h>
#include "album.h"
#include "Figurita.h"

#define INCOMPLETO 0
#define LLENO 1

#define VACIO -1

//INICIALIZACIONES
void inicializarEstado_Album(eAlbum album)
{
	album.estado = INCOMPLETO;
}

//----------------------------------------------

void inicializarID_Album(eAlbum* album)
{
	for (int i = 0; i < 55; i++)
	{
		(*album).id[i] = VACIO;
	}
}
//-------------------------------------------

void inicializarIsEmpty_Album(eAlbum* album)
{
	for (int i = 0; i < 55; i++)
	{
		(*album).isEmpty[i] = VACIO;
	}
}
void inicializarEstadoDoradas_Album(eAlbum* album)
{
	for (int i = 0; i < 55; i++)
	{
		(*album).esDorada[i] = VACIO;
	}
}


//BUSCAR ESPACIO LIBRE
int buscarEspacioLibreEnID_Album(eAlbum* album)
{
	int espacioLibre = -1;

	for(int i = 0; i < 55; i++)
	{
		if((*album).id[i] == VACIO)
		{
			espacioLibre = i;
			break;
		}
	}

	return espacioLibre;
}

int buscarEspacioLibreEnDoradas_Album(eAlbum album)
{
	int espacioLibre = -1;

	for(int i = 0; i < 55; i++)
	{
		if(album.esDorada[i] == VACIO)
		{
			espacioLibre = i;
			break;
		}
	}

	return espacioLibre;
}

/*buscar espacio en repetidas uso el buscarLibre de figuritas*/

//BUSCAR POR ID
int buscarFiguritasRepetidasPorID_Album(eAlbum* album, int id)
{
	int repetida = 0;

	//id = 2
	for (int i = 0; i < 55; i++)
	{
		//0 == 2
		//1 == 2
		//2 == 2
		if ((*album).id[i] == id)
		{
			repetida = 1;
			break;
		}
	}
	return repetida;
}


