#ifndef CAPITOL_H
#define CAPITOL_H

#include <string>

class Capitol {
private:
    std::string titolSerie;
    int numeroTemporada;
    int numeroCapitol;
    int numVisualitzacions;

public:
    Capitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol, int numVisualitzacions);

    std::string getTitolSerie() const;
    int getNumeroTemporada() const;
    int getNumeroCapitol() const;
    int getNumVisualitzacions() const;
};

#endif // CAPITOL_H
