#include <stdio.h>
#include <string.h>
#include "colores.h"
#include "fichero.h"


typedef struct Tablero {
    int filasxcol;
    char celdas[36][36];
} Tablero;

void mostrar_tablero(const Tablero *t) {
    char valores[36] = {'0','1','2','3','4','5','6','7','8','9',
                          'a','b','c','d','e','f','g','h','i','j',
                          'k','l','m','n','o','p','q','r','s','t',
                          'u','v','w','x','y','z'};
    int i=0, j=0;
    printf_color_negrita();
    switch (t->filasxcol) {
        case 4:
            printf(" |0 1|2 3|\n");
            for (i = 0; i < t->filasxcol; i++) {
                if (i%2==0) {
                    printf("-+-+-+-+-+\n");
                }
                printf("%c", valores[i]);
                for (j = 0; j < t->filasxcol; j++) {
                    if(j%2==0){
                        printf("|");
                    }else{
                        printf(" ");
                    }
                    printf("%c", t->celdas[i][j]);
                }
                printf("|\n");
            }
            printf("-+-+-+-+-+\n\n\n");
            break;
        case 9:
            printf(" |0 1 2|3 4 5|6 7 8|\n");
            for (i = 0; i < t->filasxcol; i++) {
                if (i%3==0) {
                    printf("-+-+-+-+-+-+-+-+-+-+\n");
                }
                printf("%c", valores[i]);
                for (j = 0; j < t->filasxcol; j++) {
                    if(j%3==0 ){
                        printf("|");
                    }else{
                        printf(" ");
                    }
                    printf("%c", t->celdas[i][j]);
                }
                printf("|\n");
            }
            printf("-+-+-+-+-+-+-+-+-+-+\n\n\n");
            break;
        case 16:
            printf(" |0 1 2 3|4 5 6 7|8 9 a b|c d e f|\n");
            for (i = 0; i < t->filasxcol; i++) {
                if (i%4==0) {
                    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                }
                printf("%c", valores[i]);
                for (j = 0; j < t->filasxcol; j++) {
                    if(j%4==0 ){
                        printf("|");
                    }else{
                        printf(" ");
                    }
                    printf("%c", t->celdas[i][j]);
                }
                printf("|\n");
            }
            printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n\n");
            break;
        case 25:
            printf(" |0 1 2 3 4|5 6 7 8 9|a b c d e|f g h i j|k l m n o|\n");
            for (i = 0; i < t->filasxcol; i++) {
                if (i%5==0) {
                    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                }
                printf("%c", valores[i]);
                for (j = 0; j < t->filasxcol; j++) {
                    if(j%5==0 ){
                        printf("|");
                    }else{
                        printf(" ");
                    }
                    printf("%c", t->celdas[i][j]);
                }
                printf("|\n");
            }
            printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n\n");
            break;
        case 36:
            printf(" |0 1 2 3 4 5|6 7 8 9 a b|c d e f g h|i j k l m n|o p q r s t|u v w x y z|\n");
            for (i = 0; i < t->filasxcol; i++) {
                if (i%6==0) {
                    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                }
                printf("%c", valores[i]);
                for (j = 0; j < t->filasxcol; j++) {
                    if(j%6==0 ){
                        printf("|");
                    }else{
                        printf(" ");
                    }
                    printf("%c", t->celdas[i][j]);
                }
                printf("|\n");
            }
            printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n\n");  
            break;
        default:
            printf("FELICIDADES: Sudoku resuelto! :-)\n");
            return;
    }
}

int main(void) {

    //Tableros ejemplo
    Tablero miTablero;
    miTablero.filasxcol = 4;
    char ejemplo[4][4] = {
        {'1', '0', '0', '4'},
        {'0', '0', '3', '0'},
        {'4', '3', '0', '0'},
        {'0', '2', '0', '1'}
    };
    /* copiar la matriz porque no se puede asignar arrays directamente */
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            miTablero.celdas[r][c] = ejemplo[r][c];
        }
    }

    Tablero tablero9x9;
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
    
    mostrar_tablero(&miTablero);
    mostrar_tablero(&tablero9x9);
    mostrar_tablero(&tablero16x16);
    mostrar_tablero(&tablero25x25);
    mostrar_tablero(&tablero36x36);


    //Leer tablero desde fichero
    int err, f, c, size, car;
	char nombre_fichero[SIZE_NOMBRE_FICHERO];
    Tablero tableroArchivo;
	printf("Introduce el nombre del fichero: ");
	scanf("%s%*c", nombre_fichero);
	err = abrir_fichero(nombre_fichero);
	if (err != ABRIR_FICHERO_OK) {
		printf("ERROR: FICHERO NO ENCONTRADO.\n");
		printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
	} else {
		size = leer_int_fichero();
        tableroArchivo.filasxcol = size;
		leer_char_fichero(); // '\n'
		printf("Sudoku %dx%d\n\n",
			       size, size);
		for (f = 0; f < size; f++) {
			for (c = 0; c < size; c++) {
				car = leer_char_fichero();
                tableroArchivo.celdas[f][c] = car;
				printf("%c ", car);
			}
			leer_char_fichero(); // '\n'
			printf("\n");
		}
		cerrar_fichero();
	}
    printf("\nTablero leído desde el fichero:\n");
    mostrar_tablero(&tableroArchivo);



    return 0;
}