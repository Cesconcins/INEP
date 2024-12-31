#ifndef PASSARELAPELICULA_H
#define PASSARELAPELICULA_H

#include <string>

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
    static Pelicula* consultaPelicula(const std::string& titol);
};

#endif

