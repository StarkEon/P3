#include <stdio.h>

#define MIN_PESO 5.0
#define MAX_PESO 150.0

#define MIN_TALLA 0.5
#define MAX_TALLA 2.20

void procesamiento_IMC(void);
double indiceMC (double peso, double talla);
double leerDato (double min, double max);

int main (void)
{
    procesamiento_IMC();
}

 void procesamiento_IMC(void) {

     printf("Introduce el peso en Kilos\n");
     double peso = leerDato(MIN_PESO, MAX_PESO);
     printf("Introduce la talla en metros\n");
     double talla = leerDato(MIN_TALLA, MAX_TALLA);
     double imc = indiceMC(peso,talla);
     if (imc < 16 || imc >= 30)
     {
         printf("deberia controlar su peso, IMC = %.2f", imc);
     }
     else
     {
         printf("peso aceptable, IMC = %.2f", imc);
     }
 }

 double indiceMC (double peso, double talla){

       return(peso/(talla * talla));

}

double leerDato (double min, double max){

    double scan;
    do{
        printf("Introduzca un valor real comprendido entre %.2f y %.2f \n", min, max);
        scanf("%lf", &scan);
    }while(scan <= min || scan >= max);

    return(scan);

}
