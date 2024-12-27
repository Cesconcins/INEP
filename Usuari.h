#ifndef USUARI_H
#define USUARI_H

#include <iostream>
#include <ctime>
using namespace std;

class Usuari {
private:
	std::string sobrenom;
	std::string nom;
	std::string correuElectronic;
	std::time_t dataNaixement;
	std::string modalitat;

public:
	Usuari() : sobrenom(""), nom(""), correuElectronic(""), dataNaixement(0), modalitat("") {}
	Usuari(std::string sobrenom, std::string nom, std::string correu, std::time_t dataNaixement, std::string modalitat);

};

#endif