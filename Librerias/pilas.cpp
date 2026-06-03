#ifndef PILAS_CPP
#define PILAS_CPP

#include "nodo.cpp"
#include <iostream>

using namespace std;

class Pilas {

private:

    Nodo* tope;

    int memoriaTotal;
    int memoriaUsada;

public:

    // CONSTRUCTOR

    Pilas() {

        tope = NULL;

        memoriaTotal = 8000; // 8 GB simulados

        memoriaUsada = 0;
    }

    // VERIFICAR MEMORIA DISPONIBLE

    bool memoriaDisponible(int requerida) {

        return memoriaUsada + requerida <= memoriaTotal;
    }

    // ASIGNAR MEMORIA

    void push(Proceso p) {

        // Verificar memoria

        if (!memoriaDisponible(p.memoriaRequerida)) {

            cout << "\n[ERROR] Memoria insuficiente.\n";

            return;
        }

        Nodo* nuevo = new Nodo();

        nuevo->dato = p;

        nuevo->siguiente = tope;

        tope = nuevo;

        memoriaUsada += p.memoriaRequerida;

        cout << "\n[RAM] Memoria asignada al proceso '"
             << p.nombre
             << "'.\n";
    }

    // LIBERAR MEMORIA

    void pop() {

        if (tope == NULL) {

            cout << "\nNo hay procesos en memoria.\n";

            return;
        }

        cout << "\n[RAM] Liberando memoria de:\n";

        cout << "ID: " << tope->dato.id
             << " | Nombre: " << tope->dato.nombre
             << " | RAM: " << tope->dato.memoriaRequerida
             << "MB\n";

        memoriaUsada -= tope->dato.memoriaRequerida;

        Nodo* temp = tope;

        tope = tope->siguiente;

        delete temp;
    }

    // MOSTRAR MEMORIA

    void mostrarMemoria() {

        cout << "\n=========== MEMORIA RAM ===========\n";

        cout << "RAM Total : "
             << memoriaTotal
             << " MB\n";

        cout << "RAM Usada : "
             << memoriaUsada
             << " MB\n";

        cout << "RAM Libre : "
             << memoriaTotal - memoriaUsada
             << " MB\n";

        cout << "===================================\n";
    }

    // MOSTRAR PROCESOS EN MEMORIA

    void mostrarProcesosMemoria() {

        if (tope == NULL) {

            cout << "\nNo hay procesos cargados en RAM.\n";

            return;
        }

        Nodo* actual = tope;

        cout << "\n------ PROCESOS EN MEMORIA ------\n";

        while (actual != NULL) {

            cout << "ID: " << actual->dato.id
                 << " | Nombre: " << actual->dato.nombre
                 << " | RAM: " << actual->dato.memoriaRequerida
                 << " MB\n";

            actual = actual->siguiente;
        }

        cout << "---------------------------------\n";
    }
};

#endif