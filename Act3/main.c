#include <stdio.h>
#include "uniones.h"

int main(void)
{
    double prueba = 100000000.345;

    componentes_t partes = conversor(prueba);

    printf("%u\n", partes.signo);
    printf("%u\n", partes.exp);
    printf("%lu\n", partes.mantisa);

    int exponente_real = partes.exp - 1023;
    printf("\nExponente real (valor - 1023): %d\n", exponente_real);
    return 0; 
}
