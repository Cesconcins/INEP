#ifndef TX_CONSULTA_VISUALITZACIONS_H
#define TX_CONSULTA_VISUALITZACIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <utility> // Per utilitzar std::pair
#include "../sistema/Usuari.h"
#include "../sistema/PetitFlix.h"
#include "../cercadors/CercadoraVisualitzaPel.h"
#include "../cercadors/CercadoraVisualitzaSerie.h"

class TxConsultaVisualitzacions {
private:
    CercadoraVisualitzaPeli pelicules;
    CercadoraVisualitzaSerie series;

public:
    TxConsultaVisualitzacions();

    void executar(PetitFlix &pF);

    CercadoraVisualitzaPeli obtePelicules();
    CercadoraVisualitzaSerie obteSeries();
};

#endif
