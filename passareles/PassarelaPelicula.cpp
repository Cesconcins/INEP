#include "PassarelaPelicula.h"
#include "../sistema/DBConnection.h""

Pelicula::Pelicula(const std::string& titol, int qualificacio, bool estrenada)
    : titol(titol), qualificacio(qualificacio), estrenada(estrenada) {}

std::string Pelicula::getTitol() const {
    return titol;
}

int Pelicula::getQualificacio() const {
    return qualificacio;
}

bool Pelicula::isEstrenada() const {
    return estrenada;
}
