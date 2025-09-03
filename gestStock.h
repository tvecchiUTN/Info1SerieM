#ifndef __GESTSTOCK_H
#define __GESTSTOCK_H

#include <stdint.h>

typedef struct
{
    uint32_t code; //Codigo del producto
    char name[80]; //Nombre del producto
    uint16_t cdad; //Cantidad o stock
    float pvp; //Precio venta al publico
}producto_t;

int busquedaCodigo(producto_t *vec, size_t sz, uint32_t *codigo);
void datosProductos(producto_t *vec, size_t sz, uint32_t codigo);

#endif
