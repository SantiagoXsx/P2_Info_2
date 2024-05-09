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

void Linea::agregarEstacion(Estacion* estacion, int posicion) {
    if (posicion < 0 || posicion > cantidadEstaciones) {
        cout << "Posicion invalida. La posicion debe estar entre 0 y " << cantidadEstaciones << endl;
        return;
    }

    if (cantidadEstaciones == capacidadMaxima) {
        cout << "No se pueden agregar mas estaciones. La linea esta llena." << endl;
        return;
    }

    Estacion** nuevasEstaciones = new Estacion*[capacidadMaxima + 1];

    for (int i = 0, j = 0; i <= cantidadEstaciones; ++i) {
        if (i == posicion) {
            nuevasEstaciones[i] = estacion;
        } else {
            nuevasEstaciones[i] = estaciones[j++];
        }
    }

    delete[] estaciones;

    estaciones = nuevasEstaciones;

    cantidadEstaciones++;
}


// Método para eliminar una estación de la línea
void Linea::eliminarEstacion(const string& nombreEstacion) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getNombre() == nombreEstacion) {
            delete estaciones[i]; // Liberar memoria de la estación eliminada
            // Ajustar el tiempo de viaje entre estaciones adyacentes
            for (int j = i; j < cantidadEstaciones - 1; ++j) {
                // Si hay una estación después de la estación eliminada, ajustar el tiempo de viaje
                if (j + 1 < cantidadEstaciones) {
                    int nuevoTiempoViaje = estaciones[j + 1]->getTiempoAnterior() + estaciones[j + 1]->getTiempoSiguiente();
                    estaciones[j]->setTiempoSiguiente(nuevoTiempoViaje);
                }
                // Mover las estaciones restantes una posición hacia atrás
                estaciones[j] = estaciones[j + 1];
            }
            cantidadEstaciones--;
            break;
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

int Linea::numeroEstaciones() const {
    return cantidadEstaciones;
}

Estacion* Linea::obtenerEstacion(int indice) const {
    if (indice >= 0 && indice < cantidadEstaciones) {
        return estaciones[indice];
    } else {
        return nullptr;
    }
}
