#ifndef GRAFOPLAYAS_H
#define GRAFOPLAYAS_H

#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 18
#define MAX_NOM 50

// Estructura para el peso de cada arista entre playas
typedef struct {
    int existe;      // 1 si existe tramo, 0 si no existe
    int estaciones;  // E
    int zonasRiesgo; // Z
} tPeso;

// Declaracion de la estructura principal del TDA
typedef struct {
    char nombres[MAX_VERTICES][MAX_NOM];
    tPeso matriz[MAX_VERTICES][MAX_VERTICES];
    int cantVertices;
} tGrafoPlayas;

// a) Iniciar el grafo
void iniciarGrafo(tGrafoPlayas *g) {
    int i, j;
    g->cantVertices = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            g->matriz[i][j].existe = 0;
            g->matriz[i][j].estaciones = 0;
            g->matriz[i][j].zonasRiesgo = 0;
        }
    }
}

// b) Agregar un vertice (playa)
int agregarVertice(tGrafoPlayas *g, const char *nombre) {
    if (g->cantVertices >= MAX_VERTICES) {
        printf("Error: Grafo lleno. Limite de %d playas alcanzado.\n", MAX_VERTICES);
        return 0;
    }
    strcpy(g->nombres[g->cantVertices], nombre);
    g->cantVertices++;
    return 1;
}

// c) Agregar una arista registrandola en ambos sentidos (grafo no dirigido)
int agregarArista(tGrafoPlayas *g, int v1, int v2, int estaciones, int zonasRiesgo) {
    int i, j;

    if (v1 < 1 || v1 > g->cantVertices || v2 < 1 || v2 > g->cantVertices) {
        printf("Error: Vertice invalido. Ingrese valores entre 1 y %d.\n", g->cantVertices);
        return 0;
    }

    i = v1 - 1;
    j = v2 - 1;

    g->matriz[i][j].existe = 1;
    g->matriz[i][j].estaciones = estaciones;
    g->matriz[i][j].zonasRiesgo = zonasRiesgo;

    g->matriz[j][i].existe = 1;
    g->matriz[j][i].estaciones = estaciones;
    g->matriz[j][i].zonasRiesgo = zonasRiesgo;

    return 1;
}

// d) Imprimir la matriz de adyacencia ('a') o de pesos ('p')
void imprimirMatriz(tGrafoPlayas g, char tipo) {
    int i, j;

    if (g.cantVertices == 0) {
        printf("\nEl grafo no tiene playas registradas.\n");
        return;
    }

    if (tipo == 'a' || tipo == 'A') {
        printf("\n--- MATRIZ DE ADYACENCIA ---\n    ");
        for (j = 0; j < g.cantVertices; j++) {
            printf("[%d] ", j + 1);
        }
        printf("\n");

        for (i = 0; i < g.cantVertices; i++) {
            printf("[%d] ", i + 1);
            for (j = 0; j < g.cantVertices; j++) {
                printf(" %d  ", g.matriz[i][j].existe);
            }
            printf("\n");
        }
    } 
    else if (tipo == 'p' || tipo == 'P') {
        printf("\nE = estaciones de servicio, Z = zonas de riesgo\n");
        printf("--- MATRIZ DE PESOS ---\n       ");
        for (j = 0; j < g.cantVertices; j++) {
            printf("  [%d]   ", j + 1);
        }
        printf("\n");

        for (i = 0; i < g.cantVertices; i++) {
            printf("[%d]   ", i + 1);
            for (j = 0; j < g.cantVertices; j++) {
                if (g.matriz[i][j].existe) {
                    printf("(%d, %d) ", g.matriz[i][j].estaciones, g.matriz[i][j].zonasRiesgo);
                } else {
                    printf(" (-, -) ");
                }
            }
            printf("\n");
        }
    } 
    else {
        printf("\nParametro invalido. Ingrese 'a' para adyacencia o 'p' para pesos.\n");
    }
}

// Operaciones auxiliares para consultar el TDA sin acceder a sus campos directamente
void listarPlayas(tGrafoPlayas g) {
    int i;
    if (g.cantVertices == 0) {
        printf("\nNo hay playas registradas.\n");
        return;
    }
    printf("\n--- PLAYAS REGISTRADAS ---\n");
    for (i = 0; i < g.cantVertices; i++) {
        printf("%d. %s\n", i + 1, g.nombres[i]);
    }
}

int obtenerCantidadVertices(tGrafoPlayas g) {
    return g.cantVertices;
}

#endif
