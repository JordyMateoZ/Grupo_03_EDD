#ifndef LISTA_CPP
#define LISTA_CPP

#include "nodo.cpp"
#include <iostream>

using namespace std;

class Lista {

private:

    Nodo* cabeza;

public:

    // CONSTRUCTOR

    Lista() {
        cabeza = NULL;
    }

    // INSERTAR PROCESO

    void insertarProceso(Proceso p) {

        Nodo* nuevo_nodo = new Nodo();

        nuevo_nodo->dato = p;
        nuevo_nodo->siguiente = NULL;

        // Si la lista está vacía

        if (cabeza == NULL) {

            cabeza = nuevo_nodo;
        }

        // Si ya existen nodos

        else {

            Nodo* actual = cabeza;

            while (actual->siguiente != NULL) {

                actual = actual->siguiente;
            }

            actual->siguiente = nuevo_nodo;
        }

        cout << "[EXITO] Proceso '" 
             << p.nombre 
             << "' registrado en la Lista.\n";
    }

    // MOSTRAR PROCESOS

    void mostrarProcesos() {

        if (cabeza == NULL) {

            cout << "\n[!] El registro de procesos esta vacio.\n";

            return;
        }

        Nodo* actual = cabeza;

        cout << "\n--- REGISTRO HISTORICO DE PROCESOS ---\n";

        while (actual != NULL) {

            cout << "ID: " << actual->dato.id
                 << " | Nombre: " << actual->dato.nombre
                 << " | Prioridad: " << actual->dato.prioridad
                 << " | RAM: " << actual->dato.memoriaRequerida
                 << "MB" << endl;

            actual = actual->siguiente;
        }

        cout << "--------------------------------------\n";
    }

    // BUSCAR PROCESO

    Nodo* buscarProceso(int id) {

        Nodo* actual = cabeza;

        while (actual != NULL) {

            if (actual->dato.id == id) {

                return actual;
            }

            actual = actual->siguiente;
        }

        return NULL;
    }

    // ELIMINAR PROCESO

    void eliminarProceso(int id) {

        // Lista vacía

        if (cabeza == NULL) {

            cout << "La lista esta vacia.\n";

            return;
        }

        // Eliminar primer nodo

        if (cabeza->dato.id == id) {

            Nodo* temp = cabeza;

            cabeza = cabeza->siguiente;

            delete temp;

            cout << "Proceso eliminado.\n";

            return;
        }

        Nodo* actual = cabeza;

        // Buscar nodo anterior al que se eliminará

        while (actual->siguiente != NULL &&
               actual->siguiente->dato.id != id) {

            actual = actual->siguiente;
        }

        // No encontrado

        if (actual->siguiente == NULL) {

            cout << "Proceso no encontrado.\n";

            return;
        }

        Nodo* temp = actual->siguiente;

        actual->siguiente = temp->siguiente;

        delete temp;

        cout << "Proceso eliminado.\n";
    }

    // CAMBIAR PRIORIDAD

    void cambiarPrioridad(int id, int nuevaPrioridad) {

        Nodo* encontrado = buscarProceso(id);

        if (encontrado == NULL) {

            cout << "Proceso no encontrado.\n";

            return;
        }

        encontrado->dato.prioridad = nuevaPrioridad;

        cout << "Prioridad actualizada correctamente.\n";
    }
};

#endif