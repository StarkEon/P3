#include <stdio.h>
#define MIN_HDL 20.0
#define MAX_HDL 80.0

#define MIN_LDL 100.0
#define MAX_LDL 220.0
double leerDato (double min, double max);

//NO MODIFICAR RIESGO
double riesgo (double ldl, double hdl, char* hayRiesgo);



int main(void)
{
    double hdl = leerDato(MIN_HDL, MAX_HDL);
    double ldl = leerDato(MIN_LDL, MAX_LDL);
    char hayriesgo;
    double numeroriesgo = riesgo(ldl,hdl,&hayriesgo);
    printf("%c %.2f", hayriesgo, numeroriesgo);
    return(0);
}

double riesgo (double ldl, double hdl, char* hayRiesgo)
{
    double riesgo = ldl/hdl;
    if (riesgo > 3)
    {
        *hayRiesgo = "Hay riesgo cardiovascular ya que el indice de riesgo es";
    }
    else
    {
        *hayRiesgo = "No hay riesgo cardiovascular ya que el indice de riesgo es";
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
