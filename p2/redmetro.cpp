#include "redmetro.h"

RedMetro::RedMetro() : estaciones(new Estacion*[MAX_ESTACIONES]), lineas(new Linea*[MAX_LINEAS]), numEstaciones(0), numLineas(0) {}

RedMetro::~RedMetro() {
    for (int i = 0; i < numEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;

    for (int i = 0; i < numLineas; ++i) {
        delete lineas[i];
    }
    delete[] lineas;
}

void RedMetro::agregarLinea(const string& nombreLinea) {
    if (numLineas < MAX_LINEAS) {
        lineas[numLineas++] = new Linea(nombreLinea, capacidadmaxima);
    } else {
        std::cout << "No se puede agregar mas lineas. Se alcanzo el limite mximo." << std::endl;
    }
}

void RedMetro::eliminarLinea(int indiceLinea) {
    if (indiceLinea >= 0 && indiceLinea < numLineas) {
        delete lineas[indiceLinea];
        for (int i = indiceLinea; i < numLineas - 1; ++i) {
            lineas[i] = lineas[i + 1];
        }
        numLineas--;
    } else {
        std::cout << "Indice de linea invalido." << std::endl;
    }
}

int RedMetro::numeroLineas() const {
    return numLineas;
}

int RedMetro::numeroEstaciones() const {
    return numEstaciones;
}

int RedMetro::numeroEstacionesTransferencia() const {
    int count = 0;
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->getEsTransferencia()) {
            count++;
        }
    }
    return count;
}

void RedMetro::imprimirInformacion() const {
    std::cout << "Numero de lineas: " << numLineas << "\n";
    //Siempre da cero porque no hay metodos para agregar estaciones
    std::cout << "Numero de estaciones: " << numEstaciones << "\n";
    std::cout << "Numero de estaciones de transferencia: " << numeroEstacionesTransferencia() << "\n";
}

Linea* RedMetro::obtenerLinea(const string& nombreLinea) const {
    for (int i = 0; i < numLineas; ++i) {
        if (lineas[i]->obtenerNombre() == nombreLinea) {
            return lineas[i];
        }
    }
    return nullptr; // Si no se encuentra la línea, devolvemos nullptr
}
