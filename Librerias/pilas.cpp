#ifndef PILAS_CPP
#define PILAS_CPP

#include "nodo.cpp"
#include <iostream>

using namespace std;

class Pilas {
private:
    Nodo* tope;

public:
    Pilas() {
        tope = NULL;
    }

    void push(Proceso p) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = p;
        nuevo->siguiente = tope;
        tope = nuevo;
        cout << "[EXITO] Proceso '" << p.nombre << "' apilado en memoria.\n";
    }

    void pop() {
        if (tope == NULL) return;
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
};

#endif