#include "TxVisualitzaPelicula.h"
#include <stdexcept>

// Constructor: inicializa el título de la película
TxVisualitzaPelicula::TxVisualitzaPelicula(const std::string& titol) : titolPelicula(titol) {}

// Método principal para ejecutar la transacción
bool TxVisualitzaPelicula::executar() {
    // Consultar la película
    auto pelicula = PassarelaPelicula::consultaPelicula(titolPelicula);
    if (!pelicula) {
        throw PeliculaNoExisteix();
    }

    // Verificar la edad del usuario loggeado
    Usuari* usuariLoggejat = Usuari::getUsuariLoggejat();
    if (usuariLoggejat->getEdat() < pelicula->getQualificacio()) {
        throw ErrorEdatInadequada();
    }

    // Verificar si la película ya está estrenada
    if (!pelicula->estrenada()) {
        throw PeliculaNoEstrenada();
    }

    // Registrar la visualización
    PassarelaVisualitzacioPelicula::registraVisualitzacio(
        usuariLoggejat->getSobrenom(),
        titolPelicula
    );

    return true;
}
