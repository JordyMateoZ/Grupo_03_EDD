#ifndef NODO_CPP
#define NODO_CPP

#include "proceso.cpp"

struct Nodo {
    Proceso dato;
    Nodo* siguiente;
};

#endif