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

class Linea {
private:
    string nombre;

public:
    Linea(string _nombre) : nombre(_nombre) {}

    string getNombre() const {
        return nombre;
    }
};

class RedMetro {
private:
    Estacion** estaciones;
    Linea** lineas;
    int numEstaciones;
    int numLineas;
    static const int MAX_ESTACIONES = 100;
    static const int MAX_LINEAS = 10;

public:
    RedMetro() : estaciones(new Estacion*[MAX_ESTACIONES]), lineas(new Linea*[MAX_LINEAS]), numEstaciones(0), numLineas(0) {}

    ~RedMetro() {
        for (int i = 0; i < numEstaciones; ++i) {
            delete estaciones[i];
        }
        delete[] estaciones;

        for (int i = 0; i < numLineas; ++i) {
            delete lineas[i];
        }
        delete[] lineas;
    }

    void agregarLinea(const string& nombreLinea) {
        if (numLineas < MAX_LINEAS) {
            lineas[numLineas++] = new Linea(nombreLinea);
        } else {
            cout << "No se puede agregar más líneas. Se alcanzó el límite máximo." << endl;
        }
    }

    void eliminarLinea(int indiceLinea) {
        if (indiceLinea >= 0 && indiceLinea < numLineas) {
            delete lineas[indiceLinea];
            for (int i = indiceLinea; i < numLineas - 1; ++i) {
                lineas[i] = lineas[i + 1];
            }
            numLineas--;
        } else {
            cout << "Índice de línea inválido." << endl;
        }
    }

    int numeroLineas() const {
        return numLineas;
    }
    int numeroEstaciones() const {
        return numEstaciones;
    }

    int numeroEstacionesTransferencia() const {
        int count = 0;
        for (int i = 0; i < numEstaciones; ++i) {
            if (estaciones[i]->getEsTransferencia()) {
                count++;
            }
        }
        return count;
    }
};
