#include "TxConsultaVisualitzacions.h"

void TxConsultaVisualitzacions::executar(const std::string& sobrenomUsuari) {
    // Simula consultas
    capitols.emplace_back("Sèrie Exemple", 1, 1, 10);
    pelicules.emplace_back(std::make_pair("Película Exemple", 15));
}

std::vector<Capitol> TxConsultaVisualitzacions::obteCapitols() const {
    return capitols;
}

std::vector<std::pair<std::string, int>> TxConsultaVisualitzacions::obtePelicules() const {
    return pelicules;
}
