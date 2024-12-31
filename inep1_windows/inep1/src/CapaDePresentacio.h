#ifndef CAPA_DE_PRESENTACIO_H
#define CAPA_DE_PRESENTACIO_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

#include "../transaccions/TxIniciSessio.h"
#include "../transaccions/TxTancaSessio.h"
#include "../transaccions/TxRegistraUsuari.h"
#include "../transaccions/TxEsborraUsuari.h"
#include "../transaccions/TxConsultaUsuari.h"
#include "../transaccions/TxInfoVisualitzacions.h"
#include "../transaccions/CtrlModificaUsuari.h"
#include "../transaccions/TxConsultaVisualitzacions.h"
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

	void mostraMenuVisualitzar(PetitFlix &pF);

	void mostraMenuConsultes();

	void consultaVisualitzacions(PetitFlix &pF);
};

#endif
