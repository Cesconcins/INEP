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

void CapaDePresentacio::registrarUsuari()
{
	system("clear");
	std::string nU, sU, cU, ceU, dnU_string;
	int msU_int = 0;
	cout << "** Registrar usuari **\n";
	cout << "Nom complet: "; cin >> nU;
	cout << "Sobrenom: "; cin >> sU;
	cout << "Contrasenya: "; cin >> cU;
	cout << "Correu electronic: "; cin >> ceU;
	cout << "Data naixement (DD/MM/AAAA): "; cin >> dnU_string;
	
	time_t dnU;
	try {
		dnU = stringToTimeT(dnU_string);
	} catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    
	cout << "Modalitats de subscripció disponibles\n";
	cout << " > 1. Completa\n > 2. Cinèfil\n > 3. Infantil\n";
	cout << "Escull modalitat: "; cin >> msU_int;
	std::string msU;
	switch (msU_int) {
		case 1:
			msU = "Completa";
			break;
		case 2:
			msU = "Cinèfil";
			break;
		case 3:
			msU = "Infantil";
			break;
		default:
			cout << "Opció no vàlida, s'esperava 1, 2 o 3. Opció introduida: " + msU_int << endl;
			return;
	}
	
	TxRegistraUsuari TxReg(nU, sU, cU, ceU, dnU, msU);
	int res = TxReg.executar();
	
	switch (res) {
		case -10:
			cout << "Error al Registrar nou usuari. Ja existeix un usuari amb aquest sobrenom.\n";
			return;
		case -20:
			cout << "Error al Registrar nou usuari. Ja existeix un usuari amb aquest correu electrònic.\n";
			return;
		case -30:
			cout << "Error al Registrar nou usuari. Modalitat no existeix.\n";
			return;
		case 0:
			cout << "Nou usuari registrat correctament!\n";
			return;
		default:
			cout << "Error al Registrar nou usuari. Error no definit.\n";
			return;
	}
}

time_t CapaDePresentacio::stringToTimeT(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);

    ss >> std::get_time(&tm, "%d/%m/%Y");
    if (ss.fail()) {
        throw std::runtime_error("Format no vàlid. S'esperava DD/MM/AAAA");
    }

    return std::mktime(&tm);
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
