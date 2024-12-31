#ifndef CERCADOR_VISUALITZA_PELI_H
#define CERCADOR_VISUALITZA_PELI_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../sistema/DBConnection.h"
using namespace std;

class CercadoraVisualitzaPeli
{
private:
    vector<string> data;
    vector<string> titol;
    vector<string> descripcio;
    vector<int> pegi;
    vector<int> numVisualitzacions;

public:
    CercadoraVisualitzaPeli();
    CercadoraVisualitzaPeli(string sobrenom);
    ~CercadoraVisualitzaPeli();
    CercadoraVisualitzaPeli &operator=(const CercadoraVisualitzaPeli &other);

    vector<string> obteData();
    vector<string> obteTitol();
    vector<string> obteDescripcio();
    vector<int> obtePegi();
    vector<int> obteNumVisualitzacions();

    int cercaVisualitzacions(string sobrenom);
};

#endif