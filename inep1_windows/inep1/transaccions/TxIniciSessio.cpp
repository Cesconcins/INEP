#include "TxIniciSessio.h"

TxIniciSessio::TxIniciSessio(std::string sU, std::string cU)
{
	this->sobrenomU = sU;
	this->contrasenyaU = cU;
}

bool TxIniciSessio::executar(PetitFlix &pF)
{
	CercadoraUsuari cercaU;
	PassarellaUsuari pasU(sobrenomU);
	Usuari u = cercaU.cercaUsuari(this->sobrenomU);
	std::string contr = pasU.obteContrasenya();
	// if contr not correct - return false Exc: ErrorContrasenya \ if (!u) return false - Exc: UsuariNoExisteix
	if (this->sobrenomU != u.obteSobrenom() || this->contrasenyaU != contr)
		return false;

	pF.iniciaSessio(u);

	return true;
}