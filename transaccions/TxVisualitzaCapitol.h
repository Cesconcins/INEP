#ifndef TXVISUALITZACAPITOL_H
#define TXVISUALITZACAPITOL_H

#include <string>
#include "../sistema/Capitol.h"

class TxVisualitzaCapitol {
private:
    std::string titolSerie;
    int numeroTemporada;
    int numeroCapitol;

public:
    TxVisualitzaCapitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol);
    bool executar();

    class CapitolNoExisteix {};
    class ErrorEdatInadequada {};
    class CapitolNoEstrenat {};
};

#endif // TXVISUALITZACAPITOL_H
