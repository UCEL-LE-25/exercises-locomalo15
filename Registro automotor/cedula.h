#ifndef CEDULA_H
#define CEDULA_H


typedef struct 
{
    int nroCedula; //[PK]
    char fechaEmision[11];
    char fechaVencimiento[11];
    char dominioVehiculo[10];  // [FK] de automotor
    int dniTitular; //[FK] de titular
}Cedula;


void altaCedula();

#endif
