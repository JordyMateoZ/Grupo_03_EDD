#ifndef COLAS_CPP
#define COLAS_CPP

#include "nodo.cpp"
#include <iostream>

using namespace std;

class Colas {

private:

    Nodo* frente;
    Nodo* final;

public:

    // CONSTRUCTOR

    Colas() {

        frente = NULL;
        final = NULL;
    }

    // ENCOLAR POR PRIORIDAD

    void encolar(Proceso p) {

        Nodo* nuevo = new Nodo();

        nuevo->dato = p;
        nuevo->siguiente = NULL;

        // Cola vacía

        if (frente == NULL) {

            frente = nuevo;
            final = nuevo;
        }

        // Mayor prioridad que el frente

        else if (p.prioridad > frente->dato.prioridad) {

            nuevo->siguiente = frente;

            frente = nuevo;
        }

        // Insertar ordenadamente

        else {

            Nodo* actual = frente;

            while (actual->siguiente != NULL &&
                   actual->siguiente->dato.prioridad >= p.prioridad) {

                actual = actual->siguiente;
            }

            nuevo->siguiente = actual->siguiente;

            actual->siguiente = nuevo;

            // Si se insertó al final

            if (nuevo->siguiente == NULL) {

                final = nuevo;
            }
        }

        cout << "[EXITO] Proceso '"
             << p.nombre
             << "' agregado a la cola CPU.\n";
    }

    // MOSTRAR COLA

    void mostrarCola() {

        if (frente == NULL) {

            cout << "\n[!] La cola esta vacia.\n";

            return;
        }

        Nodo* actual = frente;

        cout << "\n--- COLA DE PRIORIDAD CPU ---\n";

        while (actual != NULL) {

            cout << "ID: " << actual->dato.id
                 << " | Nombre: " << actual->dato.nombre
                 << " | Prioridad: " << actual->dato.prioridad
                 << endl;

            actual = actual->siguiente;
        }

        cout << "--------------------------------\n";
    }

    // EJECUTAR PROCESO

    void ejecutarProceso() {

        if (frente == NULL) {

            cout << "No hay procesos en cola.\n";

            return;
        }

        cout << "\n[CPU] Ejecutando proceso:\n";

        cout << "ID: " << frente->dato.id
             << " | Nombre: " << frente->dato.nombre
             << " | Prioridad: " << frente->dato.prioridad
             << endl;

        desencolar();
    }

    // DESENCOLAR

    void desencolar() {

        if (frente == NULL) {

            return;
        }

        Nodo* temp = frente;

        frente = frente->siguiente;

        // Si quedó vacía

        if (frente == NULL) {

            final = NULL;
        }

        delete temp;
    }
};

#endif