#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

// Parameters Line: parameterInt, parameterStr, parameterChar, parameterFloat

typedef struct{
    parameterInt;
    parameterStr;
    parameterChar;
    parameterFloat;
}stdStruct;

//shortOfStruct = short for stdStruct

int shortOfStruct_com3LetersOfPar(stdStruct* shortName1; stdStruct* shortName2);
int shortOfStruct_com3LetersOfParStr(stdStruct* shortName1; stdStruct* shortName2);

int shortOfStruct_get3LetersOfPar(stdStruct* shortName, toParameter);
int shortOfStruct_get3LetersOfParStr(stdStruct* shortName, toParameter);

int shortOfStruct_set3LetersOfPar(stdStruct* shortName, fromParameter);
int shortOfStruct_set3LetersOfParStr(stdStruct* shortName, fromParameter);

void shortOfStruct_show(stdStruct* shortName);


stdStruct* shortOfStruct_newEmpty();
stdStruct* shortOfStruct_new(parametersLine);
#endif // employee_H_INCLUDED
