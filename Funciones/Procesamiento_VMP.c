#include <stdio.h>
#include <string.h>

#define VECES_PESO 4
#define MIN_PESO 5.0
#define MAX_PESO 150.0

void pesosMes(double pesos[]);

double leerDato (double min, double max);

void pesoMinMax(double pesos[], double *pesomin, double *pesomax);

void procesamiento_VMP(void);

int main (void)
{
    procesamiento_VMP();
    /*double col[VECES_PESO];
    double min;
    double max;
    printf("Introduzca los pesos que ha registrado este mes \n");
    pesosMes(col);
    pesoMinMax(col, &min, &max);
    printf("Peso maximo = %.2f , Peso minimo = %.2f    Variacion = %.2f \n Peso primera semana: %.2f y peso ultima semana: %.2f Variacion: %.2f", max, min, max - min, col[0], col[VECES_PESO - 1], col[VECES_PESO - 1] - col[0]);
    return(0);*/
    return(0);
}

void pesosMes(double pesos[])
{
    int i;
    for(i=0; i < VECES_PESO;i++)
    {
        printf("Introduce los pesos de la semana %d \n", i + 1);
        pesos[i] = leerDato(MIN_PESO,MAX_PESO);
        fflush(stdin);
    }

}
double leerDato (double min, double max){

    //Cambiar a IF

    double scan;
    do{
        printf("Introduzca un valor real comprendido entre %.2f y %.2f \n", min, max);
        scanf("%lf", &scan);
        if (scan < min || scan > max)
        {
            printf("ERROR: Valor fuera de rango \n");
        }
    }while(scan < min || scan > max);

    return(scan);

}

void pesoMinMax(double pesos[], double *pesomin, double *pesomax)
{
    int i;
    *pesomin = pesos[0];
    *pesomax = pesos[0];
    for(i = 0; i< VECES_PESO; i++)
    {
        if(pesos[i]>*pesomax)
        {
            *pesomax = pesos[i];
        }
        if(pesos[i]<*pesomin)
        {
            *pesomin = pesos[i];
        }
    }
}

void procesamiento_VMP(void)
{
    double col[VECES_PESO];
    double min;
    double max;
    printf("Introduzca los pesos que ha registrado este mes \n");
    pesosMes(col);
    pesoMinMax(col, &min, &max);
    printf("Peso maximo = %.2f , Peso minimo = %.2f    Variacion = %.2f \n Peso primera semana: %.2f y peso ultima semana: %.2f Variacion: %.2f", max, min, max - min, col[0], col[VECES_PESO - 1], col[VECES_PESO - 1] - col[0]);
}
