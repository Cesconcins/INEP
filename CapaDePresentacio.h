#ifndef CAPA_DE_PRESENTACIO_H
#define CAPA_DE_PRESENTACIO_H

#include <iostream>
#include <stdlib.h> 
#include <mysql_connection.h>
using namespace std;

class CapaDePresentacio {

public:
	static void mostraMenuPrincipalNoLogin();

	static void iniciaSessio();

	static void mostraMenuPrincipalLogin();

	static void mostraMenuGestioUsuari();

	static void mostraMenuVisualitzar();

	static void mostraMenuConsultes();
};

#endif