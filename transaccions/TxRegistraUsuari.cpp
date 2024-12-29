#include "TxRegistraUsuari.h"

TxRegistraUsuari::TxRegistraUsuari(std::string nU, std::string sU, std::string cU, std::string ceU, std::time_t dnU, std::string msU)
{
	this->nomU = nU;
	this->sobrenomU = sU;
	this->contrasenyaU = cU;
	this->correuElectronicU = ceU;
	this->dataNaixementU = dnU;
	this->modalitatSubscripcio = msU;
}
	
int TxRegistraUsuari::executar()
{
	PassarellaUsuari pU(this->nomU, this->sobrenomU, this->contrasenyaU, this->correuElectronicU, this->dataNaixementU, this->modalitatSubscripcio);
	return pU.insereix();
}
