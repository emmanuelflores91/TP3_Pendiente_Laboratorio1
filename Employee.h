#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// @brief constructor por defecto de empleado
///
/// @return = puntero el empleado por defecto
Employee* employee_new();

/// @brief constructor parametrizado de empleado
///
/// @param idStr = ID del empleado
/// @param nombreStr = Nombre del empleado
/// @param horasTrabajadasStr = cantidad de horas trabajadas
/// @param sueldo = sueldo del empleado
/// @return = puntero el empleado
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/// @brief borra un empleado
///
/// @param this = el empleado a borrar
void employee_delete(Employee* this);

/// @brief asignar ID de un empleado
///
/// @param this = el empleado
/// @param id
/// @return -1 en caso de error, 0 en caso de éxito
int employee_setId(Employee* this,int id);

/// @brief obtiente el ID de un empleado
///
/// @param this = el empleado
/// @param id
/// @return -1 en caso de error, 0 en caso de éxito
int employee_getId(Employee* this,int* id);

/// @brief asignar nombre de un empleado
///
/// @param this = el empleado
/// @param nombre
/// @return -1 en caso de error, 0 en caso de éxito
int employee_setNombre(Employee* this,char* nombre);

/// @brief obtener nombre de un empleado
///
/// @param this = el empleado
/// @param nombre
/// @return -1 en caso de error, 0 en caso de éxito
int employee_getNombre(Employee* this,char* nombre);

/// @brief asignar horas de un empleado
///
/// @param this = el empleado
/// @param horasTrabajadas
/// @return -1 en caso de error, 0 en caso de éxito
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// @brief obtener horas de un empleado
///
/// @param this = el empleado
/// @param horasTrabajadas
/// @return -1 en caso de error, 0 en caso de éxito
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// @brief asignar sueldo de un empleado
///
/// @param this = el empleado
/// @param sueldo
/// @return -1 en caso de error, 0 en caso de éxito
int employee_setSueldo(Employee* this,int sueldo);

/// @brief obtener sueldo de un empleado
///
/// @param this = el empleado
/// @param sueldo
/// @return -1 en caso de error, 0 en caso de éxito
int employee_getSueldo(Employee* this,int* sueldo);

/// @brief imprime los datos de un empleado
///
/// @param empleado
/// @return -1 en caso de error, 0 en caso de éxito
int printOneEmployee (Employee* empleado);

/// @brief compara dos ID y determina cuál es mayor
///
/// @param empleadoA
/// @param empleadoB
/// @return 0 = son iguales; 1 = ID1 > ID2; -1 ID1 < ID2
int IdCompare (void* empleadoA, void* empleadoB);

/// @brief compara dos nombres y determina cuál es mayor
///
/// @param empleadoA
/// @param empleadoB
/// @return 0 = son iguales; 1 = nombre1 > nombre2; -1 nombre1 < nombre2
int NameCompare (void* empleadoA, void* empleadoB);

/// @brief compara dos horas y determina cuál es mayor
///
/// @param empleadoA
/// @param empleadoB
/// @return 0 = son iguales; 1 = Horas1 > Horas2; -1 Horas1 < Horas2
int HourCompare (void* empleadoA, void* empleadoB);

/// @brief compara dos sueldos y determina cuál es mayor
///
/// @param empleadoA
/// @param empleadoB
/// @return 0 = son iguales; 1 = sueldo1 > sueldo2; -1 sueldo1 < sueldo2
int SalaryCompare (void* empleadoA, void* empleadoB);

/// @brief pide al usuario, todos los datos del empleado
///
/// @param nombre
/// @param tamNombre
/// @param horas
/// @param sueldo
/// @return -1 en caso de error, 0 en caso de éxito
int PedirDatosEmpleados (char nombre[], int tamNombre, char horas[], char sueldo[]);

/// @brief pide un nombre y verifica que el dato ingresado tenga el formato correcto de un nombre
///
/// @param mensaje = mensaje para pedir nombre
/// @param mensajeError = mensaje al cargar un dato erroneo
/// @param cadena = la variable donde se almacena el nombre
/// @param longitud = el largo de la cadena nombre
/// @param reintentos = la cantidad de veces que se puede volver a intentar el ingreso
/// @return -1 en caso de error; 0 en caso de exito.
int PedirNombre (char* mensaje, char* mensajeError, char* cadena, int longitud, int reintentos);











#endif // employee_H_INCLUDED
