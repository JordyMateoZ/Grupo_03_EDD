#include <iostream>

using namespace std;


#define MAX 5


int cola[MAX];

int frente = -1;
int final = -1;


bool estaVacia()
{
    return frente == -1;
}


bool estaLlena()
{
    return final == MAX - 1;
}


void registrarTurno(int numeroTurno)
{
    if(estaLlena())
    {
        cout << "La cola de turnos esta llena." << endl;
    }
    else
    {
        if(frente == -1)
        {
            frente = 0;
        }

        final++;

        cola[final] = numeroTurno;

        cout << "Turno " << numeroTurno
             << " registrado correctamente." << endl;
    }
}


void atenderTurno()
{
    if(estaVacia())
    {
        cout << "No hay turnos en espera." << endl;
    }
    else
    {
        cout << "Atendiendo turno: "
             << cola[frente] << endl;

        frente++;

        if(frente > final)
        {
            frente = final = -1;
        }
    }
}


int siguienteTurno()
{
    if(estaVacia())
    {
        return -1;
    }

    return cola[frente];
}


void mostrarTurnos()
{
    if(estaVacia())
    {
        cout << "No hay turnos registrados." << endl;
    }
    else
    {
        cout << "\n--- TURNOS EN ESPERA ---\n";

        for(int i = frente; i <= final; i++)
        {
            cout << "Turno " << cola[i] << endl;
        }
    }
}


void cantidadTurnos()
{
    if(estaVacia())
    {
        cout << "Cantidad de turnos: 0" << endl;
    }
    else
    {
        cout << "Cantidad de turnos: "
             << final - frente + 1 << endl;
    }
}


void eliminarTodos()
{
    frente = -1;
    final = -1;

    cout << "Todos los turnos fueron eliminados."
         << endl;
}


int main()
{
    int opcion;

    int numeroTurno;

    do
    {
        cout << "\n";
        cout << "===== SISTEMA DE TURNOS =====" << endl;
        cout << "1. Registrar turno" << endl;
        cout << "2. Atender turno" << endl;
        cout << "3. Ver siguiente turno" << endl;
        cout << "4. Mostrar cola de turnos" << endl;
        cout << "5. Verificar si la cola esta vacia" << endl;
        cout << "6. Mostrar cantidad de turnos" << endl;
        cout << "7. Eliminar todos los turnos" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:

                cout << "Ingrese numero de turno: ";
                cin >> numeroTurno;

                registrarTurno(numeroTurno);

                break;

            case 2:

                atenderTurno();

                break;

            case 3:

                if(estaVacia())
                {
                    cout << "No hay turnos en espera."<< endl;
                }
                else
                {
                    cout << "Siguiente turno: "<< siguienteTurno() << endl;
                }

                break;

            case 4:

                mostrarTurnos();

                break;

            case 5:

                if(estaVacia())
                {
                    cout << "La cola esta vacia."<< endl;
                }
                else
                {
                    cout << "Hay turnos en espera."<< endl;
                }

                break;

            case 6:

                cantidadTurnos();

                break;

            case 7:

                eliminarTodos();

                break;

            case 8:

                cout << "Programa finalizado."<< endl;

                break;

            default:

                cout << "Opcion incorrecta."<< endl;
        }

    }while(opcion != 8);

    return 0;
}
