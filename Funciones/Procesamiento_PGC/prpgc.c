#include <stdio.h>
#include <string.h>
#define MIN_HDL 20.0
#define MAX_HDL 80.0

#define MIN_LDL 100.0
#define MAX_LDL 220.0

#define MIN_EDAD 1.0
#define MAX_EDAD 105.0

#define MIN_PESO 5.0
#define MAX_PESO 150.0

#define MIN_TALLA 0.5
#define MAX_TALLA 2.20

#define MIN_IMC 0.0
#define MAX_IMC 100.0

#define VECES_PESO 4

#define MAX_CAD 30
void procesamiento_PGC(void);
double grasaCorporal(double IMC, double edad, char sexo[]);
double leerDato (double min, double max);
int main(void)
{
    procesamiento_PGC();
}

double leerDato (double min, double max){


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




void procesamiento_PGC(void){
    double IMC;
    double edad;
    char sexo[MAX_CAD];
    double grasa;

    printf("Introduzca su IMC\n\n");
    IMC=leerDato(MIN_IMC,MAX_IMC);
    printf("Introduzca su edad\n\n");
    edad=leerDato(MIN_EDAD,MAX_EDAD);

    printf("Introduzca su sexo (hombre o mujer en minusculas): ");
    scanf("%s",sexo);
    printf("\n");



    if(strcmp(sexo,"hombre")==0){



        grasa = grasaCorporal(IMC,edad,sexo);
        if(grasa<=25){
             printf("El %% de grasa corporal es %g. Es NORMAL\n",grasa);
        }else{
             printf("El %% de grasa corporal es %g. Hay OBESIDAD\n",grasa);
        }

    }else if(strcmp(sexo,"mujer")==0){

        grasa = grasaCorporal(IMC,edad,sexo);
        if(grasa<=30){
             printf("El %% de grasa corporal es %g. Es NORMAL\n",grasa);
        }else{
             printf("El %% de grasa corporal es %g. Hay OBESIDAD\n",grasa);
        }
    }else{
        printf("ERROR. No se ha indicado el sexo correctamente\n");
    }



}

/* Codificación completa de grasaCorporal  */

    double grasaCorporal(double IMC, double edad, char sexo[])
    {

    if (strcmp(sexo,"hombre")==0)
    {
        return(1.2*IMC+0.23*edad -16.2);
    }
    else
    {
        return(1.2*IMC+0.23*edad -5.4);
    }

}


