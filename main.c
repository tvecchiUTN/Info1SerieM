#include <stdio.h>
#include <string.h>
#include "gestStock.h"

#define MAX_ELEMENTOS 100

int main(void)
{
    producto_t dataProduc[MAX_ELEMENTOS];

    dataProduc[0].code = 111;
    strcpy(dataProduc[0].name, "Pancho con coca");
    dataProduc[0].cdad = 2;
    dataProduc[0].pvp = 2000.0;
    int tama = 1;

    aplicacion(dataProduc, tama);

    printf("\n");

}

