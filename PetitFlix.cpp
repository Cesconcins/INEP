#include "PetitFlix.h"

Usuari obteUsuari();
void iniciaSessio(Usuari u);
void tancaSessio();

bool PetitFlix::isLoggedIn()
{
	return this->loggedIn;
}

std::string PetitFlix::getLoggedInUser() {
    return this->usuari.obteSobrenom();
}
