#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "cmpEmp.h"
#include "pntmenu.h"
#include "valib.h"
#include "thingSGFTBin.h"

/****************************************************
    printf("ABM Menu:\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");

    1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
del mismo.
2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de las bicicletas.
3) Asignar tiempos: Se deberá hacer uso de la función map. la cual recibirá el linkedlist y una
función que asignará a la bicicleta un valor de tiempo entre 50 y 120 minutos calculado de
manera aleatoria se mostrará por pantalla el mismo.
4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan
bicicletas del tipo seleccionado.
5) Mostrar posiciones: Se deberá mostrar por pantalla un listado de las bicicletas ordenadas
por tipo y dentro de las del mismo tipo que aparezcan ordenadas por tiempo ascendente.
6) Guardar posiciones: Se deberá guardar el listado del punto anterior en un archivo de texto.
7) Salir.
*****************************************************/


//

int print_mainMenu();
int print_sortMenu();

int main()
{
    int option = 0, dataLoaded = 0, dataSaved=1, changesMade = 0;
    char lastChance;
    LinkedList* listaEmpleados = ll_newLinkedList();
    srand(time(NULL));
    do{
        option=print_mainMenu();
        switch(option)
        {
            case 1:
                if(!dataLoaded)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    dataLoaded = 1;
                }
                else
                {
                    printf("ERROR! Ya se han cargado los datos en memoria\n");
                }
                break;
            case 2:
                if(!dataLoaded)
                {
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    dataLoaded = 1;
                }
                else
                {
                    printf("ERROR! Ya se han cargado los datos en memoria\n");
                }
                break;
            case 3:
                if(dataLoaded)
                {
                    if(!changesMade)
                    {
                        changesMade = 1;
                        dataSaved = 0;
                    }
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("ERROR! No se puede acceder a esta opcion sin antes cargar los datos de un documento\n");
                }
                break;
            case 4:
                if(dataLoaded)
                {
                    if(!changesMade)
                    {
                        changesMade = 1;
                        dataSaved = 0;
                    }
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("ERROR! No se puede acceder a esta opcion sin antes cargar los datos de un documento\n");
                }
                break;
            case 5:

                if(dataLoaded)
                {
                    if(!changesMade)
                    {
                        changesMade = 1;
                        dataSaved = 0;
                    }
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("ERROR! No se puede acceder a esta opcion sin antes cargar los datos de un documento\n");
                }
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                if(dataLoaded)
                {
                    controller_sortEmployee(listaEmpleados);
                    if(!changesMade)
                    {
                        changesMade = 1;
                        dataSaved = 0;
                    }
                }
                else
                {
                    printf("ERROR! No se puede acceder a esta opcion sin antes cargar los datos de un documento\n");
                }
                break;
            case 8:
                if(dataLoaded)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    if (!dataSaved)
                    {
                        dataSaved=1;
                    }
                    changesMade=0;
                    nextID(1);
                }
                else
                {
                    printf("ERROR! No se puede acceder a esta opcion sin antes cargar los datos de un documento\n");
                }
                break;
            case 9:
                if(dataLoaded)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    if (!dataSaved)
                    {
                        dataSaved=1;
                    }
                    changesMade=0;
                    nextID(1);
                }
                else
                {
                    printf("ERROR! No se puede acceder a esta opcion sin antes cargar los datos de un documento\n");
                }
                break;
            case 10:
                if(dataLoaded)
                {
                    if(dataSaved&&changesMade)
                    {
                        printf("Cerrando Programa\n");
                    }
                    else if(!dataSaved&&changesMade)
                    {
                        printf("ADVERTENCIA. Esta por cerrar el programa sin guardar los cambios\n");
                        printf("realizados. Desea guardar los cambios? (S/N)\n");
                        printf("Opcion: ");
                        scanf("%c",&lastChance);
                        fflush(stdin);
                        if(lastChance=='s'||lastChance=='S')
                        {
                            controller_saveAsText("data.csv",listaEmpleados);
                            controller_saveAsBinary("data.bin",listaEmpleados);
                            printf("Cerrando Programa, cambios guardados\n");
                            nextID(1);
                        }
                        else
                        {
                            printf("Cerrando Programa, sin guardar los cambios\n");
                            nextID(-1);
                        }
                    }
                }
                printf("Hasta Luego!\n");
                break;
            default:
                if(dataLoaded&&changesMade)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    nextID(1);
                }
                break;
        }
        system("pause");
    }while(option != 10);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

int getRandom(int max, int min)
{
    int rnd;
    rnd=rand()% max + min;
    return rnd;
}
