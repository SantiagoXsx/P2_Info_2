#ifndef CONEXION_ESTACION_H
#define CONEXION_ESTACION_H

#include <string>


using namespace std;
class ConexionEstacion {
private:
    string estacionOrigen;
    string estacionDestino;
    int tiempoViaje;
    bool transferencia;

public:
    // Constructor
    ConexionEstacion(const string& origen, const string& destino, int tiempo, bool esTransferencia);

    // Destructor
    ~ConexionEstacion();

    // Getters y Setters
    string obtenerEstacionOrigen() const;
    void establecerEstacionOrigen(const std::string& origen);
    string obtenerEstacionDestino() const;
    void establecerEstacionDestino(const std::string& destino);
    int obtenerTiempoViaje() const;
    void establecerTiempoViaje(int tiempo);
    bool esTransferencia() const;
    void establecerTransferencia(bool esTransferencia);
};

#endif // CONEXION_ESTACION_H
