#ifndef CAPA_DE_PRESENTACIO_H
#define CAPA_DE_PRESENTACIO_H

#include <iostream>
#include <stdlib.h> 
#include <ctime>

#include "../transaccions/TxIniciSessio.h"
#include "../transaccions/TxTancaSessio.h"
#include "../sistema/PetitFlix.h"
using namespace std;

class CapaDePresentacio {

public:
	static void mostraMenuPrincipalNoLogin();

	static void iniciaSessio(PetitFlix &pF);

	static void mostraMenuPrincipalLogin();
	
	static void tancaSessio(PetitFlix &pF);

	static void mostraMenuGestioUsuari();

	static void mostraMenuVisualitzar();

	static void mostraMenuConsultes();
};

#endif
