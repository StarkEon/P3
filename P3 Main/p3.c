/*****************************************************************************************
 * practica3.c
 * Control de salud: �ndice de masa corporal, c�lculo de los valores de riesgo de enfermedad
 * card�aca, variaci�n de peso, y porcentaje de grasa corporal de una persona.
 * El usuario puede elegir entre estas opciones tantas veces como desee.
 * Para cada una, se pedir�n los datos, se realizar� el c�lculo y se mostrar�
 * el resultado por pantalla.
 *
 * Programadores: (Nombre y apellidos de los 2 miembros del grupo)
 * Fecha: Octubre 2018
 *
 *****************************************************************************************/

#include <stdio.h>
#include <string.h>

/* Definici�n de constantes */

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
 Funci�n: leerDato
		Lee un valor real en el rango [min, max].
 Algoritmo:
        La funci�n pide un valor real contenido entre los valores del rango y
        lo lee de teclado. Mientras que el usuario introduzca un valor que no
        cumpla esa condici�n, volver� a solicitar y leer el valor.
	Par�metros de entrada:
		min: m�nimo valor v�lido
		max: m�ximo valor v�lido
 	Par�metro de salida (valor devuelto por la funci�n):
        Valor real le�do por teclado.
***********************************************************************************/
double leerDato (double min, double max);


/***********************************************************************************
 Funci�n: menu
		Presenta el men� y lee la opci�n tecleada por el usuario.
 Algoritmo:
	Par�metros de entrada:
        Ninguno
    Par�metro de salida (valor devuelto por la funci�n):
        Opci�n elegida por el usuario (entero).
************************************************************************************/
int menu(void);


/**********************************************************************************
 Funci�n: procesamiento_IMC
        Lee los datos necesarios para calcular el IMC, lo calcula y muestra por
        pantalla los resultados.
 Algoritmo:
	Par�metros de entrada:
        Ninguno
 	Par�metros de salida:
        Ninguno
*************************************************************************************/
 void procesamiento_IMC(void);


 /**********************************************************************************
 Funci�n: procesamiento_VMP
        Lee los datos del peso de varias semanas (n�mero de semanas definido en
        VECES_PESO) y los almacena en un array.
        Calcula el peso m�ximo y m�nimo, lo escribe por pantalla junto con la
        variaci�n entre ambos. Escribe tambi�n por pantalla el peso de la primera
        y �ltima semana y su variaci�n.
 Algoritmo:
	Par�metros de entrada:
        Ninguno
 	Par�metros de salida:
        Ninguno
***********************************************************************************/
 void procesamiento_VMP(void);


 /***********************************************************************************
 Funci�n: procesamiento_REC
	 	Lee los datos necesarios para calcular el riesgo de enfermedad cardiaca, lo
 		calcula y muestra por pantalla los resultados.
 Algoritmo:
	Par�metros de entrada:
        Ninguno
 	Par�metros de salida:
        Ninguno
************************************************************************************/
void procesamiento_REC(void);


/*************************************************************************************
 Funci�n: procesamiento_PGC
        Lee los datos necesarios para calcular el porcentaje de grasa corporal, lo
        calcula y muestra por pantalla los resultados.
 Algoritmo:
	Par�metros de entrada:
        Ninguno
 	Par�metros de salida:
        Ninguno
***************************************************************************************/
void procesamiento_PGC(void);


/**************************************************************************************
 Funci�n: riesgo
        Calcula el �ndice de riesgo de enfermedad cardiaca (ldl/hdl) e indica si hay
        riesgo (indice>3) o si no lo hay.
 Algoritmo:
 	Par�metros de entrada:
 		ldl: colesterol �malo� en mg/dL
 		hdl: colesterol �bueno� en mg/dL
    Precondiciones: ldl y hdl deben estar entre los rangos v�lidos.
    Par�metros de salida:
        hayRiesgo: mensaje "Hay riesgo cardiovascular" o "No hay riesgo cardiovascular"
    Par�metro de salida (valor devuelto por la funci�n):
        Valor del �ndice de riesgo.
 ***************************************************************************************/
double riesgo (double ldl, double hdl, char* hayRiesgo);


/* Funciones a describir por el alumno/a con sus comentarios de cabecera. */

/**************************************************************************************
 Funci�n: indiceMC
        Recibe el peso y la altura y devuelve el Indice de Masa Corporal
 Algoritmo:
 	Par�metros de entrada:
 	Precondiciones:
 	Par�metros de salida:
 	Par�metro de salida (valor devuelto por la funci�n):
 ***************************************************************************************/
          indiceMC(      );


/**************************************************************************************
 Funci�n: grasaCorporal
        Recibe el Indice de Masa Corporal, la edad y el sexo y calcula y devuelve
        el porcentaje de masa corporal
 Algoritmo:
 	Par�metros de entrada:
 	Precondiciones:
 	Par�metros de salida:
 	Par�metro de salida (valor devuelto por la funci�n):
 ***************************************************************************************/
           grasaCorporal (    );


/**************************************************************************************
 Funci�n: pesoMes
        Lee de la entrada est�ndar los pesos registrados en un mes y los almacena en un
        array de tama�o VECES_PESO
 Algoritmo:
 	Par�metros de entrada:
    Precondiciones:
 	Par�metros de salida:
 	Par�metro de salida (valor devuelto por la funci�n):
 ***************************************************************************************/
          pesosMes (      );


/**************************************************************************************
 Funci�n: pesoMinMax
        Recibe la serie de pesos del mes y calcula y devuelve el peso m�ximo y el m�nimo
 Algoritmo:
 	Par�metros de entrada:
    Precondiciones:
 	Par�metros de salida:
 	Par�metro de salida (valor devuelto por la funci�n):
 ***************************************************************************************/
            pesoMinMax (          );



 /* Funci�n principal */

int main(void)
{
	int opcion;

	do
	{
		opcion=menu();
		switch(opcion)
		{
			case 1: /* �ndice de Masa Muscular */
				procesamiento_IMC();
				break;

			case 2: /* Variaci�n Mensual del Peso */
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

/* Codificaci�n completa de menu  */

int menu(void){
    printf("1.- Indice de Masa Corporal \n2.- Variacion mensual del peso \n3.- Riesgo de enfermedad cardiovascular \n4.- Porcentaje de grasa corporal \n5.- Salir\nEscoja una opcion:");

}


/* Codificaci�n completa de leerDato  */

double leerDato (double min, double max){

    double scan;
    do{
        printf("Introduzca un valor real comprendido entre %.2f y %.2f", min, max);
        scanf("%lf", &scan);
    }while(scan <= min || scan >= max);

    return(scan);

}


/* Codificaci�n completa de indiceMC  */

   indiceMC {

}


/* Codificaci�n completa de pesosMes  */

    pesosMes {

}


/* Codificaci�n completa de pesoMinMax  */

      pesoMinMax {

}


/* Codificaci�n completa de riesgo  */

double riesgo (double ldl, double hdl, char* hayRiesgo){

}


/* Codificaci�n completa de grasaCorporal  */

      grasaCorporal {


}


/** Codificaci�n completa de procesamiento_IMC  **/

 void procesamiento_IMC(void) {

 }


/** Codificaci�n completa de procesamiento_VMP  **/

void procesamiento_VMP(void){

}


/** Codificaci�n completa de procesamiento_REC  **/

void procesamiento_REC(void){

}


/** Codificaci�n completa de procesamiento_PGC  **/

void procesamiento_PGC(void){

}

