#include "Usuari.h"

Usuari::Usuari(std::string sobrenom, std::string nom, std::string correu, std::time_t dataNaixement, std::string modalitat)
{
	this->sobrenom = sobrenom;
	this->nom = nom;
	this->correuElectronic = correu;
	this->dataNaixement = dataNaixement;
	this->modalitat = modalitat;
}

std::string Usuari::obteSobrenom()
{
	return this->sobrenom;
}