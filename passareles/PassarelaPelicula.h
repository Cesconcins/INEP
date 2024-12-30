#ifndef PASSARELAPELICULA_H
#define PASSARELAPELICULA_H

#include <string>
#include <optional>

class Pelicula {
private:
    std::string titol;
    int qualificacio;
    bool estrenada;

public:
    Pelicula(const std::string& titol, int qualificacio, bool estrenada);
    std::string getTitol() const;
    int getQualificacio() const;
    bool isEstrenada() const;
};

class PassarelaPelicula {
public:
    static std::optional<Pelicula> consultaPelicula(const std::string& titol);
};

#endif // PASSARELAPELICULA_H
