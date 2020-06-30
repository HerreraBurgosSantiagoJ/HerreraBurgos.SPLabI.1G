#include "../Heathers/sBike.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int notAmongTypes(char* cheking)
{
    int auxBoo=1;
    if(strcmp("bmx",cheking)==0)
        auxBoo=0;
    else if(strcmp("playera",cheking)==0)
        auxBoo=0;
    else if(strcmp("mtb",cheking)==0)
        auxBoo=0;
    else if(strcmp("paseo",cheking)==0)
        auxBoo=0;
    return auxBoo;
}

sBike* bike_newEmpty()
{
    return (sBike*) malloc(sizeof(sBike));
}

sBike* bike_new(int bike_id, char* name, char* type, int time)
{
    sBike* bike = (sBike*) malloc(sizeof(sBike));
    int isError=1;
    if(bike!=NULL)
    {
        isError=bike_setId(bike,bike_id);
        isError=bike_setNme(bike,name);
        isError=bike_setTpe(bike,type);
        isError=bike_setTme(bike,time);
        if(isError)//Burdo debe mejorarse...
        {
            bike=NULL;
        }
    }
    return bike;
}

int bike_comId(void* bike1, void* bike2)
{
    int anw;
    sBike* a = (sBike*) bike1;
    sBike* b = (sBike*) bike2;
    if(a->bike_id==b->bike_id)
    {
        anw=0;
    }
    else if(a->bike_id>b->bike_id)
    {
        anw=-1;
    }
    else
    {
        anw=1;
    }
    return anw;
}

int bike_comNme(void* bike1, void* bike2)
{
    int anw;
    sBike* a = (sBike*) bike1;
    sBike* b = (sBike*) bike2;
    anw=strcmp(b->name,a->name);
    return anw;
}

int bike_comTme(void* bike1, void* bike2)
{
    int anw;
    sBike* a = (sBike*) bike1;
    sBike* b = (sBike*) bike2;
    if(a->time==b->time)
    {
        anw=0;
    }
    else if(a->time>b->time)
    {
        anw=-1;
    }
    else
    {
        anw=1;
    }
    return anw;
}

int bike_comTpe(void* bike1, void* bike2)
{
    int anw;
    sBike* a = (sBike*) bike1;
    sBike* b = (sBike*) bike2;
    anw=strcmp(b->type,a->type);
    return anw;
}

int bike_getId(sBike* bike, int* to)
{
    int isError = 1;
    if (bike!=NULL)
    {
        *to = bike->bike_id;
        isError=0;
    }
    return isError;
}

int bike_getNme(sBike* bike, char* to)
{
    int isError = 1;
    if (bike!=NULL)
    {
        strcpy(to,bike->name);
        isError=0;
    }
    return isError;
}

int bike_getTme(sBike* bike, int* to)
{
    int isError = 1;
    if (bike!=NULL)
    {
        *to = bike->time;
        isError=0;
    }
    return isError;
}

int bike_getTpe(sBike* bike, char* to)
{
    int isError = 1;
    if (bike!=NULL)
    {
        strcpy(to,bike->type);
        isError=0;
    }
    return isError;
}

int bike_setId(sBike* bike, int from)
{
    int isError=1;
    if(bike!=NULL)
    {
        bike->bike_id=from;
        isError=0;
    }
    return isError;
}

int bike_setNme(sBike* bike, char* from)
{
    int isError=1;
    if(bike!=NULL)
    {
        strcpy(bike->name,from);
        isError=0;
    }
    return isError;
}

int bike_setTme(sBike* bike, int from)
{
    int isError=1;
    if(bike!=NULL)
    {
        bike->time=from;
        isError=0;
    }
    return isError;
}

int bike_setTpe(sBike* bike, char* from)
{
    int isError=1;
    if(bike!=NULL)
    {
        strcpy(bike->type,from);
        isError=0;
    }
    return isError;
}

void bike_show(sBike* bike)
{
    if (bike!=NULL)
    {
        printf(" %04d|%24s|%10s     |%6d\n",bike->bike_id,bike->name,bike->type,bike->time);
        printf("------------------------------------------------------\n");
    }
}

int bike_excludeTpe(void* bike1, void* excluded)
{
    int anw;
    sBike* a = (sBike*) bike1;
    char* b = (char*) excluded;
    anw=strcmp(b,a->type);
    return anw;
}
