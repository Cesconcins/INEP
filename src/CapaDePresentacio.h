#ifndef CAPA_DE_PRESENTACIO_H
#define CAPA_DE_PRESENTACIO_H

#include <iostream>
#include <string>
#include <stdlib.h> 
#include <ctime>
#include <termios.h>
#include <unistd.h>

#include "../transaccions/TxIniciSessio.h"
#include "../transaccions/TxTancaSessio.h"
#include "../transaccions/TxRegistraUsuari.h"
#include "../transaccions/TxEsborraUsuari.h"
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

	void mostraMenuGestioUsuari(PetitFlix &pF);
	
	void esborraUsuari(PetitFlix &pF);
	
	std::string getHiddenInput(const std::string& prompt);

	void mostraMenuVisualitzar();

	void mostraMenuConsultes();
};

#endif
