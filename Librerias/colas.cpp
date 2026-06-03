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
    Colas() {
        frente = NULL;
        final = NULL;
    }

    // Insertar proceso manteniendo el orden de prioridad
    void encolar(Proceso p) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = p;
        nuevo->siguiente = NULL;

        if (frente == NULL || p.prioridad > frente->dato.prioridad) {
            nuevo->siguiente = frente;
            frente = nuevo;
        } else {
            Nodo* actual = frente;
            while (actual->siguiente != NULL && actual->siguiente->dato.prioridad >= p.prioridad) {
                actual = actual->siguiente;
            }
            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;
        }
        cout << "[EXITO] Proceso '" << p.nombre << "' encolado por prioridad.\n";
    }

    void desencolar() {
        if (frente == NULL) return;
        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }
};

#endif