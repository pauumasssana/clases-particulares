#ifndef JUGADAS_H
#define JUGADAS_H

#include <stdio.h>
#include "tablero.h"

int errores_chekear_fila(const Tablero *t, int a);
int errores_filas(const Tablero *t);
int errores_chekear_columna(const Tablero *t, int a);
int errores_columnas(const Tablero *t);
int errores_chekear_cuadrado(const Tablero *t, int f, int c);
int errores_cuadrados(const Tablero *t);
int checkear_tablero(const Tablero *t);
Tablero tirada(const Tablero *t, const Tablero *tab_inicial);

#endif