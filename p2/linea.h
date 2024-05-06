#ifndef LINEA_H
#define LINEA_H

#include <string>

using namespace std;

class Linea {
private:
    string nombre;
    string* estaciones; // Array de strings para almacenar las estaciones
    int capacidadMaxima; // Capacidad máxima del array
    int cantidadEstaciones; // Cantidad actual de estaciones en la línea

public:
    // Constructor
    Linea(const string& _nombre, int _capacidadMaxima);

    // Destructor
    ~Linea();

    // Método para agregar una estación al final de la línea
    void agregarEstacion(const string& nombreEstacion);

    // Método para eliminar una estación de la línea
    void eliminarEstacion(const string& nombreEstacion);

    // Método para obtener el nombre de la línea
    string obtenerNombre() const;

    // Método para imprimir la lista de estaciones
    void imprimirEstaciones() const;

    //Método para verificar si una estacion pertenece a una linea
    bool verificarEstacion(const std::string& nombreEstacion) const;

};

#endif // LINEA_H
