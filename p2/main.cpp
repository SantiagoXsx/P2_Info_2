#include <iostream>
#include "redmetro.h"

using namespace std;

int main() {
    RedMetro red;

    int opcion;
    do {
        cout << "1. Agregar linea\n";
        cout << "2. Agregar estacion a una linea existente\n";
        cout << "3. Eliminar estacion de una linea existente\n";
        cout << "4. Cantidad de lineas en la red\n";
        cout << "5. Verificar si una estacion pertenece a una linea\n";
        cout << "6. Eliminar linea\n";
        cout << "7. Cantidad de estaciones tiene una linea dada\n";
        cout << "8. Cantidad de estaciones en la red metro\n";
        cout << "9. Imprimir estaciones de una linea\n";
        cout << "10. Calcular tiempo de llegada\n";
        cout << "11. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1: {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            red.agregarLinea(nombreLinea);
            break;
        }
        case 2: {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea a la que desea agregar la estacion: ";
            cin >> nombreLinea;
            Linea* linea = red.obtenerLinea(nombreLinea);
            if (linea != nullptr) {
                string nombreEstacion;
                int tiempoAnterior, tiempoSiguiente;
                bool esTransferencia;
                int posicion;

                cout << "Ingrese el nombre de la estacion: ";
                cin >> nombreEstacion;
                cout << "Ingrese el tiempo anterior (en segundos): ";
                cin >> tiempoAnterior;
                cout << "Ingrese el tiempo siguiente (en segundos): ";
                cin >> tiempoSiguiente;
                cout << "Es una estacion de transferencia? (1: Si / 0: No): ";
                cin >> esTransferencia;
                cout << "Ingrese la posicion de la estacion (entre 0 y " << linea->numeroEstaciones() << "): ";
                cin >> posicion;

                Estacion* estacion = new Estacion(nombreEstacion, tiempoAnterior, tiempoSiguiente, esTransferencia);
                linea->agregarEstacion(estacion, posicion);
                cout << "Estacion agregada a la linea correctamente.\n";
            } else {
                cout << "La linea especificada no existe.\n";
            }
            break;
        }

        case 3: {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea de la que desea eliminar la estacion: ";
            cin >> nombreLinea;
            Linea* linea = red.obtenerLinea(nombreLinea);
            if (linea != nullptr) {
                string nombreEstacion;
                cout << "Ingrese el nombre de la estacion que desea eliminar: ";
                cin >> nombreEstacion;
                if (linea->verificarEstacion(nombreEstacion)) {
                    linea->eliminarEstacion(nombreEstacion);
                    cout << "Estacion eliminada de la linea correctamente.\n";
                } else {
                    cout << "La estacion especificada no pertenece a la linea.\n";
                }
            } else {
                cout << "La linea especificada no existe.\n";
            }
            break;
        }
        case 4:
            cout << "Cantidad de lineas en la red: " << red.numeroLineas() << endl;
            break;
        case 5: {
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
        case 6: {
            int indiceLinea;
            cout << "Ingrese el numero de la linea que desea eliminar: ";
            cin >> indiceLinea;
            red.eliminarLinea(indiceLinea - 1);
            break;
        }
        case 7: {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            int numEstaciones = red.numeroEstacionesEnLinea(nombreLinea);
            if (numEstaciones != -1) {
                cout << "La linea " << nombreLinea << " tiene " << numEstaciones << " estaciones." << endl;
            } else {
                cout << "La linea especificada no existe." << endl;
            }
            break;
        }
        case 8: {
            cout << "Numero de estaciones unicas en la red: " << red.numeroEstacionesUnicas() << endl;
            break;
        }
        case 9: {
            string nombreLinea;
            cout << "Ingrese el nombre de la linea que desea imprimir: ";
            cin >> nombreLinea;
            Linea* linea = red.obtenerLinea(nombreLinea);
            if (linea != nullptr) {
                cout << "Estaciones en la linea " << nombreLinea << ":\n";
                for (int i = 0; i < linea->numeroEstaciones(); ++i) {
                    Estacion* estacion = linea->obtenerEstacion(i);
                    if (estacion != nullptr) {
                        cout << "Posicion " << i << ": " << estacion->getNombre() << endl;
                    }
                }
            } else {
                cout << "La linea especificada no existe.\n";
            }
            break;
        }
        case 10: {
            string nombreLinea, estacionOrigen, estacionDestino;
            int horaSalida;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            cout << "Ingrese la estacion de origen: ";
            cin >> estacionOrigen;
            cout << "Ingrese la estacion de destino: ";
            cin >> estacionDestino;
            cout << "Ingrese la hora de salida (en horas): ";
            cin >> horaSalida;

            int tiempoLlegada = red.calcularTiempoLlegada(nombreLinea, estacionOrigen, estacionDestino, horaSalida);
            if (tiempoLlegada != -1) {
                cout << "El tren llegara a la estacion " << estacionDestino << " en " << tiempoLlegada << " horas.\n";
            }
            break;
        }
        case 11:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 11);

    return 0;
}
