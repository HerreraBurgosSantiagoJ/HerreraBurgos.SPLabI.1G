/*1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
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
*/

#include "../Heathers/sBike.h"
#include "../Heathers/LinkedList.h"
#include "../Heathers/steart.h"

int ctlr_load(LinkedList* this)
{
    char source[120], buffer[4][129];
    int isError = 1, scnVls,trys=3;
    sBike* auxBike;
    progHeader("Adm. de Datos carrera de bicicletas");//My head was fumming by this time
    subHeader("Cargar Datos");
    do{
        if(trys<3)
        {
            printf("\nERROR: La fuente ingresada no es valida, o el archivo no existe");
            printf("\n%d intentos restantes",trys);
        }
        printf("\nIngrese la ubicacion desde donde desa cargar los datos(D:carpeta/carpeta2/archivo.extencion)\nFuente: ");
        myFgets(source,120);
        FILE* file = fopen(source,"r");
        trys--;
    }while(file==NULL&&trys>0)
    if(file!=NULL)
    {
        while(!feof(file))
        {
            scnVls=fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(scnVls==4)
            {
                auxBike=bike_newEmpty();
                bike_setId(auxBike,atoi(buffer[0]));
                bike_setNme(auxBike,buffer[1])
                bike_setTpe(auxBike,buffer[2]);
                bike_setTme(auxBike,buffer[3]);
                isError=ll_add(this,auxBike);
                if(isError==-1)
                {
                    isError=1;
                    break;
                }
            }
        }
        if(isError)
        {
            printf("ERROR! No se pudo cargar los datos del documento, es posible que\n");
            printf("el documento no exista, este dañado o no contenga datos.\n");
        }
        else
        {
            printf("Datos cargados.\n");
        }
        fclose(file);
    }
}

int ctlr_showList(LinkedList* this)
{
    int length,isError = 1;
    sBike* auxBike;
    length = ll_len(this);
    progHeader("Adm. de Datos carrera de bicicletas");//My head was fumming by this time
    subHeader("Mostrar Datos");
    if (length>0)
    {
        printf("  ID           Corredor            Tipo  Tiempo'\n");
        printf("------------------------------------------------------\n");
        for(int i=0; i<length; i++)
        {
            auxBike = (sBike*) ll_get(this,i);
            bike_show(auxBike);
        }
        isError=0;
    }
    else
    {
        printf("\nNo hay corredores para mostrar. Carguelos desde un documento.\n");
    }
    return isError;
}

int ctlr_setRndTimes(LinkedList* this, int (*pFunc)(void*))
int ctlr_fillterType(LinkedList* this)
{
    ll_fillter()
}
int ctlr_sortTypeShowPositions(LinkedList* this)
int ctlr_save(LinkedList* this)
