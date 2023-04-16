#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *tipoProductos [] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto
{
    int productoId;
    int cantidad; 
    char *TipoProducto; 
    float PrecioUnitario;
} typedef Producto;

struct Cliente
{
    int clienteID; 
    char *nombreCliente; 
    int cantPedidos; 
    Producto *productos;

} typedef Cliente;
void cargarClientes(Cliente *clientes, int cantidad);
void mostrarClientes(Cliente *clientes, int cantidad);
float calcularCosto(Producto Producto);



int main(){
    srand(time(NULL));
    Cliente *clientes;
    int cantidadClientes;
    printf("ingrese la cantidad de clientes \n"); 
    scanf("%d", &cantidadClientes);
    fflush(stdin);
    clientes = malloc(sizeof(Cliente)* cantidadClientes);

    cargarClientes(clientes, cantidadClientes);
    mostrarClientes(clientes, cantidadClientes);

    return 0;
}

void cargarClientes(Cliente *clientes, int cantidad){
char aux[20];
 srand(time(NULL));
 int id = 1;
 int precio= 0;
    for (int i = 0; i < cantidad; i++)
    {
        printf("ingrese el nombre del cliente numero %d:  ", i+1);
        gets(aux);
        fflush(stdin);
        clientes[i].nombreCliente= (char*) malloc(sizeof(char)* strlen(aux));
        strcpy(clientes[i].nombreCliente, aux);
        clientes[i].clienteID = i+1;
        clientes[i].cantPedidos = 1+ rand() % (6-1);
        clientes[i].productos = malloc(sizeof(Producto) * clientes[i].cantPedidos);
        for (int j = 0; j < clientes[i].cantPedidos; j++)
        {
            clientes[i].productos[j].productoId = id;
            clientes[i].productos[j].cantidad = 1 + rand() % 10;
             clientes[i].productos[j].TipoProducto= malloc(sizeof(char)*12);
             strcpy(clientes[i].productos[j].TipoProducto, tipoProductos[rand()%5] );
             precio = 10 + rand() % 100;
             clientes[i].productos[j].PrecioUnitario=  ((float) ( 10 + rand() % 10100))/100;
             id++;
        }   
    }  
}

float calcularCosto(Producto Producto){
    return Producto.cantidad * Producto.PrecioUnitario;
}


void mostrarClientes(Cliente *clientes, int cantidad){

float total = 0;
float costoProducto =0;

    for (int i = 0; i < cantidad; i++)
    {
        printf(" \n el id del cliente es %d ", clientes[i].clienteID);
        printf(" \n el nombre del cliente es : "); 
        puts(clientes[i].nombreCliente); 
        printf("la cantidad de productos pedidos es : "); 
        printf("%d \n",clientes[i].cantPedidos); 
        for (int j = 0; j < clientes[i].cantPedidos; j++)
        {
            printf("************** *********** ***********");
            printf(" \n producto numero %d \n", j+1);
            printf("el producto es : "); 
            puts(clientes[i].productos[j].TipoProducto);
           printf(" El id del producto es %d \n", clientes[i].productos[j].productoId);
            printf(" La cantidad de unidades es %d \n", clientes[i].productos[j].cantidad);
            printf(" El precio por unidad del producto es %.2f \n", clientes[i].productos[j].PrecioUnitario);
            costoProducto =  calcularCosto(clientes[i].productos[j]);
            printf ("El total por estos productos es de $%.2f \n, ", costoProducto);
            total += costoProducto;
        }
        
    }

    printf(" \n ********************************************* \n");
    printf("el Total de todos los productos de todos los clientes es de %.2f", total);
    


}


/*iv) Implemente una función que calcule el costo total de un producto. Esta función debe
recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
el PrecioUnitario. 
v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente
(sumatoria del costo de todos los productos)*/