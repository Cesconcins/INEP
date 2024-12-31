#include "TxConsultaVisualitzacions.h"

TxConsultaVisualitzacions::TxConsultaVisualitzacions() {}

void TxConsultaVisualitzacions::executar(PetitFlix &pF)
{
    PassarellaUsuari usuari = pF.obteUsuari();
    string sobrenom = usuari.obteSobrenom();

    this->pelicules = CercadoraVisualitzaPeli(sobrenom);
    this->series = CercadoraVisualitzaSerie(sobrenom);
}

CercadoraVisualitzaPeli TxConsultaVisualitzacions::obtePelicules()
{
    return this->pelicules;
}

CercadoraVisualitzaSerie TxConsultaVisualitzacions::obteSeries()
{
    return this->series;
}