#ifndef TX_CONSULTA_USUARI_H
#define TX_CONSULTA_USUARI_H

#include <iostream>
#include "../sistema/Usuari.h"
#include "../sistema/PetitFlix.h"
#include "../passareles/PassarellaUsuari.h"
using namespace std;

class TxConsultaUsuari {
private:
	Usuari resultat;
	PassarellaUsuari usuari;
	
public:
	TxConsultaUsuari();
	
	void executar(PetitFlix &pF);
	Usuari obteResultat();
	PassarellaUsuari obteUsuari();

};

#endif
