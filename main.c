#include <stdio.h>
#include <string.h>
#include "gestStock.h"

#define MAX_ELEMENTOS 100

#define INGRESO 1
#define MODIFICACION 2
#define LISTADO 3
#define SALIR 4

int main(void)
{
    producto_t dataProduc[MAX_ELEMENTOS];

    dataProduc[0].code = 111;
    strcpy(dataProduc[0].name, "Pancho con coca");
    dataProduc[0].cdad = 2;
    dataProduc[0].pvp = 2000.0;

    int tama = 1;

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
                uint32_t codigoProducto = 0;
                if(busquedaCodigo(dataProduc, tama, &codigoProducto))
                {
                    printf("Encontrado\n");
                    datosProductos(dataProduc, tama, codigoProducto);
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

    printf("\n");

}

