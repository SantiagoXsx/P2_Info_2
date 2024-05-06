#ifndef REDMETRO_H
#define REDMETRO_H

#include <iostream>

class Estacion;

class RedMetro {
private:
    Estacion** estaciones;
    int numEstaciones;
    static const int MAX_ESTACIONES = 100;

public:
    RedMetro();
    ~RedMetro();

    void agregarEstacion(const std::string& nombre, int tiempoSiguiente, int tiempoAnterior, bool esTransferencia);
    void eliminarEstacion(const std::string& nombre);
    void imprimirInformacion() const;
};

#endif // REDMETRO_H
