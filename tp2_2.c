#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define F 5
#define C 12

int main()
{
    srand(time(NULL));
    int aleatorio= rand();
    int i, j;
    float mt[F][C];

    
    //cargando matriz
    for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {
            mt[i][j] = (float) (10000 + rand()%(50000-10000));
           
        }
      
    }
   
   // mostrar matriz 
 
   for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {    
           printf("%4.2f ", (mt[i][j]));
        }
        printf("\n");
    }
      // sacar promedio de ganancias por año
 
 float acumulador; 
 float promedio;
   for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {    
           acumulador += mt[i][j];

        }
        printf("\n");
    }
    printf("el total vendio de todos los anios es %.2f \n", acumulador);

//mostrar el promedio por anio
     for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {    
            promedio +=  mt[i][j];
           if(j == C-1){
             promedio =( promedio/acumulador) *100;
             printf("el promedio vendido el anio nro %d es %.2f \n", i+1, promedio);
             promedio = 0;
           }
           
        }
        printf("\n");
    }

    //mostrar el minimo y el maximo
    float maximo = 0;
    
    int mesMax, mesMin, anioMax, anioMin;
    float minimo = 99999999999;
     for (i = 0; i < F; i++)
    {
        for (j = 0; j < C; j++)
        {    
            if(minimo > mt[i][j]){
                minimo= mt[i][j]; 
                anioMin = i+1; 
                mesMin = j+1;
            }
           if(maximo < mt[i][j]){

            maximo = mt[i][j];
              mesMax = j+1;
              anioMax = i+1;
             
           }
           
        }
        printf("\n");
    }
         printf(" mes que mas se gano es el %d  del anio %d con una ganancia de %.2f \n", mesMax, anioMax, maximo);
         
         printf(" mes que menos se gano es el %d  del anio %d con una ganancia de %.2f \n", mesMin, anioMin, minimo);




    return 0;
}

 
 
