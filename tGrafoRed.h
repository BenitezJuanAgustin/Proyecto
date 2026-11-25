#ifndef TGRAFORED_H
#define TGRAFORED_H
#include <stdio.h>
#include <string.h>
#define MAX_HOSPITALES 15
#define MAX_NOM 50

typedef struct {
    int distanciaKm;
    int tiempoMinutos;
    int existe; // 1 si hay conexion directa, 0 si no
} tRuta;

typedef struct {
    char nombre[MAX_NOM];
    int nivelComplejidad; // 1: Primario, 2: Secundario, 3: Alta Complejidad
} tHospital;

typedef struct {
    tHospital centros[MAX_HOSPITALES];
    tRuta matrizRutas[MAX_HOSPITALES][MAX_HOSPITALES];
    int cantHospitales;
} tGrafoRed;

// Operaciones del TDA Grafo
void iniciarRed(tGrafoRed *g);
int agregarHospital(tGrafoRed *g, const char *nombre, int complejidad);
int agregarRuta(tGrafoRed *g, int h1, int h2, int km, int min);
void mostrarMatrizRed(tGrafoRed g, char tipo); // 'd': distancias, 't': tiempos

#endif
