#include "TxInfoVisualitzacions.h"

TxInfoVisualitzacions::TxInfoVisualitzacions() {}

void TxInfoVisualitzacions::executar(PetitFlix &pF)
{
    PassarellaUsuari u = pF.obteUsuari();
    std::string sobrenom = u.obteSobrenom();
    CercadoraVisualitzaPeli cercPel;
    CercadoraVisualitzaSerie cercSer;
    int nP = cercPel.cercaVisualitzacions(sobrenom);
    int nS = cercSer.cercaVisualitzacions(sobrenom);
    std::pair p(nP, nS);
    this->resultat = p;
}

std::pair<int, int> TxInfoVisualitzacions::obteResultat()
{
    return this->resultat;
}
