#include <stdio.h>
#include "gestStock.h"

#define NO_ENCONTRADO 0
#define ENCONTRADO 1

int buscar_producto_por_codigo(producto_t *inventario, size_t cantidad_productos, uint32_t *codigo_ingresado)
{
    uint32_t codigo_a_buscar = 0;
    printf("Ingrese codigo: ");
    scanf("%u", &codigo_a_buscar);

    *codigo_ingresado = codigo_a_buscar;
    for(size_t i = 0; i < cantidad_productos; i++)
    {
        if((inventario[i].codigo) == codigo_a_buscar)
        {
            return ENCONTRADO;
        }
    }

    return NO_ENCONTRADO;
}

void mostrar_datos_producto(producto_t *inventario, size_t cantidad_productos, uint32_t codigo_producto)
{
    for(size_t i = 0; i < cantidad_productos; i++)
    {
        if((inventario[i].codigo) == codigo_producto)
        {
            printf("Nombre: %s\n", inventario[i].nombre);
            printf("Cantidad: %u\n", inventario[i].cantidad);
            printf("Precio: %.2f\n", inventario[i].precio);
            break;
        }
    }
}

void ingresar_datos_producto(producto_t *inventario, size_t cantidad_productos, uint32_t codigo_producto)
{

}
