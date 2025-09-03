#include <stdio.h>
#include "gestStock.h"

#define NO_ENCONTRADO 0
#define ENCONTRADO 1

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
