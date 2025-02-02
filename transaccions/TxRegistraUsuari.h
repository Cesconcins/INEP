#ifndef TX_REGISTRA_USUARI_H
#define TX_REGISTRA_USUARI_H

#include <iostream>
#include <ctime>
#include "../passareles/PassarellaUsuari.h"
using namespace std;

class TxRegistraUsuari
{
private:
	std::string nomU;
	std::string sobrenomU;
	std::string contrasenyaU;
	std::string correuElectronicU;
	std::string dataNaixementU;
	std::string modalitatSubscripcio;

public:
	TxRegistraUsuari(std::string nU, std::string sU, std::string cU, std::string ceU, std::string dnU, std::string msU);
	int executar();
};

#endif
