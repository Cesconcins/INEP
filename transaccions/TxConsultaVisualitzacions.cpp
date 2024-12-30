#include "TxConsultaVisualitzacions.h"

void TxConsultaVisualitzacions::executar(const std::string& sobrenomUsuari) {
    pelicules = PassarelaVisualitzacioPelicula::consultaVisualitzacions(sobrenomUsuari);
    capitols = PassarelaVisualitzacioCapitol::consultaVisualitzacions(sobrenomUsuari);
}

std::vector<std::pair<std::string, int>> TxConsultaVisualitzacions::obtePelicules() const {
    return pelicules;
}

std::vector<Capitol> TxConsultaVisualitzacions::obteCapitols() const {
    return capitols;
}
