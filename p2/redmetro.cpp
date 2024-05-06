#include "redmetro.h"
#include "estacion.h"

RedMetro::RedMetro() : estaciones(new Estacion*[MAX_ESTACIONES]), numEstaciones(0) {}

RedMetro::~RedMetro() {
    for (int i = 0; i < numEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;
}

void RedMetro::agregarEstacion(const std::string& nombre, int tiempoSiguiente, int tiempoAnterior, bool esTransferencia) {
    if (numEstaciones < MAX_ESTACIONES) {
        estaciones[numEstaciones++] = new Estacion(nombre, tiempoSiguiente, tiempoAnterior, esTransferencia);
    } else {
        std::cout << "No se pueden agregar más estaciones. Se alcanzó el límite máximo." << std::endl;
    }
}

void RedMetro::eliminarEstacion(const std::string& nombre) {
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nombre) {
            delete estaciones[i];
            for (int j = i; j < numEstaciones - 1; ++j) {
                estaciones[j] = estaciones[j + 1];
            }
            numEstaciones--;
            return;
        }
    }
    std::cout << "La estación '" << nombre << "' no se encontró en la red de metro." << std::endl;
}

void RedMetro::imprimirInformacion() const {
    std::cout << "Número de estaciones: " << numEstaciones << std::endl;
    for (int i = 0; i < numEstaciones; ++i) {
        estaciones[i]->imprimirInformacion();
    }
}
