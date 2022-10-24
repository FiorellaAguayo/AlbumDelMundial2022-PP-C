#include "figuritas.h"
#ifndef ALBUM_H_
#define ALBUM_H_

typedef struct
{
	int idFigurita[55];
	int esDorada[55];
	int estado;
} eAlbum;

#endif /* ALBUM_H_ */

void inicializarAlbum(eAlbum album);

int inicializarIdsFiguritasEnAlbum(eAlbum album);
//int inicializarIdsFiguritasEnAlbum(eAlbum album, int idFigurita[], int tamIdFigurita);

int buscarIdsFiguritasEnAlbum(eAlbum album);
//int buscarIdsFiguritasEnAlbum(eAlbum album, int idFigurita[], int tamIdFigurita);

int pegarFiguritasEnAlbum(eAlbum album, eFiguritas unaFigurita);

int comprarFiguritasRandoms(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos, eAlbum album, eFiguritas arrayRepetidas[],
		int tamRepetidas, eFiguritas arrayDoradas[], int tamDoradas, int* precioAcumulado);

int buscarIdsFig(eAlbum album, int id);

int mostrarFiguritasPegadas(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos, int criterio, eFiguritas arrayDoradas[]);

void mostrarUnaFiguritaPegada(eFiguritas unaFigurita, eEquipo arrayEquipos[], int tamEquipo);

void comprobarAlbumCompleto(eAlbum unAlbum, eFiguritas arrayFiguritas[], eFiguritas arrayDoradas[]);
