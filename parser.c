#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char id[12];
	char nombre[128];
	char horasTrabajadas[12];
	char sueldo[12];
	int estado;
	Employee* pEmpleado = NULL;
	estado = -1;

	fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",id, nombre, horasTrabajadas, sueldo);

	while (!feof(pFile))
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",id, nombre, horasTrabajadas, sueldo);

		pEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

		if (pEmpleado != NULL &&
			ComprobarSiEsEntero(id) &&
			ComprobarSiEsNombre(nombre) &&
			ComprobarSiEsEntero(horasTrabajadas) &&
			ComprobarSiEsFlotante(sueldo))
		{
			if(ll_add(pArrayListEmployee, pEmpleado)== 0)
			{
				estado = 0;
			}
			else
			{
				employee_delete(pEmpleado);
			}
		}
	}

    return estado;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int estado;
	estado = -1;
	Employee* pEmpleado = NULL;

	while(!feof(pFile))
	{
		pEmpleado = employee_new();

		if (pEmpleado != NULL &&
			fread(pEmpleado, sizeof(Employee), 1, pFile)==1 &&
			ll_add(pArrayListEmployee, pEmpleado) == 0)
		{
			estado = 0;
		}
		else
		{
			employee_delete(pEmpleado);
		}
	}



    return estado;
}


