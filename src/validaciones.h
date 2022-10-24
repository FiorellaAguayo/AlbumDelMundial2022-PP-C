
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#endif /* VALIDACIONES_H_ */

int getValidInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int getValidFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int getString(char* cadena, char* mensaje);
int validateCharacter(char string[]);
int firstCapitalChar(char name[]);
void validarPosicion(char string[]);
int getChar(char* caracter, char* mensaje);
int getInt(int* pResultado, char* pMensaje);
int getOnlyInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
