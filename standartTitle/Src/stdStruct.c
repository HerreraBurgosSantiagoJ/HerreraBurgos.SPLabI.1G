#include "../Heathers/stdStruct.h"
#include <string.h>

stdStruct* shortOfStruct_newEmpty()
{
    return (stdStruct*) malloc(sizeof(stdStruct));
}

stdStruct* shortOfStruct_new(parametersLine)
{
    stdStruct* shortName = (stdStruct*) malloc(sizeof(stdStruct));
    if(shortName!=NULL)
    {
        shortOfStruct_set3LetersOfPar(shortName,parameter);
    }
    return stdStruct;
}

int shortOfStruct_com3LetersOfPar(stdStruct* shortName1; stdStruct* shortName2)
{
    int anw;
    stdStruct* a = (stdStruct*) shortName1;
    stdStruct* b = (stdStruct*) shortName2;
    if(a->parameter==b->parameter)
    {
        anw=0;
    }
    else if(a->parameter>b->parameter)
    {
        anw=-1;
    }
    else
    {
        anw=1;
    }
    return anw;
}

int shortOfStruct_com3LetersOfParStr(stdStruct* shortName1; stdStruct* shortName2)
{
    int anw;
    stdStruct* a = (stdStruct*) shortName1;
    stdStruct* b = (stdStruct*) shortName2;
    anw=strcmp(b->parameter,a->parameter);
    return anw;
}

int shortOfStruct_get3LetersOfPar(stdStruct* shortName, toParameter)
{
    int isError = 1;
    if (shortName!=NULL)
    {
        *parameter = shortName->parameter;
        isError=0;
    }
    return isError;
}

int shortOfStruct_get3LetersOfParStr(stdStruct* shortName, toParameter)
{
    int isError = 1;
    if (shortName!=NULL)
    {
        isError=strcpy(*parameter,shortName->parameter);
    }
    return isError;
}

int shortOfStruct_set3LetersOfPar(stdStruct* shortName, fromParameter)
{
    int isError=1;
    if(shortName!=NULL)
    {
        shortName->parameter=parameter;
        isError=0;
    }
    return isError;
}

int shortOfStruct_set3LetersOfParStr(stdStruct* shortName, fromParameter)
{
    int isError=1;
    if(shortName!=NULL)
    {
        isError=strcpy(shortName->parameterStr,parameterStr);
    }
    return isError;
}

void shortOfStruct_show(stdStruct* shortName)
{
    if (shortName!=NULL)
    {
        printf(" %04d|%24s|%10d     |%6d\n",shortName->parameterInt,shortName->parameterStr,shortName->parameterChar,shortName->parameterFloat);
        printf("------------------------------------------------------\n");
    }
}
