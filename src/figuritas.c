#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "validaciones.h"
#include "figuritas.h"
#include "menus.h"
#include "album.h"
#define VACIO 0
#define OCUPADO 1
#define PEGADA 2
#define ES_DORADA 4

int inicializarBancoFiguritas(eFiguritas arrayFiguritas[], int tam)
{
	int todoOk = -1;

	if (arrayFiguritas != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{

			arrayFiguritas[i].estado = VACIO;
		}
		todoOk = 0;
	}

	return todoOk;
}

int buscarEspacioLibre(eFiguritas arrayFiguritas[], int tam)
{
	int espacioLibre = -1;

	if (arrayFiguritas != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (arrayFiguritas[i].estado == VACIO)
			{
				espacioLibre = i;
				break;
			}
		}
	}

	return espacioLibre;
}

int altaFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas, int *id, eEquipo arrayEquipos[], int tamEquipos)
{
	int todoOk = -1;
	int indice;
	eFiguritas auxFigurita;

	printf("\n--------------------------------------------------------------------------------------------");
	printf("\n---------------------------------- alta de figuritas ---------------------------------------");
	printf("\n--------------------------------------------------------------------------------------------");

	indice = buscarEspacioLibre(arrayFiguritas, tamFiguritas);

	if (indice == -1)
	{
		printf("\nNo hay espacio para más figuritas.\n");
	}
	else
	{
		auxFigurita.idFigurita = *id;
		(*id)++;

		getString(auxFigurita.nombreJugador, "\nIngrese nombre del jugador: ");
		validateCharacter(auxFigurita.nombreJugador);
		firstCapitalChar(auxFigurita.nombreJugador);

		getString(auxFigurita.posicion, "Ingrese posición del jugador (delantero, mediocampista, defensor, arquero): ");
		validateCharacter(auxFigurita.posicion);
		firstCapitalChar(auxFigurita.posicion);
		validarPosicion(auxFigurita.posicion);

		mostrarEquipos(arrayEquipos, tamEquipos);
		getValidInt(&auxFigurita.equipo.id, "\nIngrese ID del equipo: ", "Error. ID inválido.", 1000, 1004, 3);

		getValidFloat(&auxFigurita.altura, "\nIngrese altura (entre 1 y 3 metros): ", "Error. Altura no valida.", 1, 3, 3);
		getValidFloat(&auxFigurita.peso, "Ingrese peso (entre 30 y 130 kilos): ", "Error. Peso no valida.", 30, 130, 3);

		getValidInt(&auxFigurita.anioIngreso, "Ingrese año de ingreso a la selección: ", "Error. Año no válido.", 1900, 2022, 3);

		getValidInt(&auxFigurita.fechaNacimiento.dia, "Ingrese dia de nacimiento del jugador: ", "Error. Dia no válido.", 1, 31, 3);
		getValidInt(&auxFigurita.fechaNacimiento.mes, "Ingrese mes de nacimiento del jugador: ", "Error. Mes no válido.", 1, 12, 3);
		getValidInt(&auxFigurita.fechaNacimiento.anio, "Ingrese año de nacimiento del jugador: ", "Error. Año no válido.", 1900, 2022, 3);

		auxFigurita.estado = OCUPADO;

		arrayFiguritas[indice] = auxFigurita;

		todoOk = 0;
	}

	return todoOk;
}

void mostrarEquipos(eEquipo equipos[], int tam)
{
	printf("\n============ listado de equipos =============");
	printf("\n---------------------------------------------");
	printf("\n| id   | descripcion    | director tecnico  |");
	printf("\n---------------------------------------------");

	for (int i = 0; i < tam; i++)
	{
		printf("\n| %-4d | %-14s | %-17s |", equipos[i].id, equipos[i].descripcion, equipos[i].directorTecnico);
	}
	printf("\n=============================================");
}

int cargarDatosDeEquipoPorID(eEquipo arrayEquipos[], int tamEquipos, int idEquipo, char descripcion[], char directorTecnico[])
{
	int todoOk = -1;
	if (arrayEquipos != NULL && tamEquipos > 0 && idEquipo > 0 && descripcion != NULL && directorTecnico != NULL)
	{
		for (int i = 0; i < tamEquipos; i++)
		{
			if (arrayEquipos[i].id == idEquipo)
			{
				strcpy(descripcion, arrayEquipos[i].descripcion);
				strcpy(directorTecnico, arrayEquipos[i].directorTecnico);
			}
		}
		todoOk = 0;
	}
	return todoOk;
}

void mostrarUnaFigurita(eFiguritas unaFigurita, eEquipo arrayEquipos[], int tamEquipo)
{
	char descripcion[51];
	char directorTecnico[51];

	cargarDatosDeEquipoPorID(arrayEquipos, tamEquipo, unaFigurita.equipo.id, descripcion, directorTecnico);

	printf("\n| %-4d | %-19s | %-14s | %-10s | %-17s | %-8.2f | %-8.2f | %-14d | %d/%d/%d ", unaFigurita.idFigurita, unaFigurita.nombreJugador,
			unaFigurita.posicion, descripcion, directorTecnico, unaFigurita.altura, unaFigurita.peso, unaFigurita.anioIngreso, unaFigurita.fechaNacimiento.dia,
			unaFigurita.fechaNacimiento.mes, unaFigurita.fechaNacimiento.anio);
}

int buscarFiguritaPorID(eFiguritas arrayFiguritas[], int tamFiguritas, int *id)
{
	int indice = -1;
	for (int i = 0; i < tamFiguritas; i++)
	{
		if (arrayFiguritas[i].estado == OCUPADO && arrayFiguritas[i].idFigurita == *id)
		{
			indice = i;
		}
	}
	return indice;
}

int mostrarFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos)
{
	int todoOk = -1;
	int flag = 0;

	if (arrayFiguritas != NULL && tamFiguritas > 0 && arrayEquipos != NULL && tamEquipos > 0)
	{
		printf("\n================================================ listado de figuritas =====================================================================");
		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------");
		printf(
				"\n| id   | nombre del jugador  | posición       | equipo     | director tecnico  | altura   | peso     | año de ingreso | fecha de nacimiento  ");
		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------");

		for (int i = 0; i < tamFiguritas; i++)
		{
			if (arrayFiguritas[i].estado == OCUPADO)
			{
				mostrarUnaFigurita(arrayFiguritas[i], arrayEquipos, tamEquipos);
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

int modificarFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos)
{
	int todoOk = -1;
	int indice;
	int id;
	char respuesta;
	char auxNombre[51];
	char auxPosicion[51];
	int auxIdEquipo;
	float auxAltura;
	float auxPeso;
	int auxAnioIngreso;
	int auxDia;
	int auxMes;
	int auxAnio;
	int auxEstado;

	if (arrayFiguritas != NULL && tamFiguritas > 0 && arrayEquipos != NULL && tamEquipos > 0)
	{
		printf("\n--------------------------------------------------------------------------------------------");
		printf("\n---------------------------------- modificar figuritas -------------------------------------");
		printf("\n--------------------------------------------------------------------------------------------\n");
		mostrarFiguritas(arrayFiguritas, tamFiguritas, arrayEquipos, tamEquipos);
		getInt(&id, "\nIngrese el ID de la figurita que quiere modificar: ");

		indice = buscarFiguritaPorID(arrayFiguritas, tamFiguritas, &id);

		if (indice == -1)
		{
			printf("\nError. ID no existente.\n");
		}
		else
		{
			printf(
					"\n-------------------------------------------------------------------------------------------------------------------------------------------");
			printf(
					"\nid | nombre del jugador |    posición    |   equipo   | director tecnico |   altura   |   peso   | año de ingreso | fecha de nacimiento  ");
			printf(
					"\n-------------------------------------------------------------------------------------------------------------------------------------------");
			mostrarUnaFigurita(arrayFiguritas[indice], arrayEquipos, tamEquipos);
			getChar(&respuesta, "\n\n¿Esta seguro de modificar esta figurita? (s = si | n = no): ");
			if (respuesta == 's')
			{
				switch (menuModificar())
				{
					case 1:
						getString(auxNombre, "\nIngrese nuevo nombre del jugador: ");
						validateCharacter(auxNombre);
						firstCapitalChar(auxNombre);
						strcpy(arrayFiguritas[indice].nombreJugador, auxNombre);
						break;

					case 2:
						getString(auxPosicion, "Ingrese nueva posición del jugador (delantero, mediocampista, defensor, arquero): ");
						validateCharacter(auxPosicion);
						firstCapitalChar(auxPosicion);
						validarPosicion(auxPosicion);
						strcpy(arrayFiguritas[indice].posicion, auxPosicion);
						break;

					case 3:
						mostrarEquipos(arrayEquipos, tamEquipos);
						getValidInt(&auxIdEquipo, "\nIngrese ID del nuevo equipo: ", "Error. ID inválido.", 1000, 1004, 3);
						arrayFiguritas[indice].equipo.id = auxIdEquipo;
						break;

					case 4:
						getValidFloat(&auxAltura, "\nIngrese nueva altura (entre 1 y 3 metros): ", "Error. Altura no valida.", 1, 3, 3);
						arrayFiguritas[indice].altura = auxAltura;
						break;

					case 5:
						getValidFloat(&auxPeso, "Ingrese nuevo peso (entre 30 y 130 kilos): ", "Error. Peso no valida.", 30, 130, 3);
						arrayFiguritas[indice].peso = auxPeso;
						break;

					case 6:
						getValidInt(&auxAnioIngreso, "Ingrese nuevo año de ingreso a la selección: ", "Error. Año no válido.", 1900, 2022, 3);
						arrayFiguritas[indice].anioIngreso = auxAnioIngreso;
						break;

					case 7:
						getValidInt(&auxDia, "Ingrese nuevo dia de nacimiento del jugador: ", "Error. Dia no válido.", 1, 31, 3);
						arrayFiguritas[indice].fechaNacimiento.dia = auxDia;
						break;

					case 8:
						getValidInt(&auxMes, "Ingrese nuevo mes de nacimiento del jugador: ", "Error. Mes no válido.", 1, 12, 3);
						arrayFiguritas[indice].fechaNacimiento.mes = auxMes;
						break;

					case 9:
						getValidInt(&auxAnio, "Ingrese nuevo año de nacimiento del jugador: ", "Error. Año no válido.", 1900, 2022, 3);
						arrayFiguritas[indice].fechaNacimiento.anio = auxAnio;
						break;

					default:
						printf("\nOpcion inválida.\n");
						break;
				}

				auxEstado = OCUPADO;
				arrayFiguritas[indice].estado = auxEstado;

				todoOk = 0;
			}
			else
			{
				printf("\nSe canceló la modificacion.\n");
			}
		}
	}
	return todoOk;
}

void ordenarFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas)
{
	eFiguritas aux;
	for (int i = 0; i < tamFiguritas - 1; i++)
	{
		for (int j = i + 1; j < tamFiguritas; j++)
		{
			if (strcmp(arrayFiguritas[i].nombreJugador, arrayFiguritas[j].nombreJugador) > 0)
			{
				aux = arrayFiguritas[i];
				arrayFiguritas[i] = arrayFiguritas[j];
				arrayFiguritas[j] = aux;
			}
		}
	}
}

void listarFiguritasOrdenadas(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos)
{
	ordenarFiguritas(arrayFiguritas, tamFiguritas);
	mostrarFiguritas(arrayFiguritas, tamFiguritas, arrayEquipos, tamEquipos);
}

int buscarFiguritasRepetidas(eFiguritas arrayFiguritas[], int tamFiguritas)
{
	int todoOk = -1;
	if (arrayFiguritas != NULL && tamFiguritas > 0)
	{
		todoOk = 0;
	}
	return todoOk;
}

void listarFiguritasPorEquipo(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo equipos[], int tamEquipos, eFiguritas figuritasDoradas[])
{
	int idEquipo;
	char nombrEquipo[15];
	char directorTecnico[51];

	mostrarEquipos(equipos, tamEquipos);
	getValidInt(&idEquipo, "\nIngrese ID del equipo que quiere listar: ", "Error. ID inválido.", 1000, 1004, 3);

	switch(idEquipo)
	{
		case 1000:
			buscarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, PEGADA, &idEquipo, nombrEquipo, directorTecnico);
			break;

		case 1001:
			buscarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, PEGADA, &idEquipo, nombrEquipo, directorTecnico);

			break;
		case 1002:
			buscarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, PEGADA, &idEquipo, nombrEquipo, directorTecnico);

			break;
		case 1003:
			buscarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, PEGADA, &idEquipo, nombrEquipo, directorTecnico);

			break;
		case 1004:
			buscarFiguritasPorEquipo(arrayFiguritas, tamFiguritas, equipos, tamEquipos, PEGADA, &idEquipo, nombrEquipo, directorTecnico);
			break;
	}
}

int buscarFiguritasPorEquipo(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo equipos[], int tamEquipos, int criterio, int* id, char* nombreEquipo,  char* directorTecnico)
{
	int todoOk = -1;
	int flag = 0;

	if(arrayFiguritas != NULL && tamFiguritas > 0 && equipos != NULL && tamEquipos > 0)
	{
		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------");
		printf("\n| id | nombre del jugador |    posición    |   equipo   | director tecnico |   altura   |   peso   | año de ingreso | fecha de nacimiento    ");
		printf("\n-------------------------------------------------------------------------------------------------------------------------------------------");

		for(int i = 0; i < tamFiguritas; i++)
		{
			if(arrayFiguritas[i].estado == criterio && arrayFiguritas[i].equipo.id == *id)
			{
				mostrarUnaFigurita(arrayFiguritas[i], equipos, tamEquipos);
				flag = 1;
			}
		}
		todoOk = 0;
	}

	if(!flag)
	{
		printf("\nNo hay figuritas de %s pegadas.\n", nombreEquipo);
	}
	return todoOk;
}

