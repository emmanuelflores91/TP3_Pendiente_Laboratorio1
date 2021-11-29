#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	pFile = fopen(path,"r");
	int estado;
	estado = -1;

	if (pFile != NULL && parser_EmployeeFromText(pFile, pArrayListEmployee)!= -1)
	{
		estado = 0;
	}

	fclose(pFile);

    return estado;
}

int NewID(char* NewID)
{
	int estado;
	char idLeidoChar[12];
	int idLeidoInt;

	FILE* pFile;
	estado = -1;

	pFile = fopen ("lastID.txt","r");

	if (NewID != NULL && pFile != NULL)
	{
		fgets(idLeidoChar,sizeof(idLeidoChar),pFile);

		idLeidoInt = atoi(idLeidoChar);

		idLeidoInt ++;

		itoa(idLeidoInt, NewID, 10);

		estado = 0;
	}

	fclose(pFile);

	return estado;
}

int SaveNewID(char* newID)
{
	int estado;

	FILE* pFile;
	estado = -1;

	pFile = fopen("lastID.txt", "w");

	if (pFile != NULL && newID != NULL)
	{
		fprintf(pFile, "%s", newID);

		estado = 0;
	}

	fclose(pFile);

	return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int estado;
	FILE* pFile;

	estado = -1;

	pFile = fopen(path,"rb");

	if (pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee)==0)
	{
		estado = 0;
	}

	fclose(pFile);

    return estado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int estado;

	char id[12];
	char nombre[128];
	char horasTrabajadas[12];
	char sueldo[12];

	Employee* pEmpleado;

	pEmpleado = NULL;
	estado = -2;

		if (pArrayListEmployee != NULL && PedirDatosEmpleados(nombre, sizeof(nombre), horasTrabajadas, sueldo) == 0 && NewID(id)== 0)
		{
			pEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			if (pEmpleado != NULL)
			{
				estado = -1;
				if(ll_add(pArrayListEmployee, pEmpleado)==0)
				{
					SaveNewID(id);
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

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int estado;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int opcion;
	int idBuscado;
	int indexEmpleadoBuscado;
	estado = -1;

	Employee* pEmpleado = NULL;



	controller_ListEmployee(pArrayListEmployee);

	if(PedirEnteroPositivo(&idBuscado, "\n Ingrese el ID del empleado a editar: ",
						  "\n Datos erroneos.", 2) == 0)
	{

		indexEmpleadoBuscado = ObtenerEmpleadoPorID(pArrayListEmployee, idBuscado);

		pEmpleado = (Employee*) ll_get(pArrayListEmployee, indexEmpleadoBuscado);


		PedirEnteroEnRango(&opcion, "\n 1 - Editar nombre."
									"\n 2 - Editar horas trabajadas."
									"\n 3 - Editar Sueldo."
									"\n 4 - Cancelar."
									"\n\n Ingrese la opcion que desea editar: ",
									"\n Datos erroneos.", 1, 4, 2);
		switch (opcion)
		{

			case 1:
				if (PedirNombre("\n Ingrese el nombre (maximo 128 caracteres): ", "\n Datos erroneos.", nombre, sizeof(nombre), 2) == 0 )
				{
					estado = employee_setNombre(pEmpleado, nombre);
				}

			break;

			case 2:
				if (PedirEnteroEnRango(&horasTrabajadas, "\n Ingrese la cantidad horas (entre 0 y 300 hs): ", "\n Datos erroneos.", 0, 300, 2) == 0)
				{
					estado = employee_setHorasTrabajadas(pEmpleado, horasTrabajadas);
				}
			break;

			case 3:
				if (PedirEnteroEnRango(&sueldo, "\n Ingrese el sueldo (entre $25.000 y $350.000): ", "\n Datos erroneos.", 25000, 350000, 2) == 0)
				{
					estado = employee_setSueldo(pEmpleado, sueldo);
				}

			break;

		}
	}

    return estado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int estado;
	int idBuscado;
	int indexEmpleadoBuscado;
	char respuesta[2];
	Employee* pEmpleado;

	estado = -1;

	controller_ListEmployee(pArrayListEmployee);

	if(PedirEnteroPositivo(&idBuscado, "\n Ingrese el ID del empleado a eliminar: ",
						  "\n Datos erroneos.", 2) == 0)
	{
		indexEmpleadoBuscado = ObtenerEmpleadoPorID(pArrayListEmployee, idBuscado);

		if (indexEmpleadoBuscado!=-1)
		{
			pEmpleado = ll_get(pArrayListEmployee, indexEmpleadoBuscado);

			if (pEmpleado != NULL &&
				PedirCadena("\n Seguro desea eliminar el empleado?\n Ingrese S para confirmar: ", "", respuesta, sizeof(respuesta), 2) == 0 &&
				stricmp(respuesta,"S") == 0)
			{
				ll_remove(pArrayListEmployee, indexEmpleadoBuscado);

				employee_delete(pEmpleado);

				estado = 0;
			}
		}
	}

    return estado;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int estado;
	int len;
	Employee* pEmpleado;

	estado = -1;
	len = ll_len(pArrayListEmployee);

	for(int i = 0; i< len; i++)
	{
		pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

		printOneEmployee(pEmpleado);
	}
    return estado;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int estado;
	int opcion;
	int criterioOrden;

	estado = -1;

	if(PedirEnteroEnRango(&opcion, "\n Por cual campo desea ordenar?"
								"\n 1 - ID."
								"\n 2 - Nombre."
								"\n 3 - Horas trabajadas."
								"\n 4 - Sueldo."
								"\n Ingrese una opcion: ", "\n Datos erroneos.", 1, 4, 2) == 0)
	{

		if(PedirEnteroEnRango(&criterioOrden,	"\n Seleccione criterio de orden."
											"\n 0 - Descendente."
											"\n 1 - Ascendente."
											"\n Ingrese una opcion: ", "\n Datos erroneos.", 0, 1, 2)==0)

		{
			printf("\n Orden en proceso...");

			switch (opcion)
			{
				case 1:
					estado = ll_sort(pArrayListEmployee, IdCompare, criterioOrden);
				break;

				case 2:
					estado = ll_sort(pArrayListEmployee, NameCompare, criterioOrden);
				break;

				case 3:
					estado = ll_sort(pArrayListEmployee, HourCompare, criterioOrden);
				break;

				case 4:
					estado = ll_sort(pArrayListEmployee, SalaryCompare, criterioOrden);
				break;
			}
		}
	}
    return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int estado;
	int len;
	int idAux;
	char nombreAux[128];
	int horasAux;
	int sueldoAux;
	Employee* pEmpleado;

	estado = -1;
	pFile = fopen(path,"w");

	len = ll_len(pArrayListEmployee);

	if (pFile != NULL)
	{
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

		for (int i = 0; i < len; i++)
		{

			pEmpleado = ll_get(pArrayListEmployee, i);

			employee_getId(pEmpleado, &idAux);

			employee_getNombre(pEmpleado, nombreAux);

			employee_getHorasTrabajadas(pEmpleado, &horasAux);

			employee_getSueldo(pEmpleado, &sueldoAux);

			fprintf(pFile, "%d,%s,%d,%d\n", idAux, nombreAux, horasAux, sueldoAux);
		}
		estado = 0;
	}

	fclose(pFile);

	return estado;
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int estado;
	int len;
	Employee* pEmpleado;
	FILE* pFile;

	estado = -1;

	pFile = fopen(path,"wb");

	if (pFile != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(int i = 0; i<len; i++)
		{
			pEmpleado = ll_get(pArrayListEmployee, i);

			fwrite(pEmpleado, sizeof(Employee), 1, pFile);
		}

		estado = 0;
	}

	fclose(pFile);

    return estado;
}

int ShowMenu (int* opcion )
{
	int estado;
	estado = -1;

	printf("\n.......................................................\n");
	printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
			" 2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).\n"
			" 3. Alta de empleado.\n"
			" 4. Modificar datos de empleado.\n"
			" 5. Baja de empleado.\n"
			" 6. Listar empleados.\n"
			" 7. Ordenar empleados.\n"
			" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
			" 9. Guardar los datos de los empleados en el archivo data.dat (modo binario).\n"
			" 10. Salir");
	printf("\n.......................................................\n");

	if(PedirEnteroEnRango(opcion, "\n Ingrese opcion deseada: ", "\n Datos erroneos.", 1, 10, 2)== 0)
	{
		estado = 0;
	}

	return estado;
}

int ObtenerEmpleadoPorID (LinkedList* pArrayListEmployee, int idBuscado)
{
	 int idEncontrado;
	 idEncontrado =-1;
	 int idObtenido;
	 int len;

	 Employee* pEmpleado;

	 len = ll_len(pArrayListEmployee);

	 for(int i = 0; i < len; i ++)
	 {
		pEmpleado = ll_get(pArrayListEmployee, i);

		if(pEmpleado != NULL)
		{
			employee_getId(pEmpleado, &idObtenido);

			if(idBuscado == idObtenido)
			{
				idEncontrado = i;
				break;
			}
		}
	 }
	 return idEncontrado;
}

void BorrarEmpleados (LinkedList* listaEmpleados)
{
	if(listaEmpleados != NULL)
	{
		for (int i = 0; i < ll_len(listaEmpleados); i++)
		{
			ll_remove(listaEmpleados, i);
		}
	}
}



