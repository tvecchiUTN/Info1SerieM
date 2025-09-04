#ifndef __UNIONES_H
#define __UNIONES_H

#include <stdint.h>
typedef union 
{
    double var;
    uint64_t entero;

    struct{
        uint64_t mantisa : 52;
        uint64_t exponente : 11;
        uint64_t signo : 1;
    }bits;
    
}flotante_t;

typedef struct
{
    uint8_t signo;
    uint16_t exp;
    uint64_t mantisa;
}componentes_t;

componentes_t conversor(double num);

#endif