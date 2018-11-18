/*****************************************************************************************
 * practica3.c
 * Control de salud: �ndice de masa corporal, c�lculo de los valores de riesgo de enfermedad
 * card�aca, variaci�n de peso, y porcentaje de grasa corporal de una persona.
 * El usuario puede elegir entre estas opciones tantas veces como desee.
 * Para cada una, se pedir�n los datos, se realizar� el c�lculo y se mostrar�
 * el resultado por pantalla.
 *
 * Programadores: Luis Ignacio de Benito Ochoa
                  Angie Maza Gonz�lez
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
        peso: peso en Kilos
        talla: talla en metros
 	Precondiciones: peso y talla dentro de los rangos v�lidos.
 	Par�metros de salida: ninguno
 	Par�metro de salida (valor devuelto por la funci�n): El valor del IMC
 ***************************************************************************************/
   double indiceMC(double peso,double talla);


/**************************************************************************************
 Funci�n: grasaCorporal
        Recibe el Indice de Masa Corporal, la edad y el sexo y calcula y devuelve
        el porcentaje de masa corporal
 Algoritmo:
 	Par�metros de entrada:
        IMC: Valor de Indice de Masa Corporal
        edad: edad de la persona en a�os.
        sexo: sexo de la persona.
 	Precondiciones: Valores dentro de los rangos v�lidos y valor de la cadena sexo sea "hombre" o "mujer".
 	Par�metros de salida: ninguno
 	Par�metro de salida (valor devuelto por la funci�n): valor del porcentaje de grasa corporal
 ***************************************************************************************/
 double grasaCorporal(double IMC, double edad, const char sexo[]);


/**************************************************************************************
 Funci�n: pesosMes
        Lee de la entrada est�ndar los pesos registrados en un mes y los almacena en un
        array de tama�o VECES_PESO
 Algoritmo:
 	Par�metros de entrada: ninguno
    Precondiciones: existencia de un array de tama�o VECES_PESO en la funci�n llamante
 	Par�metros de salida:
        pesos: array de pesos registrados en un mes
 	Par�metro de salida (valor devuelto por la funci�n): ninguno
 ***************************************************************************************/
 void pesosMes(double pesos[VECES_PESO]);


/**************************************************************************************
 Funci�n: pesoMinMax
        Recibe la serie de pesos del mes y calcula y devuelve el peso m�ximo y el m�nimo
 Algoritmo:
 	Par�metros de entrada:
        pesos: array de pesos registrados en un mes

    Precondiciones: ejecuci�n de la funci�n pesosMes (llenar el array con caracteres v�lidos)
 	Par�metros de salida:
        pesomin : el valor m�nimo almacenado en el array pesos[]
        pesomax : el valor m�ximo almacenado en el array pesos[]
 	Par�metro de salida (valor devuelto por la funci�n): ninguno
 ***************************************************************************************/
 void pesoMinMax(const double pesos[], double *pesomin, double *pesomax);


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
    int opcion;
    printf("\n\n1.- Indice de Masa Corporal \n2.- Variacion mensual del peso \n3.- Riesgo de enfermedad cardiovascular \n4.- Porcentaje de grasa corporal \n5.- Salir\nEscoja una opcion:");
    scanf("%d",&opcion);
    fflush(stdin);

    return(opcion);

}


/* Codificaci�n completa de leerDato  */

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


/* Codificaci�n completa de indiceMC  */

   double indiceMC (double peso, double talla){

       return(peso/(talla * talla));

}


/* Codificaci�n completa de pesosMes  */

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


/* Codificaci�n completa de pesoMinMax  */

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


/* Codificaci�n completa de riesgo  */

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


/* Codificaci�n completa de grasaCorporal  */

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


/** Codificaci�n completa de procesamiento_IMC  **/

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


/** Codificaci�n completa de procesamiento_VMP  **/

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


/** Codificaci�n completa de procesamiento_REC  **/

void procesamiento_REC(void){
    printf("Introduce el colesterol bueno en mg/dL\n");
    double hdl1 = leerDato(MIN_HDL, MAX_HDL);
    printf("Introduce el colesterol malo en mg/dL\n");
    double ldl1 = leerDato(MIN_LDL, MAX_LDL);
    char hayriesgo[MAX_CAD];
    double numeroriesgo = riesgo(ldl1,hdl1,&hayriesgo);
    printf("%s %.2f", hayriesgo, numeroriesgo);
}


/** Codificaci�n completa de procesamiento_PGC  **/

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

