#include "TxEsborraUsuari.h"

TxEsborraUsuari::TxEsborraUsuari(std::string contraU)
{
	this->contrasenyaU = contraU;
}

bool TxEsborraUsuari::executar(PetitFlix &pF)
{
	PassarellaUsuari usu = pF.obteUsuari();
	std::string c = usu.obteContrasenya();
	
	if (c != contrasenyaU) return false;
	
	usu.esborra();
	pF.tancaSessio();
	
	return true;
}
