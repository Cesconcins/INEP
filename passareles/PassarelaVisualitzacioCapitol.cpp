#include "PassarelaVisualitzacioCapitol.h"
#include "../sistema/DBConnection.h""

void PassarelaVisualitzacioCapitol::registraVisualitzacio(const std::string& sobrenomUsuari, const std::string& titolSerie, int numeroTemporada, int numeroCapitol) {
    std::string consulta = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, numero_temporada, numero_capitol, data, num_visualitzacions) "
                           "VALUES (?, ?, ?, ?, NOW(), 1) "
                           "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1;";
    DBConnection::executaConsulta(consulta, {sobrenomUsuari, titolSerie, std::to_string(numeroTemporada), std::to_string(numeroCapitol)});
}

std::vector<Capitol> PassarelaVisualitzacioCapitol::consultaVisualitzacions(const std::string& sobrenomUsuari) {
    std::string consulta = "SELECT titol_serie, numero_temporada, numero_capitol, num_visualitzacions FROM visualitzacio_capitol WHERE sobrenom_usuari = ?";
    auto resultat = DBConnection::executaConsulta(consulta, {sobrenomUsuari});

    std::vector<Capitol> capitols;
    for (const auto& fila : resultat) {
        capitols.emplace_back(
            fila["titol_serie"],
            std::stoi(fila["numero_temporada"]),
            std::stoi(fila["numero_capitol"]),
            std::stoi(fila["num_visualitzacions"])
        );
    }
    return capitols;
}
