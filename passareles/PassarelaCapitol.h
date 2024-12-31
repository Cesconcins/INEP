#ifndef PASSARELACAPITOL_H
#define PASSARELACAPITOL_H

#include <string>
#include <optional>
#include "../sistema/Capitol.h"

class PassarelaCapitol {
public:
    static std::optional<Capitol> consultaCapitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol);
};

#endif // PASSARELACAPITOL_H


=== PassarelaCapitol.cpp ===
#include "PassarelaCapitol.h"

std::optional<Capitol> PassarelaCapitol::consultaCapitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol) {
    // Simula una consulta a la base de datos
    // Puedes agregar lógica para recuperar un Capitol real
    return Capitol(titolSerie, numeroTemporada, numeroCapitol, 0); // Ejemplo con valores por defecto
}

