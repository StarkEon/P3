/*****************************************************************************************
 * practica3.c
 * Control de salud: índice de masa corporal, cálculo de los valores de riesgo de enfermedad
 * cardíaca, variación de peso, y porcentaje de grasa corporal de una persona.
 * El usuario puede elegir entre estas opciones tantas veces como desee.
 * Para cada una, se pedirán los datos, se realizará el cálculo y se mostrará
 * el resultado por pantalla.
 *
 * Programadores: (Nombre y apellidos de los 2 miembros del grupo)
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
 	Precondiciones:
 	Parámetros de salida:
 	Parámetro de salida (valor devuelto por la función):
 ***************************************************************************************/
          indiceMC(      );


/**************************************************************************************
 Función: grasaCorporal
        Recibe el Indice de Masa Corporal, la edad y el sexo y calcula y devuelve
        el porcentaje de masa corporal
 Algoritmo:
 	Parámetros de entrada:
 	Precondiciones:
 	Parámetros de salida:
 	Parámetro de salida (valor devuelto por la función):
 ***************************************************************************************/
           grasaCorporal (    );


/**************************************************************************************
 Función: pesoMes
        Lee de la entrada estándar los pesos registrados en un mes y los almacena en un
        array de tamaño VECES_PESO
 Algoritmo:
 	Parámetros de entrada:
    Precondiciones:
 	Parámetros de salida:
 	Parámetro de salida (valor devuelto por la función):
 ***************************************************************************************/
          pesosMes (      );


/**************************************************************************************
 Función: pesoMinMax
        Recibe la serie de pesos del mes y calcula y devuelve el peso máximo y el mínimo
 Algoritmo:
 	Parámetros de entrada:
    Precondiciones:
 	Parámetros de salida:
 	Parámetro de salida (valor devuelto por la función):
 ***************************************************************************************/
            pesoMinMax (          );



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
    printf("1.- Indice de Masa Corporal \n2.- Variacion mensual del peso \n3.- Riesgo de enfermedad cardiovascular \n4.- Porcentaje de grasa corporal \n5.- Salir\nEscoja una opcion:");

}


/* Codificación completa de leerDato  */

double leerDato (double min, double max){

    double scan;
    do{
        printf("Introduzca un valor real comprendido entre %.2f y %.2f", min, max);
        scanf("%lf", &scan);
    }while(scan <= min || scan >= max);

    return(scan);

}


/* Codificación completa de indiceMC  */

   indiceMC {

}


/* Codificación completa de pesosMes  */

    pesosMes {

}


/* Codificación completa de pesoMinMax  */

      pesoMinMax {

}


/* Codificación completa de riesgo  */

double riesgo (double ldl, double hdl, char* hayRiesgo){

}


/* Codificación completa de grasaCorporal  */

      grasaCorporal {


}


/** Codificación completa de procesamiento_IMC  **/

 void procesamiento_IMC(void) {

 }


/** Codificación completa de procesamiento_VMP  **/

void procesamiento_VMP(void){

}


/** Codificación completa de procesamiento_REC  **/

void procesamiento_REC(void){

}


/** Codificación completa de procesamiento_PGC  **/

void procesamiento_PGC(void){

}

