#include "TxVisualitzaCapitol.h"

TxVisualitzaCapitol::TxVisualitzaCapitol(const std::string& titolSerie, int numeroTemporada, int numeroCapitol)
    : titolSerie(titolSerie), numeroTemporada(numeroTemporada), numeroCapitol(numeroCapitol) {}

bool TxVisualitzaCapitol::executar() {
    auto capitol = PassarelaCapitol::consultaCapitol(titolSerie, numeroTemporada, numeroCapitol);
    if (!capitol) {
        throw CapitolNoExisteix();
    }

    Usuari* usuariLoggejat = Usuari::getUsuariLoggejat();
    if (usuariLoggejat->getEdat() < capitol->getQualificacio()) {
        throw ErrorEdatInadequada();
    }

    if (!capitol->estrenat()) {
        throw CapitolNoEstrenat();
    }

    PassarelaVisualitzacioCapitol::registraVisualitzacio(
        usuariLoggejat->getSobrenom(),
        titolSerie,
        numeroTemporada,
        numeroCapitol
    );

    return true;
}
