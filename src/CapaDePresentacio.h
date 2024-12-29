#ifndef CAPA_DE_PRESENTACIO_H
#define CAPA_DE_PRESENTACIO_H

#include <iostream>
#include <stdlib.h> 
#include <ctime>

#include "../transaccions/TxIniciSessio.h"
#include "../transaccions/TxTancaSessio.h"
#include "../transaccions/TxRegistraUsuari.h"
#include "../sistema/PetitFlix.h"
using namespace std;

class CapaDePresentacio {

public:
	void mostraMenuPrincipalNoLogin();

	void iniciaSessio(PetitFlix &pF);
	
	void registrarUsuari();
	
	static time_t stringToTimeT(const std::string& dateStr);

	void mostraMenuPrincipalLogin();
	
	void tancaSessio(PetitFlix &pF);

	void mostraMenuGestioUsuari();

	void mostraMenuVisualitzar();

	void mostraMenuConsultes();
};

#endif
