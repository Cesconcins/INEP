#include "TxIniciSessio.h"

TxIniciSessio::TxIniciSessio(std::string sU, std::string cU) {
	this->sobrenomU = sU;
	this->contrasenyaU = cU;
}

bool TxIniciSessio::executar()
{
	CercadoraUsuari cercaU;
	Usuari u = cercaU.cercaUsuari(this->sobrenomU);
	// if (!u) return false - Exc: UsuariNoExisteix
	PassarellaUsuari pasU;
	std::string contr = pasU.obteContrasenya();
	// if contr not correct - return false Exc: ErrorContrasenya
	// petitFlix inciaSessio
	return true;
}