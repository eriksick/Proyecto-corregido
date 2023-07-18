#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecturas.h"
#include "funciones.h"
#include "menu.h"

#define MAX_PRODUCTOS 150
#define MAX_NOMBRE 100




int main()
{
    int opcion;
    int opc2;
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int n_productos = 0;

    printf("SISTEMA DE INVENTARIO NOVOPAN\n");

    do
    {
        mostrarMenu();
        opcion = leerEnteroEntre("Ingrese una opcion valida: ", 1, 5);

        switch (opcion)
        {
        case 1:
            printf("\nPor favor, ingrese los siguientes datos:\n");
            agregarProducto(nombres, cantidades, precios, &n_productos);
            break;
        case 2:
            mostrarOpciones();
            opc2 = leerEnteroEntre("Ingrese una opcion dentro del rango: ", 1, 2);
            switch (opc2)
            {
            case 1:
                editarCantidad(nombres, cantidades, n_productos);
                break;
            case 2:
                editarPrecio(nombres, precios, n_productos);
                break;
            }
            break;
        case 3:
            printf("\nEliminar producto.\n");
            eliminarProducto(nombres, cantidades, precios, &n_productos);
            break;
        case 4:
            listarProducto(nombres, cantidades, precios, n_productos);
            break;
        case 5:
            printf("Saliendo del programa\n");
            break;
        default:
            printf("Opción invalida\n");
            break;
        }
    } while (opcion != 5);

    return 0;
}






