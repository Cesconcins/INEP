#ifndef TXVISUALITZAPELICULA_H
#define TXVISUALITZAPELICULA_H

#include <string>
#include "PassarelaPelicula.h"
#include "PassarelaVisualitzacioPelicula.h"
#include "Usuari.h"

class TxVisualitzaPelicula {
private:
    std::string titolPelicula; // Título de la película a visualizar

public:
    // Constructor
    TxVisualitzaPelicula(const std::string& titol);

    // Método principal para ejecutar la transacción
    bool executar();

    // Excepciones personalizadas
    class PeliculaNoExisteix {};
    class ErrorEdatInadequada {};
    class PeliculaNoEstrenada {};
};

#endif // TXVISUALITZAPELICULA_H
