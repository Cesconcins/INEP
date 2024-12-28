#ifndef CERCADORA_USUARI_H
#define CERCADORA_USUARI_H

#include <iostream>
#include <ctime>
#include "../sistema/Usuari.h"
#include "../passareles/PassarellaUsuari.h"
using namespace std;

class CercadoraUsuari {
public:
	Usuari cercaUsuari(std::string sobrenomU, PassarellaUsuari& pasU);
};

#endif
