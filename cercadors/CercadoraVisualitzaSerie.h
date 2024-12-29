#ifndef CERCADOR_VISUALITZA_SERIE_H
#define CERCADOR_VISUALITZA_SERIE_H

#include <iostream>
#include "../sistema/DBConnection.h"
using namespace std;

class CercadoraVisualitzaSerie
{
public:
    CercadoraVisualitzaSerie();

    int cercaVisualitzacions(std::string sobrenom);
};

#endif