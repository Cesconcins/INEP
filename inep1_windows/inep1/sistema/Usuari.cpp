#include "Usuari.h"

Usuari::Usuari(std::string sobrenom, std::string nom, std::string correu, std::string dataNaixement, std::string modalitat)
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

std::string Usuari::obteNom()
{
	return this->nom;
}

std::string Usuari::obteCorreuElectronic()
{
	return this->correuElectronic;
}

std::string Usuari::obteDataNaixement()
{
	return this->dataNaixement;
}


std::string Usuari::obteModalitat()
{
	return this->modalitat;
}
