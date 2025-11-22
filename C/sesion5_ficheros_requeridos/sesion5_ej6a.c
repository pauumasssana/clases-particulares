#include <stdio.h>
#define DIM 100

typedef struct {
  	int  num;        /* numero de la matricula */
  	char letras[3];  /* letras de la matricula */
} t_matricula;

typedef struct{
   	int nmat;               /* numero de matriculas en la lista */
   	t_matricula lmat[DIM];   /* lista de matriculas */
} t_lista_matriculas;

int main()
{
    t_lista_matriculas lista1={4,{{1111,{'A','B','C'}},{1111,{'A','C','C'}},
                              {1122,{'A','B','C'}},{1134,{'B','B','C'}}}};
    t_lista_matriculas lista2={3,{{2222,{'B','D','F'}},{1134, {'B','B','C'}},
                             {2223,{'B','D','F'}}}};
    t_lista_matriculas lunion;
  
    /* Complete el programa */






}

