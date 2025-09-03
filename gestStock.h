#ifndef __GESTSTOCK_H
#define __GESTSTOCK_H

#include <stdint.h>

typedef struct
{
    uint32_t codigo;      // Antes: code
    char     nombre[80];  // Antes: name
    uint16_t cantidad;    // Antes: cdad
    float    precio;      // Antes: pvp
} producto_t;

// Antes: busquedaCodigo
int buscar_producto_por_codigo(producto_t *inventario, size_t cantidad_productos, uint32_t *codigo_ingresado);

// Antes: datosProductos
void mostrar_datos_producto(producto_t *inventario, size_t cantidad_productos, uint32_t codigo_producto);

#endif
