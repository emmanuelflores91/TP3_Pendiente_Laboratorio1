#include "myFunctions.h"

int PedirEntero (int* numero, char mensaje[], char mensajeError[], int cantidadReintentos)
{
	int estado;
	int longitud;
	char cadena[10];

	estado = -1;
	longitud = sizeof(cadena);

	do
		{
			printf("%s", mensaje);
			if (LeerCadena(cadena, longitud) == 0 && ComprobarSiEsEntero(cadena) == 1)
			{
				*numero = atoi(cadena);
				estado = 0;
				break;
			}

			printf("%s",mensajeError);

			cantidadReintentos--;

		}while(cantidadReintentos >=0);

	return estado;
}

int PedirEntero2 (int* numero, char mensaje[], char mensajeError[], int cantidadReintentos, int* contadorErrores)
{
	int estado;
	char cadena[10];
	int longitud;
	estado = -1;
	contadorErrores = 0;
	longitud = sizeof(cadena);

	do
		{
			printf("%s", mensaje);
			if (LeerCadena(cadena, longitud) == 0 && ComprobarSiEsEntero(cadena) == 1)
			{
				*numero = atoi(cadena);
				estado = 0;
				break;
			}
			contadorErrores ++;

			printf("%s",mensajeError);

			cantidadReintentos--;

		}while(cantidadReintentos >= 0);

	if(cantidadReintentos < 0)
	{
		estado = -2;
	}

	return estado;
}


int PedirEnteroPositivo (int* numero, char mensaje[], char mensajeError[], int cantidadReintentos)
{
	int estado;
	int longitud;
	char cadena[10];

	estado = -1;
	longitud = sizeof(cadena);

	do
		{
			printf("%s", mensaje);
			if (LeerCadena(cadena, longitud) == 0 &&
				ComprobarSiEsEntero(cadena) == 1 && atoi(cadena) >= 0)
			{
				*numero = atoi(cadena);
				estado = 0;
				break;
			}

			printf("%s",mensajeError);
			cantidadReintentos--;

		}while(cantidadReintentos >=0);


	return estado;
}


int PedirEnteroEnRango (int* numero, char mensaje[], char mensajeError[], int minimo, int maximo, int cantidadReintentos)
{
	int longitud;
	int estado;
	char cadena [10];

	estado = -1;
	longitud = sizeof(cadena);


	do
	{	printf("%s", mensaje);
		if(LeerCadena(cadena, longitud) == 0 &&
		ComprobarSiEsEntero(cadena) == 1 &&
		atoi(cadena) >= minimo && atoi(cadena) <= maximo)
		{
			*numero = atoi(cadena);
			estado = 0;
			break;
		}
		cantidadReintentos--;
		printf("%s", mensajeError);


	}while(cantidadReintentos >=0);

	return estado;
}

float PedirFlotante (float* numero, char mensaje [], char mensajeError[], int cantidadReintentos)
{
	int estado;
	char cadena[10];
	int longitud;

	estado = -1;
	longitud = sizeof(cadena);


	do
	{
		printf("%s", mensaje);
		if(LeerCadena(cadena, longitud) == 0 &&
			ComprobarSiEsFlotante(cadena) == 1)
		{
			*numero = atof(cadena);
			estado = 0;
			break;
		}

		cantidadReintentos--;
		printf("%s", mensajeError);

	}while(cantidadReintentos >=0);

	return estado;
}

int PedirFlotanteEnRango (float* numero, char mensaje[], char mensajeError[], float minimo, float maximo, int cantidadReintentos)
{
	int longitud;
	int estado;
	char cadena [10];

	estado = -1;
	longitud = sizeof(cadena);


	do
	{	printf("%s", mensaje);
		if(LeerCadena(cadena, longitud) == 0 &&
		ComprobarSiEsEntero(cadena) == 1 &&
		atof(cadena) >= minimo && atof(cadena) <= maximo)
		{
			*numero = atof(cadena);
			estado = 0;
			break;
		}
		cantidadReintentos--;
		printf("%s", mensajeError);


	}while(cantidadReintentos >=0);

	return estado;
}

int PedirFlotanteGrande (double* numero, char mensaje [], char mensajeError[], int cantidadReintentos)
{
	int estado;
	char cadena[20];
	int longitud;

	estado = -1;
	longitud = sizeof(cadena);


	do
	{	printf("%s", mensaje);
		if(LeerCadena(cadena, longitud) == 0 &&
			ComprobarSiEsFlotante(cadena) == 1)
		{
			*numero = atof(cadena);
			estado = 0;
			break;
		}

		cantidadReintentos--;
		printf("%s", mensajeError);

	}while(cantidadReintentos >=0);

	return estado;
}

/*char PedirCaracter (char mensaje [])
{
	char caracter;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &caracter);
	caracter = toupper(caracter);
	return caracter;
}*/

int LeerCadena(char cadena[], int longitud)
{
	char cadenaAuxiliar[5000];
	int longitudAux;
	int cantCaracteres;
	int estado = -1;
	longitudAux = sizeof(cadenaAuxiliar);

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(cadenaAuxiliar,longitudAux,stdin) != NULL)
		{
			cantCaracteres = strnlen(cadenaAuxiliar,longitudAux);
			if(cadenaAuxiliar[cantCaracteres-1] == '\n')
			{
				cadenaAuxiliar[cantCaracteres-1] = '\0';
			}
			if(cantCaracteres <= longitud)
			{
				strncpy(cadena,cadenaAuxiliar,longitud);
				estado = 0;
			}
		}
	}
	return estado;
}


int PedirCadena(char mensaje[], char mensajeError[], char cadena[], int longitud, int cantidadReintentos)
{
	int estado;
	estado = -1;

	do
	{
		printf("%s", mensaje);
		if (LeerCadena(cadena, longitud)==0)
		{
			estado = 0;
			break;
		}

		printf("%s",mensajeError);
		cantidadReintentos--;

	}while(cantidadReintentos >=0);


	return estado;
}

int PedirCadenaEnRango(char mensaje [], char mensajeError, char cadena[], int longitud, int minimo)
{
	int estado;
	char cadenaAuxiliar[5000];
	int longitudAux;
	int cantCaracteres;

	longitudAux = sizeof(cadenaAuxiliar);
	estado = -1;
	cantCaracteres = strlen(cadenaAuxiliar);

	printf("%s", mensaje);
	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(cadenaAuxiliar,longitudAux,stdin) != NULL)
		{
			cantCaracteres = strnlen(cadenaAuxiliar,longitudAux);
			if(cadenaAuxiliar[cantCaracteres-1] == '\n')
			{
				cadenaAuxiliar[cantCaracteres-1] = '\0';
			}
			if(cantCaracteres-1 <= longitud-1 && cantCaracteres-1 >= minimo)
			{
				strncpy(cadena,cadenaAuxiliar,longitud);
				estado = 0;
			}
		}
	}
	return estado;
}



/*int ExcluirEntero (int numeroIngresado, int numeroExcluido)
{

		while (numeroIngresado == numeroExcluido)
		{
			printf("\nNo se admite el numero %d", numeroExcluido);
			numeroIngresado = PedirEntero("\nIntente nuevamente: ");
		}
	return numeroIngresado;

}

float ExcluirFlotante (float numeroIngresado, float numeroExcluido)
{

		while (numeroIngresado == numeroExcluido)
		{
			printf("\nNo se admite el numero %.2f", numeroExcluido);
			numeroIngresado = PedirFlotante("\nIntente nuevamente: ");
		}
	return numeroIngresado;

}

int DistinguirEnteroDeFlotante (float numeroIngresado)
{
	int parteEntera;
	float parteDecimal;
	int esEntero;

	esEntero = 1;

	parteEntera = numeroIngresado;
	parteDecimal = numeroIngresado - parteEntera;

	if (parteDecimal > 0)
	{
		esEntero = 0;
	}

	return esEntero;
}
*/

int ComprobarSiEsFlotante (char datoIngresado[])
{
	int esFlotante = 1;
	int contadorPuntos = 0;
	int longitud;
	longitud = strlen(datoIngresado);

	for(int i=0;i<longitud;i++)
	{
		if (datoIngresado[i]==',')
		{
			datoIngresado[i] = '.';
		}
	}

	if (((datoIngresado[0] == '+' || datoIngresado[0] == '-' || datoIngresado[0] == '.') && longitud > 1) || isdigit(datoIngresado[0]))
	{
		for (int i = 0; i < longitud; i++)
		{
			if (datoIngresado[i] == '.')
			{
				contadorPuntos++;
			}
		}
		if(contadorPuntos <= 1)
		{
			for(int i = 1; i < longitud; i++)
			{
				if((!isdigit(datoIngresado[i])&& datoIngresado[i]!='.')||(!isdigit(datoIngresado[1]) && longitud==2))
				{
					esFlotante = 0;
					break;
				}
			}
		}
		else
		{
			esFlotante = 0;
		}
	}
	else
	{
		esFlotante = 0;
	}

	return esFlotante;
}

 int ComprobarSiEsEntero (char datoIngresado[])
 {

	 int longitud;
	 int esEntero = 1;
	 longitud = strlen(datoIngresado);

	 if (isdigit(datoIngresado[0])||((datoIngresado[0] == '-' || datoIngresado[0] == '+') && longitud>1))
	 {
		 for(int i = 1; i < longitud; i++)
		 {
			if (!isdigit(datoIngresado[i]))
			{
				esEntero = 0;
				break;
			}
		 }
	 }
	 else
	 {
		 esEntero = 0;
	 }

	 return esEntero;
 }

 int ComprobarSiEsNombre (char datoIngresado[])
 {
	 int esNombre;
	 int longitud;

	 esNombre = 1;
	 longitud = strlen(datoIngresado);

	 if (isalpha(datoIngresado[0]) == 0|| isspace(datoIngresado[0]) || datoIngresado[0]== '\n' || isspace(datoIngresado[longitud-1]))
	{
		 esNombre = 0;
	}
	else
	{
		 for(int i = 1; i < longitud; i++)
		 {
			 if((isspace(datoIngresado[i]) && isspace(datoIngresado[i+1])) ||
				(isalpha(datoIngresado[i]) == 0 && isspace(datoIngresado[i])== 0))
			 {
				 esNombre = 0;
				 break;
			 }
		 }
	}


	 return esNombre;
 }


void ImprimirFlotante (char mensaje [], float flotanteParaImprimir)
{
	printf("%s %.2f", mensaje, flotanteParaImprimir);
}

void ImprimirEntero (char mensaje [], int enteroParaImprimir)
{
	printf("%s %d", mensaje, enteroParaImprimir);
}

void ImprimirCaracter (char mensaje [], char caracterParaImprimir)
{
	printf("%s %c", mensaje, caracterParaImprimir);
}

void ImprimirDosMensajes( int estado, char mensajeMenos1[], char mensajeCero[])
{
	if(estado == -1)
	{
		printf("%s", mensajeMenos1);
	}
	else
	{
		printf("%s", mensajeCero);
	}
}

/*void CargaSecuencialVectorDeEnteros (int vector[], int longitud, char mensaje[])
{
	for (int i = 0; i < longitud; i++)
		{
			vector[i] = PedirEntero(mensaje);
		}
}

void CargaSecuencialVectorDeFlotantes (float vector[], int longitud, char mensaje[])
{
	for (int i = 0; i < longitud; i++)
		{
			vector[i] = PedirFlotante(mensaje);
		}
}

void CargaAleatoriaVectorDeEnteros (int vector [], int longitud)
{
	char respuesta;
	int posicion;

	InicializarVectorDeEnteros(vector, longitud, 0);

	do
	{
		posicion = PedirEnteroEnRango("Ingrese la posicion en la que desea cargar.", 1, longitud);

		vector[posicion-1] = PedirEntero("Ingrese el valor para la posicion: ");

		respuesta = PedirCaracter("Desea ingresar otro numero? S/N: ");

	}while (respuesta == 'S');

}

void CargaAleatoriaVectorDeEnterosLimitada (int vector [], int longitud, int minimo, int maximo)
{
	char respuesta;
	int posicion;

	InicializarVectorDeEnteros(vector, longitud, 0);

	do
	{
		posicion = PedirEnteroEnRango("Ingrese la posicion en la que desea cargar.", 1, longitud);

		vector[posicion-1] = PedirEnteroEnRango("Ingrese el valor para la posicion: ", minimo, maximo);

		respuesta = PedirCaracter("Desea ingresar otro numero? S/N: ");

	}while (respuesta == 'S');

}

void InicializarVectorDeEnteros (int vector[], int longitud, int valorParaInicializar)
{
	for (int i = 0; i < longitud; i++)
	{
		 vector[i] = valorParaInicializar;
	}
}

void ImprimirVectorDeEnteros (int vector [], int longitud)
{
	for (int i = 0; i < longitud; i++)
		{
			 printf("\nPosicion %d: %d", i+1, vector[i]);
		}
}


double SumarDosNumeros (double A, double B)
{
	double resultadoSuma;

	resultadoSuma = A + B;

	return resultadoSuma;
}

double RestarDosNumeros (double A, double B)
{
	double resultadoResta;

	resultadoResta = A - B;

	return resultadoResta;
}

double DividirUnNumeroPorOtro (double A, double B)
{
	double resultadoDivision;

	resultadoDivision = A / B;

	return resultadoDivision;
}

double MultiplicarDosNumeros (double A, double B)
{
	double resultadoMultiplicacion;

	resultadoMultiplicacion = A * B;

	return resultadoMultiplicacion;
}

double CalcularFactorialDeUnNumero (double numero)
{
	double resultadoFactorial;
	int i;
	resultadoFactorial = 1;

	if (numero > 0)
	{
		for(i= numero; i > 0; i--)
		{
			resultadoFactorial *=  i;
		}
	}

	return resultadoFactorial;
}*/



