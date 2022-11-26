#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Figurita.h"
#include "inputs.h"
#include "Equipo.h"
#include "menus.h"
#include "validaciones.h"
#include "album.h"
#include "club.h"

//estado figurita
#define VACIO -1
#define OCUPADO 1
#define PEGADO 2
#define SUELTO 3

//estado dorada
#define NO 4
#define SI 5

//estado album
#define LLENO 6


//ABM
int altaFiguritas(eFigurita arrayFiguritas[], int tamFiguritas, int* id, eEquipo arrayEquipos[], int tamEquipos, eClub arrayClubs[], int tamClubs)
{
	int todoOk = -1;
	int indiceLibre;
	eFigurita auxFigurita;
	char respuestaDorada;
	char confirmar;

	if(arrayFiguritas != NULL && tamFiguritas > 0 && id != NULL && arrayEquipos != NULL && tamEquipos > 0)
	{
		printf("\n>>>>>>>> alta de figuritas\n");

		indiceLibre = buscarEspacioLibre(arrayFiguritas, tamFiguritas);

		if(indiceLibre == -1)
		{
			printf("\nNo hay espacio para más figuritas.\n");
		}
		else
		{
			auxFigurita.id = *id;
			(*id)++;

			pedirCadena(auxFigurita.nombreJugador, "\nIngrese el nombre del jugador: ", "\nError. El nombre ingresado no es valido.", 30);
			validateCharacter(auxFigurita.nombreJugador);
			firstCapitalChar(auxFigurita.nombreJugador);

			pedirCadena(auxFigurita.posicion, "Ingrese la posicion del jugador (delantero, mediocampista, defensor o arquero): ", "\nError. La posicion ingresada no es valida.", 15);
			validateCharacter(auxFigurita.posicion);
			firstCapitalChar(auxFigurita.posicion);
			validarPosicion(auxFigurita.posicion);

			listarEquipos(arrayEquipos, tamEquipos);
			pedirEntero(&auxFigurita.idEquipo, "\nIngrese ID del equipo: ", "Error. El ID ingresado no es valido.\n", 1000, 1004);

			pedirFlotante(&auxFigurita.altura, "\nIngrese la altura del jugador (entre 1 y 3 mts): ", "Error. La altura ingresada no es valida.\n", 1, 3);

			pedirFlotante(&auxFigurita.peso, "\nIngrese el peso del jugador (entre 50 y 130 kg): ", "Error. El peso ingresado no es valido.\n", 50, 130);

			pedirEntero(&auxFigurita.anioIngresoSeleccion, "\nIngrese el anio de ingreso del jugador (entre 1930 y 2022): ", "Error. El anio ingresado no es valido.\n", 1930, 2022);

			pedirEntero(&auxFigurita.fechaNacimiento.dia, "\nIngrese el dia de nacimiento del jugador: ", "Error. El dia ingresado no es valido.\n", 1, 31);
			pedirEntero(&auxFigurita.fechaNacimiento.mes, "\nIngrese el mes de nacimiento del jugador: ", "Error. El mes ingresado no es valido.\n", 1, 12);
			pedirEntero(&auxFigurita.fechaNacimiento.anio, "\nIngrese el anio de nacimiento del jugador: ", "Error. El anio ingresado no es valido.\n", 1930, 2022);

			listarClubs(arrayClubs, tamClubs);
			pedirEntero(&auxFigurita.idClub, "\nIngrese ID del club: ", "Error. El ID ingresado no es valido.\n", 100, 109);

			auxFigurita.estado = OCUPADO;

			pedirCaracter(&respuestaDorada, "\n¿Es dorada? (s = si | n = no): ", "\nError. Respuesta no valida.", 's', 'n');
			if(respuestaDorada == 's')
			{
				auxFigurita.esDorada = SI;
			}

			encabezadoFigurita_1();
			mostrarUnaFigurita(auxFigurita, arrayEquipos, tamEquipos, arrayClubs, tamClubs);
			pedirCaracter(&confirmar, "\n\n¿Desea dar de alta esta figurita? (s = si | n = no): ", "\nError, El caracter ingresado no es valido.", 's', 'n');
			if(confirmar == 's')
			{
				arrayFiguritas[indiceLibre] = auxFigurita;
				printf("\nAlta exitosa !!!\n");
			}
			else
			{
				printf("\nSe ha cancelado el alta.\n");
			}
		}
		todoOk = 0;
	}
	return todoOk;
}

int modificarFiguritas(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos, eClub clubs[], int tamClubs)
{
	int todoOk = -1;
	int id;
	int indiceFigurita;
	char opcion;

	char auxNombre[30];
	char auxPosicion[15];
	int auxIdEquipo;
	float auxAltura;
	float auxPeso;
	int auxAnioIngresoSeleccion;
	eFecha auxFecha;

	char descripcion[30];
	char directorTecnico[30];

	if(arrayFiguritas != NULL && tamFiguritas > 0 && arrayEquipos != NULL && tamEquipos)
	{
		printf("\n>>>>>>>> modificacion de figuritas\n");
		listarFiguritasCreadas(arrayFiguritas, tamFiguritas, arrayEquipos, tamEquipos, clubs, tamClubs);

		printf("\nIngrese el ID de la figurita que desea modificar: ");
		scanf("%d", &id);

		indiceFigurita = buscarFiguritaPorID(arrayFiguritas, tamFiguritas, id);

		if(indiceFigurita == -1)
		{
			printf("\nNo existe figurita con ese ID.\n");
		}
		else
		{
			encabezadoFigurita_1();
			mostrarUnaFigurita(arrayFiguritas[indiceFigurita], arrayEquipos, tamEquipos, clubs, tamClubs);
			printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");
			pedirCaracter(&opcion, "\n\n¿Desea modificar esta figurita? (s = si | n = no): ", "\nError. Ingrese opcion valida.", 's', 'n');

			if(opcion == 's')
			{
				switch(menuModificar())
				{
					case '1':
						printf("\nNOMBRE ACTUAL: %s", arrayFiguritas[indiceFigurita].nombreJugador);
						pedirCadena(auxNombre, "\nIngrese el nuevo nombre del jugador: ", "\nError. El nombre ingresado no es valido.", 30);
						validateCharacter(auxNombre);
						firstCapitalChar(auxNombre);
						strcpy(arrayFiguritas[indiceFigurita].nombreJugador, auxNombre);
						break;

					case '2':
						printf("\nPOSICION ACTUAL: %s", arrayFiguritas[indiceFigurita].posicion);
						pedirCadena(auxPosicion, "\nIngrese la nueva posicion del jugador (delantero, mediocampista, defensor o arquero): ", "\nError. La posicion ingresada no es valida.", 15);
						validateCharacter(auxPosicion);
						firstCapitalChar(auxPosicion);
						validarPosicion(auxPosicion);
						strcpy(arrayFiguritas[indiceFigurita].posicion, auxPosicion);
						break;

					case '3':
						listarEquipos(arrayEquipos, tamEquipos);
						cargarDatosDeEquipoPorID(arrayEquipos, tamEquipos, arrayFiguritas[indiceFigurita].idEquipo, descripcion, directorTecnico);
						printf("\nEQUIPO ACTUAL: %s", descripcion);
						pedirEntero(&auxIdEquipo, "\nIngrese el ID del nuevo equipo: ", "\nError. ID no valido.", 1000, 1004);
						arrayFiguritas[indiceFigurita].idEquipo = auxIdEquipo;
						break;

					case '4':
						pedirFlotante(&auxAltura, "\nIngrese la nueva altura del jugador (entre 1 y 3 mts): ", "\nError. Altura no valida.", 1, 3);
						arrayFiguritas[indiceFigurita].altura = auxAltura;
						break;

					case '5':
						pedirFlotante(&auxPeso, "\nIngrese el nuevo peso del jugador (entre 50 y 130 kg): ", "\nError. Peso no valido.", 50, 130);
						arrayFiguritas[indiceFigurita].peso = auxPeso;
						break;

					case '6':
						pedirEntero(&auxAnioIngresoSeleccion, "\nIngrese el nuevo anio de ingreso a la seleccion (entre 1930 y 2022):  ", "\nError. Anio no valido.", 1930, 2022);
						arrayFiguritas[indiceFigurita].anioIngresoSeleccion = auxAnioIngresoSeleccion;
						break;

					case '7':
						pedirEntero(&auxFecha.dia, "\nIngrese el nuevo dia de nacimiento del jugador: ", "Error. El dia ingresado no es valido.\n", 1, 31);
						arrayFiguritas[indiceFigurita].fechaNacimiento.dia = auxFecha.dia;

						pedirEntero(&auxFecha.mes, "\nIngrese el nuevo mes de nacimiento del jugador: ", "Error. El mes ingresado no es valido.\n", 1, 12);
						arrayFiguritas[indiceFigurita].fechaNacimiento.mes = auxFecha.mes;

						pedirEntero(&auxFecha.anio, "\nIngrese el nuevo anio de nacimiento del jugador: ", "Error. El anio ingresado no es valido.\n", 1930, 2022);
						arrayFiguritas[indiceFigurita].fechaNacimiento.anio = auxFecha.anio;
						break;
				}
				printf("\nModificacion exitosa !!!\n");
			}
			else
			{
				printf("\nSe cancelo la modificacion.\n");
			}
		}
		todoOk = 0;
	}
	return todoOk;
}

//MOSTRAR
void mostrarUnaFigurita(eFigurita unaFigurita, eEquipo arrayEquipos[], int tamEquipos, eClub clubs[], int tamClubs)
{
	char descripcion[51];
	char directorTecnico[51];
	char nombreClub[30];

	char estadoDorada[] = {" SI"};
	char estadoDorada2[] = {" NO"};

	cargarDatosDeEquipoPorID(arrayEquipos, tamEquipos, unaFigurita.idEquipo, descripcion, directorTecnico);
	cargarDatosDeClubPorID(clubs, tamClubs, unaFigurita.idClub, nombreClub);

	printf("\n| %-4d | %-23s | %-14s | %-10s | %-28s | %-8.2f | %-8.2f | %-14d | %2.d/%2.d/%-13d | %-14s | ", unaFigurita.id, unaFigurita.nombreJugador,
			unaFigurita.posicion, descripcion, directorTecnico, unaFigurita.altura, unaFigurita.peso, unaFigurita.anioIngresoSeleccion, unaFigurita.fechaNacimiento.dia,
			unaFigurita.fechaNacimiento.mes, unaFigurita.fechaNacimiento.anio, nombreClub);

	if(unaFigurita.esDorada == SI)
	{
		printf("%-13s   |", estadoDorada);
	}
	else
	{
		printf("%-13s   |", estadoDorada2);
	}
}

int listarFiguritasCreadas(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos, eClub clubs[], int tamClubs)
{
	int todoOk = -1;
	int flag = 0;
	if(arrayFiguritas != NULL && tamFiguritas > 0)
	{
		printf("\n================================================ listado de figuritas ===================================================================================================");
		encabezadoFigurita_1();
		for(int i = 0; i < tamFiguritas; i++)
		{
			if(arrayFiguritas[i].estado == OCUPADO)
			{
				mostrarUnaFigurita(arrayFiguritas[i], arrayEquipos, tamEquipos, clubs, tamClubs);
				flag = 1;
			}
		}

		if(!flag)
		{
			printf("\nNo se ingresaron figuritas.\n");
		}

		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

		todoOk = 0;
	}
	return todoOk;
}

void mostrarUnaFiguritaPegadasYRepetidas(eFigurita unaFigurita, eEquipo arrayEquipos[], int tamEquipos)
{
	char descripcion[51];
	char directorTecnico[51];

	cargarDatosDeEquipoPorID(arrayEquipos, tamEquipos, unaFigurita.idEquipo, descripcion, directorTecnico);

	printf("\n| %-23s | %-14s | %-12s |", unaFigurita.nombreJugador, unaFigurita.posicion, descripcion);

}

int listadoFiguritasPegadas(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos)
{
	int todoOk = -1;
	int flag = 0;
	if(arrayFiguritas != NULL && tamFiguritas)
	{
		printf("\n============== listado de figuritas pegadas ===============");
		encabezadoFigurita_2();

		for(int i = 0; i < tamFiguritas; i++)
		{
			if(arrayFiguritas[i].estadoAlbum == PEGADO)
			{
				mostrarUnaFiguritaPegadasYRepetidas(arrayFiguritas[i], arrayEquipos, tamEquipos);
				flag = 1;
			}
		}
		printf("\n-----------------------------------------------------------");

		if(!flag)
		{
			printf("\nNo hay figuritas pegadas.\n");
		}
		todoOk = 0;
	}
	return todoOk;
}

int listarFiguritasRepetidas(eFigurita arrayRepetidas[], int tamRepetidas, eEquipo arrayEquipos[], int tamEquipos)
{
	int todoOk = -1;
	int flag = 0;
	if(arrayRepetidas != NULL && tamRepetidas > 0)
	{
		encabezadoFigurita_2();
		for(int i = 0; i < tamRepetidas; i++)
		{
			if(arrayRepetidas[i].estado == OCUPADO)
			{
				mostrarUnaFiguritaPegadasYRepetidas(arrayRepetidas[i], arrayEquipos, tamEquipos);
				flag= 1;
			}
		}
		printf("\n-----------------------------------------------------------");

		if(!flag)
		{
			printf("\nNo hay figuritas repetidas.\n");
		}

		todoOk = 0;
	}
	return todoOk;
}

//HARCODEO

int hardcodeoDeFiguritas(eFigurita arrayFiguritas[], int tamFiguritas, int* id, int* flag)
{
	int todoOk = -1;

	char nombreCargado[55][50] = {  { "Phil Foden" },
									{ "Diogo Costa" },
									{ "Thiago Almada" },
									{ "Lisandro Martinez" },
									{ "Ricardo Queresma" },
									{ "Alisson Becker" },
									{ "Kai Havertz" },
									{ "Jude Bellingham" },
									{ "Nicolas Otamendi" },
									{ "Trent Alexander Arnold" },
									{ "David Raum Defensa" },
									{ "Bukayo Saka" },
									{ "Lucas Paqueta" },
									{ "Harry Maguir" },
									{ "Pepe" },
									{ "Julian Alvarez" },
									{ "Rui Patricio" },
									{ "Ederson Moraes" },
									{ "Cristiano Ronaldo" },
									{ "Manuel Neuer" },
									{ "Thomas Muller" },
									{ "Lionel Messi" },
									{ "Paulo Dybala" },
									{ "Di Maria" },
									{ "Thilo Kehrer" },
									{ "Dani Alves" },
									{ "Renato Sanches" },
									{ "William Carvalho" },
									{ "Dibu" },
									{ "Jordan Pickford" },
									{ "Leandro Paredes" },
									{ "Jonas Hofmann" },
									{ "Mason Mount" },
									{ "Bernardo Silva" },
									{ "Richarlison" },
									{ "Kevin Trapp" },
									{ "Nick Pope" },
									{ "Philipe Coutinho" },
									{ "Cristiano Ronaldo" },
									{ "Vitor Ferreira" },
									{ "Jamal Musiala" },
									{ "Thiago Silva" },
									{ "Neymar" },
									{ "Alejandro Gomez" },
									{ "Alez Telles" },
									{ "Harry Kane" },
									{ "Franco Armani" },
									{ "Marco Reus" },
									{ "Antonio Rudigier" },
									{ "Otavio" },
									{ "Vinicius Junior" },
									{ "Jack Grealish" },
									{ "Timo Werner" },
									{ "Raphinha" },
									{ "Mason Greenwood" }};


	char posicionCargada[55][15] = { { "Mediocampista" },
									 { "Arquero" },
									 { "Mediocampista" },
									 { "Defensor" },
									 { "Delantero" },
									 { "Arquero" },
									 { "Medicoampista" },
									 { "Mediocampista" },
									 { "Defensor" },
									 { "Defensor" },
									 { "Defensor" },
									 { "Delantero" },
									 { "Mediocampista" },
									 { "Defensor" },
									 { "Defensor" },
									 { "Delantero" },
									 { "Arquero" },
									 { "Defensor" },
									 { "Delantero" },
									 { "Arquero" },
									 { "Delantero" },
									 { "Delantero" },
									 { "Delantero" },
									 { "Mediocampista" },
									 { "Defensor" },
									 { "Mediocampista" },
									 { "Mediocampista" },
									 { "Mediocampista" },
									 { "Arquero" },
									 { "Arquero" },
									 { "Mediocampista" },
									 { "Mediocampista" },
									 { "Mediocampista" },
									 { "Mediocampista" },
									 { "Delantero" },
									 { "Arquero" },
									 { "Arquero" },
									 { "Mediocampista" },
									 { "Mediocampista" },
									 { "Delantero" },
									 { "Defensor" },
									 { "Delantero" },
									 { "Mediocampista" },
									 { "Defensor" },
									 { "Delantero" },
									 { "Delantero" },
									 { "Arquero" },
									 { "Defensor" },
									 { "Mediocampista"  },
									 { "Delantero" },
									 { "Mediocampista" },
									 { "Delantero" },
									 { "Delantero" },
									 { "Delantero" },
									 { "Delantero" } };

	int equipoCargado[55] = {1001, 1003, 1000, 1000, 1003, 1004, 1002, 1001, 1000, 1001, 1002, 1001, 1004, 1001, 1003, 1000, 1003, 1004, 1003, 1002, 1002, 1000, 1000, 1000, 1002, 1004, 1003, 1003, 1000, 1001, 1000, 1002, 1001, 1003, 1004, 1002, 1001, 1004, 1003, 1002, 1004, 1004, 1000, 1004, 1001, 1003, 1000, 1002, 1002, 1003, 1004, 1001, 1002, 1004, 1001};

	float alturaCargada[55] = {2.51, 2.44, 1.14, 1.59, 1.59, 1.2, 2.81, 2.64, 2.02, 1.22, 2.51, 2.44, 1.14, 1.59, 1.59, 1.2, 2.81, 2.64, 2.02, 1.22, 2.51, 2.44, 1.14, 1.59, 1.59, 1.2, 2.81, 2.64, 2.02, 1.22, 2.51, 2.44, 1.14, 1.59, 1.59, 1.2, 2.81, 2.64, 2.02, 1.22, 2.51, 2.44, 1.14, 1.59, 1.59, 1.2, 2.81, 2.64, 2.02, 1.22, 2.51, 2.44, 1.14, 1.59, 1.59};

	float pesoCargado[55] = {87.05, 73.73, 93.16, 51.57, 88.56, 101.03, 93.67, 81.89, 96.82, 42.8, 87.05, 73.73, 93.16, 51.57, 88.56, 101.03, 93.67, 81.89, 96.82, 42.8, 87.05, 73.73, 93.16, 51.57, 88.56, 101.03, 93.67, 81.89, 96.82, 42.8, 87.05, 73.73, 93.16, 51.57, 88.56, 101.03, 93.67, 81.89, 96.82, 42.8, 87.05, 73.73, 93.16, 51.57, 88.56, 101.03, 93.67, 81.89, 96.82, 42.8, 87.05, 73.73, 93.16, 51.57, 88.56};

	int anioIngresoCargado[55] = {2017, 2015, 2020, 2000, 2000, 2003, 2018, 2022, 2019, 2020, 2006, 2008, 2016, 2013, 2000, 2002, 2015, 2022, 2019, 2018, 2017, 2015, 2020, 2000, 2000, 2003, 2018, 2022, 2019, 2020, 2006, 2008, 2016, 2013, 2000, 2002, 2015, 2022, 2019, 2018, 2017, 2015, 2020, 2000, 2000, 2003, 2018, 2022, 2019, 2020, 2006, 2008, 2016, 2013, 2000};

	int fechaDiaCargado[55] = {03, 05, 25, 26, 21, 12, 7, 3, 9, 12, 03, 05, 25, 26, 21, 12, 7, 3, 9, 12, 03, 05, 25, 26, 21, 12, 7, 3, 9, 12, 03, 05, 25, 26, 21, 12, 7, 3, 9, 12, 03, 05, 25, 26, 21, 12, 7, 3, 9, 12, 03, 05, 25, 26, 21};

	int fechaMesCargado[55] = {02, 03, 04, 05, 06, 07, 03, 10, 11, 02, 03, 04, 05, 06, 07, 03, 10, 11, 05, 12, 02, 03, 04, 05, 06, 07, 03, 10, 11, 02, 03, 04, 05, 06, 07, 03, 10, 11, 05, 12, 02, 03, 04, 05, 06, 07, 03, 10, 11, 02, 03, 04, 05, 06, 07};

	int fechaAnioCargado[55] = {2000, 2003, 1993, 2000, 2003, 1994, 1997, 1999, 1991, 2001, 2000, 2003, 1993, 2000, 2003, 1994, 1997, 1999, 1991, 2001, 2000, 2003, 1993, 2000, 2003, 1994, 1997, 1999, 1991, 2001, 2000, 2003, 1993, 2000, 2003, 1994, 1997, 1999, 1991, 2001, 2000, 2003, 1993, 2000, 2003, 1994, 1997, 1999, 1991, 2001, 2000, 2003, 1993, 2000, 2003};

	int club[55] = {104, 100, 107, 100, 102, 107, 102, 105, 109, 108, 104, 100, 107, 102, 108, 101, 109, 106, 108, 101, 100, 100, 102, 105, 104, 106, 105, 107, 100, 105, 100, 100, 108, 104, 107, 106, 100, 102, 107, 108, 108, 109, 107, 103, 102, 106, 103, 104, 102, 105, 103, 105, 100, 106, 106};

	int estadoCargado[55] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	int estadoDoradaCargado[55] = {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, SI, SI, SI, SI, SI};

	if (arrayFiguritas != NULL && tamFiguritas > 0 && id != NULL)
	{
		for (int i = 0; i < 55; i++)
		{
			if (estadoCargado[i] == OCUPADO)
			{
				arrayFiguritas[i].id = *id;
				(*id)++;

				strcpy(arrayFiguritas[i].nombreJugador, nombreCargado[i]);
				strcpy(arrayFiguritas[i].posicion, posicionCargada[i]);

				arrayFiguritas[i].idEquipo = equipoCargado[i];
				arrayFiguritas[i].altura = alturaCargada[i];
				arrayFiguritas[i].peso = pesoCargado[i];
				arrayFiguritas[i].anioIngresoSeleccion = anioIngresoCargado[i];
				arrayFiguritas[i].fechaNacimiento.dia = fechaDiaCargado[i];
				arrayFiguritas[i].fechaNacimiento.mes = fechaMesCargado[i];
				arrayFiguritas[i].fechaNacimiento.anio = fechaAnioCargado[i];
				arrayFiguritas[i].idClub = club[i];
				arrayFiguritas[i].estado = estadoCargado[i];
				arrayFiguritas[i].esDorada = estadoDoradaCargado[i];
			}
			else
			{
				break;
			}
		}
		*flag = 1;
		printf("\nFiguritas hardcodeadas con exito.\n");
		todoOk = 0;
	}
	return todoOk;
}

//INICIALIZACIONES

int inicializarFiguritas_ArrayFiguritas(eFigurita arrayFiguritas[], int tamFiguritas)
{
	int todoOk = -1;
	if(arrayFiguritas != NULL && tamFiguritas >= 0)
	{
		for(int i = 0; i < tamFiguritas; i++)
		{
			arrayFiguritas[i].estado = VACIO;
			arrayFiguritas[i].esDorada = NO;
			arrayFiguritas[i].estadoAlbum = SUELTO;
		}
		printf("\nFiguritas inicializadas con exito.\n");
		todoOk = 0;
	}
	return todoOk;
}

int inicializarColeccionRepetidas(eFigurita arrayFiguritasRepetidas[], int tamRepetidas)
{
	int todoOk = -1;

	if(arrayFiguritasRepetidas != NULL && tamRepetidas > 0)
	{
		for(int i = 0; i < tamRepetidas; i++)
		{
			arrayFiguritasRepetidas[i].estado = VACIO;
		}
		todoOk = 0;
	}

	return todoOk;
}

int buscarEspacioLibre(eFigurita arrayFiguritas[], int tamFiguritas)
{
	int espacioLibre = -1;
	if(arrayFiguritas != NULL && tamFiguritas > 0)
	{
		for(int i = 0; i < tamFiguritas; i++)
		{
			if(arrayFiguritas[i].estado == VACIO)
			{
				espacioLibre = i;
				break;
			}
		}
	}
	return espacioLibre;
}

int cargarDatosDeEquipoPorID(eEquipo arrayEquipos[], int tamEquipos, int idEquipoFigurita, char descripcion[], char directorTecnico[])
{
	int todoOk = -1;
	if(arrayEquipos != NULL && tamEquipos > 0 && idEquipoFigurita > 0 && descripcion != NULL && directorTecnico != NULL)
	{
		for(int i = 0; i < tamEquipos; i++)
		{
			if(arrayEquipos[i].id == idEquipoFigurita)
			{
				strcpy(descripcion, arrayEquipos[i].descripcion);
				strcpy(directorTecnico, arrayEquipos[i].directorTecnico);
			}
		}
		todoOk = 0;
	}
	return todoOk;
}

int cargarDatosDeClubPorID(eClub arrayClubs[], int tamClubs, int idClubFigurita, char nombre[])
{
	int todoOk = -1;
	if(arrayClubs != NULL && tamClubs > 0 && idClubFigurita > 0 && nombre != NULL)
	{
		for(int i = 0; i < tamClubs; i++)
		{
			if(arrayClubs[i].id == idClubFigurita)
			{
				strcpy(nombre, arrayClubs[i].nombre);
			}
		}
		todoOk = 0;
	}
	return todoOk;
}


int buscarFiguritaPorID(eFigurita arrayFiguritas[], int tamFiguritas, int idIngresado)
{
	int indice = -1;
	if(arrayFiguritas != NULL && tamFiguritas > 0 && idIngresado >= 0)
	{
		for(int i = 0; i < tamFiguritas; i++)
		{
			if(arrayFiguritas[i].estado == OCUPADO && arrayFiguritas[i].id == idIngresado)
			{
				indice = i;
			}
		}
	}
	return indice;
}


int comprarPaqueteDeFiguritasRandom(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos, eAlbum* album, eFigurita arrayRepetidas[], int tamRepetidas, int* cantidadRepetidas, int* contadorSobres, int* cantidadSobresTotal, int* precioAcumulado, int* precioAlbumCompleto, eClub clubs[], int tamClubs)
{
	int todoOk = -1;
	int maximo = tamFiguritas;
	int minimo = 0;
	int contadorFiguritas = 5;

	int indiceRandom;
	int indiceLibreRepetidas;
	int indiceLibreAlbum;

	int flagSobres = 0;
	int precio = 170;

	static int hay10Sobres = 0;

	if(arrayFiguritas != NULL && tamFiguritas > 0)
	{
		srand(time(0));

		(*contadorSobres)++;
		*precioAcumulado += precio;
		hay10Sobres++;

		printf("\n******************************************************************************************");
		printf("\n                        PAQUETE DE FIGURITAS VENDIDO CON ÉXITO                            ");
		printf("\n******************************************************************************************");
		printf("\nA usted le han tocado las siguientes figuritas...\n");

		encabezadoFigurita_1();
		for(int i = 0; i < contadorFiguritas; i++)
		{
			indiceRandom = (rand() % (maximo - minimo + 1)) + minimo;

			indiceLibreAlbum = buscarEspacioLibreEnID_Album(album);
			indiceLibreRepetidas = buscarEspacioLibre(arrayRepetidas, tamRepetidas);

			if(arrayFiguritas[indiceRandom].estado == OCUPADO)
			{
				if(hay10Sobres == 10 && arrayFiguritas[indiceRandom].esDorada == SI)
				{
					mostrarUnaFigurita(arrayFiguritas[indiceRandom], arrayEquipos, tamEquipos, clubs, tamClubs);
					for(int i = 0; i < 55; i++)
					{
						if(album->id[i] == VACIO && album->isEmpty[i] == VACIO)
						{
							album->id[indiceLibreAlbum] = arrayFiguritas[indiceRandom].id;
							album->isEmpty[indiceLibreAlbum] = OCUPADO;
							arrayFiguritas[indiceRandom].estadoAlbum = PEGADO;
						}
					}
					hay10Sobres = 0;
				}

				if(arrayFiguritas[indiceRandom].esDorada == NO)
				{
					mostrarUnaFigurita(arrayFiguritas[indiceRandom], arrayEquipos, tamEquipos, clubs, tamClubs);

					if(buscarFiguritasRepetidasPorID_Album(album, arrayFiguritas[indiceRandom].id) == 0)
					{
						if(indiceLibreAlbum == -1)
						{
							printf("\nNo hay espacio libre en el album.\n");
							(*album).estado = LLENO;

							if(album->estado == LLENO && flagSobres == 0)
							{
								*cantidadSobresTotal = *contadorSobres;
								*precioAlbumCompleto = *precioAcumulado;
								flagSobres = 1;
							}
						}
						else
						{
//							printf("\nespacio libre en el album = %d", indiceLibreAlbum);
//							printf("\nen el indice %d del id en el album, se guarda el id %d de figurita ",indiceLibreAlbum, arrayFiguritas[indiceRandom].id);

							for(int i = 0; i < 55; i++)
							{
								if(album->id[i] == VACIO && album->isEmpty[i] == VACIO)
								{
									album->id[indiceLibreAlbum] = arrayFiguritas[indiceRandom].id;
									album->isEmpty[indiceLibreAlbum] = OCUPADO;
								}
							}

//							printf("\nvalor que guarda el id album = %d\n", album->id[indiceLibreAlbum]);

							arrayFiguritas[indiceRandom].estadoAlbum = PEGADO;
						}
					}
					else
					{
						printf("\nEs repetida.");
//						printf("\nid en el indice %d tiene el valor %d = valor del id figurita %d\n", indiceLibreAlbum, album->id[indiceLibreAlbum], arrayFiguritas[indiceRandom].id);

						if(indiceLibreRepetidas == -1)
						{
							printf("\nNo hay espacio libre en repetidas.\n");
						}
						else
						{
							arrayRepetidas[indiceLibreRepetidas] = arrayFiguritas[indiceRandom];
							(*cantidadRepetidas)++;
						}
					}
				}
				else
				{
					contadorFiguritas++;
				}
			}
			else
			{
				contadorFiguritas++;
			}
		}
		printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

		printf("\n\n");

//		for(int i = 0; i < 55; i++)
//		{
//			if(album->id[i] != VACIO)
//			{
//				printf("\nvalor de id album (%d) = %d",i, album->id[i]);
//			}
//		}
		todoOk = 0;
	}
	return todoOk;
}

int listadoFiguritasDoradasPegadas(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos, eClub clubs[], int tamClubs)
{
	int todoOk = -1;
	int flag = 0;
	if(arrayFiguritas != NULL && tamFiguritas)
	{
		printf("\n================================================ listado de figuritas doradas pegadas =======================================================================================");
		encabezadoFigurita_1();
		for(int i = 0; i < tamFiguritas; i++)
		{
			if(arrayFiguritas[i].esDorada == SI && arrayFiguritas[i].estadoAlbum == PEGADO)
			{
				mostrarUnaFigurita(arrayFiguritas[i], arrayEquipos, tamEquipos, clubs, tamClubs);
				flag = 1;
			}
		}
		printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

		if(!flag)
		{
			printf("\nNo hay figuritas doradas pegadas.\n");
		}

		todoOk = 0;
	}
	return todoOk;
}

void mostrarFiguritasPorEquipo(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo equipos[], int tamEquipos, int id, char criterio[], eClub clubs[], int tamClubs)
{
	int flag = 0;

	printf("\n=========================== listado de figuritas de %s pegadas ==============================================================================================================", criterio);
	encabezadoFigurita_1();
	for(int i = 0; i < tamFiguritas; i++)
	{
		if(id == arrayFiguritas[i].idEquipo && arrayFiguritas[i].estadoAlbum == PEGADO)
		{
			mostrarUnaFigurita(arrayFiguritas[i], equipos, tamEquipos, clubs, tamClubs);
			flag = 1;
		}
	}
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	if(!flag)
	{
		printf("\nNo se pegaron figuritas de este equipo");
	}
}

int listarFiguritasPegadasPorEquipo(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo equipos[], int tamEquipos, eClub clubs[], int tamClubs)
{
	int todoOk = -1;

	if(arrayFiguritas != NULL && tamFiguritas > 0)
	{
		switch(menuListarPegadasPorEquipo())
		{
			case 1:
				mostrarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, 1000, "Argentina", clubs, tamClubs);
				break;

			case 2:
				mostrarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, 1001, "Inglaterra", clubs, tamClubs);
				break;

			case 3:
				mostrarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, 1002, "Alemania", clubs, tamClubs);
				break;

			case 4:
				mostrarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, 1003, "Portugal", clubs, tamClubs);
				break;

			case 5:
				mostrarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, 1004, "Brasil", clubs, tamClubs);
				break;
		}
		todoOk = 0;
	}
	return todoOk;
}

int intercambiarFiguritas(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo equipos[], int tamEquipos, eFigurita arrayRepetidas[], int tamRepetidas, int* flag, eClub clubs[], int tamClubs)
{
	int todoOk = -1;

	int idObtenido;
	int indiceObtenido;

	int idIntercambio;
	int indiceIntercambio;
	char confirma;

	int indiceLibre;

	if(arrayFiguritas != NULL && equipos > 0)
	{
		if(*flag == 1)
		{
			listarFiguritasCreadas(arrayFiguritas, tamFiguritas, equipos, tamEquipos, clubs, tamClubs);
			pedirEntero(&idObtenido, "\nIngrese el ID de la figurita que quiere obtener: ", "\nError. El ID ingresado no es valido.\n", 0, tamFiguritas);
			indiceObtenido = buscarFiguritaPorID(arrayFiguritas, tamFiguritas, idObtenido);

			if(indiceObtenido == -1)
			{
				printf("\nEl id ingresado no existe.\n");
			}
			else
			{
				listarFiguritasRepetidas(arrayRepetidas, tamRepetidas, equipos, tamEquipos);
				pedirEntero(&idIntercambio, "\nIngrese el ID de la figurita que quiere intercambiar: ", "\nError. El ID ingresado no es valido.\n", 0, tamRepetidas);
				indiceIntercambio = buscarFiguritaPorID(arrayRepetidas, tamFiguritas, idIntercambio);

				if(indiceIntercambio == -1)
				{
					printf("\nEl id ingresado no existe.\n");
				}
				else
				{
					printf("\nUsted obtendrá...");
					encabezadoFigurita_1();
					mostrarUnaFigurita(arrayFiguritas[indiceObtenido], equipos, tamEquipos, clubs, tamClubs);

					encabezadoFigurita_1();
					printf("\n\nA cambio de...");
					mostrarUnaFigurita(arrayRepetidas[indiceIntercambio], equipos, tamEquipos, clubs, tamClubs);
					printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

					pedirCaracter(&confirma, "\n¿Desea hacer el intercambio? (s = si | n = no): ", "\nError. El caracter ingresado no es valido.", 's', 'n');

					if(confirma == 's')
					{
						arrayRepetidas[indiceIntercambio].estado = VACIO;

						if(arrayFiguritas[indiceObtenido].estadoAlbum == PEGADO)
						{
							indiceLibre = buscarEspacioLibre(arrayRepetidas, tamRepetidas);
							arrayRepetidas[indiceLibre] = arrayFiguritas[indiceObtenido];
						}
						else
						{
							arrayFiguritas[indiceObtenido].estadoAlbum = PEGADO;
						}
					}
					else
					{
						printf("\nSe cancelo el intercambio.\n");
					}
				}
			}
		}
		else
		{
			printf("\nNo tienes figuritas para intercambiar");
		}
		todoOk = 0;
	}

	return todoOk;
}

void contadorDeClubs(eFigurita arrayFiguritas[], int tamFiguritas, int* contadorBJ, int* contadorRP, int* contadorLiverpool, int* contadorChelsea, int* contadorLeverkusen, int* contadorColonia, int* contadorOporto, int* contadorLisboa, int* contadorSantos, int* contadorCorinthias, int* idClubMayor)
{
	int idClub;
	for(int i = 0; i < tamFiguritas; i++)
	{
		if(arrayFiguritas[i].estado == OCUPADO && arrayFiguritas[i].estadoAlbum == PEGADO)
		{
			idClub = arrayFiguritas[i].idClub;
			switch(idClub)
			{
				case 100:
					(*contadorBJ)++;
					break;

				case 101:
					(*contadorRP)++;
					break;

				case 102:
					(*contadorLiverpool)++;
					break;

				case 103:
					(*contadorChelsea)++;
					break;

				case 104:
					(*contadorLeverkusen)++;
					break;

				case 105:
					(*contadorColonia)++;
					break;

				case 106:
					(*contadorOporto)++;
					break;

				case 107:
					(*contadorLisboa)++;
					break;

				case 108:
					(*contadorSantos)++;
					break;

				case 109:
					(*contadorCorinthias)++;
					break;
			}
		}
	}

	if(*contadorBJ > *contadorRP && *contadorBJ > *contadorLiverpool && *contadorBJ > *contadorChelsea && *contadorBJ > *contadorLeverkusen && *contadorBJ > *contadorColonia && *contadorBJ > *contadorOporto && *contadorBJ > *contadorLisboa && *contadorBJ > *contadorSantos && *contadorBJ > *contadorCorinthias)
	{
		*idClubMayor = 100;
	}
	else if(*contadorRP > *contadorLiverpool && *contadorRP > *contadorChelsea && *contadorRP > *contadorLeverkusen && *contadorRP > *contadorColonia && *contadorRP > *contadorOporto && *contadorRP > *contadorLisboa && *contadorRP > *contadorSantos && *contadorRP > *contadorCorinthias)
	{
		*idClubMayor = 101;
	}
	else if(*contadorLiverpool > *contadorChelsea && *contadorLiverpool > *contadorLeverkusen && *contadorLiverpool > *contadorColonia && *contadorLiverpool > *contadorOporto && *contadorLiverpool > *contadorLisboa && *contadorLiverpool > *contadorSantos && *contadorLiverpool > *contadorCorinthias)
	{
		*idClubMayor = 102;
	}
	else if(*contadorChelsea > *contadorLeverkusen && *contadorChelsea > *contadorColonia && *contadorChelsea > *contadorOporto && *contadorChelsea > *contadorLisboa && *contadorChelsea > *contadorSantos && *contadorChelsea > *contadorCorinthias)
	{
		*idClubMayor = 103;
	}
	else if(*contadorLeverkusen > *contadorColonia && *contadorLeverkusen > *contadorOporto && *contadorLeverkusen > *contadorLisboa && *contadorLeverkusen > *contadorSantos && *contadorLeverkusen > *contadorCorinthias)
	{
		*idClubMayor = 104;
	}
	else if(*contadorColonia > *contadorOporto && *contadorColonia > *contadorLisboa && *contadorColonia > *contadorSantos && *contadorColonia > *contadorCorinthias)
	{
		*idClubMayor = 105;
	}
	else if(*contadorOporto > *contadorLisboa && *contadorOporto > *contadorSantos && *contadorOporto > *contadorCorinthias)
	{
		*idClubMayor = 106;
	}
	else if(*contadorLisboa > *contadorSantos && *contadorLisboa > *contadorCorinthias)
	{
		*idClubMayor = 107;
	}
	else if(*contadorSantos > *contadorCorinthias)
	{
		*idClubMayor = 108;
	}
	else
	{
		*idClubMayor = 109;
	}
}

int listarFiguritasPegadasPorClubMayor(eFigurita arrayFiguritas[], int tamFiguritas, eEquipo equipos[], int tamEquipos, eClub clubs[], int tamClubs, int idClubMayor)
{
	int todoOk = -1;
	char nombre[30];

	if(arrayFiguritas != NULL && tamFiguritas > 0)
	{
		for(int i = 0; i < tamClubs; i++)
		{
			if(idClubMayor == clubs[i].id)
			{
				strcpy(nombre, clubs[i].nombre);
			}
		}

		printf("\nEl club que mas veces aparece entre las figuritas pegadas es: %s", nombre);

		encabezadoFigurita_1();

		for(int i = 0; i < tamFiguritas; i++)
		{
			if(arrayFiguritas[i].estadoAlbum == PEGADO && arrayFiguritas[i].idClub == idClubMayor)
			{
				mostrarUnaFigurita(arrayFiguritas[i], equipos, tamEquipos, clubs, tamClubs);
			}
		}

		todoOk = 0;
	}
	return todoOk;
}
