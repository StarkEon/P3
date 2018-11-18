/*****************************************************************************************
 * practica3.c
 * Control de salud: índice de masa corporal, cálculo de los valores de riesgo de enfermedad
 * cardíaca, variación de peso, y porcentaje de grasa corporal de una persona.
 * El usuario puede elegir entre estas opciones tantas veces como desee.
 * Para cada una, se pedirán los datos, se realizará el cálculo y se mostrará
 * el resultado por pantalla.
 *
 * Programadores: Luis Ignacio de Benito Ochoa
                  Angie Maza González
 * Fecha: Octubre 2018
 *
 *****************************************************************************************/

#include <stdio.h>
#include <string.h>

/* Definición de constantes */

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



/***********************************************************************************
 Función: leerDato
		Lee un valor real en el rango [min, max].
 Algoritmo:
        La función pide un valor real contenido entre los valores del rango y
        lo lee de teclado. Mientras que el usuario introduzca un valor que no
        cumpla esa condición, volverá a solicitar y leer el valor.
	Parámetros de entrada:
		min: mínimo valor válido
		max: máximo valor válido
 	Parámetro de salida (valor devuelto por la función):
        Valor real leído por teclado.
***********************************************************************************/
double leerDato (double min, double max);


/***********************************************************************************
 Función: menu
		Presenta el menú y lee la opción tecleada por el usuario.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
    Parámetro de salida (valor devuelto por la función):
        Opción elegida por el usuario (entero).
************************************************************************************/
int menu(void);


/**********************************************************************************
 Función: procesamiento_IMC
        Lee los datos necesarios para calcular el IMC, lo calcula y muestra por
        pantalla los resultados.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
 	Parámetros de salida:
        Ninguno
*************************************************************************************/
 void procesamiento_IMC(void);


 /**********************************************************************************
 Función: procesamiento_VMP
        Lee los datos del peso de varias semanas (número de semanas definido en
        VECES_PESO) y los almacena en un array.
        Calcula el peso máximo y mínimo, lo escribe por pantalla junto con la
        variación entre ambos. Escribe también por pantalla el peso de la primera
        y última semana y su variación.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
 	Parámetros de salida:
        Ninguno
***********************************************************************************/
 void procesamiento_VMP(void);


 /***********************************************************************************
 Función: procesamiento_REC
	 	Lee los datos necesarios para calcular el riesgo de enfermedad cardiaca, lo
 		calcula y muestra por pantalla los resultados.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
 	Parámetros de salida:
        Ninguno
************************************************************************************/
void procesamiento_REC(void);


/*************************************************************************************
 Función: procesamiento_PGC
        Lee los datos necesarios para calcular el porcentaje de grasa corporal, lo
        calcula y muestra por pantalla los resultados.
 Algoritmo:
	Parámetros de entrada:
        Ninguno
 	Parámetros de salida:
        Ninguno
***************************************************************************************/
void procesamiento_PGC(void);


/**************************************************************************************
 Función: riesgo
        Calcula el índice de riesgo de enfermedad cardiaca (ldl/hdl) e indica si hay
        riesgo (indice>3) o si no lo hay.
 Algoritmo:
 	Parámetros de entrada:
 		ldl: colesterol “malo” en mg/dL
 		hdl: colesterol “bueno” en mg/dL
    Precondiciones: ldl y hdl deben estar entre los rangos válidos.
    Parámetros de salida:
        hayRiesgo: mensaje "Hay riesgo cardiovascular" o "No hay riesgo cardiovascular"
    Parámetro de salida (valor devuelto por la función):
        Valor del índice de riesgo.
 ***************************************************************************************/
double riesgo (double ldl, double hdl, char* hayRiesgo);


/* Funciones a describir por el alumno/a con sus comentarios de cabecera. */

/**************************************************************************************
 Función: indiceMC
        Recibe el peso y la altura y devuelve el Indice de Masa Corporal
 Algoritmo:
 	Parámetros de entrada:
        peso: peso en Kilos
        talla: talla en metros
 	Precondiciones: peso y talla dentro de los rangos válidos.
 	Parámetros de salida: ninguno
 	Parámetro de salida (valor devuelto por la función): El valor del IMC
 ***************************************************************************************/
   double indiceMC(double peso,double talla);


/**************************************************************************************
 Función: grasaCorporal
        Recibe el Indice de Masa Corporal, la edad y el sexo y calcula y devuelve
        el porcentaje de masa corporal
 Algoritmo:
 	Parámetros de entrada:
        IMC: Valor de Indice de Masa Corporal
        edad: edad de la persona en años.
        sexo: sexo de la persona.
 	Precondiciones: Valores dentro de los rangos válidos y valor de la cadena sexo sea "hombre" o "mujer".
 	Parámetros de salida: ninguno
 	Parámetro de salida (valor devuelto por la función): valor del porcentaje de grasa corporal
 ***************************************************************************************/
 double grasaCorporal(double IMC, double edad, const char sexo[]);


/**************************************************************************************
 Función: pesosMes
        Lee de la entrada estándar los pesos registrados en un mes y los almacena en un
        array de tamaño VECES_PESO
 Algoritmo:
 	Parámetros de entrada: ninguno
    Precondiciones: existencia de un array de tamaño VECES_PESO en la función llamante
 	Parámetros de salida:
        pesos: array de pesos registrados en un mes
 	Parámetro de salida (valor devuelto por la función): ninguno
 ***************************************************************************************/
 void pesosMes(double pesos[VECES_PESO]);


/**************************************************************************************
 Función: pesoMinMax
        Recibe la serie de pesos del mes y calcula y devuelve el peso máximo y el mínimo
 Algoritmo:
 	Parámetros de entrada:
        pesos: array de pesos registrados en un mes

    Precondiciones: ejecución de la función pesosMes (llenar el array con caracteres válidos)
 	Parámetros de salida:
        pesomin : el valor mínimo almacenado en el array pesos[]
        pesomax : el valor máximo almacenado en el array pesos[]
 	Parámetro de salida (valor devuelto por la función): ninguno
 ***************************************************************************************/
 void pesoMinMax(const double pesos[], double *pesomin, double *pesomax);


 /* Función principal */

int main(void)
{
	int opcion;

	do
	{
		opcion=menu();
		switch(opcion)
		{
			case 1: /* Índice de Masa Muscular */
				procesamiento_IMC();
				break;

			case 2: /* Variación Mensual del Peso */
				procesamiento_VMP();
				break;

			case 3: /* Riesgo de Enfermedad Cardiovascular */
				procesamiento_REC();
				break;

			case 4: /* Porcentaje de Grasa Corporal */
				procesamiento_PGC();
				break;

			case 5:
				printf("\n\nFIN DEL PROGRAMA.\n\n");
				break;

			default:
				printf("\n\nOpcion incorrecta.\n\n");
		}

	} while(opcion != 5);

return 0;
}

/* FUNCIONES  ***/

/* Codificación completa de menu  */

int menu(void){
    int opcion;
    printf("\n\n1.- Indice de Masa Corporal \n2.- Variacion mensual del peso \n3.- Riesgo de enfermedad cardiovascular \n4.- Porcentaje de grasa corporal \n5.- Salir\nEscoja una opcion:");
    scanf("%d",&opcion);
    fflush(stdin);

    return(opcion);

}


/* Codificación completa de leerDato  */

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


/* Codificación completa de indiceMC  */

   double indiceMC (double peso, double talla){

       return(peso/(talla * talla));

}


/* Codificación completa de pesosMes  */

void pesosMes(double pesos[VECES_PESO])
{
    int i;
    for(i=0; i < VECES_PESO;i++)
    {
        printf("Introduce los pesos de la semana %d \n", i + 1);
        pesos[i] = leerDato(MIN_PESO,MAX_PESO);
        fflush(stdin);
    }

}


/* Codificación completa de pesoMinMax  */

void pesoMinMax(const double pesos[], double *pesomin, double *pesomax)
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


/* Codificación completa de riesgo  */

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


/* Codificación completa de grasaCorporal  */

double grasaCorporal(double IMC, double edad,const char sexo[])
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


/** Codificación completa de procesamiento_IMC  **/

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


/** Codificación completa de procesamiento_VMP  **/

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


/** Codificación completa de procesamiento_REC  **/

void procesamiento_REC(void){
    printf("Introduce el colesterol bueno en mg/dL\n");
    double hdl1 = leerDato(MIN_HDL, MAX_HDL);
    printf("Introduce el colesterol malo en mg/dL\n");
    double ldl1 = leerDato(MIN_LDL, MAX_LDL);
    char hayriesgo[MAX_CAD];
    double numeroriesgo = riesgo(ldl1,hdl1,&hayriesgo);
    printf("%s %.2f", hayriesgo, numeroriesgo);
}


/** Codificación completa de procesamiento_PGC  **/

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

