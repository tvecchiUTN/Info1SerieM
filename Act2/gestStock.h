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

//Funciones de busqueda
int buscar_producto_por_codigo(producto_t *inventario, size_t cantidad_productos, uint32_t codigo_ingresado);
void mostrar_datos_producto(producto_t *inventario, size_t cantidad_productos, uint32_t codigo_producto);

//Funciones de ingreso de productos
void ordenar_productos(producto_t *inventario, size_t *cantidad_productos, producto_t *producto);
void ingresar_datos_producto(producto_t *inventario, size_t *cantidad_productos, uint32_t codigo_producto);
int buscar_nombre(producto_t *inventario, size_t cantidad_productos, char* nombreBuscar);
void borrar_salto(char *s);

//Funciones para el listado de productos
void imprimir_listado(const producto_t *inventario, size_t cantidad_productos, int opcion);

#endif
