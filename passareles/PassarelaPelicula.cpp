#include "PassarelaPelicula.h"
#include "DBConnection.h"

Pelicula::Pelicula(const std::string& titol, int qualificacio, bool estrenada)
    : titol(titol), qualificacio(qualificacio), estrenada(estrenada) {}

std::string Pelicula::getTitol() const {
    return titol;
}

int Pelicula::getQualificacio() const {
    return qualificacio;
}

bool Pelicula::isEstrenada() const {
    return estrenada;
}

std::optional<Pelicula> PassarelaPelicula::consultaPelicula(const std::string& titol) {
    std::string consulta = "SELECT titol, qualificacio, data_estrena FROM pelicula WHERE titol = ?";
    auto resultat = DBConnection::executaConsulta(consulta, {titol});

    if (resultat.empty()) {
        return std::nullopt;
    }

    std::string titolPelicula = resultat[0]["titol"];
    int qualificacio = std::stoi(resultat[0]["qualificacio"]);
    std::string dataEstrena = resultat[0]["data_estrena"];
    bool estrenada = (dataEstrena <= "2024-12-30");

    return Pelicula(titolPelicula, qualificacio, estrenada);
}
