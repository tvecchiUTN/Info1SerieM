#include <stdio.h>
#include "gestStock.h"

#define INGRESO 1
#define MODIFICACION 2
#define LISTADO 3
#define SALIR 4

#define NO_ENCONTRADO 0
#define ENCONTRADO 1

void aplicacion(producto_t *vec, size_t sz)
{
    printf("Bienvenido a ... esto tiene nombre, no la verdad que no pero como es dificiel la mayoria de veces elegir un un nombre a un programa directamente lo ignoro, principalmente porque no tengo otra opcion mas que decir cualquir cosa con la unica razon en acordarme como lo llame y si me lo olvido, gracias a dios esta el autocompletado, si no? no?? lo sacaron? por que? si era muy bueno... osea que yo mismo me tengo que acordar las variables, dios, no termina mas esto...\n");
    int opcion = 0;
    while(opcion != SALIR)
    {
        printf("1 -Ingreso de codigo.\n");
        printf("2 -Modificacion de datos.\n");
        printf("3 -Listado de productos.\n");
        printf("4 -Salir del programa.\n");


        printf("Eliga una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case INGRESO:
                if(busquedaCodigo(vec, sz))
                {
                    printf("Encontrado\n");
                }
                else
                {
                    printf("No encontrado\n");
                }
                break;

            case SALIR:
            printf("Saliendo...\n");
            break;
        }
    }
}

int busquedaCodigo(producto_t *vec, size_t sz)
{
    uint32_t codigoBuscar = 0;
    printf("Ingrese codigo: ");
    scanf("%u", &codigoBuscar);

    for(int i = 0; i < sz; i++)
    {
        if((vec[i].code) == codigoBuscar)
        {
            return ENCONTRADO;
        }
    }

    return NO_ENCONTRADO;
}
