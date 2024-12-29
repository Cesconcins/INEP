#ifndef PETIT_FLIX_H
#define PETIT_FLIX_H

#include <iostream>
using namespace std;

#include "Usuari.h"
#include "../passareles/PassarellaUsuari.h"

class PetitFlix {
private:
	PassarellaUsuari usuari;
	bool loggedIn;

public:
	PetitFlix() : usuari(PassarellaUsuari()), loggedIn(false) {};

	PassarellaUsuari obteUsuari();
	void iniciaSessio(Usuari &u);
	void tancaSessio();

	bool isLoggedIn();
	void modificaU(PassarellaUsuari u);

	std::string getLoggedInUser();

};

#endif
