#ifndef __FUNCS_H
#define __FUNCS_H

typedef struct
{
    float ejeX;
    float ejeY;
    float ejeZ;
}punto3d_t;

void dataSpace(punto3d_t *esp);
double vector(const punto3d_t *punto);
double dPP(const punto3d_t *punto1, const punto3d_t *punto2);

#endif
