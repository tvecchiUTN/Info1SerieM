#include <stdio.h>
#include <string.h>
#include "funcs.h"
#include "gestStock.h"

#define MAX_ELEMENTOS 100

#define OPCION_INGRESO 1
#define OPCION_MODIFICACION 2
#define OPCION_LISTADO 3
#define OPCION_SALIR 4

int main(void)
{
    producto_t inventario[MAX_ELEMENTOS];
    size_t cantidad_productos = 0;

    // (Mensaje de bienvenida largo omitido por claridad)

    int opcion_menu = 0;
    while(opcion_menu != OPCION_SALIR)
    {
        printf("1 - Buscar producto.\n"); // El menú ahora refleja mejor la acción
        printf("2 - Modificacion de datos.\n");
        printf("3 - Listado de productos.\n");
        printf("4 - Salir del programa.\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion_menu);

        switch(opcion_menu)
        {
            case OPCION_INGRESO:
                uint32_t codigo_buscado = 0;
                printf("Ingrese codigo: ");
                scanf("%u", &codigo_buscado);

                if(buscar_producto_por_codigo(inventario, cantidad_productos, codigo_buscado))
                {
                    printf("Producto encontrado:\n");
                    mostrar_datos_producto(inventario, cantidad_productos, codigo_buscado);
                }
                else
                {
                    printf("Producto no encontrado.\n");
                    int opcion_aniadir = 0;
                    printf("Desea añadir los datos del producto?\n");
                    printf("Si (ingrese 1)\n");
                    printf("No (ingrese 0)\n");
                    scanf("%d", &opcion_aniadir);
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    if(opcion_aniadir)
                    {
                        ingresar_datos_producto(inventario, &cantidad_productos, codigo_buscado);
                    }
                }
                break;

            case OPCION_SALIR:
                printf("Saliendo...\n");
                break;
        }
    }

    printf("\n");

    for(int z = 0; z < cantidad_productos; z++)
    {
        printf("%u\n", inventario[z].codigo);
        printf("%s\n", inventario[z].nombre);
        printf("%hu\n", inventario[z].cantidad);
        printf("%.2f\n", inventario[z].precio);
    }
    return 0;
}
