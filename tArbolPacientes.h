#ifndef TARBOLPACIENTES_H
#define TARBOLPACIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long dni;
    char nombre[50];
    int edad;
    char obraSocial[30];
} tPaciente;

typedef struct nodoP {
    tPaciente info;
    struct nodoP *izq;
    struct nodoP *der;
} tNodoPaciente, *tArbolPacientes;

// Operaciones del TDA ABB
tArbolPacientes insertarPaciente(tArbolPacientes a, tPaciente p);
tArbolPacientes buscarPacientePorDNI(tArbolPacientes a, long dni);
void listarPacientesInOrder(tArbolPacientes a);

#endif
