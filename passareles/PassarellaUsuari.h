#ifndef PASSARELLA_USUARI_H
#define PASSARELLA_USUARI_H

#include <iostream>
#include <ctime>
#include <regex>
#include "../sistema/DBConnection.h"
using namespace std;

class PassarellaUsuari
{
private:
	std::string sobrenom;
	std::string nom;
	std::string contrasenya;
	std::string correuElectronic;
	std::string dataNaixement;
	std::string modalitatSubscripcio;

public:
	PassarellaUsuari() : sobrenom(""), nom(""), contrasenya(""), correuElectronic(""), dataNaixement(""), modalitatSubscripcio("") {}
	PassarellaUsuari(std::string nom, std::string sobrenom, std::string contrasenya, std::string correuElectronic, std::string dataNaixement, std::string modalitatSubscripcio);
	PassarellaUsuari(std::string sobrenom);
	~PassarellaUsuari();

	std::string obteSobrenom();
	std::string obteNom();
	std::string obteContrasenya();
	std::string obteCorreuElectronic();
	std::string obteDataNaixement();
	std::string obteModalitatSubscripcio();

	void posaNom(std::string nom);
	void posaContrasenya(std::string contrasenya);
	void posaCorreuElectronic(std::string correuElectronic);
	void posaDataNaixement(std::string dataNaixement);
	void posaModalitat(std::string modalitatSubscripcio);

	int insereix();
	bool modifica();
	void esborra();

	std::string convertToSQLDate(const std::string &date);
	bool isDateValid(const std::string &date);
};

#endif
