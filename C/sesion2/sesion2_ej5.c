#include <stdio.h>

int main()
{
   char lletra = 'A';
   
   lletra = lletra  + 32; // Convertir a minúscula sumando 32 al código ASCII
   

   // array de carácteres
   char vocals[10] = {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};

   for (int i = 0; i < 10; i=i+2) 
   {
      printf("El caracter es: %c\n", vocals[i]);
   }



   //Matrices de carácteres
   char matriu[2][5] = { {'a', 'e', 'i', 'o', 'u'},
                         {'A', 'E', 'I', 'O', 'U'} };

   for (int i = 0; i < 2; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         printf("|%c|", matriu[i][j]);
      }
      
   }

   //struct de carácteres
   struct Forma_geometrica {
      int num_costats;
      int area;
      int perimetre;

   }; 

   struct Forma_geometrica quadrat;
   quadrat.num_costats = 4;


   struct Forma_geometrica triangle;
   triangle.num_costats = 3;

   //Manel
   char nom[20] = "Manel";
   
   
}


