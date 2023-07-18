#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecturas.h"
#include "funciones.h"
#include "menu.h"
int leerSoloNumerosEnteros(char *mensaje)
{
    char input[256];
    int valor;

    do
    {
        printf("%s", mensaje);
        fgets(input, sizeof(input), stdin);
        valor = atoi(input);
        if (valor == 0)
        {
            printf("Por favor, ingrese un numero válido.\n");
        }
    } while (valor == 0);

    return valor;
}

float leerSoloNumerosFloatantes(char *mensaje)
{
    char input[256];
    float valor;

    do
    {
        printf("%s", mensaje);
        fgets(input, sizeof(input), stdin);
        valor = atof(input);
        if (valor == 0)
        {
            printf("Por favor, ingrese un numero válido.\n");
        }
    } while (valor == 0);

    return valor;
}

int leerEnteroEntre(char *mensaje, int minimo, int maximo)
{
    int valor;
    do
    {
        printf("%s", mensaje);
        scanf("%d", &valor);
        getchar(); // Consumir el carácter de nueva línea pendiente en el búfer
    } while (valor < minimo || valor > maximo);
    return valor;
}