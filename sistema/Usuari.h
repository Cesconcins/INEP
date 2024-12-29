#ifndef USUARI_H
#define USUARI_H

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;

class Usuari {
private:
	std::string sobrenom;
	std::string nom;
	std::string correuElectronic;
	std::string dataNaixement;
	std::string modalitat;

public:
	Usuari() : sobrenom(""), nom(""), correuElectronic(""), dataNaixement(""), modalitat("") {}
	Usuari(std::string sobrenom, std::string nom, std::string correu, std::string dataNaixement, std::string modalitat);

	std::string obteSobrenom();
	std::string obteNom();
	std::string obteCorreuElectronic();
	std::string obteDataNaixement();
	std::string obteModalitat();

};

#endif
