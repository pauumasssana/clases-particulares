#ifndef TABLERO_H
#define TABLERO_H

#include <stdio.h>

typedef struct Tablero {
    int filasxcol;
    char celdas[36][36];
    int acabado;
    int sqrt;
} Tablero;

void mostrar_tablero(const Tablero *t);
Tablero tablero_archivo();

#endif