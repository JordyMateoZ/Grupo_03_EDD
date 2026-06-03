#include <iostream>
// Importamos las librerias
#include "../librerias/lista.cpp"
#include "../librerias/colas.cpp"
#include "../librerias/pilas.cpp"

using namespace std;

// ===============================
// FUNCIONES DE MENUS
// ===============================

void menuLista(Lista &listaProcesos) {

    int opcion;

    do {

        system("cls");

        cout << "=========================================\n";
        cout << " GESTION DE LISTA DE PROCESOS\n";
        cout << "=========================================\n";

        cout << "1. Registrar Proceso\n";
        cout << "2. Mostrar Procesos\n";
        cout << "3. Buscar Proceso\n";
        cout << "4. Eliminar Proceso\n";
        cout << "5. Cambiar Prioridad\n";
        cout << "6. Volver\n";

        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {

            // REGISTRAR

            case 1: {

                Proceso p;

                system("cls");

                cout << "--- REGISTRO DE PROCESO ---\n";

                cout << "ID: ";
                cin >> p.id;

                cout << "Nombre: ";
                cin >> p.nombre;

                cout << "Prioridad: ";
                cin >> p.prioridad;

                cout << "RAM requerida (MB): ";
                cin >> p.memoriaRequerida;

                listaProcesos.insertarProceso(p);

                system("pause");

            break;
            }

            // MOSTRAR

            case 2:

                system("cls");

                listaProcesos.mostrarProcesos();

                system("pause");

            break;

            // BUSCAR

            case 3: {

                int idBuscar;

                system("cls");

                cout << "Ingrese ID del proceso: ";
                cin >> idBuscar;

                Nodo* encontrado =
                listaProcesos.buscarProceso(idBuscar);

                if (encontrado != NULL) {

                    cout << "\n--- PROCESO ENCONTRADO ---\n";

                    cout << "ID: "
                         << encontrado->dato.id << endl;

                    cout << "Nombre: "
                         << encontrado->dato.nombre << endl;

                    cout << "Prioridad: "
                         << encontrado->dato.prioridad << endl;

                    cout << "RAM: "
                         << encontrado->dato.memoriaRequerida
                         << " MB\n";

                } else {

                    cout << "\nProceso no encontrado.\n";
                }

                system("pause");

            break;
            }

            // ELIMINAR

            case 4: {

                int idEliminar;

                system("cls");

                cout << "Ingrese ID a eliminar: ";
                cin >> idEliminar;

                listaProcesos.eliminarProceso(idEliminar);

                system("pause");

            break;
            }

            // CAMBIAR PRIORIDAD

            case 5: {

                int id;
                int nueva;

                system("cls");

                cout << "ID del proceso: ";
                cin >> id;

                cout << "Nueva prioridad: ";
                cin >> nueva;

                listaProcesos.cambiarPrioridad(id, nueva);

                system("pause");

            break;
            }

            case 6:

                cout << "\nVolviendo al menu principal...\n";

            break;

            default:

                cout << "\n[ERROR] Opcion no valida.\n";

                system("pause");
        }

    } while(opcion != 6);
}

// ===============================

void menuCola(Lista &listaProcesos,
               Colas &colaPrioridad) {

    int opcion;

    do {

        system("cls");

        cout << "=========================================\n";
        cout << " PLANIFICADOR CPU - COLA PRIORIDAD\n";
        cout << "=========================================\n";

        cout << "1. Agregar Proceso a Cola\n";
        cout << "2. Mostrar Cola CPU\n";
        cout << "3. Ejecutar Proceso\n";
        cout << "4. Volver\n";

        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {

            // ENCOLAR

            case 1: {

                int idBuscar;

                system("cls");

                cout << "ID del proceso a encolar: ";
                cin >> idBuscar;

                Nodo* encontrado =
                listaProcesos.buscarProceso(idBuscar);

                if (encontrado != NULL) {

                    colaPrioridad.encolar(encontrado->dato);

                } else {

                    cout << "\nProceso no encontrado.\n";
                }

                system("pause");

            break;
            }

            // MOSTRAR COLA

            case 2:

                system("cls");

                colaPrioridad.mostrarCola();

                system("pause");

            break;

            // EJECUTAR

            case 3:

                system("cls");

                colaPrioridad.ejecutarProceso();

                system("pause");

            break;

            case 4:

                cout << "\nVolviendo al menu principal...\n";

            break;

            default:

                cout << "\n[ERROR] Opcion no valida.\n";

                system("pause");
        }

    } while(opcion != 4);
}

// ===============================

void menuPila(Lista &listaProcesos,
              Pilas &pilaMemoria) {

    int opcion;

    do {

        system("cls");

        cout << "=========================================\n";
        cout << " GESTION DE MEMORIA RAM\n";
        cout << "=========================================\n";

        cout << "1. Asignar Memoria\n";
        cout << "2. Liberar Memoria\n";
        cout << "3. Mostrar Memoria RAM\n";
        cout << "4. Mostrar Procesos en RAM\n";
        cout << "5. Volver\n";

        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {

            // ASIGNAR MEMORIA

            case 1: {

                int idBuscar;

                system("cls");

                cout << "ID del proceso: ";
                cin >> idBuscar;

                Nodo* encontrado =
                listaProcesos.buscarProceso(idBuscar);

                if (encontrado != NULL) {

                    pilaMemoria.push(encontrado->dato);

                } else {

                    cout << "\nProceso no encontrado.\n";
                }

                system("pause");

            break;
            }

            // LIBERAR MEMORIA

            case 2:

                system("cls");

                pilaMemoria.pop();

                system("pause");

            break;

            // MOSTRAR RAM

            case 3:

                system("cls");

                pilaMemoria.mostrarMemoria();

                system("pause");

            break;

            // MOSTRAR PROCESOS RAM

            case 4:

                system("cls");

                pilaMemoria.mostrarProcesosMemoria();

                system("pause");

            break;

            case 5:

                cout << "\nVolviendo al menu principal...\n";

            break;

            default:

                cout << "\n[ERROR] Opcion no valida.\n";

                system("pause");
        }

    } while(opcion != 5);
}

// ===============================
// MAIN PRINCIPAL
// ===============================

int main() {

    Lista listaProcesos;

    Colas colaPrioridad;

    Pilas pilaMemoria;

    int opcion;

    do {

        system("cls");

        cout << "=========================================\n";
        cout << " SISTEMA DE GESTION DE PROCESOS\n";
        cout << "=========================================\n";

        cout << "1. Gestionar Lista de Procesos\n";
        cout << "2. Gestionar Cola CPU\n";
        cout << "3. Gestionar Memoria RAM\n";
        cout << "4. Salir\n";

        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:

                menuLista(listaProcesos);

            break;

            case 2:

                menuCola(listaProcesos,
                          colaPrioridad);

            break;

            case 3:

                menuPila(listaProcesos,
                         pilaMemoria);

            break;

            case 4:

                cout << "\nSaliendo del sistema...\n";

            break;

            default:

                cout << "\n[ERROR] Opcion no valida.\n";

                system("pause");
        }

    } while(opcion != 4);

    return 0;
}