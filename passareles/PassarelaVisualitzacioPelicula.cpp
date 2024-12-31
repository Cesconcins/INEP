#include "TxVisualitzaPelicula.h"
#include "../passareles/PassarelaPelicula.h"

TxVisualitzaPelicula::TxVisualitzaPelicula(const std::string& titolPelicula)
    : titolPelicula(titolPelicula) {}

bool TxVisualitzaPelicula::executar() {
    auto pelicula = PassarelaPelicula::consultaPelicula(titolPelicula);
    if (!pelicula) {
        throw PeliculaNoExisteix();
    }

    if (!pelicula->isEstrenada()) {
        throw PeliculaNoEstrenada();
    }

    PassarelaVisualitzacioPelicula::registraVisualitzacio(pelicula->getTitol());
    return true;
}
