#ifndef CERCADOR_VISUALITZA_PELI_H
#define CERCADOR_VISUALITZA_PELI_H

#include <iostream>
#include "../sistema/DBConnection.h"
using namespace std;

class CercadoraVisualitzaPeli
{
public:
    CercadoraVisualitzaPeli();

    int cercaVisualitzacions(std::string sobrenom);
};

#endif