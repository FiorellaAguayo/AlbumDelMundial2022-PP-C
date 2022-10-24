#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menus.h"
#include "validaciones.h"

int menuPrincipal(int *opcion)
{
	getOnlyInt(opcion, "\n\n******************************************"
			"\n***********   MENU PRINCIPAL   ************"
			"\n*******************************************"
			"\n** 1. Perfil administrador."
			"\n** 2. Perfil coleccionista."
			"\n** 3. Informes."
			"\n** 4. Finalizar programa."
			"\n** Elige una opcion: ", "\nOpcion invalida. Reingrese.\n", 1, 4, 3);
	return *opcion;
}

int menuAdministrador()
{
	int opcion;

	printf("\n=========================================");
	printf("\n          Perfil Administrador           ");
	printf("\n=========================================");
	printf("\n1. Alta figurita.");
	printf("\n2. Modificar figurita.");
	printf("\n3. Listado de figuritas.");
	printf("\n4. Atrás.");
	printf("\nElige una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int menuModificar()
{
	int opcion;

	printf("\nIngrese la opción que desea modificar...\n");
	printf("\n1. Nombre.");
	printf("\n2. Posición.");
	printf("\n3. Equipo.");
	printf("\n4. Altura.");
	printf("\n5. Peso.");
	printf("\n6. Año de ingreso a la selección.");
	printf("\n7. Dia de nacimiento.");
	printf("\n8. Mes de nacimiento.");
	printf("\n9. Año de nacimiento.");
	printf("\nOpcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int menuColeccionista()
{
	int opcion;

	printf("\n=========================================");
	printf("\n          Perfil Coleccionista           ");
	printf("\n=========================================");
	printf("\n1. Comprar paquete de figuritas.");
	printf("\n2. Intercambiar figuritas.");
	printf("\n3. Atrás.");
	printf("\nElige una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int menuInformes()
{
	int opcion;

	printf("\n=========================================");
	printf("\n                Informes                 ");
	printf("\n=========================================");
	printf("\n1. Listado de figuritas pegadas.");
	printf("\n2. Listado de figuritas repetidas.");
	printf("\n3. Listado de figuritas doradas que están pegadas en el álbum.");
	printf("\n4. Cuántos sobres tuvo que comprar el coleccionista para llenar el álbum.");
	printf("\n5. Cuánto dinero lleva gastado el coleccionista, teniendo en cuenta que cada paquete cuesta $170.");
	printf("\n6. Cuánto dinero gastó el coleccionista para completar el álbum, teniendo en cuenta que cada paquete cuesta $170.");
	printf("\n7. Seleccionar un equipo y listar todas las figuritas que esten pegadas.");
	printf("\nElige una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
