#ifndef TXCONSULTAVISUALITZACIONS_H
#define TXCONSULTAVISUALITZACIONS_H

#include <vector>
#include <utility>
#include <string>
#include "PassarelaVisualitzacioPelicula.h"
#include "PassarelaVisualitzacioCapitol.h"

class TxConsultaVisualitzacions {
private:
    std::vector<std::pair<std::string, int>> pelicules;
    std::vector<Capitol> capitols;

public:
    void executar(const std::string& sobrenomUsuari);
    std::vector<std::pair<std::string, int>> obtePelicules() const;
    std::vector<Capitol> obteCapitols() const;
};

#endif
