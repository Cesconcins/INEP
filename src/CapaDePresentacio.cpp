#include "CapaDePresentacio.h"

void CapaDePresentacio::mostraMenuPrincipalNoLogin()
{
	cout << "*********************\n";
	cout << "    Menu Principal   \n";
	cout << "*********************\n";
	cout << "1. Iniciar sessió\n";
	cout << "2. Registrar usuari\n";
	cout << "3. Consultes\n";
	cout << "4. Sortir\n";
	cout << "Escriu opció: ";
}

void CapaDePresentacio::iniciaSessio(PetitFlix &pF)
{
	std::string sU, cU;
	system("clear");
	cout << "** Inici sessio **\n";
	cout << "Sobrenom: "; cin >> sU;
	cout << "Contrasenya: "; cin >> cU;
	
	TxIniciSessio TxIni(sU, cU);
	if (!TxIni.executar(pF)) cout << "Hi ha hagut un error amb el Sobrenom o la contrasenya.\n";
	else cout << "Sessio iniciada correctament!\n";
}

void CapaDePresentacio::mostraMenuPrincipalLogin()
{
	cout << "*********************\n";
	cout << "    Menu Principal   \n";
	cout << "*********************\n";
	cout << "1. Gestió usuaris\n";
	cout << "2. Visualitzar\n";
	cout << "3. Consultes\n";
	cout << "4. Tancar sessió\n";
	cout << "5. Sortir\n";
	cout << "Escriu opció: ";
}

void CapaDePresentacio::tancaSessio(PetitFlix &pF)
{
	char opcio;
	system("clear");
	cout << "** Tancar sessio **\n";
	cout << "Vols tancar la sessio (S/N): ";
	cin >> opcio;
	
	if (opcio == 'S' || opcio == 's') {
		TxTancaSessio txTanca;
		txTanca.executar(pF);
		cout << "Sessio tancada correctament!\n";
	} else cout << "No s'ha tancat la sessio.\n";
}


void CapaDePresentacio::mostraMenuGestioUsuari()
{
	cout << "*********************\n";
	cout << "    Menu Principal   \n";
	cout << "*********************\n";
	cout << "1. Consulta usuari\n";
	cout << "2. Modifica usuari\n";
	cout << "3. Esborra usuari\n";
	cout << "4. Tornar\n";
	cout << "Escriu opció: ";
}

void CapaDePresentacio::mostraMenuVisualitzar()
{
	cout << "*********************\n";
	cout << "    Menu Principal   \n";
	cout << "*********************\n";
	cout << "1. Visualitzar pel·lícula\n";
	cout << "2. Visualitzar capítol\n";
	cout << "3. Consultar visualitzacions\n";
	cout << "4. Tornar\n";
	cout << "Escriu opció: ";
/*
	case 1: { // Visualitzar pel·lícula
    std::string movieTitle;
    std::cout << "Introdueix el títol de la pel·lícula: ";
    std::cin.ignore();
    std::getline(std::cin, movieTitle);
    VisualitzaPellicula::visualitza(PetitFlix::getLoggedInUser(), movieTitle);
    break;
	}

	case 2: { // Visualitzar capítol
    std::string seriesTitle;
    std::cout << "Introdueix el títol de la sèrie: ";
    std::cin.ignore();
    std::getline(std::cin, seriesTitle);
    VisualitzaCapitol::visualitza(PetitFlix::getLoggedInUser(), seriesTitle);
    break;
	}
*/
}

void CapaDePresentacio::mostraMenuConsultes()
{
	cout << "*********************\n";
	cout << "    Menu Principal   \n";
	cout << "*********************\n";
	cout << "1. Properes Estrenes\n";
	cout << "2. Últimes novetats\n";
	cout << "3. Pel·lícules més vistes\n";
	cout << "4. Tornar\n";
	cout << "Escriu opció: ";
}
