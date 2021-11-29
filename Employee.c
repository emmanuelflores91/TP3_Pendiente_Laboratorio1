#include "Controller.h"

Employee* employee_new()
{
	Employee* defaultEmployee;

	defaultEmployee = (Employee*) malloc (sizeof(Employee));


	if (defaultEmployee != NULL)
	{
		employee_setId(defaultEmployee,0);
		employee_setNombre(defaultEmployee, "\0");
		employee_setHorasTrabajadas(defaultEmployee, 0);
		employee_setSueldo(defaultEmployee, 0);
	}

	return defaultEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
	Employee* oneEmployee;

	oneEmployee = employee_new();

	if (oneEmployee != NULL)
	{
		employee_setId(oneEmployee, atoi(idStr));
		employee_setNombre(oneEmployee, nombreStr);
		employee_setHorasTrabajadas(oneEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(oneEmployee, atoi(sueldo));
	}

	return oneEmployee;
}



int employee_setId(Employee* this, int id)
{
	int estado;
	estado = -1;

	if(this != NULL)
	{
		this->id = id;
		estado = 0;
	}

	return estado;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int estado;
	estado = -1;

	if (this != NULL)
	{
		strcpy(this->nombre, nombre);
		estado = 0;
	}

	return estado;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int estado;
	estado = -1;

	if (this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		estado = 0;
	}

	return estado;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int estado;
	estado = -1;

	if (this != NULL)
	{
		this->sueldo = sueldo;
		estado = 0;
	}

	return estado;
}

int employee_getId(Employee* this,int* id)
{
	int estado;
	estado = -1;

	if (this != NULL)
	{
		*id = this->id;
		estado = 0;
	}

	return estado;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int estado;
	estado = -1;

	if (this != NULL)
	{
		strcpy(nombre, this->nombre);
		estado = 0;
	}

	return estado;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int estado;
	estado = -1;

	if (this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		estado = 0;
	}

	return estado;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int estado;
	estado = -1;

	if (this != NULL)
	{
		*sueldo = this->sueldo;
		estado = 0;
	}

	return estado;

}

int printOneEmployee (Employee* empleado)
{
	int estado;
	estado = -1;

	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if (empleado != NULL &&
		employee_getId(empleado, &id) == 0 &&
		employee_getNombre(empleado, nombre) == 0 &&
		employee_getHorasTrabajadas(empleado, &horasTrabajadas) == 0 &&
		employee_getSueldo(empleado, &sueldo) == 0)
	{
		printf("\n %-8d %-20s %-8d    $ %d",id, nombre, horasTrabajadas, sueldo);
		estado = 0;
	}

	return estado;

}

void employee_delete(Employee* this)
{
	if (this != NULL)
	{
		free(this);
	}
}

int HourCompare (void* empleadoA, void* empleadoB)
{
	int estado;
	estado = 0;
	Employee* empleado1 = NULL;
	Employee* empleado2 = NULL;
	int horas1;
	int horas2;


	empleado1 = (Employee*) empleadoA;

	empleado2 = (Employee*) empleadoB;

	employee_getHorasTrabajadas(empleado1, &horas1);

	employee_getHorasTrabajadas(empleado2, &horas2);

	if (horas1 > horas2)
	{
		estado = 1;
	}
	else if ( horas2 > horas1)
	{
		estado = -1;
	}

	return estado;

}

int SalaryCompare (void* empleadoA, void* empleadoB)
{
	int estado;
	estado = 0;
	Employee* empleado1 = NULL;
	Employee* empleado2 = NULL;
	int sueldo1;
	int sueldo2;


	empleado1 = (Employee*) empleadoA;

	empleado2 = (Employee*) empleadoB;

	employee_getSueldo(empleado1, &sueldo1);

	employee_getSueldo(empleado2, &sueldo2);

	if (sueldo1 > sueldo2)
	{
		estado = 1;
	}
	else if ( sueldo2 > sueldo1)
	{
		estado = -1;
	}

	return estado;

}

int IdCompare (void* empleadoA, void* empleadoB)
{
	int estado;
	estado = 0;
	Employee* empleado1 = NULL;
	Employee* empleado2 = NULL;
	int id1;
	int id2;

	empleado1 = (Employee*) empleadoA;

	empleado2 = (Employee*) empleadoB;

	employee_getId(empleado1, &id1);

	employee_getId(empleado2, &id2);

	if (id1 > id2)
	{
		estado = 1;
	}
	else if ( id2 > id1)
	{
		estado = -1;
	}

	return estado;

}

int NameCompare (void* empleadoA, void* empleadoB)
{
	int estado;
	estado = 0;
	Employee* empleado1 = NULL;
	Employee* empleado2 = NULL;
	char name1[128];
	char name2[128];

	empleado1 = (Employee*) empleadoA;

	empleado2 = (Employee*) empleadoB;

	employee_getNombre(empleado1, name1);

	employee_getNombre(empleado2, name2);

	estado = stricmp(name1, name2);

	return estado;
}

int PedirDatosEmpleados (char nombre[], int tamNombre, char horas[], char sueldo[])
{
	int estado;
	estado = -1;

	int horasInt = 0;
	int sueldoInt = 0;

	if (PedirNombre("\n Ingrese el nombre (maximo 128 caracteres): ", "\n Datos erroneos.", nombre, tamNombre, 2) == 0 &&

		PedirEnteroEnRango(&horasInt, "\n Ingrese la cantidad horas (entre 0 y 300 hs): ", "\n Datos erroneos.", 0, 300, 2) == 0 &&

		PedirEnteroEnRango(&sueldoInt, "\n Ingrese el sueldo (entre $25.000 y $350.000): ", "\n Datos erroneos.", 25000, 350000, 2) == 0 )
		{
			itoa(horasInt, horas, 10);

			itoa(sueldoInt, sueldo, 10);

			estado = 0;
		}

	return estado;
}

int PedirNombre (char* mensaje, char* mensajeError, char* cadena, int longitud, int reintentos)
{
	int estado;
	estado = -1;

	do
	{
		if (PedirCadena(mensaje, mensajeError, cadena, longitud, reintentos) == 0 &&
			ComprobarSiEsNombre(cadena)==1)
		{
			estado = 0;
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos >=0);

	return estado;

}













