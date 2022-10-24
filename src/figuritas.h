#ifndef FIGURITAS_H_
#define FIGURITAS_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
} eFecha;

typedef struct
{
	int id;
	char descripcion[51];
	char directorTecnico[51];
} eEquipo;

typedef struct
{
	int idFigurita;
	char nombreJugador[51];
	char posicion[51];
	eEquipo equipo;
	float altura;
	float peso;
	int anioIngreso;
	eFecha fechaNacimiento;
	int estado;
} eFiguritas;

#endif /* FIGURITAS_H_ */

int inicializarBancoFiguritas(eFiguritas arrayFiguritas[], int tam);
int buscarEspacioLibre(eFiguritas arrayFiguritas[], int tam);
int altaFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas, int *id, eEquipo arrayEquipos[], int tamEquipos);
void mostrarEquipos(eEquipo equipos[], int tam);
int cargarDatosDeEquipoPorID(eEquipo arrayEquipos[], int tamEquipos, int idEquipo, char descripcion[], char directorTecnico[]);
void mostrarUnaFigurita(eFiguritas unaFigurita, eEquipo arrayEquipos[], int tamEquipo);
int buscarFiguritaPorID(eFiguritas arrayFiguritas[], int tamFiguritas, int *id);
int mostrarFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos);
int modificarFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos);
void ordenarFiguritas(eFiguritas arrayFiguritas[], int tamFiguritas);
void listarFiguritasOrdenadas(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo arrayEquipos[], int tamEquipos);

void listarFiguritasPorEquipo(eFiguritas arrayFiguritas[], int tamFigurits, eEquipo equipos[], int tamEquipos, eFiguritas figuritasDoradas[]);
int buscarFiguritasPorEquipo(eFiguritas arrayFiguritas[], int tamFiguritas, eEquipo equipos[], int tamEquipos, int criterio, int* id, char* nombreEquipo, char* directorTecnico);
