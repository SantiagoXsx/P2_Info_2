#include "conexionestacion.h"

// Constructor
ConexionEstacion::ConexionEstacion(const string& origen, const string& destino, int tiempo, bool esTransferencia)
    : estacionOrigen(origen), estacionDestino(destino), tiempoViaje(tiempo), transferencia(esTransferencia) {}

// Destructor
ConexionEstacion::~ConexionEstacion() {}

// Getter para obtener la estación de origen
string ConexionEstacion::obtenerEstacionOrigen() const {
    return estacionOrigen;
}

// Setter para establecer la estación de origen
void ConexionEstacion::establecerEstacionOrigen(const string& origen) {
    estacionOrigen = origen;
}

// Getter para obtener la estación de destino
string ConexionEstacion::obtenerEstacionDestino() const {
    return estacionDestino;
}

// Setter para establecer la estación de destino
void ConexionEstacion::establecerEstacionDestino(const string& destino) {
    estacionDestino = destino;
}

// Getter para obtener el tiempo de viaje
int ConexionEstacion::obtenerTiempoViaje() const {
    return tiempoViaje;
}

// Setter para establecer el tiempo de viaje
void ConexionEstacion::establecerTiempoViaje(int tiempo) {
    tiempoViaje = tiempo;
}

// Getter para verificar si hay transferencia en la conexión
bool ConexionEstacion::esTransferencia() const {
    return transferencia;
}

// Setter para establecer si hay transferencia en la conexión
void ConexionEstacion::establecerTransferencia(bool esTransferencia) {
    transferencia = esTransferencia;
}
