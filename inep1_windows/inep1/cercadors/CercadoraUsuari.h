#ifndef CERCADORA_USUARI_H
#define CERCADORA_USUARI_H

#include <iostream>
#include <ctime>
#include "../sistema/Usuari.h"
#include "../sistema/DBConnection.h"
using namespace std;

class CercadoraUsuari
{
public:
	CercadoraUsuari();

	Usuari cercaUsuari(std::string sobrenomU);
};

#endif
