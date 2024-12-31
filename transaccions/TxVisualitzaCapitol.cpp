#include "TxVisualitzaCapitol.h"
#include <stdexcept>

TxVisualitzaCapitol::TxVisualitzaCapitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol)
    : titolSerie(titolSerie), numeroTemporada(numeroTemporada), numeroCapitol(numeroCapitol) {}

bool TxVisualitzaCapitol::executar() {
    // Aquí va la lógica para validar si el capítulo existe, si es adecuado para la edad, y si ya está estrenado
    bool capitolExisteix = true; // Ejemplo de validación ficticia
    bool edatAdequada = true; // Ejemplo de validación ficticia
    bool capitolEstrenat = true; // Ejemplo de validación ficticia

    if (!capitolExisteix) {
        throw CapitolNoExisteix();
    }
    if (!edatAdequada) {
        throw ErrorEdatInadequada();
    }
    if (!capitolEstrenat) {
        throw CapitolNoEstrenat();
    }

    return true;
}

const char* TxVisualitzaCapitol::CapitolNoExisteix::what() const noexcept {
    return "El capítol no existeix.";
}

const char* TxVisualitzaCapitol::ErrorEdatInadequada::what() const noexcept {
    return "Edat inadequada per veure aquest capítol.";
}

const char* TxVisualitzaCapitol::CapitolNoEstrenat::what() const noexcept {
    return "El capítol encara no ha estat estrenat.";
}