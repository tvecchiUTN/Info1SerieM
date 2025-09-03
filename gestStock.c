#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"
#include "gestStock.h"

#define NO_ENCONTRADO 0
#define ENCONTRADO 1

static void asignacion_struct(const producto_t *src, producto_t *dst);

int buscar_producto_por_codigo(producto_t *inventario, size_t cantidad_productos, uint32_t codigo_ingresado)
{
    for(size_t i = 0; i < cantidad_productos; i++)
    {
        if((inventario[i].codigo) == codigo_ingresado)
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

void ingresar_datos_producto(producto_t *inventario, size_t *cantidad_productos, uint32_t codigo_producto)
{
    producto_t nuevo;
    //Codigo del producto
    nuevo.codigo = codigo_producto;

    //Nombre del producto
    char *auxNombre = NULL;
    auxNombre = (char*)malloc(80 * sizeof(char*));
    if(auxNombre == NULL)
    {
        return;
    }
    int puede = 1;
    while(puede)
    {
        printf("Ingrese nombre: ");
        fgets(auxNombre, sizeof(auxNombre), stdin);
        borrar_salto(auxNombre);
            //BUscar nombre devuelve 1 si encuentra repetido
        if(buscar_nombre(inventario, cantidad_productos, auxNombre))
        {
            printf("Nombre repetido, intente de nuevo\n");
            auxNombre = NULL;
            if(auxNombre == NULL)
            {
                return;
            }
        }
        else{
            puede = 0;
        }
    }


    //Asignacion de nombre
    strcpy(nuevo.nombre, auxNombre);
    free(auxNombre);

    uint16_t cdadAux = 0;
    printf("Ingrese la cantidad: ");
    scanf("%hu", &cdadAux);
    nuevo.cantidad = cdadAux;

    float precioAux = 0;
    printf("Ingrese el precio: ");
    scanf("%f", &precioAux);
    nuevo.precio = precioAux;

    ordenar_productos(inventario, cantidad_productos, &nuevo);
}

void ordenar_productos(producto_t *inventario, size_t *cantidad_productos, producto_t *producto)
{
    int habilitado = 1;
    int i;
    for(i = 0; i < *cantidad_productos; i++)
    {
        if(inventario[i].codigo > producto->codigo)
        {
            habilitado = 0;
            for(size_t j = *cantidad_productos; j > i; j--)
            {
                inventario[j] = inventario[j-1];
            }
            *cantidad_productos += 1;
            asignacion_struct(producto, &inventario[i]);
            break;
        }
    }

    if(habilitado)
    {
        asignacion_struct(producto, &inventario[i]);
        *cantidad_productos += 1;
    }
}

int buscar_nombre(producto_t *inventario, size_t cantidad_productos, char* nombreBuscar)
{
    for(int i = 0; i < cantidad_productos; i++)
    {
        if(!strcmp(inventario[i].nombre, nombreBuscar))
        {
            return ENCONTRADO;
        }
    }

    return NO_ENCONTRADO;
}

static void asignacion_struct(const producto_t *src, producto_t *dst)
{
    dst->codigo = src->codigo;
    strcpy(dst->nombre, src->nombre);
    dst->cantidad = src->cantidad;
    dst->precio = src->precio;
}
