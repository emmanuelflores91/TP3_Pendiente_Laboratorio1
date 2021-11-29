
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Employee.h"
#include "LinkedList.h"
#include "myFunctions.h"
#include "Parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/// @brief muestra el menú de opciones
///
/// @param opcion = las opciones permitidas para ingresar
/// @return -1 en caso de error; 0 en caso de éxito
int ShowMenu (int* opcion );

/// @brief lee el último ID de un archivo y lo aumenta en uno
///
/// @param NewID= el Id disponible para utilizar
/// @return -1 en caso de error; 0 en caso de éxito
int NewID(char* NewID);

/// @brief guarda en un archivo el último ID utilizado
///
/// @param newID = el ID a escribir en el archivo
/// @return -1 en caso de error; 0 en caso de éxito
int SaveNewID(char* newID);

/// @brief recorre la lista y borra cada empleado
///
/// @param listaEmpleados
void BorrarEmpleados (LinkedList* listaEmpleados);

/// @brief busca un empleado por ID y retorna su posición en la lista
///
/// @param pArrayListEmployee = la lista de empleados
/// @param idBuscado = el ID deseado
/// @return -1 en caso de error; index del empleado en caso de éxito
int ObtenerEmpleadoPorID (LinkedList* pArrayListEmployee, int idBuscado);







#endif // controller_H_INCLUDED
