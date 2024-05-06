#include <iostream>
#include "redmetro.h"

using namespace std;

int main() {
    RedMetro red;

    char opcion;
    do {
        cout << "1. Agregar linea\n";
        cout << "2. Agregar estacion a una linea existente\n";
        cout << "3. Eliminar estacion de una linea existente\n";
        cout << "4. Cantidad de lineas en la red\n";
        cout << "5. Verificar si una estacion pertenece a una linea\n";
        cout << "6. Eliminar linea\n";
        cout << "7. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch(opcion) {
        case '1':
        {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            red.agregarLinea(nombreLinea);
            cout << "Linea agregada correctamente.\n";
            break;
        }
        case '2':
        {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea a la que desea agregar la estacion: ";
            cin >> nombreLinea;
            Linea* linea = red.obtenerLinea(nombreLinea);
            if (linea != nullptr) {
                string nombreEstacion;
                int tiempoAnterior, tiempoSiguiente;
                bool esTransferencia;

                cout << "Ingrese el nombre de la estacion: ";
                cin >> nombreEstacion;
                cout << "Ingrese el tiempo anterior (en segundos): ";
                cin >> tiempoAnterior;
                cout << "Ingrese el tiempo siguiente (en segundos): ";
                cin >> tiempoSiguiente;
                cout << "Es una estacion de transferencia? (1: Si / 0: No): ";
                cin >> esTransferencia;

                Estacion* estacion = new Estacion(nombreEstacion, tiempoAnterior, tiempoSiguiente, esTransferencia);
                linea->agregarEstacion(estacion);
                cout << "Estacion agregada a la linea correctamente.\n";
            } else {
                cout << "La linea especificada no existe.\n";
            }
            break;
        }
        case '3':
        {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea de la que desea eliminar la estacion: ";
            cin >> nombreLinea;
            Linea* linea = red.obtenerLinea(nombreLinea);
            if (linea != nullptr) {
                string nombreEstacion;
                cout << "Ingrese el nombre de la estacion que desea eliminar: ";
                cin >> nombreEstacion;
                Estacion* estacion = new Estacion(nombreEstacion, 0, 0, false);
                if (linea->verificarEstacion(nombreEstacion)) {
                    linea->eliminarEstacion(estacion);
                    cout << "Estacion eliminada de la linea correctamente.\n";
                } else {
                    cout << "La estacion especificada no pertenece a la linea.\n";
                }
            } else {
                cout << "La linea especificada no existe.\n";
            }
            break;
        }
        case '4':
            cout << "Cantidad de lineas en la red: " << red.numeroLineas() << endl;
            break;
        case '5':
        {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            Linea* linea = red.obtenerLinea(nombreLinea);
            if (linea != nullptr) {
                string nombreEstacion;
                cout << "Ingrese el nombre de la estacion: ";
                cin >> nombreEstacion;
                if (linea->verificarEstacion(nombreEstacion)) {
                    cout << "La estacion pertenece a la linea.\n";
                } else {
                    cout << "La estacion no pertenece a la linea.\n";
                }
            } else {
                cout << "La linea especificada no existe.\n";
            }
            break;
        }
        case '6':
        {
            int indiceLinea;
            cout << "Ingrese el numero de la linea que desea eliminar: ";
            cin >> indiceLinea;
            red.eliminarLinea(indiceLinea - 1);
            break;
        }
        case '7':
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != '7');

    return 0;
}
