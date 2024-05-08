#ifndef LINEA_H
#define LINEA_H

#include <string>

using namespace std;

class Estacion;

class Linea {
private:
    string nombre;
    Estacion** estaciones;
    int capacidadMaxima; // Capacidad máxima del array
    int cantidadEstaciones; // Cantidad actual de estaciones en la línea


public:
    // Constructor
    Linea(const string& _nombre, int _capacidadMaxima);

    // Destructor
    ~Linea();

    // Método para agregar una estación al final de la línea
    void agregarEstacion(Estacion* estacion, int posicion);

    // Método para eliminar una estación de la línea
    void eliminarEstacion(const string& nombreEstacion);

    // Método para obtener el nombre de la línea
    string obtenerNombre() const;

    // Método para imprimir la lista de estaciones
    void imprimirEstaciones() const;

    //Método para verificar si una estacion pertenece a una linea
    bool verificarEstacion(const string& nombreEstacion) const;

    int numeroEstaciones() const;
    
    Estacion* obtenerEstacion(int indice) const;



};

#endif // LINEA_H
