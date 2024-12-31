#ifndef TXCONSULTAVISUALITZACIONS_H
#define TXCONSULTAVISUALITZACIONS_H

#include <string>
#include <vector>
#include <utility>
#include "../sistema/Capitol.h"

class TxConsultaVisualitzacions {
private:
    std::vector<Capitol> capitols;
    std::vector<std::pair<std::string, int>> pelicules;

public:
    void executar(const std::string& sobrenomUsuari);
    std::vector<Capitol> obteCapitols() const;
    std::vector<std::pair<std::string, int>> obtePelicules() const;
};

#endif // TXCONSULTAVISUALITZACIONS_H
