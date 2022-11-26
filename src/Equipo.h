#ifndef EQUIPO_H_
#define EQUIPO_H_

typedef struct
{
	int id;
	char descripcion[30];
	char directorTecnico[30];
}eEquipo;

#endif /* EQUIPO_H_ */

/**
 * \fn int cargaDeEquipos(eEquipo[], int)
 * \brief Funcion que carga datos de los equipos
 *
 * \param arrayEquipos array a estructura eEquipo
 * \param tamEquipos tamaño de los equipos
 * \return todoOk retorna -1 si esta mal y 0 si esta bien
 */
int cargaDeEquipos(eEquipo arrayEquipos[], int tamEquipos);

/**
 * \fn void mostrarUnEquipo(eEquipo)
 * \brief Funcion que muestra un equipo del array de equipos
 *
 * \param unEquipo variable tipo eEquipo que guarda un equipo
 */
void mostrarUnEquipo(eEquipo unEquipo);

/**
 * \fn int listarEquipos(eEquipo[], int)
 * \brief Funcion que lista los equipos
 *
 * \param arrayEquipos array a estructura eEquipo
 * \param tamEquipos tamaño de los equipos
 * \return todoOk retorna -1 si esta mal y 0 si esta bien
 */
int listarEquipos(eEquipo arrayEquipos[], int tamEquipos);
