#include <stdio.h>
#include <stdlib.h>
#include "Figurita.h"
#include "menus.h"
#include "Equipo.h"
#include "Album.h"

#define TAM_BANCO_FIGURITAS 56
#define TAM_EQUIPOS 5
#define TAM_REPETIDAS 100
#define TAM_CLUBS 10
#define INCOMPLETO 0

int main(void)
{
	setbuf(stdout, NULL);
	int salir = 0;

	eEquipo equipos[TAM_EQUIPOS];
	eFigurita bancoFiguritas[TAM_BANCO_FIGURITAS];
	eAlbum album;
	eFigurita coleccionRepetidas[TAM_REPETIDAS];
	eClub clubs[TAM_CLUBS];

	int id = 0;
	int cantidadRepeticiones = 0;
	int contadorSobres = 0;
	int cantidadSobresTotal = 0;
	int precioAcumulado = 0;
	int precioAlbumCompleto = 0;
	int flag = 0;
	int flag2 = 0;

	int contadorBJ = 0, contadorRP = 0, contadorLiverpool = 0, contadorChelsea = 0, contadorLeverkusen = 0, contadorColonia = 0, contadorOporto = 0, contadorLisboa = 0, contadorSantos = 0, contadorCorinthias = 0;
	int idClubMayor;

	if(cargaDeEquipos(equipos, TAM_EQUIPOS) == -1)
	{
		printf("\nHubo un problema al cargar los equipos.\n");
	}

	if(inicializarFiguritas_ArrayFiguritas(bancoFiguritas, TAM_BANCO_FIGURITAS) == -1)
	{
		printf("\nHubo un problema al inicializar las figuritas.\n");
	}

	if(hardcodeoDeFiguritas(bancoFiguritas, TAM_BANCO_FIGURITAS, &id, &flag) == -1)
	{
		printf("\nHubo un problema al hardcodear las figuritas.\n");
	}

	if(cargaDeClubs(clubs, TAM_CLUBS) == -1)
	{
		printf("\nHubo un problema al cargar los equipos.\n");
	}


	//PUNTO COLECCIONISTA 2
	//inicializo estado figurita VACIO, NO DORADA, SUELTA (ya esta)
	//inicializo estado ALBUM
	inicializarEstado_Album(album);

	//inicializo repetidas
	if(inicializarColeccionRepetidas(coleccionRepetidas, TAM_REPETIDAS) == -1)
	{
		printf("\nHubo un problema al inicializar las figuritas.\n");
	}

	//inicializo los id en el album
	inicializarID_Album(&album);
	//inicializo los id es dorada
	inicializarEstadoDoradas_Album(&album);

	inicializarIsEmpty_Album(&album);

	while(salir == 0)
	{
		switch(menuPrincipal())
		{
			case 1:
				//perfil administrador
				switch(menuAdministrador())
				{
					case 1:
						//alta figurita
						if(altaFiguritas(bancoFiguritas, TAM_BANCO_FIGURITAS, &id, equipos, TAM_EQUIPOS, clubs, TAM_CLUBS) == -1)
						{
							printf("\nHubo un problema al hacer el alta de figuritas.\n");
						}
						else
						{
							flag = 1;
						}
						break;

					case 2:
						//modificar figurita
						if(flag)
						{
							if(modificarFiguritas(bancoFiguritas, TAM_BANCO_FIGURITAS, equipos, TAM_EQUIPOS, clubs, TAM_CLUBS) == -1)
							{
								printf("\nHubo un problema al hacer la modificacion de figuritas.\n");
							}
						}
						else
						{
							printf("\nAtencion. Debe ingresar al menos una figurita.\n");
						}
						break;

					case 3:
						//listar figuritas
						if(flag)
						{
							if(listarFiguritasCreadas(bancoFiguritas, TAM_BANCO_FIGURITAS, equipos, TAM_EQUIPOS, clubs, TAM_CLUBS) == -1)
							{
								printf("\nHubo un problema al hacer la modificacion de figuritas.\n");
							}
						}
						else
						{
							printf("\nAtencion. Debe ingresar al menos una figurita.\n");
						}
						break;
				}
				break;

			case 2:
				//perfil coleccionista
				if(flag)
				{
					switch(menuColeccionista())
					{
						case 1:
							if(comprarPaqueteDeFiguritasRandom(bancoFiguritas, TAM_BANCO_FIGURITAS, equipos, TAM_EQUIPOS, &album, coleccionRepetidas, TAM_REPETIDAS, &cantidadRepeticiones, &contadorSobres, &cantidadSobresTotal, &precioAcumulado, &precioAlbumCompleto, clubs, TAM_CLUBS) == -1)
							{
								printf("\nHubo un problema al hacer la compra de figuritas.\n");
							}
							else
							{
								flag2 = 1;
							}
							break;

						case 2:
							if(intercambiarFiguritas(bancoFiguritas, TAM_BANCO_FIGURITAS, equipos, TAM_EQUIPOS, coleccionRepetidas, TAM_REPETIDAS, &flag2, clubs, TAM_CLUBS) == -1)
							{
								printf("\nHubo un problema al hacer el intercambio de figuritas.\n");
							}
							break;
					}
				}
				else
				{
					printf("\nAtencion. Para ingresar a este perfil deben cargarse figuritas.\n");
				}
				break;

			case 3:
				//informes
				switch(menuInformes())
				{
					case 1:
						// Listado de figuritas pegadas
						if(flag)
						{
							if(listadoFiguritasPegadas(bancoFiguritas, TAM_BANCO_FIGURITAS, equipos, TAM_EQUIPOS) == -1)
							{
								printf("\nHubo un problema al hacer el listado de figuritas pegadas.\n");
							}
						}
						else
						{
							printf("\nAtencion. No se ingresaron figuritas.\n");
						}
						break;

					case 2:
						if(flag)
						{
							printf("\n========== listado de figuritas repetidas =================");
							printf("\n\nCantidad de repeticiones en la pila: %d", cantidadRepeticiones);
							if(listarFiguritasRepetidas(coleccionRepetidas, TAM_REPETIDAS, equipos, TAM_EQUIPOS) == -1)
							{
								printf("\nHubo un problema al hacer el listado de figuritas repetidas.\n");
							}
						}
						else
						{
							printf("\nAtencion. No se ingresaron figuritas.\n");
						}
						break;

					case 3:
						if(flag)
						{
							if(listadoFiguritasDoradasPegadas(bancoFiguritas, TAM_BANCO_FIGURITAS, equipos, TAM_EQUIPOS, clubs, TAM_CLUBS) == -1)
							{
								printf("\nHubo un problema al hacer el listado de figuritas doradas pegadas.\n");
							}
						}
						else
						{
							printf("\nAtencion. No se ingresaron figuritas.\n");
						}
						break;

					case 4:
						if(flag)
						{
							if(cantidadSobresTotal == 0)
							{
								printf("\nEl album no está completo.\n");
							}
							else
							{
								printf("\nLa cantidad de sobres que tuvo que comprar para completar el album es %d.\n", cantidadSobresTotal);
							}
						}
						else
						{
							printf("\nAtencion. No se ingresaron figuritas.\n");
						}
						break;

					case 5:
						if(flag)
						{
							if(precioAcumulado == 0)
							{
								printf("\nEl coleccionista no ha comprado ningún sobre.\n");
							}
							else
							{
								printf("\nEl coleccionista lleva gastado por el momento $%d.\n", precioAcumulado);
							}
						}
						else
						{
							printf("\nAtencion. No se ingresaron figuritas.\n");
						}
						break;

					case 6:
						if(flag)
						{
							if(album.estado == INCOMPLETO)
							{
								printf("\nEl album no está completo.\n");
							}
							else
							{
								printf("\nPara completar el album, el coleccionista gasto $%d", precioAlbumCompleto);
							}
						}
						else
						{
							printf("\nAtencion. No se ingresaron figuritas.\n");
						}
						break;

					case 7:
						if(flag)
						{
							if(listarFiguritasPegadasPorEquipo(bancoFiguritas, TAM_BANCO_FIGURITAS, equipos, TAM_EQUIPOS, clubs, TAM_CLUBS) == -1)
							{
								printf("\nHubo un problema al hacer el listado de figuritas doradas pegadas.\n");
							}
						}
						else
						{
							printf("\nAtencion. No se ingresaron figuritas.\n");
						}
						break;

					case 8:
						if(flag)
						{
							contadorDeClubs(bancoFiguritas, TAM_BANCO_FIGURITAS, &contadorBJ, &contadorRP, &contadorLiverpool, &contadorChelsea, &contadorLeverkusen, &contadorColonia, &contadorOporto, &contadorLisboa, &contadorSantos, &contadorCorinthias, &idClubMayor);
							if(listarFiguritasPegadasPorClubMayor(bancoFiguritas, TAM_BANCO_FIGURITAS, equipos, TAM_EQUIPOS, clubs, TAM_CLUBS, idClubMayor) == -1)
							{
								printf("\nHubo un problema al hacer el listado de figuritas segun el club.\n");
							}
						}
						else
						{
							printf("\nAtencion. No se ingresaron figuritas.\n");
						}
						break;

					case 9:
						break;
				}
				break;

			case 4:
				//salir
				printf("\nGracias por utilizar este programa. Adios!");
				salir = 1;
				break;
		}
	}
	return EXIT_SUCCESS;
}

