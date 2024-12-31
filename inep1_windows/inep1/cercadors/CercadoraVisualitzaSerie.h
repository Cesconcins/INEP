#ifndef CERCADOR_VISUALITZA_SERIE_H
#define CERCADOR_VISUALITZA_SERIE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../sistema/DBConnection.h"
using namespace std;

class CercadoraVisualitzaSerie
{
private:
    vector<string> data;
    vector<string> titol;
    vector<int> numTemporada;
    vector<int> numCapitol;
    vector<int> pegi;
    vector<int> numVisualitzacions;

public:
    CercadoraVisualitzaSerie();
    CercadoraVisualitzaSerie(string sobrenom);
    ~CercadoraVisualitzaSerie();
    CercadoraVisualitzaSerie &operator=(const CercadoraVisualitzaSerie &other);

    // Mètodes per obtenir la informació
    vector<string> obteData();
    vector<string> obteTitol();
    vector<int> obteNumTemporada();
    vector<int> obteNumCapitol();
    vector<int> obtePegi();
    vector<int> obteNumVisualitzacions();

    int cercaVisualitzacions(string sobrenom);
};

#endif