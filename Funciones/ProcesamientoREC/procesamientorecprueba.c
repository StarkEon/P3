#include <stdio.h>
#include <string.h>
#define MIN_HDL 20.0
#define MAX_HDL 80.0

#define MIN_LDL 100.0
#define MAX_LDL 220.0
#define MAX_CAD 30
double leerDato (double min, double max);

//NO MODIFICAR RIESGO
double riesgo (double ldl, double hdl, char* hayRiesgo);



int main(void)
{
    double hdl1 = leerDato(MIN_HDL, MAX_HDL);
    double ldl1 = leerDato(MIN_LDL, MAX_LDL);
    char hayriesgo[MAX_CAD];
    double numeroriesgo = riesgo(ldl1,hdl1,&hayriesgo);
    printf("%s %.2f", hayriesgo, numeroriesgo);
    return(0);
}

double riesgo (double ldl, double hdl, char *hayRiesgo)
{
    double riesgo = ldl/hdl;
    if (riesgo > 3)
    {
        strcpy (hayRiesgo, "Hay riesgo cardiovascular");
    }
    else
    {
        strcpy (hayRiesgo,"No hay riesgo cardiovascular");
    }
    return(riesgo);
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
