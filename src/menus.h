#ifndef MENUS_H_
#define MENUS_H_
#include "Equipo.h"

#endif /* MENUS_H_ */

/**
 * \fn int menuPrincipal()
 * \brief Funcion que muestra el menu principal y permite ingresar un dato
 *
 * \return option variable entera que garda la opcion ingresada por el usuario
 */
int menuPrincipal();

/**
 * \fn int menuAdministrador()
 * \brief Funcion que muestra el menu de administrador y permite ingresar un dato
 *
 * \return option variable entera que garda la opcion ingresada por el usuario
 */
int menuAdministrador();

/**
 * \fn int menuModificar()
 * \brief Funcion que muestra el menu de modificacion y permite ingresar un dato
 *
 * \return option variable entera que garda la opcion ingresada por el usuario
 */
int menuModificar();

/**
 * \fn int menuInformes()
 * \brief  Funcion que muestra el menu de infomres y permite ingresar un dato
 *
 * \return option variable entera que garda la opcion ingresada por el usuario
 */
int menuInformes();

/**
 * \fn int menuListarPegadasPorEquipo()
 * \brief  Funcion que muestra el menu de Listar pegadas po equipo y permite ingresar un dato
 *
 * \return option variable entera que garda la opcion ingresada por el usuario
 */
int menuListarPegadasPorEquipo(eEquipo equipos[]);

/**
 * \fn int menuColeccionista()
 * \brief Funcion que muestra el menu de Coleccionista y permite ingresar un dato
 *
 * \return option variable entera que garda la opcion ingresada por el usuario
 */
int menuColeccionista();
