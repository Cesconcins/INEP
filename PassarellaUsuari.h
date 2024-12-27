#ifndef PASSARELLA_USUARI_H
#define PASSARELLA_USUARI_H

#include <iostream>
#include <ctime>
#include "DBConnection.h"
using namespace std;

class PassarellaUsuari {
private:
	std::string sobrenom;
	std::string nom;
	std::string contrasenya;
	std::string correuElectronic;
	std::time_t dataNaixement;
	std::string modalitatSubscripcio;

public:
	PassarellaUsuari() : sobrenom(""), nom(""), contrasenya(""), correuElectronic(""), dataNaixement(0), modalitatSubscripcio("") {}
	PassarellaUsuari(std::string sobrenom);

	std::string obteSobrenom();
	std::string obteNom();
	std::string obteContrasenya();
	std::string obteCorreuElectronic();
	std::time_t obteDataNaixement();
	std::string obteModalitatSubscripcio();

	void insereix();
	void modifica();
	void esborra();
};

#endif