#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari() {}

void TxConsultaUsuari::executar(PetitFlix &pF) 
{
	this->usuari = pF.obteUsuari();
	Usuari u(usuari.obteSobrenom(), usuari.obteNom(), usuari.obteCorreuElectronic(), usuari.obteDataNaixement(), usuari.obteModalitatSubscripcio());
	this->resultat = u;
}

Usuari TxConsultaUsuari::obteResultat()
{
	return this->resultat;
}

PassarellaUsuari TxConsultaUsuari::obteUsuari()
{
	return this->usuari;
}

