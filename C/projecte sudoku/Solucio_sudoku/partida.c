#include <stdio.h>
#include <string.h>
#include "colores.h"
#include "fichero.h"
#include "tablero.h"
#include "jugadas.h"

int main(void){
    Tablero tab = tablero_archivo();
    Tablero tab_partida = tab;
    while(tab_partida.acabado ==0){
        tab_partida = tirada(&tab_partida, &tab);
        if(checkear_tablero(&tab_partida)!=0){
            tab_partida.acabado=1;
        }
        mostrar_tablero(&tab_partida);
    }
    printf("FELICIDADES: Sudoku resuelto! :-)\n");
}