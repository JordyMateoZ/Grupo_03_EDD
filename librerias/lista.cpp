#ifndef LISTA_CPP
#define LISTA_CPP

#include "nodo.cpp"
#include <iostream>

using namespace std;

class Lista {
private:
    Nodo* cabeza; // Puntero principal que controla la lista

public:
    // Constructor: Inicializa la lista vacía
    Lista() {
        cabeza = NULL;
    }

    // 1. AGREGAR PROCESO (Inserta al final)

    void insertarProceso(Proceso p) {
        // Paso 1: Fabricar el nuevo bloque de memoria
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = p;
        nuevo_nodo->siguiente = NULL;

        // Paso 2: Conectarlo a la lista
        if (cabeza == NULL) {
            cabeza = nuevo_nodo; // Es el primer proceso
        } else {
            Nodo* actual = cabeza;
            // Recorremos hasta encontrar el último nodo
            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo_nodo; // Lo enganchamos al final
        }
        cout << "[EXITO] Proceso '" << p.nombre << "' registrado en la Lista.\n";
    }

    // 2. MOSTRAR PROCESOS

    void mostrarProcesos() {
        if (cabeza == NULL) {
            cout << "\n[!] El registro de procesos esta vacio.\n";
            return;
        }

        Nodo* actual = cabeza;
        cout << "\n--- REGISTRO HISTORICO DE PROCESOS ---" << endl;
        while (actual != NULL) {
            cout << "ID: " << actual->dato.id 
                 << " | Tarea: " << actual->dato.nombre 
                 << " | Prioridad: " << actual->dato.prioridad 
                 << " | RAM: " << actual->dato.memoriaRequerida << "MB" << endl;
            actual = actual->siguiente; // Saltar al siguiente nodo
        }
        cout << "--------------------------------------" << endl;
    }
};
#endif