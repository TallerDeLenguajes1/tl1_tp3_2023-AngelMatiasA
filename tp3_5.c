#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
/*5) Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, el
usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación.
*/

char **VectorChar; 
// char *nombre; 
char aux[20];
int cantidadNombres = 0;

printf("ingrese cuantos nombres quiere ingresar \n"); 
scanf("%d", &cantidadNombres); 
fflush(stdin);
VectorChar =(char**) malloc(sizeof(char*)*cantidadNombres);

//cargar nombres
for (int i = 0; i < cantidadNombres; i++)
{
   printf("ingrese el nombre numero %d ", i+1);
   gets(aux); 
    fflush(stdin);
    VectorChar[i] = (char*) malloc(sizeof(char)* strlen(aux));
    strcpy(VectorChar[i], aux); 
        printf("\n");
}

//mostrar 

for (int i = 0; i < cantidadNombres; i++)

{
       printf(" el nombre numero %d ingresado es ", i+1);

    puts(VectorChar[i]); 
    printf("\n");
}

    return 0;
}