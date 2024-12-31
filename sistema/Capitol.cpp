#include "Capitol.h"

Capitol::Capitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol, int numVisualitzacions)
    : titolSerie(titolSerie), numeroTemporada(numeroTemporada), numeroCapitol(numeroCapitol), numVisualitzacions(numVisualitzacions) {}

std::string Capitol::getTitolSerie() const {
    return titolSerie;
}

int Capitol::getNumeroTemporada() const {
    return numeroTemporada;
}

int Capitol::getNumeroCapitol() const {
    return numeroCapitol;
}

int Capitol::getNumVisualitzacions() const {
    return numVisualitzacions;
}

