#include <stdio.h>


double leerDato (double min, double max){
    double scan;
    do{
        printf("Introduzca un valor real comprendido entre %.2f y %.2f", min, max);
        scanf("%lf", &scan);
    }while(scan <= min || scan >= max);

    return(scan);

}
int main (void){
    double d1 = 5.5;
    double d2 = 150;
    //double dato = leerDato(d1, d2);
printf("%.2f", leerDato(d1, d2) );
}



