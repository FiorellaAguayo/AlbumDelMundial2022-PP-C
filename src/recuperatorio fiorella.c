#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "figuritas.h"
#include "hardcodeo.h"
#include "album.h"
#include "validaciones.h"

#define TAM_FIGURITAS 55
#define TAM_EQUIPOS 5
#define TAM_ALBUM 55
#define TAM_REPETIDAS 1000
#define TAM_DORADAS 1000

#define PEGADO 2
#define REPETIDA 3
#define ES_DORADA 4
#define COMPLETO 1

int main(void)
{
	setbuf(stdout, NULL);

	char respuesta = 's';
	int respuestaMenuPrincipal;
	int precioAcumulado = 0;

	eFiguritas bancoFiguritas[TAM_FIGURITAS];
	eFiguritas figuritasRepetidas[TAM_REPETIDAS];
	eFiguritas figuritasDoradas[TAM_DORADAS];

	eEquipo equiposHardcodeados[TAM_EQUIPOS] =
	{
	{ 1000, "Argentina", "Lionel Scaloni" },
	{ 1001, "Brasil", "Adenor Bacchi" },
	{ 1002, "Inglaterra", "Gareth Southgate" },
	{ 1003, "Francia", "Didier Deschamps" },
	{ 1004, "Alemania", "Hansi Flick" } };

	eAlbum album;

	inicializarAlbum(album);

	inicializarIdsFiguritasEnAlbum(album);

	buscarIdsFiguritasEnAlbum(album);

	int contadorId = 1;

	if (inicializarBancoFiguritas(bancoFiguritas, TAM_FIGURITAS) != 0)
	{
		printf("\nHubo un problema al inicializar las figuritas.\n");
	}

	if (hardcodearFiguritas(bancoFiguritas, TAM_FIGURITAS, &contadorId) != 0)
	{
		printf("\nHubo un problema al hardcodear las figuritas.\n");
	}

	hardcodearDoradas(bancoFiguritas, figuritasDoradas, TAM_DORADAS, &contadorId);

	while (respuesta == 's')
	{
		switch (menuPrincipal(&respuestaMenuPrincipal))
		{
			case 1:
				//perfil administrador
				switch (menuAdministrador())
				{
					case 1:
						//alta figurita
						if (altaFiguritas(bancoFiguritas, TAM_FIGURITAS, &contadorId, equiposHardcodeados, TAM_EQUIPOS) == 0)
						{
							printf("\nAlta exitosa.\n");
						}
						break;
					case 2:
						//modificar figurita
						if (modificarFiguritas(bancoFiguritas, TAM_FIGURITAS, equiposHardcodeados, TAM_EQUIPOS) == 0)
						{
							printf("\nModificación exitosa.\n");
						}
						break;
					case 3:
						listarFiguritasOrdenadas(bancoFiguritas, TAM_FIGURITAS, equiposHardcodeados, TAM_EQUIPOS);
						break;
					case 4:
						//atrás
						break;
					default:
						printf("\nOpción inválida.\n");
						break;
				}
				break;
			case 2:
				//perfil coleccionista
				switch (menuColeccionista())
				{
					case 1:
						//comprar paquete de figuritas
						comprarFiguritasRandoms(bancoFiguritas, TAM_FIGURITAS, equiposHardcodeados, TAM_EQUIPOS, album, figuritasRepetidas, TAM_REPETIDAS,
								figuritasDoradas, TAM_DORADAS, &precioAcumulado);
						break;
					case 2:
						printf("\nmostrando pegadas");
						mostrarFiguritasPegadas(bancoFiguritas, TAM_FIGURITAS, equiposHardcodeados, TAM_EQUIPOS, PEGADO, figuritasDoradas);
						break;
					case 3:
						mostrarFiguritasPegadas(figuritasRepetidas, TAM_REPETIDAS, equiposHardcodeados, TAM_EQUIPOS, REPETIDA, figuritasDoradas);
						printf("\nmostrando repetidas");
						//atras
						break;
					default:
						printf("\nOpción inválida.\n");
						break;
				}
				break;
			case 3:
				//informes
				switch (menuInformes())
				{
					case 1:

							printf("\nmostrando pegadas");
							mostrarFiguritasPegadas(bancoFiguritas, TAM_FIGURITAS, equiposHardcodeados, TAM_EQUIPOS, PEGADO, figuritasDoradas);

						break;
					case 2:
						mostrarFiguritasPegadas(figuritasRepetidas, TAM_REPETIDAS, equiposHardcodeados, TAM_EQUIPOS, REPETIDA, figuritasDoradas);
						printf("\nmostrando repetidas");
						break;
					case 3:
						mostrarFiguritasPegadas(figuritasDoradas, TAM_REPETIDAS, equiposHardcodeados, TAM_EQUIPOS, ES_DORADA, figuritasDoradas);
						//mostrarFiguritasPegadas(album, figuritasRepetidas, TAM_REPETIDAS, equiposHardcodeados, TAM_EQUIPOS, DORADA_PEGADA);
						//listarFiguritasDoradasPegadas(album, bancoFiguritas, TAM_DORADAS, equiposHardcodeados, TAM_EQUIPOS);
						break;
					case 4:
//						comprobarAlbumCompleto(album, bancoFiguritas, figuritasDoradas);
						break;
					case 5:
						printf("\nHasta el momento, el coleccionista lleva gastado $%d", precioAcumulado);
						break;
					case 6:
						break;
					case 7:
						listarFiguritasPorEquipo(bancoFiguritas, TAM_FIGURITAS, equiposHardcodeados, TAM_EQUIPOS, figuritasDoradas);
						break;
					default:
						break;
				}
		}
	}

	return EXIT_SUCCESS;
}
