#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecturas.h"
#include "funciones.h"
#include "menu.h"
void agregarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *n_productos)
{
    if (*n_productos == MAX_PRODUCTOS)
    {
        printf("\nNo se pueden agregar más productos. Límite alcanzado.\n");
        return;
    }

    char nuevoNombre[MAX_NOMBRE];
    ingresarCadenas("\nNombre del producto: ", &nuevoNombre, 1);

    int nuevaCantidad;
    nuevaCantidad = leerSoloNumerosEnteros("Ingrese la cantidad del producto: ");

    float nuevoPrecio;
    nuevoPrecio = leerSoloNumerosFloatantes("Ingrese el precio del producto: ");

    strcpy(nombres[*n_productos], nuevoNombre);
    cantidades[*n_productos] = nuevaCantidad;
    precios[*n_productos] = nuevoPrecio;
    (*n_productos)++;

    FILE *archivo;
    archivo = fopen("productos.txt", "a");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "Nombre del producto: %s\n", nuevoNombre);
    fprintf(archivo, "Cantidad del producto: %d\n", nuevaCantidad);
    fprintf(archivo, "Precio del producto: %.2f\n", nuevoPrecio);
    fprintf(archivo, "---------------------------------\n");
    fprintf(archivo, "\n");

    fclose(archivo);

    printf("Producto agregado correctamente.\n");
}

void listarProducto(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int n_productos)
{
    if (n_productos == 0)
    {
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("\nListando los productos Novopan:\n");

    for (int i = 0; i < n_productos; i++)
    {
        printf("Nombre del producto: %s\n", nombres[i]);
        printf("Cantidad del producto: %d\n", cantidades[i]);
        printf("Precio del producto: %.2f\n", precios[i]);
        printf("\n");
    }
}

void editarPrecio(char nombres[][MAX_NOMBRE], float precios[], int n_productos)
{
    if (n_productos == 0)
    {
        printf("No hay productos en el inventario.\n");
        return;
    }

    char nombre[MAX_NOMBRE];
    ingresarCadenas("\nIngrese el nombre del producto a editar: ", &nombre, 1);

    int indice = buscarProductoPorNombre(nombres, n_productos, nombre);

    if (indice == -1)
    {
        printf("El producto no se encontro en el inventario.\n");
        return;
    }

    float nuevoPrecio;
    nuevoPrecio = leerSoloNumerosFloatantes("\nIngresar el nuevo costo del producto: ");

    precios[indice] = nuevoPrecio;

    printf("\nPrecio del producto editado correctamente.\n");
}

void editarCantidad(char nombres[][MAX_NOMBRE], int cantidades[], int n_productos)
{
    if (n_productos == 0)
    {
        printf("\nNo hay productos en el inventario.\n");
        return;
    }

    char nombre[MAX_NOMBRE];
    ingresarCadenas("Ingrese el nombre del producto a editar: ", &nombre, 1);

    int indice = buscarProductoPorNombre(nombres, n_productos, nombre);

    if (indice == -1)
    {
        printf("El producto no se encontró en el inventario.\n");
        return;
    }

    int nuevaCantidad;
    nuevaCantidad = leerSoloNumerosEnteros("Ingrese la nueva cantidad del producto: ");

    cantidades[indice] = nuevaCantidad;

    printf("Cantidad del producto editada correctamente.\n");
}

int buscarProductoPorNombre(const char nombres[][MAX_NOMBRE], int n_productos, const char *nombre)
{
    for (int i = 0; i < n_productos; i++)
    {
        if (strcmp(nombres[i], nombre) == 0)
        {
            return i;
        }
    }
    return -1;
}

void eliminarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *n_productos)
{
    if (*n_productos == 0)
    {
        printf("No hay productos en el inventario.\n");
        return;
    }

    char nombre[MAX_NOMBRE];
    ingresarCadenas("Ingrese el nombre del producto a eliminar: ", &nombre, 1);

    int indice = buscarProductoPorNombre(nombres, *n_productos, nombre);

    if (indice == -1)
    {
        printf("El producto no se encontró en el inventario.\n");
        return;
    }

    desplazarProductos(nombres, cantidades, precios, indice, *n_productos);
    (*n_productos)--;

    FILE *archivo;
    archivo = fopen("archivo.txt", "w");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < *n_productos; i++)
    {
        fprintf(archivo, "Nombre del producto: %s\n", nombres[i]);
        fprintf(archivo, "Cantidad del producto: %d\n", cantidades[i]);
        fprintf(archivo, "Precio del producto: %.2f\n", precios[i]);
        fprintf(archivo, "\n");
    }

    fclose(archivo);

    printf("Producto eliminado correctamente.\n");
}
void desplazarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int indice, int n_productos)
{
    for (int i = indice; i < n_productos - 1; i++)
    {
        strcpy(nombres[i], nombres[i + 1]);
        cantidades[i] = cantidades[i + 1];
        precios[i] = precios[i + 1];
    }
}

void ingresarCadenas(char *mensaje, char nombres[][MAX_NOMBRE], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s", mensaje);
        fgets(nombres[i], MAX_NOMBRE, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0'; // Eliminar el carácter de nueva línea
    }
}