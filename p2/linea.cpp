#include "linea.h"
#include <iostream>
#include "estacion.h"
using namespace std;

// Constructor
Linea::Linea(const string& _nombre, int _capacidadMaxima) : nombre(_nombre), capacidadMaxima(_capacidadMaxima), cantidadEstaciones(0) {
    estaciones = new Estacion*[capacidadMaxima]; // Crear array de punteros a Estacion con la capacidad máxima
}

// Destructor
Linea::~Linea() {
    delete[] estaciones; // Liberar memoria asignada al array de punteros a Estacion
}

// Método para agregar una estación al final de la línea
void Linea::agregarEstacion(Estacion* estacion) {
    if (cantidadEstaciones < capacidadMaxima) {
        estaciones[cantidadEstaciones++] = estacion;
    } else {
        cout << "No se pueden agregar más estaciones. La línea está llena." << endl;
    }
}

// Método para eliminar una estación de la línea
void Linea::eliminarEstacion(Estacion* estacion) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i] == estacion) {
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
        cout << estaciones[i]->getNombre() << endl; // Utilizar el método getNombre() de Estacion
    }
}

bool Linea::verificarEstacion(const string& nombreEstacion) const {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nombreEstacion) { // Utilizar el método getNombre() de Estacion
            return true;
        }
    }
    return false;
}

