#include <stdio.h>
#include <string.h>
#include "colores.h"
#include "fichero.h"
#include "tablero.h"

int errores_chekear_fila(const Tablero *t, int a){
    int errores=0;
    for(int i=0;i < t->filasxcol;i++){
        for(int j=0; j < t->filasxcol;j++){
            if((j!=i && t->celdas[a][j]==t->celdas[a][i]) || t->celdas[a][j] == ' '){
                errores++;
            }
        }
    }
    return errores;
}

int errores_filas(const Tablero *t){
    int errores=0;
    for(int i=0; i<t->filasxcol;i++){
        errores = errores + errores_chekear_fila(t, i);
    }
    return errores;
}

int errores_chekear_columna(const Tablero *t, int a){
    int errores=0;
    for(int i=0;i < t->filasxcol;i++){
        for(int j=0; j < t->filasxcol;j++){
            if((j!=i && t->celdas[j][a]==t->celdas[i][a]) || t->celdas[a][j] == ' '){
                errores++;
            }
        }
    }
    return errores;
}

int errores_columnas(const Tablero *t){
    int errores=0;
    for(int i=0; i<t->filasxcol;i++){
        errores = errores + errores_chekear_columna(t, i);
    }
    return errores;
}

int errores_chekear_cuadrado(const Tablero *t, int f, int c){
    int errores=0;
    int fila = f*(t->sqrt);
    int col = c*(t->sqrt);
    for(int i = fila; i < fila+(t->sqrt);i++){
        for (int j = col; j < col+(t->sqrt); j++){
            for(int a = fila; a < fila+(t->sqrt); a++){
                for(int b =col; b < col+(t->sqrt); b++){
                    if((a!=i || b!=j || t->celdas[a][j] == ' ') && t->celdas[i][j]==t->celdas[a][b]){
                        errores++;
                    }
                }
            }
        }

    }
    return errores;
}


int errores_cuadrados(const Tablero *t){
    int errores=0;
    for(int i=0; i<t->sqrt;i++){
        for(int j=0; j<t->sqrt;j++){
            errores = errores + errores_chekear_cuadrado(t, i, j);
        }
    }
    return errores;
}


int checkear_tablero(const Tablero *t){
    int errores= errores_cuadrados(t)+errores_columnas(t)+errores_filas(t);
    if(errores == 0){
        return 1;
        //t.acabado=0;
    }
    return 0;
}


Tablero tirada(const Tablero *t, const Tablero *tab_inicial){
    char jugada[3];
    char valores[36] = {'1','2','3','4','5','6','7','8','9','0',
                          'A','B','C','D','E','F','G','H','I','J',
                          'K','L','M','N','O','P','Q','R','S','T',
                          'U','V','W','X','Y','Z'};
    printf("Intro [fila col car] sin espacios: ");
	scanf("%s%*c", jugada);
    int fila = jugada[0] - '0';
    if(fila>9){
        fila = fila - 7;
    }
    int col = jugada[1] - '0';
    if(col>9){
        col = col - 7;
    }
    Tablero tab = *t;
    int aux=0;
    for(int i=0; i<t->filasxcol;i++){
        if (jugada[2]==valores[i]){
            aux++;
        }
    }
    if(aux==0){
        return tab;
    }
    if (tab_inicial->celdas[fila][col]==' '){
        tab.celdas[fila][col]=jugada[2];
    }
    return tab;

}


/*

int main(void){
    
    //Tableros ejemplo
    Tablero miTablero;
    miTablero.filasxcol = 4;
    miTablero.sqrt=2;
    char ejemplo[4][4] = {
        {'1', ' ', '3', ' '},
        {' ', '4', '1', '2'},
        {'2', ' ', ' ', '1'},
        {'4', '1', '2', ' '}
    };
    /* copiar la matriz porque no se puede asignar arrays directamente 
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            miTablero.celdas[r][c] = ejemplo[r][c];
        }
    }

    Tablero tablero9x9;
    tablero9x9.sqrt=3;
    tablero9x9.filasxcol = 9;
    char ejemplo9x9[9][9] = {
        {'5','3','0','0','7','0','0','0','0'},
        {'6','0','0','1','9','5','0','0','0'},
        {'0','9','8','0','0','0','0','6','0'},
        {'8','0','0','0','6','0','0','0','3'},
        {'4','0','0','8','0','3','0','0','1'},
        {'7','0','0','0','2','0','0','0','6'},
        {'0','6','0','0','0','0','2','8','0'},
        {'0','0','0','4','1','9','0','0','5'},
        {'0','0','0','0','8','0','0','7','9'}
    };
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            tablero9x9.celdas[r][c] = ejemplo9x9[r][c];
        }
    }
    
    Tablero tablero16x16;
    tablero16x16.sqrt=4;
    tablero16x16.filasxcol = 16;
    char ejemplo16x16[16][16] = {
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
        {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
        {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
        {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
        {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
        {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
        {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
        {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
        {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'}
    };
    for (int r = 0; r < 16; r++) {
        for (int c = 0; c < 16; c++) {
            tablero16x16.celdas[r][c] = ejemplo16x16[r][c];
        }
    }

    Tablero tablero25x25;
    tablero25x25.sqrt=5;
    tablero25x25.filasxcol = 25;
    char ejemplo25x25[25][25] = {
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
        {'o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'},
        {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'}
        };
    for (int r = 0; r < 25; r++) {
        for (int c = 0; c < 25; c++) {
            tablero25x25.celdas[r][c] = ejemplo25x25[r][c];
        }
    }
    
    Tablero tablero36x36;
    tablero36x36.filasxcol = 36;
    tablero36x36.sqrt=6;
    char ejemplo36x36[36][36];
    char valoresa[36] = {'0','1','2','3','4','5','6','7','8','9',
                          'a','b','c','d','e','f','g','h','i','j',
                          'k','l','m','n','o','p','q','r','s','t',
                          'u','v','w','x','y','z'};
    for (int i = 0; i < 36; i++) {
        for (int j = 0; j < 36; j++) {
            ejemplo36x36[i][j] = valoresa[(i + j) % 36];
        }
    }
    for (int r = 0; r < 36; r++) {
        for (int c = 0; c < 36; c++) {
            tablero36x36.celdas[r][c] = ejemplo36x36[r][c];
        }
    }
    
    
    int errores_tab_4x4_filas = errores_filas(&miTablero);
    printf("Errores en filas: %d\n", errores_tab_4x4_filas);
    int errores_tab_4x4_columnas = errores_columnas(&miTablero);
    printf("Errores en columnas: %d\n", errores_tab_4x4_columnas);
    
    int errores_tab_4x4_cuadrado = errores_chekear_cuadrado(&tablero9x9, 0, 0);
    printf("Errores en cuadrado 00: %d\n", errores_tab_4x4_cuadrado);
    int errores_totales_tab_4x4_cuadrado = errores_cuadrados(&miTablero);
    printf("Errores en cuadrado 00: %d\n", errores_totales_tab_4x4_cuadrado);

    int finalizada = checkear_tablero(&miTablero);
    printf("Partida finalizada: %d\n", finalizada);


    mostrar_tablero(&miTablero);
    Tablero tab =  tirada(&miTablero);
    mostrar_tablero(&tab);

}
*/
