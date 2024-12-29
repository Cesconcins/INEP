#include "PetitFlix.h"

PassarellaUsuari PetitFlix::obteUsuari()
{
	return usuari;
}

void PetitFlix::iniciaSessio(Usuari &u)
{
	this->usuari = PassarellaUsuari(u.obteSobrenom());
	this->loggedIn = true;
}

void PetitFlix::tancaSessio()
{
	this->usuari.~PassarellaUsuari();
	this->loggedIn = false;
}

bool PetitFlix::isLoggedIn()
{
	return this->loggedIn;
}

std::string PetitFlix::getLoggedInUser() {
    return this->usuari.obteSobrenom();
}
