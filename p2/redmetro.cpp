#include "redmetro.h"
#include "linea.h"

RedMetro::RedMetro() : estaciones(new Estacion*[MAX_ESTACIONES]), lineas(new Linea*[MAX_LINEAS]), numEstaciones(0), numLineas(0) {}

RedMetro::~RedMetro() {
    for (int i = 0; i < numEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;

    for (int i = 0; i < numLineas; ++i) {
        delete lineas[i];
    }
    delete[] lineas;
}

void RedMetro::agregarLinea(const string& nombreLinea) {
    // Verificar si ya existe una línea con el mismo nombre
    for (int i = 0; i < numLineas; ++i) {
        if (lineas[i]->obtenerNombre() == nombreLinea) {
            cout << "Ya existe una linea con el nombre '" << nombreLinea << "'. No se puede agregar una nueva linea con el mismo nombre.\n";
            return; // Salir del método si ya existe una línea con el mismo nombre
        }
    }

    // Si no se encuentra ninguna línea con el mismo nombre, agregar la nueva línea
    if (numLineas < MAX_LINEAS) {
        lineas[numLineas++] = new Linea(nombreLinea, capacidadmaxima);
        cout << "Linea agregada correctamente.\n";
    } else {
        cout << "No se puede agregar mas lineas. Se alcanzo el limite máximo.\n";
    }
}

void RedMetro::eliminarLinea(int indiceLinea) {
    if (indiceLinea >= 0 && indiceLinea < numLineas) {
        delete lineas[indiceLinea];
        for (int i = indiceLinea; i < numLineas - 1; ++i) {
            lineas[i] = lineas[i + 1];
        }
        numLineas--;
    } else {
        std::cout << "Indice de linea invalido." << std::endl;
    }
}

int RedMetro::numeroLineas() const {
    return numLineas;
}

int RedMetro::numeroEstaciones() const {
    return numEstaciones;
}

int RedMetro::numeroEstacionesTransferencia() const {
    int count = 0;
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->getEsTransferencia()) {
            count++;
        }
    }
    return count;
}

void RedMetro::imprimirInformacion() const {
    std::cout << "Numero de lineas: " << numLineas << "\n";
    //Siempre da cero porque no hay metodos para agregar estaciones
    std::cout << "Numero de estaciones: " << numEstaciones << "\n";
    std::cout << "Numero de estaciones de transferencia: " << numeroEstacionesTransferencia() << "\n";
}

Linea* RedMetro::obtenerLinea(const string& nombreLinea) const {
    for (int i = 0; i < numLineas; ++i) {
        if (lineas[i]->obtenerNombre() == nombreLinea) {
            return lineas[i];
        }
    }
    return nullptr; // Si no se encuentra la línea, devolvemos nullptr
}

int RedMetro::numeroEstacionesEnLinea(const std::string& nombreLinea) const {
    Linea* linea = obtenerLinea(nombreLinea);
    if (linea != nullptr) {
        return linea->numeroEstaciones();
    } else {
        return -1; // Retorna -1 si la línea no existe
    }
}

int RedMetro::numeroEstacionesUnicas() const {
    const int MAX_ESTACIONES = 1000; // Tamaño máximo del array de estaciones
    string estaciones[MAX_ESTACIONES]; // Array para almacenar nombres de estaciones
    int numEstaciones = 0; // Número actual de estaciones

    // Iterar sobre todas las líneas en la red
    for (int i = 0; i < numLineas; ++i) {
        Linea* linea = lineas[i];
        // Iterar sobre todas las estaciones en la línea actual
        for (int j = 0; j < linea->numeroEstaciones(); ++j) {
            Estacion* estacion = linea->obtenerEstacion(j);
            bool esEstacionNueva = true;

            // Verificar si la estación ya ha sido contada
            for (int k = 0; k < numEstaciones; ++k) {
                if (estaciones[k] == estacion->getNombre()) {
                    esEstacionNueva = false;
                    break;
                }
            }

            // Si la estación es nueva, agregarla al array de estaciones
            if (esEstacionNueva) {
                estaciones[numEstaciones++] = estacion->getNombre();
            }
        }
    }

    return numEstaciones; // Devolver el número de estaciones encontradas
}


int RedMetro::calcularTiempoLlegada(const string& nombreLinea, const string& estacionOrigen, const string& estacionDestino, int horaSalida) const {
    Linea* linea = obtenerLinea(nombreLinea);

    if (linea == nullptr) {
        cout << "La linea especificada no existe en la red.\n";
        return -1;
    }

    // Verificar si las estaciones existen en la línea especificada
    if (!linea->verificarEstacion(estacionOrigen) || !linea->verificarEstacion(estacionDestino)) {
        cout << "Al menos una de las estaciones especificadas no existe en la linea.\n";
        return -1;
    }

    // Obtener las estaciones desde la línea
    Estacion* origen = nullptr;
    Estacion* destino = nullptr;
    int posicionOrigen = -1;
    int posicionDestino = -1;
    for (int i = 0; i < linea->numeroEstaciones(); ++i) {
        Estacion* estacion = linea->obtenerEstacion(i);
        if (estacion->getNombre() == estacionOrigen) {
            origen = estacion;
            posicionOrigen = i;
        }
        if (estacion->getNombre() == estacionDestino) {
            destino = estacion;
            posicionDestino = i;
        }
    }

    // Verificar si se encontraron las estaciones
    if (origen == nullptr || destino == nullptr) {
        cout << "Error al encontrar las estaciones en la linea.\n";
        return -1;
    }

    // Calcular el tiempo de viaje entre las estaciones
    int tiempoViaje;
    if (posicionOrigen == posicionDestino - 1) {
        // Las estaciones están una junto a la otra
        tiempoViaje = destino->getTiempoSiguiente();
    } else {
        // Las estaciones están a una distancia de n estaciones
        tiempoViaje = origen->getTiempoSiguiente();
    }

    // Calcular los minutos y segundos adicionales
    int minutos = tiempoViaje / 60; // Convertir segundos a minutos
    int segundos = tiempoViaje % 60; // Resto de la división por 60 para obtener los segundos adicionales

    // Calcular la hora de llegada
    int horaLlegada = horaSalida + tiempoViaje;

    // Ajustar la hora de llegada si supera las 24 horas
    horaLlegada %= 24;

    // Mostrar el tiempo de llegada
    cout << "El tren partira a las " << horaSalida << ":00 y llegara a las " << horaLlegada << ":" << minutos << ":" << segundos << endl;

    return horaLlegada;
}
