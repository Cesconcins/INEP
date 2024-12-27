#ifndef CERCADORA_USUARI_H
#define CERCADORA_USUARI_H

#include <iostream>
#include "Usuari.h"
#include "PassarellaUsuari.h"
using namespace std;

class CercadoraUsuari {
public:
	Usuari cercaUsuari(std::string sobrenomU);

};

#endif