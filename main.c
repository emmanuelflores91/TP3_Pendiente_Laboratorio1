
#include "Controller.h"

int main()
{
	setbuf(stdout, NULL);
    int option;
    int cargaArchivo = -2;
    int flagAltaEmpleado = -3;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	if (ShowMenu(&option)== -1)
    	{
    		printf("\n No se pudo acceder.\n");
    		break;
    	}

        switch(option)
        {
            case 1: // CARGA TXT //////////////
            	system("cls");
            	if(cargaArchivo == -2 || cargaArchivo == -1)
            	{
            		cargaArchivo = controller_loadFromText("data.csv",listaEmpleados);
            		if (cargaArchivo == 0)
            		{
                		printf("\n Carga realizada.");
            		}
            		else
            		{
                		printf("\n Error en carga.");

            		}
            	}
            	else
            	{
            		printf("\n El archivo ya esta cargado.");
            	}

            break;

            case 2: // CARGA BIN //////////////
            	system("cls");

            	if(cargaArchivo == -2 || cargaArchivo == -1)
				{
                	cargaArchivo = controller_loadFromBinary("data.dat", listaEmpleados);
                	if (cargaArchivo == 0)
					{
                		printf("\n Carga realizada.");
					}
                	else
					{
						printf("\n Error en carga.");

					}
				}
				else
				{
					printf("\n EL archivo ya esta cargado.");
				}

            break;

            case 3:// ALTA //////////////
            	system("cls");

               flagAltaEmpleado = controller_addEmployee(listaEmpleados);
            break;

            case 4: // MODIFICACIÓN //////////////
            	system("cls");
            	if(cargaArchivo == 0 || flagAltaEmpleado == 0)
            	{
            		if(controller_editEmployee(listaEmpleados)== 0)
            		{
    					printf("\n Edición exitosa.");
            		}
            		else
            		{
    					printf("\n Los datos no fueron editados.");
            		}
            	}
            	else
            	{
					printf("\n No hay cargas realizadas.");
            	}
            break;

            case 5: // BAJA //////////////
            	system("cls");
            	if(cargaArchivo == 0 || flagAltaEmpleado == 0)
				{
                	if(controller_removeEmployee(listaEmpleados)==0)
                	{
    					printf("\n Empleado eliminado.");
                	}
                	else
                	{
    					printf("\n Error en baja.");

                	}
				}
				else
				{
					printf("\n No hay cargas realizadas.");
				}
            break;

            case 6: // IMPRIMIR //////////////
            	system("cls");
            	if(cargaArchivo == 0 || flagAltaEmpleado == 0)
				{
                	controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("\n No hay cargas realizadas.");
				}
            break;

            case 7: // ORDENAR //////////////
            	system("cls");
            	if(cargaArchivo == 0 || flagAltaEmpleado == 0)
				{
                	if(controller_sortEmployee(listaEmpleados)==0)
                	{
    					printf("\n Lista ordenada.");

                	}
                	else
                	{
    					printf("\n Error en ordenamiento.");
                	}
				}
				else
				{
					printf("\n No hay cargas realizadas.");
				}
            break;

            case 8: // GUARDAR TXT //////////////
            	system("cls");
            	if(cargaArchivo == 0)
				{
            		if(	controller_saveAsText("data.csv", listaEmpleados)== 0 &&

            			controller_saveAsBinary("data.dat", listaEmpleados)== 0)
            		{
    					printf("\n Archivos guardados.");
            		}
				}
				else
				{
					printf("\n No hay cargas realizadas.");
				}

            break;

            case 9: // GUARDAR BIN //////////////
            	system("cls");
            	if(cargaArchivo == 0)
				{
            		if(	controller_saveAsText("data.csv", listaEmpleados)== 0 &&

            			controller_saveAsBinary("data.dat", listaEmpleados)==0)
            		{
            			printf("\n Archivos guardados.");
            		}
				}
				else
				{
					printf("\n No hay cargas realizadas.");
				}

            break;
        }

    }while(option != 10);

    BorrarEmpleados(listaEmpleados);

    ll_deleteLinkedList(listaEmpleados);

    system("pause");

    return 0;
}



