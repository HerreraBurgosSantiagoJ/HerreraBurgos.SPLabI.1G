#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "pntmenu.h"
#include "steart.h"
#include "utn.h"
#include "string.h"

int controller_ListEmployee(LinkedList* pArrayListEmployee);
int my_ll_indexOfId(LinkedList* this, int id)
{
    int length, notError = -1;
    Employee* auxEmp;
    length=ll_len(this);
    for(int i=0; i<length; i++)
    {
        auxEmp = ll_get(this,i);
        if (auxEmp->id==id)
        {
            notError = i;
        }
    }
    free(auxEmp);
    return notError;
}

int nextID(int saving)
{
    int nxID, lastID, returner=-1;
    FILE* next = fopen("nextID.bin","rb");
    if(saving!=-1)
    {
        if(saving)
        {
            if (next!=NULL)
            {
                fread(&nxID,sizeof(int),1,next);
                if (nxID!=0)
                {
                    lastID=nxID-1;
                }
                returner = 0;
            }
        }
        else
        {
            if (next!=NULL)
            {
                fread(&nxID,sizeof(int),1,next);
                if (nxID!=0)
                {
                    returner=nxID;
                }
                fread(&lastID,sizeof(int),1,next);
                nxID++;
            }
        }
    }
    else
    {
        if (next!=NULL)
        {
            fread(&nxID,sizeof(int),1,next);
            fread(&lastID,sizeof(int),1,next);
            nxID=lastID+1;
        }
    }
    fclose(next);
    next = fopen("nextID.bin","wb");
    fwrite(&nxID,sizeof(int),1,next);
    fwrite(&lastID,sizeof(int),1,next);
    fclose(next);
    return returner;
}

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    char buffer[4][129];
    int isError = 1, scnVls;
    Employee* auxEmp;
    FILE* txtFile;
    txtFile = fopen(path,"r");
    while(!feof(txtFile))
    {
        scnVls=fscanf(txtFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(scnVls==4)
        {
            auxEmp=employee_new();
            auxEmp->id=atoi(buffer[0]);
            strcpy(auxEmp->nombre,buffer[1]);
            auxEmp->horasTrabajadas=atoi(buffer[2]);
            auxEmp->sueldo=atoi(buffer[3]);
            ll_add(pArrayListEmployee,auxEmp);
            isError=0;
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
    fclose(txtFile);
    return isError;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int isError = 1;
    Employee* auxEmp;
    FILE* binFile;
    binFile = fopen(path,"rb");
    while(!feof(binFile))
    {
        auxEmp=employee_new();
        fread(auxEmp,sizeof(Employee),1,binFile);
        if(auxEmp->id!=0)
        {
            ll_add(pArrayListEmployee,auxEmp);
            isError=0;
        }
    }
    if(isError)
    {
        printf("ERROR! No se pudo cargar los datos del documento, es posible que\n");
        printf("el documento no exista o este dañado.\n");
    }
    else
    {
        printf("Datos cargados.\n");
    }
    fclose(binFile);

    return isError;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int isError=1;
    char temp[12]="el empleado\0";
    Employee* newEmp = employee_new();
    progHeader("Recursos Humanos: Administracion");
    subHeader("Alta Empleado");
    if(newEmp!=NULL)
    {
        newEmp->id=nextID(0);
        printf("\nEl ID del nuevo empleado sera: %d\n",newEmp->id);
        getName(newEmp->nombre,temp,128);
        printf("Ingrese las horas trabajadas por el empleado: ");
        scanf("%d",&newEmp->horasTrabajadas);
        fflush(stdin);
        printf("Ingrese el sueldo del empleado: ");
        scanf("%d",&newEmp->sueldo);
        fflush(stdin);
        isError=ll_add(pArrayListEmployee,newEmp);
        if(isError)
        {
            printf("ERROR! No se pudo conseguir memoria.\n");
        }
        else
        {
            printf("Empleado implementado con exito.\nRecuerde guardar los cambios antes de cerrar el programa\n");
        }
        free(newEmp);
    }
    else
    {
        printf("ERROR! No se pudo conseguir memoria.\n");
    }
    return isError;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int isError=1, id, index, choice=6, wkdHours, salary;
    char doubt,options[4]="SsNn",temp[12]="el empleado\0";
    Employee* auxEmp;
    do{
        do{
            auxEmp = employee_new();
            progHeader("Recursos Humanos: Administracion");
            subHeader("Modificar Empleado");
            controller_ListEmployee(pArrayListEmployee);
            getInt(&id,"Ingrese el ID del empleado que desea modificar: ");
            index = my_ll_indexOfId(pArrayListEmployee,id);
            if(id!=-1)
            {
                progHeader("Recursos Humanos: Administracion");
                subHeader("Modificar Empleado");
                auxEmp = (Employee*) ll_get(pArrayListEmployee,index);
                printf("\n  ID           Nombre             Hrs Trabajo  Sueldo\n");
                printf("------------------------------------------------------\n");
                employee_show(auxEmp);
                getChar(&doubt,"Es este el empleado que desea Modificar? (s/n): ","Lo ingresado no es un caracter/opcion valida\n",options);
            }
        }while(doubt!='s'&&doubt!='S');
        do{
            choice = print_modifyMenu(auxEmp);
            switch (choice)
            {
                case 1:
                    getName(auxEmp->nombre,temp,128);
                    break;
                case 2:
                    do{
                        getInt(&wkdHours,"Ingrese la cantidad de horas trabajadas que desea AGREGAR: ");
                    }while(wkdHours<1);
                    auxEmp->horasTrabajadas+=wkdHours;
                    break;
                case 3:
                    getInt(&salary,"Ingrese la cantidad de dinero que desea agregar/sustraer(+/-) del sueldo del empleado: ");
                    auxEmp->sueldo+=salary;
                    break;
                case 5:
                    printf("Regresando al Menu Principal\n");
                    break;
            }
            isError=0;
        }while(choice!=4&&choice!=5);
    }while(choice!=5);
    return isError;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int isError=1,id,index;
    char doubt,options[4]="SsNn";
    Employee* auxEmp;
    do{
        progHeader("Recursos Humanos: Administracion");
        subHeader("Baja Empleado");
        controller_ListEmployee(pArrayListEmployee);
        getInt(&id,"Ingrese el ID del empleado al que desea dar de baja: ");
        index = my_ll_indexOfId(pArrayListEmployee,id);
        if(id!=-1)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee,index);
            printf("  ID           Nombre             Hrs Trabajo  Sueldo\n");
            printf("------------------------------------------------------\n");
            employee_show(auxEmp);
            getChar(&doubt,"Es este el empleado que desea borrar? (s/n): ","Lo ingresado no es un caracter/opcion valida",options);
            if(doubt=='s'||doubt=='S')
            {
                ll_remove(pArrayListEmployee,index);
                isError=0;
            }
        }
    }while(doubt!='s'&&doubt!='S');
    free(auxEmp);
    return isError;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int length,isError = 1;
    Employee* auxEmp;
    length = ll_len(pArrayListEmployee);
    progHeader("Recursos Humanos: Administracion");
    subHeader("Lista de Empleados");
    if (length>0)
    {
        printf("  ID           Nombre             Hrs Trabajo  Sueldo\n");
        printf("------------------------------------------------------\n");
        for(int i=0; i<length; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
            employee_show(auxEmp);
        }
        isError=0;
    }
    else
    {
        printf("\nNo hay empleados para mostrar. Carguelos desde un documento o manualmente.\n");
    }
    free(auxEmp);
    return isError;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option = 0;
    do{
        option = print_sortMenu();
        switch(option)
        {
            case 1:
                ll_sort(pArrayListEmployee,compare_id,0);
                break;
            case 2:
                ll_sort(pArrayListEmployee,compare_name,0);
                break;
            case 3:
                ll_sort(pArrayListEmployee,compare_workedHours,0);
                break;
            case 4:
                ll_sort(pArrayListEmployee,compare_salary,0);
                break;
            case 5:
                ll_sort(pArrayListEmployee,compare_id,1);
                break;
            case 6:
                ll_sort(pArrayListEmployee,compare_name,1);
                break;
            case 7:
                ll_sort(pArrayListEmployee,compare_workedHours,1);
                break;
            case 8:
                ll_sort(pArrayListEmployee,compare_salary,1);
                break;
            default:
                printf("Regresando al menu principal\n");
                break;
        }
        if(option!=9)
        {
            controller_ListEmployee(pArrayListEmployee);
            system("pause");
        }
    }while(option != 9);
    return 1;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int isError = 1, size;//Short scaned Values
    Employee* emp;
    FILE* txtFile;
    txtFile = fopen(path,"w");
    size = ll_len(pArrayListEmployee);
    for(int i = 0; i<size; i++)
    {
        emp = (Employee*) ll_get(pArrayListEmployee,i);
        isError=fprintf(txtFile,"%d,%s,%d,%d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
        if(isError<0)
        {
            break;
        }
        else
        {
            isError=0;
        }

    }
    if(isError)
    {
        printf("ERROR! No se pudo guardar los datos en el documento, intente guardarlos\n");
        printf("en un archivo binario\n");
    }
    else
    {
        printf("Datos guardados.\n");
    }
    free(emp);
    fclose(txtFile);
    return isError;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int isError = 1, size;
    Employee* emp;
    FILE* binFile;
    binFile = fopen(path,"wb");
    size = ll_len(pArrayListEmployee);
    for(int i = 0; i<size; i++)
    {
        emp = (Employee*) ll_get(pArrayListEmployee,i);
        fwrite(emp,sizeof(Employee),1,binFile);
        isError=0;
    }
    free(emp);
    fclose(binFile);
    return isError;
}

