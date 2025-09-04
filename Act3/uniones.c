#include <stdio.h>
#include "uniones.h"

componentes_t conversor(double num)
{
    flotante_t aux;
    componentes_t ret;

    aux.var = num;

    ret.signo = aux.bits.signo;
    ret.exp = aux.bits.exponente;
    ret.mantisa = aux.bits.mantisa;

    return ret;
}