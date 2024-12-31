#include "PassarelaCapitol.h"
#include "../sistema/DBConnection.h"

std::unique_ptr<Capitol> PassarelaCapitol::consultaCapitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol) {
    std::string consulta = "SELECT titol_serie, numero_temporada, numero_capitol, num_visualitzacions "
                           "FROM capitol WHERE titol_serie = ? AND numero_temporada = ? AND numero_capitol = ?";
    auto resultat = DBConnection::executaConsulta(consulta, {titolSerie, std::to_string(numeroTemporada), std::to_string(numeroCapitol)});

    if (resultat.empty()) {
        return nullptr;
    }

    return std::make_unique<Capitol>(
        resultat[0]["titol_serie"],
        std::stoi(resultat[0]["numero_temporada"]),
        std::stoi(resultat[0]["numero_capitol"]),
        std::stoi(resultat[0]["num_visualitzacions"])
    );
}
