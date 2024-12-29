#ifndef TX_ESBORRA_USUARI_H
#define TX_ESBORRA_USUARI_H

#include <iostream>
#include "../sistema/PetitFlix.h"
#include "../passareles/PassarellaUsuari.h"
using namespace std;

class TxEsborraUsuari {
private:
	std::string contrasenyaU;
	
public:
	TxEsborraUsuari(std::string contraU);
	bool executar(PetitFlix &pF);

};

#endif
