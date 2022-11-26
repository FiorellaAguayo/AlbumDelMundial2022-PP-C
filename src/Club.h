#ifndef CLUB_H_
#define CLUB_H_

typedef struct
{
	int id;
	char nombre[30];
	char entrenador[30];
	int anioFundacion;
}eClub;

#endif /* CLUB_H_ */

/**
 * \fn int cargaDeClubs(eClub[], int)
 * \brief Funcion que carga datos de los clubs
 *
 * \param arrayClubs array a estructura eClub
 * \param tamClubs tamaño de los clubs
 * \return todoOk retorna -1 si esta mal y 0 si esta bien
 */
int cargaDeClubs(eClub arrayClubs[], int tamClubs);

/**
 * \fn void mostrarUnClub(eClub)
 * \brief Funcion que muestra un club del array de clubs
 *
 * \param unClub variable tipo eEquipo que guarda un club
 */
void mostrarUnClub(eClub unClub);

/**
 * \fn int listarClubs(eClub[], int)
 * \brief Funcion que lista los clubs
 *
 * \param arrayClubs array a estructura eClub
 * \param tamClubs tamaño de los clubs
 * \return todoOk retorna -1 si esta mal y 0 si esta bien
 */
int listarClubs(eClub arrayClubs[], int tamClubs);
