
#ifndef ALBUM_H_
#define ALBUM_H_

typedef struct
{
	int id[55];
	int esDorada[55];
	int estado;
	int isEmpty[55];
}eAlbum;

#endif /* ALBUM_H_ */

//INICIALIZACIONES
/**
 * \fn void inicializarAlbum(eAlbum)
 * \brief Funcion que inicializa el estado del album en INCOMPLETO
 *
 * \param album variable de tipo eAlbum que guarda un album
 */
void inicializarEstado_Album(eAlbum album);

/**
 * \fn void inicializarIdFiguritasEnAlbum(eAlbum)
 * \brief Funcion que inicializa los IDs de las figuritas en el album en VACIO
 *
 * \param album variable de tipo eAlbum que guarda un album
 */
//void inicializarID_Album(eAlbum* album);
void inicializarID_Album(eAlbum* album);


/**
 * \fn void inicializarEstadoDoradas(eAlbum)
 * \brief Funcion que inicializa el array del campo esDorada en VACIO
 *
 * \param album variable de tipo eAlbum que guarda un album
 */
void inicializarEstadoDoradas_Album(eAlbum* album);

void inicializarIsEmpty_Album(eAlbum* album);
//BUSCAR ESPACIO LIBRE
/**
 * \fn int buscarEspacioLibrePorID(eAlbum)
 * \brief Funcion que busca un espacio libre en el album
 *
 * \param album variable de tipo eAlbum que guarda un album
 * \return espacioLibre retorna -1 si no hay espacio y el indice si hay lugar
 */
int buscarEspacioLibreEnID_Album(eAlbum* album);

/**
 * \fn int buscarEspacioLibreEnArrayDoradas(eAlbum)
 * \brief Funcion que busca un espacio libre en el array del campo esDorada
 *
 * \param album variable de tipo eAlbum que guarda un album
 * \return espacioLibre retorna -1 si no hay espacio y el indice si hay lugar
 */
int buscarEspacioLibreEnDoradas_Album(eAlbum album);

/*buscar espacio en repetidas uso el buscarLibre de figuritas*/

//BUSCAR POR ID
/**
 * \fn int buscarFiguritasRepetidasPorID_Album(eAlbum, int)
 * \brief Funcion que busca figuritas con id repetido en el album
 *
 * \param album variable de tipo eAlbum que guarda un album
 * \param id variable entera que guarda el id de la figurita
 * \return espacioLibre retorna -1 si no hay espacio y el indice si hay lugar
 */
int buscarFiguritasRepetidasPorID_Album(eAlbum* album, int id);
