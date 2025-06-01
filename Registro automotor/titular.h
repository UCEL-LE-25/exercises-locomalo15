#ifndef TITULAR_H
#define TITULAR_H

typedef struct 
{
    char nombre [20];
    int cuit;
    char tipoDocumento [10];
    int nroDocumento; //[PK]
    char fechaNacimiento [20]; //Se puede usar DATE
    int idVehiculo[3]; //[FK] de vehiculo
}Titular;

void altaTitular();
void listarTitularesConVehiculos();

#endif