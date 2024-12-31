#ifndef CTRL_MODIFICA_USUARI_H
#define CTRL_MODIFICA_USUARI_H

#include <iostream>
#include "TxConsultaUsuari.h"
#include "../passareles/PassarellaUsuari.h"
#include "../sistema/Usuari.h"
#include "../sistema/PetitFlix.h"
using namespace std;

class CtrlModificaUsuari
{
private:
	PassarellaUsuari usuari;

public:
	CtrlModificaUsuari();

	Usuari consultaUsuari(PetitFlix &pF);
	bool modificaUsuari(std::string nomU, std::string contraU, std::string correuU, std::string neixU, std::string modalitatU, PetitFlix &pF);
};

#endif
