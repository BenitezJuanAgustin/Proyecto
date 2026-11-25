#include "tArbolPacientes.h"

tArbolPacientes insertarPaciente(tArbolPacientes a, tPaciente p) {
    if (a == NULL) {
        tArbolPacientes nuevo = (tArbolPacientes) malloc(sizeof(tNodoPaciente));
        nuevo->info = p;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        return nuevo;
    }
    if (p.dni < a->info.dni) {
        a->izq = insertarPaciente(a->izq, p);
    } else if (p.dni > a->info.dni) {
        a->der = insertarPaciente(a->der, p);
    }
    return a;
}

tArbolPacientes buscarPacientePorDNI(tArbolPacientes a, long dni) {
    if (a == NULL || a->info.dni == dni) return a;
    if (dni < a->info.dni) return buscarPacientePorDNI(a->izq, dni);
    return buscarPacientePorDNI(a->der, dni);
}

void listarPacientesInOrder(tArbolPacientes a) {
    if (a != NULL) {
        listarPacientesInOrder(a->izq);
        printf("DNI: %ld | Nombre: %-15s | Edad: %d | OS: %s\n", 
               a->info.dni, a->info.nombre, a->info.edad, a->info.obraSocial);
        listarPacientesInOrder(a->der);
    }
}
