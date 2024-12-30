#ifndef PASSARELACAPITOL_H
#define PASSARELACAPITOL_H

#include <string>
#include <optional>

class Capitol {
private:
    std::string titolSerie;
    int numeroTemporada;
    int numeroCapitol;
    int qualificacio;
    bool estrenat;

public:
    Capitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol, int qualificacio, bool estrenat);
    std::string getTitolSerie() const;
    int getNumeroTemporada() const;
    int getNumeroCapitol() const;
    int getQualificacio() const;
    bool isEstrenat() const;
};

class PassarelaCapitol {
public:
    static std::optional<Capitol> consultaCapitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol);
};

#endif // PASSARELACAPITOL_H
