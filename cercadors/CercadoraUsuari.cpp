#include "CercadoraUsuari.h"

Usuari CercadoraUsuari::cercaUsuari(std::string sobrenomU, PassarellaUsuari& pasU)
{
	std::string sobreNom = pasU.obteSobrenom();
	std::string nom = pasU.obteNom();
	std::string correu = pasU.obteCorreuElectronic();
	std::string data = pasU.obteDataNaixement();
	std::string modalitat = pasU.obteModalitatSubscripcio();
	
	Usuari u(sobreNom, nom, correu, data, modalitat);
	return u;
}