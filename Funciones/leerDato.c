#include <stdio.h>


double leerDato (double min, double max)
{
    double scan;
    do{
        printf("Introduzca un valor real comprendido entre %.2f y %.2f", min, max);
        scanf("%lf", &scan);
    }while(scan <= min || scan >= max);

    return(scan);
}



