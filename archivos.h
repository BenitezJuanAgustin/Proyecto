#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idHospital;
    char nombreHospital[30];
    char especialidad[30];
    long dniPaciente;
    float costoAtencion;
} tRegistroAtencion;

void generarArchivoPruebaAtenciones();
void generarReporteCorteDeControl(const char *nombreArchivo);

#endif
