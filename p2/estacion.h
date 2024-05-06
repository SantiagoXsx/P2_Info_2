#ifndef ESTACION_H
#define ESTACION_H

#include <string>
using namespace std;

class Estacion {
private:
    string nombre;
    int tiempoSiguiente;
    int tiempoAnterior;
    bool esTransferencia;

public:
    Estacion(const string& nom, int sig, int ant, bool trans);
    ~Estacion();

    const string& getNombre() const;
    int getTiempoSiguiente() const;
    int getTiempoAnterior() const;
    bool getEsTransferencia() const;

    void setNombre(const string& nom);
    void setTiempoSiguiente(int sig);
    void setTiempoAnterior(int ant);
    void setEsTransferencia(bool trans);

    void imprimirInformacion() const;
};

#endif // ESTACION_H
