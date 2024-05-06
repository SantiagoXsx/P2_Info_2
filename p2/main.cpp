#include <iostream>
#include "conexionestacion.h"

using namespace std;

int main() {
    // Crear una instancia de ConexionEstacion
    ConexionEstacion conexion("Estacion A", "Estacion B", 10, true);

    // Acceder a los atributos y mostrar la información
    cout << "Estacion de origen: " << conexion.obtenerEstacionOrigen() << endl;
    cout << "Estacion de destino: " << conexion.obtenerEstacionDestino() << endl;
    cout << "Tiempo de viaje: " << conexion.obtenerTiempoViaje() << " minutos" << endl;
    cout << "Es una estacion de transferencia: " << (conexion.esTransferencia() ? "Si" : "No") << endl;

    // Modificar algunos atributos
    conexion.establecerEstacionOrigen("Estacion C");
    conexion.establecerTiempoViaje(15);

    // Mostrar la información actualizada
    cout << "\nInformacion actualizada:" << endl;
    cout << "Estacion de origen: " << conexion.obtenerEstacionOrigen() << endl;
    cout << "Tiempo de viaje: " << conexion.obtenerTiempoViaje() << " minutos" << endl;

    return 0;
}
