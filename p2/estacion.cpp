#include "estacion.h"
#include <iostream>

Estacion::Estacion(const string& nom, int sig, int ant, bool trans)
    : nombre(nom), tiempoSiguiente(sig), tiempoAnterior(ant), esTransferencia(trans) {}

Estacion::~Estacion() {}

const string& Estacion::getNombre() const {
    return nombre;
}

int Estacion::getTiempoSiguiente() const {
    return tiempoSiguiente;
}

int Estacion::getTiempoAnterior() const {
    return tiempoAnterior;
}

bool Estacion::getEsTransferencia() const {
    return esTransferencia;
}

void Estacion::setNombre(const string& nom) {
    nombre = nom;
}

void Estacion::setTiempoSiguiente(int sig) {
    tiempoSiguiente = sig;
}

void Estacion::setTiempoAnterior(int ant) {
    tiempoAnterior = ant;
}

void Estacion::setEsTransferencia(bool trans) {
    esTransferencia = trans;
}

void Estacion::imprimirInformacion() const {
    cout << "Estación: " << nombre << "\n";
    cout << "Tiempo al siguiente: " << tiempoSiguiente << " segundos\n";
    cout << "Tiempo al anterior: " << tiempoAnterior << " segundos\n";
    cout << "Es transferencia: " << (esTransferencia ? "Sí" : "No") << "\n";
}
