#include "tGrafoRed.h"

void iniciarRed(tGrafoRed *g) {
    int i, j;
    g->cantHospitales = 0;
    for (i = 0; i < MAX_HOSPITALES; i++) {
        for (j = 0; j < MAX_HOSPITALES; j++) {
            g->matrizRutas[i][j].existe = 0;
            g->matrizRutas[i][j].distanciaKm = 0;
            g->matrizRutas[i][j].tiempoMinutos = 0;
        }
    }
}

int agregarHospital(tGrafoRed *g, const char *nombre, int complejidad) {
    if (g->cantHospitales >= MAX_HOSPITALES) return 0;
    strcpy(g->centros[g->cantHospitales].nombre, nombre);
    g->centros[g->cantHospitales].nivelComplejidad = complejidad;
    g->cantHospitales++;
    return 1;
}

int agregarRuta(tGrafoRed *g, int h1, int h2, int km, int min) {
    int i = h1 - 1, j = h2 - 1;
    if (h1 < 1 || h1 > g->cantHospitales || h2 < 1 || h2 > g->cantHospitales) return 0;

    // Grafo no dirigido (conexion simetrica)
    g->matrizRutas[i][j].existe = 1;
    g->matrizRutas[i][j].distanciaKm = km;
    g->matrizRutas[i][j].tiempoMinutos = min;

    g->matrizRutas[j][i].existe = 1;
    g->matrizRutas[j][i].distanciaKm = km;
    g->matrizRutas[j][i].tiempoMinutos = min;

    return 1;
}

void mostrarMatrizRed(tGrafoRed g, char tipo) {
    int i, j;
    printf("\n--- MATRIZ DE RED HOSPITALARIA (%s) ---\n", (tipo == 'd') ? "DISTANCIAS KM" : "TIEMPOS MIN");
    for (i = 0; i < g.cantHospitales; i++) {
        for (j = 0; j < g.cantHospitales; j++) {
            if (g.matrizRutas[i][j].existe) {
                printf("%3d ", (tipo == 'd') ? g.matrizRutas[i][j].distanciaKm : g.matrizRutas[i][j].tiempoMinutos);
            } else {
                printf("  - ");
            }
        }
        printf("\n");
    }
}
