#ifndef TX_INICI_SESSIO_H
#define TX_INICI_SESSIO_H

#include <iostream>
#include "../cercadors/CercadoraUsuari.h"
#include "../passareles/PassarellaUsuari.h"
#include "../sistema/Usuari.h"
#include "../sistema/PetitFlix.h"
using namespace std;

class TxIniciSessio {
private:
	std::string sobrenomU;
	std::string contrasenyaU;

public:
	TxIniciSessio(std::string sU, std::string cU);
	bool executar(PetitFlix &pF);

};

#endif
