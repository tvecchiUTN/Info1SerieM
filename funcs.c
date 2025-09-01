#include <stdio.h>
#include <math.h>
#include "funcs.h"

void dataSpace(punto3d_t *esp)
{
    printf("Ingrese datos: ");
    float aux = 0;

    scanf("%f", &aux);

    esp->ejeX = aux;

    scanf("%f", &aux);

    esp -> ejeY = aux;

    scanf("%f", &aux);

    esp -> ejeZ = aux;

    printf("Fin ingreso de datos\n");
}

double vector(const punto3d_t *punto)
{
    double cuadradoX = (double)(punto->ejeX) * (punto->ejeX);
    double cuadradoY = (double)(punto->ejeY) * (punto->ejeY);
    double cuadradoZ = (double)(punto->ejeZ) * (punto->ejeZ);
    return sqrt(cuadradoX + cuadradoY + cuadradoZ);
}

double dPP(const punto3d_t *punto1, const punto3d_t *punto2)
{
    double x = (double)(punto1->ejeX) - (punto2->ejeX);
    double y = (double)(punto1->ejeY) - (punto2->ejeY);
    double z = (double)(punto1->ejeZ) - (punto2->ejeZ);

    double cuadradoX = x * x;
    double cuadradoY = y * y;
    double cuadradoZ = z * z;
    return sqrt(cuadradoX + cuadradoY + cuadradoZ);
}


