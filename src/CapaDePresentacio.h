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
#include "../transaccions/TxConsultaUsuari.h"
#include "../transaccions/TxInfoVisualitzacions.h"
#include "../transaccions/CtrlModificaUsuari.h"
#include "../sistema/PetitFlix.h"
using namespace std;

class CapaDePresentacio
{

public:
	void mostraMenuPrincipalNoLogin();

	void iniciaSessio(PetitFlix &pF);

	void registrarUsuari();

	void mostraMenuPrincipalLogin();

	void tancaSessio(PetitFlix &pF);

	void mostraMenuGestioUsuari(PetitFlix &pF);

	void consultaUsuari(PetitFlix &pF);

	void modificaUsuari(PetitFlix &pF);

	void esborraUsuari(PetitFlix &pF);

	std::string getHiddenInput(const std::string &prompt);

	void mostraMenuVisualitzar();

	void mostraMenuConsultes();
};

#endif
