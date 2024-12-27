#ifndef TX_INICI_SESSIO_H
#define TX_INICI_SESSIO_H

#include <iostream>
#include "CercadoraUsuari.h"
#include "PassarellaUsuari.h"
#include "Usuari.h"
using namespace std;

class TxIniciSessio {
private:
	std::string sobrenomU;
	std::string contrasenyaU;

public:
	TxIniciSessio(std::string sU, std::string cU);
	bool executar();

};

#endif