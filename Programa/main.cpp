#include <iostream>
#include <string>

using namespace std;

class Estacion {
private:
    string nombre;
    int tiempoSiguiente;
    int tiempoAnterior;
    bool esTransferencia;

public:

    Estacion(const string& nom, int sig, int ant, bool trans)
        : nombre(nom), tiempoSiguiente(sig), tiempoAnterior(ant), esTransferencia(trans) {}


    const string& getNombre() const { return nombre; }
    int getTiempoSiguiente() const { return tiempoSiguiente; }
    int getTiempoAnterior() const { return tiempoAnterior; }
    bool getEsTransferencia() const { return esTransferencia; }


    void setNombre(const string& nom) { nombre = nom; }
    void setTiempoSiguiente(int sig) { tiempoSiguiente = sig; }
    void setTiempoAnterior(int ant) { tiempoAnterior = ant; }
    void setEsTransferencia(bool trans) { esTransferencia = trans; }


    void imprimirInformacion() const {
        cout << "Estación: " << nombre << "\n";
        cout << "Tiempo al siguiente: " << tiempoSiguiente << " segundos\n";
        cout << "Tiempo al anterior: " << tiempoAnterior << " segundos\n";
        cout << "Es transferencia: " << (esTransferencia ? "Sí" : "No") << "\n";
    }
};

int main() {
    Estacion estacion1("Poblado", 60, 45, false);
    Estacion estacion2("Industriales", 70, 60, true);

    cout << "Información de la estación 1:\n";
    estacion1.imprimirInformacion();
    cout << "\nInformación de la estación 2:\n";
    estacion2.imprimirInformacion();

    return 0;
}

