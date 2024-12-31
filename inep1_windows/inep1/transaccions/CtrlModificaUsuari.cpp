#include "CtrlModificaUsuari.h"

CtrlModificaUsuari::CtrlModificaUsuari() {}

Usuari CtrlModificaUsuari::consultaUsuari(PetitFlix &pF)
{
    TxConsultaUsuari TxCons;
    TxCons.executar(pF);
    Usuari u = TxCons.obteResultat();
    this->usuari = TxCons.obteUsuari();
    return u;
}

bool CtrlModificaUsuari::modificaUsuari(std::string nomU, std::string contraU, std::string correuU, std::string neixU, std::string modalitatU, PetitFlix &pF)
{
    bool res = true;

    if (!nomU.empty())
        this->usuari.posaNom(nomU);
    if (!contraU.empty())
        this->usuari.posaContrasenya(contraU);
    if (!correuU.empty())
        this->usuari.posaCorreuElectronic(correuU);
    if (!neixU.empty())
        this->usuari.posaDataNaixement(neixU);
    if (!modalitatU.empty())
        this->usuari.posaModalitat(modalitatU);

    res = this->usuari.modifica();

    if (res)
        pF.modificaU(this->usuari);

    return res;
}
