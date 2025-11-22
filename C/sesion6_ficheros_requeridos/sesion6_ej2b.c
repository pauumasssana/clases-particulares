#include <stdio.h>
#define MAX_CAPITALES 6
#define MAX_CAMINO    10
#define TRUE 1
#define FALSE 0

typedef struct{
   int nciudades;   // numero de ciudades que se visitan
   int camino[MAX_CAMINO]; // identificadores de las ciudades que se visitan
} tcamino;

int main()
{
    /* Matriz distancias con la lista de valores iniciales fila a fila */
    int distancias[MAX_CAPITALES][MAX_CAPITALES] = {0, 1720, 456, 1845, 1473,1093, 1720, 0, 1272, 1965, 2399, 2322, 456, 1272, 0, 1468, 1280, 1054, 1845, 1965, 1468, 0, 1130, 1519, 1473, 2399, 1280, 1130, 0, 682, 1093, 2322, 1054, 1519, 682, 0};
    tcamino cm;

    /* Completa el programa */
}



