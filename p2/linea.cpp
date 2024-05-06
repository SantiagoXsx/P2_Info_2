#include "linea.h"
#include <iostream>

using namespace std;

// Constructor
Linea::Linea(const std::string& _nombre, int _capacidadMaxima) : nombre(_nombre), capacidadMaxima(_capacidadMaxima), cantidadEstaciones(0) {
    estaciones = new std::string[capacidadMaxima]; // Crear array con la capacidad máxima
}

// Destructor
Linea::~Linea() {
    delete[] estaciones; // Liberar memoria asignada al array
}

// Método para agregar una estación al final de la línea
void Linea::agregarEstacion(const std::string& nombreEstacion) {
    if (cantidadEstaciones < capacidadMaxima) {
        estaciones[cantidadEstaciones++] = nombreEstacion;
    } else {
        cout << "No se pueden agregar mas estaciones. La linea esta llena." << endl;
    }
}

// Método para eliminar una estación de la línea
void Linea::eliminarEstacion(const std::string& nombreEstacion) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i] == nombreEstacion) {
            // Mover las estaciones restantes una posición hacia atrás
            for (int j = i; j < cantidadEstaciones - 1; ++j) {
                estaciones[j] = estaciones[j + 1];
            }
            cantidadEstaciones--;
            break;  // Importante salir del bucle después de eliminar la estación
        }
    }
}

// Método para obtener el nombre de la línea
string Linea::obtenerNombre() const {
    return nombre;
}

// Método para imprimir la lista de estaciones
void Linea::imprimirEstaciones() const {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        cout << estaciones[i] << endl;
    }
}

bool Linea::verificarEstacion(const std::string& nombreEstacion) const {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i] == nombreEstacion) {
            return true;
        }
    }
    return false;
}
