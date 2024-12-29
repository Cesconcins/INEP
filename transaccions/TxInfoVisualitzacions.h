#ifndef TX_INFO_VISUALITZACIONS_H
#define TX_INFO_VISUALITZACIONS_H

#include <utility>
#include <iostream>
#include "../passareles/PassarellaUsuari.h"
#include "../cercadors/CercadoraVisualitzaPel.h"
#include "../cercadors/CercadoraVisualitzaSerie.h"
#include "../sistema/PetitFlix.h"
using namespace std;

class TxInfoVisualitzacions
{
private:
    std::pair<int, int> resultat;

public:
    TxInfoVisualitzacions();

    void executar(PetitFlix &pF);
    std::pair<int, int> obteResultat();
};

#endif