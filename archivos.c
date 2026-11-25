#include "archivos.h"

void generarArchivoPruebaAtenciones() {
    FILE *arch = fopen("atenciones_ordenadas.txt", "w");
    if (arch != NULL) {
        // Datos ordenados por Hospital ID -> Especialidad
        fprintf(arch, "1 Hospital_Central Cardiologia 35123456 15000.0\n");
        fprintf(arch, "1 Hospital_Central Cardiologia 40987654 15000.0\n");
        fprintf(arch, "1 Hospital_Central Pediatria 42111222 8000.0\n");
        fprintf(arch, "2 Sanatorio_Norte Traumatologia 28555666 22000.0\n");
        fprintf(arch, "2 Sanatorio_Norte Traumatologia 31444333 22000.0\n");
        fclose(arch);
    }
}

void generarReporteCorteDeControl(const char *nombreArchivo) {
    FILE *arch = fopen(nombreArchivo, "r");
    tRegistroAtencion reg;
    int hospActual;
    char espActual[30];
    int cantAtencionesHosp, cantAtencionesEsp, totalAtencionesGeneral = 0;
    float costoTotalHosp, costoTotalEsp, costoTotalGeneral = 0.0;

    if (arch == NULL) {
        printf("Error: No se pudo abrir el archivo de atenciones.\n");
        return;
    }

    printf("\n===================================================================\n");
    printf("        REPORTE ESTADISTICO DE ATENCIONES HOSPITALARIAS           \n");
    printf("===================================================================\n");

    if (fscanf(arch, "%d %s %s %ld %f", &reg.idHospital, reg.nombreHospital, 
               reg.especialidad, &reg.dniPaciente, &reg.costoAtencion) == EOF) {
        printf("El archivo esta vacio.\n");
        fclose(arch);
        return;
    }

    while (!feof(arch)) {
        hospActual = reg.idHospital;
        cantAtencionesHosp = 0;
        costoTotalHosp = 0.0;
        printf("\nHOSPITAL ID: %d - %s\n", hospActual, reg.nombreHospital);
        printf("-------------------------------------------------------------------\n");

        while (!feof(arch) && reg.idHospital == hospActual) {
            strcpy(espActual, reg.especialidad);
            cantAtencionesEsp = 0;
            costoTotalEsp = 0.0;
            printf("  Especialidad: %s\n", espActual);

            while (!feof(arch) && reg.idHospital == hospActual && strcmp(reg.especialidad, espActual) == 0) {
                printf("    -> DNI Paciente: %ld | Costo: $%.2f\n", reg.dniPaciente, reg.costoAtencion);

                cantAtencionesEsp++;
                costoTotalEsp += reg.costoAtencion;

                fscanf(arch, "%d %s %s %ld %f", &reg.idHospital, reg.nombreHospital, 
                       reg.especialidad, &reg.dniPaciente, &reg.costoAtencion);
            }

            printf("  Subtotal Especialidad (%s): %d atenciones | Total: $%.2f\n", 
                   espActual, cantAtencionesEsp, costoTotalEsp);

            cantAtencionesHosp += cantAtencionesEsp;
            costoTotalHosp += costoTotalEsp;
        }

        printf("Subtotal Hospital ID %d: %d atenciones | Total: $%.2f\n", 
               hospActual, cantAtencionesHosp, costoTotalHosp);

        totalAtencionesGeneral += cantAtencionesHosp;
        costoTotalGeneral += costoTotalHosp;
    }

    printf("===================================================================\n");
    printf("TOTAL GENERAL DE LA RED: %d atenciones | Monto Total: $%.2f\n", 
           totalAtencionesGeneral, costoTotalGeneral);
    printf("===================================================================\n");

    fclose(arch);
}
