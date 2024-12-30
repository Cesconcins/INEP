#include "PassarelaVisualitzacioPelicula.h"
#include "DBConnection.h"

void PassarelaVisualitzacioPelicula::registraVisualitzacio(const std::string& sobrenomUsuari, const std::string& titolPelicula) {
    std::string consulta = "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) "
                           "VALUES (?, ?, NOW(), 1) "
                           "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1;";
    DBConnection::executaConsulta(consulta, {sobrenomUsuari, titolPelicula});
}

std::vector<std::pair<std::string, int>> PassarelaVisualitzacioPelicula::consultaVisualitzacions(const std::string& sobrenomUsuari) {
    std::string consulta = "SELECT titol_pelicula, num_visualitzacions FROM visualitzacio_pelicula WHERE sobrenom_usuari = ?";
    auto resultat = DBConnection::executaConsulta(consulta, {sobrenomUsuari});

    std::vector<std::pair<std::string, int>> pelicules;
    for (const auto& fila : resultat) {
        pelicules.emplace_back(fila["titol_pelicula"], std::stoi(fila["num_visualitzacions"]));
    }
    return pelicules;
}
