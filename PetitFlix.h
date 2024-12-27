#ifndef PETIT_FLIX_H
#define PETIT_FLIX_H

#include <iostream>
using namespace std;

#include "Usuari.h"
#include "PassarellaUsuari.h"

class PetitFlix {
private:
	PassarellaUsuari usuari;
	bool loggedIn;

public:
	PetitFlix() : usuari(PassarellaUsuari()), loggedIn(false) {};

	Usuari obteUsuari();
	void iniciaSessio(Usuari u);
	void tancaSessio();

	bool isLoggedIn();

	std::string getLoggedInUser();

};

#endif