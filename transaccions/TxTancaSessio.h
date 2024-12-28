#ifndef TANCA_SESSIO_H
#define TANCA_SESSIO_H

#include <iostream>
#include "../sistema/PetitFlix.h"
using namespace std;

class TxTancaSessio {
public:
	TxTancaSessio();
	void executar(PetitFlix &pF);

};

#endif
