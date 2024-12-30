#include "PassarelaCapitol.h"
#include "DBConnection.h"

Capitol::Capitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol, int qualificacio, bool estrenat)
    : titolSerie(titolSerie), numeroTemporada(numeroTemporada), numeroCapitol(numeroCapitol), qualificacio(qualificacio), estrenat(estrenat) {}

std::string Capitol::getTitolSerie() const {
    return titolSerie;
}

int Capitol::getNumeroTemporada() const {
    return numeroTemporada;
}

int Capitol::getNumeroCapitol() const {
    return numeroCapitol;
}

int Capitol::getQualificacio() const {
    return qualificacio;
}

bool Capitol::isEstrenat() const {
    return estrenat;
}

std::optional<Capitol> PassarelaCapitol::consultaCapitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol) {
    std::string consulta = "SELECT titol_serie, numero_temporada, numero_capitol, qualificacio, data_estrena "
                           "FROM capitol WHERE titol_serie = ? AND numero_temporada = ? AND numero_capitol = ?";
    auto resultat = DBConnection::executaConsulta(consulta, {titolSerie, std::to_string(numeroTemporada), std::to_string(numeroCapitol)});

    if (resultat.empty()) {
        return std::nullopt;
    }

    int qualificacio = std::stoi(resultat[0]["qualificacio"]);
    std::string dataEstrena = resultat[0]["data_estrena"];
    bool estrenat = (dataEstrena <= "2024-12-30");

    return Capitol(titolSerie, numeroTemporada, numeroCapitol, qualificacio, estrenat);
}
