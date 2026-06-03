#include <iostream>
// Importamos tus librerías usando la ruta relativa
#include "../librerias/lista.cpp"
#include "../librerias/colas.cpp"
#include "../librerias/pilas.cpp"

using namespace std;

int main() {
    // Creamos las instancias de tus estructuras
    Lista listaProcesos;
    Colas colaPrioridad;
    Pilas pilaMemoria;
    
    int opcion;
    Proceso p;

    do {
        cout << "\n--- SISTEMA DE GESTION DE PROCESOS ---" << endl;
        cout << "1. Registrar Proceso (Lista)" << endl;
        cout << "2. Encolar por Prioridad (Cola)" << endl;
        cout << "3. Gestionar Memoria (Pila)" << endl;
        cout << "4. Ver Registros" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "ID: "; cin >> p.id;
                cout << "Nombre: "; cin >> p.nombre;
                cout << "Prioridad: "; cin >> p.prioridad;
                cout << "RAM (MB): "; cin >> p.memoriaRequerida;
                listaProcesos.insertarProceso(p);
                break;
            case 4:
                listaProcesos.mostrarProcesos();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while(opcion != 5);

    return 0;
}