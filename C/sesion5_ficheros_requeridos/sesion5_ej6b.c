#include <stdio.h>
#define DIM 100

typedef struct {
  	int  num;        /* numero de la matricula */
  	char letras[3];  /* letras de la matricula */
} t_matricula;

typedef struct{
   	int nmat;               /* numero de matriculas en la lista */
   	t_matricula lmat[DIM];   /* lista ORDENADA de matriculas, primero por letra
                              y luego por numero */
} t_lista_matriculas;

int main()
{
    t_lista_matriculas lista1={5,{{1111,{'A','B','C'}},{1122,{'A','B','C'}},
                                 {1111,{'A','C','C'}}, {234,{'A','D','A'}},
                                 {1134,{'B','B','C'}}}};
    t_lista_matriculas lista2={4,{{1112,{'A','B','C'}},{1111,{'A','C','C'}}, 
                                {1134, {'B','B','C'}}, {333,{'F','D','A'}}}};
    t_lista_matriculas lunion;
  
    /* Complete el programa */








}

