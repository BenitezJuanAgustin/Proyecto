#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tGrafoRed.h"
#include "tArbolPacientes.h"
#include "archivos.h"

// Agregamos las implementaciones .c para que Dev-C++ las enlace directamente
#include "tGrafoRed.c"
#include "tArbolPacientes.c"
#include "archivos.c"

int main() {
    tGrafoRed red;
    tArbolPacientes arbol = NULL;
    tPaciente p;
    tArbolPacientes resBusqueda;
    int opcion;
    long dniBuscado;

    iniciarRed(&red);
    generarArchivoPruebaAtenciones();

    // Carga inicial de prueba
    agregarHospital(&red, "Hospital Central", 3);
    agregarHospital(&red, "Sanatorio Norte", 2);
    agregarHospital(&red, "Centro de Salud Barrio Este", 1);
    agregarRuta(&red, 1, 2, 12, 20);
    agregarRuta(&red, 2, 3, 5, 10);
    // Carga inicial de prueba
    agregarHospital(&red, "Hospital Central", 3);
    agregarHospital(&red, "Sanatorio Norte", 2);
    agregarHospital(&red, "Centro de Salud Barrio Este", 1);
    agregarRuta(&red, 1, 2, 12, 20);
    agregarRuta(&red, 2, 3, 5, 10);

    p.dni = 35123456; strcpy(p.nombre, "Carlos Gomez"); p.edad = 45; strcpy(p.obraSocial, "INSSSEP");
    arbol = insertarPaciente(arbol, p);
    p.dni = 28555666; strcpy(p.nombre, "Ana Martinez"); p.edad = 52; strcpy(p.obraSocial, "PAMI");
    arbol = insertarPaciente(arbol, p);
    p.dni = 42111222; strcpy(p.nombre, "Lucia Perez"); p.edad = 23; strcpy(p.obraSocial, "IOSCOR");
    arbol = insertarPaciente(arbol, p);

    do {
        printf("\n=======================================================\n");
        printf("    SISTEMA DE GESTION DE RED MEDICA Y URGENCIAS\n");
        printf("=======================================================\n");
        printf("1. Registrar nuevo paciente (ABB)\n");
        printf("2. Buscar paciente por DNI (Buscador ABB)\n");
        printf("3. Listar padron de pacientes ordenado por DNI (In-Order)\n");
        printf("4. Visualizar matriz de distancias de la Red (Grafo)\n");
        printf("5. Generar reporte estadistico de atenciones (Corte de Control)\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nIngrese DNI: "); scanf("%ld", &p.dni);
                printf("Ingrese Nombre: "); scanf("%s", p.nombre);
                printf("Ingrese Edad: "); scanf("%d", &p.edad);
                printf("Ingrese Obra Social: "); scanf("%s", p.obraSocial);
                arbol = insertarPaciente(arbol, p);
                printf("Paciente cargado en el arbol correctamente.\n");
                break;

            case 2:
                printf("\nIngrese DNI a buscar: ");
                scanf("%ld", &dniBuscado);
                resBusqueda = buscarPacientePorDNI(arbol, dniBuscado);
                if (resBusqueda != NULL) {
                    printf("Encontrado: %s | Edad: %d | OS: %s\n", 
                           resBusqueda->info.nombre, resBusqueda->info.edad, resBusqueda->info.obraSocial);
                } else {
                    printf("Paciente con DNI %ld no registrado.\n", dniBuscado);
                }
                break;

            case 3:
                printf("\n--- PADRON DE PACIENTES REGISTRADOS (IN-ORDER) ---\n");
                listarPacientesInOrder(arbol);
                break;

            case 4:
                mostrarMatrizRed(red, 'd');
                break;

            case 5:
                generarReporteCorteDeControl("atenciones_ordenadas.txt");
                break;

            case 6:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while (opcion != 6);

    return 0;
}
