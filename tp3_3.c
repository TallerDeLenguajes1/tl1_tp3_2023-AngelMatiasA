#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
//      Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
// vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria) (Lea
// las notas 1 y 2)

char **VectorChar; 
// char *nombre; 
char aux[20];
int largo = 0;

VectorChar =(char*) malloc(sizeof(char*)*5);

//cargar nombres
for (int i = 0; i < 5; i++)
{
   printf("ingrese el nombre numero %d ", i+1);
   gets(aux); 
    fflush(stdin);
    VectorChar[i] = (char*) malloc(sizeof(char)* strlen(aux));
    strcpy(VectorChar[i], aux); 
        printf("\n");
}

//mostrar 

for (int i = 0; i < 5; i++)

{
       printf(" el nombre numero %d ingresado es ", i+1);

    puts(VectorChar[i]); 
    printf("\n");
}

    return 0;
}