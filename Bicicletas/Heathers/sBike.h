#ifndef sBike_H_INCLUDED
#define sBike_H_INCLUDED

// Parameters Line: int bike_id, char* name, char type, int time

typedef struct{
    int bike_id;
    char name[40];
    char type[7];
    int time;
}sBike;

//bike = short for sBike

int bike_comId(void* bike1, void* bike2);
int bike_comNme(void* bike1, void* bike2);
int bike_comTpe(void* bike1, void* bike2);
int bike_comTme(void* bike1, void* bike2);

int bike_getId(sBike* bike, int* to);
int bike_getNme(sBike* bike, char* to);
int bike_getTpe(sBike* bike, char* to);
int bike_getTme(sBike* bike, int* to);

int bike_setId(sBike* bike, int from);
int bike_setNme(sBike* bike, char* from);
int bike_setTpe(sBike* bike, char* from);
int bike_setTme(sBike* bike, int from);

void bike_show(sBike* bike);

int bike_excludeTpe(void* bike1, void* excluded);

sBike* bike_newEmpty();
sBike* bike_new(int bike_id, char* name, char* type, int time);

#endif // sBike_H_INCLUDED
