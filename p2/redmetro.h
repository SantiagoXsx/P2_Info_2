#ifndef REDMETRO_H
#define REDMETRO_H

#include <iostream>
#include <string>
#include "estacion.h"
#include "linea.h"

class RedMetro {
private:
    Estacion** estaciones;
    Linea** lineas;
    int numEstaciones;
    int numLineas;
    static const int MAX_ESTACIONES = 100;
    static const int MAX_LINEAS = 10;
    static const int capacidadmaxima = 10;

public:
    RedMetro();
    ~RedMetro();

    void agregarLinea(const string& nombreLinea);
    void eliminarLinea(int indiceLinea);
    int numeroLineas() const;
    int numeroEstaciones() const;
    int numeroEstacionesTransferencia() const;
    void imprimirInformacion() const;
    Linea* obtenerLinea(const string& nombreLinea) const;

};

#endif // REDMETRO_H
