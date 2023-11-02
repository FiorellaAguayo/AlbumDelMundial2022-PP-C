#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "inputs.h"
#include "validaciones.h"

int menuPrincipal()
{
	int option;

	printf("\n\n*********************************");
	printf("\n         Menu Principal          ");
	printf("\n*********************************");
	printf("\n1. Acceda a Perfil administrador.");
	printf("\n2. Acceda a Perfil coleccionista.");
	printf("\n3. Acceda a Informes.");
	printf("\n4. Finalizar programa.");

	pedirEntero(&option, "\nIngrese opcion: ", "\nError. La opcion ingresada no es valida.", 1, 4);

	return option;
}

int menuAdministrador()
{
	int option;

	printf("\n---------------------------------");
	printf("\n       Menu Administrador        ");
	printf("\n---------------------------------");
	printf("\n1. Acceda a Alta de figurita.");
	printf("\n2. Acceda a Modificar figurita.");
	printf("\n3. Acceda a Listado de figuritas.");
	printf("\n4. Atras.");

	pedirEntero(&option, "\nIngrese opcion: ", "\nError. La opcion ingresada no es valida.", 1, 4);

	return option;
}

int menuModificar()
{
	int option;

	printf("\n----------------------------------------------");
	printf("\n     Ingrese el dato que desea modificar...   ");
	printf("\n----------------------------------------------");
	printf("\n1. modificar nombre.");
	printf("\n2. modificar posicion.");
	printf("\n3. modificar equipo.");
	printf("\n4. modificar altura.");
	printf("\n5. modificar peso.");
	printf("\n6. modificar anio de ingreso a la seleccion.");
	printf("\n7. modificar fecha de nacimiento.");
	printf("\n8. modificar estado figurita.");

	pedirEntero(&option, "\nIngrese opcion: ", "\nError. La opcion ingresada no es valida.", 1, 8);

	return option;
}

int menuColeccionista()
{
	int option;

	printf("\n---------------------------------");
	printf("\n       Menu Coleccionista        ");
	printf("\n---------------------------------");
	printf("\n1. Comprar un paquete de figuritas.");
	printf("\n2. Intercambiar figuritas.");
	printf("\n3. Atras.");

	pedirEntero(&option, "\nIngrese opcion: ", "\nError. La opcion ingresada no es valida.", 1, 3);

	return option;
}

int menuInformes()
{
	int option;

	printf("\n----------------------------------------------");
	printf("\n                  Informes                    ");
	printf("\n----------------------------------------------");
	printf("\n1. Listado de figuritas pegadas.");
	printf("\n2. Listado de figuritas repetidas.");
	printf("\n3. Listado de figuritas doradas pegadas.");
	printf("\n4. Sobres comprados para llenar el album.");
	printf("\n5. Dinero gastado por el momento.");
	printf("\n6. Dinero gastado para completar el album.");
	printf("\n7. Listar figuritas pegadas por equipo.");
	printf("\n8. Listar figuritas pegadas por el club con mayor cantidad de figuritas");
	printf("\n9. Atras.");

	pedirEntero(&option, "\nIngrese opcion: ", "\nError. La opcion ingresada no es valida.", 1, 9);

	return option;
}

int menuListarPegadasPorEquipo(eEquipo equipos[])
{
	char paisSeleccionado[30];
	int idEquipo;

	printf("\n----------------------------------------------------------");
	printf("\n Seleccione el equipo de figuritas pegadas a listar...    ");
	printf("\n----------------------------------------------------------");

	printf("\nPuede seleccionar los siguientes paises (Argentina - Inglaterra - Alemania - Portugal - Brasil)");
	pedirCadena(paisSeleccionado, "\nIngrese un pais que desea listar: ", "\nError, ingrese bien el pais", 30);
	validarEquipo(paisSeleccionado);

	for(int i = 0; i < 5;  i++)
	{
		if(strcmp(paisSeleccionado, equipos[i].descripcion) == 0)
		{
			idEquipo = equipos[i].id;
		}
	}
	return idEquipo;
}

