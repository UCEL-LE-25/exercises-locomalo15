#ifndef IMPRESORAS_H
#define IMPRESORAS_H

#define SECTORES 3
#define IMPRESORAS 4

typedef struct {
    int paginas;
    int estado;
} Impresora;

void inicializarOficina(Impresora impresora[SECTORES][IMPRESORAS]);
void modificarImpresora(Impresora impresora[SECTORES][IMPRESORAS], int sector, int nro);
void paginasPorSector(Impresora impresora[SECTORES][IMPRESORAS], int sector);
int activasPorSector(Impresora impresora[SECTORES][IMPRESORAS], int sector);
void sectorMasActivo(Impresora impresora[SECTORES][IMPRESORAS]);
void informeGeneral(Impresora impresora[SECTORES][IMPRESORAS]);

#endif
