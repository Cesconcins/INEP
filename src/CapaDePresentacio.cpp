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
	cout << "Sobrenom: ";
	cin >> sU;
	cout << "Contrasenya: ";
	cin >> cU;

	TxIniciSessio TxIni(sU, cU);
	if (!TxIni.executar(pF))
		cout << "Hi ha hagut un error amb el Sobrenom o la contrasenya.\n";
	else
		cout << "Sessio iniciada correctament!\n";
}

void CapaDePresentacio::registrarUsuari()
{
	system("clear");
	std::string nU, sU, cU, ceU, dnU;
	int msU_int = 0;
	cout << "** Registrar usuari **\n";
	cout << "Nom complet: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, nU);

	cout << "Sobrenom: ";
	cin >> sU;

	cout << "Contrasenya: ";
	cin >> cU;

	cout << "Correu electronic: ";
	cin >> ceU;

	cout << "Data naixement (DD/MM/AAAA): ";
	cin >> dnU;

	cout << "Modalitats de subscripció disponibles\n";
	cout << " > 1. Completa\n > 2. Cinèfil\n > 3. Infantil\n";
	cout << "Escull modalitat: ";
	cin >> msU_int;
	std::string msU;
	switch (msU_int)
	{
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

	switch (res)
	{
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

	if (opcio == 'S' || opcio == 's')
	{
		TxTancaSessio txTanca;
		txTanca.executar(pF);
		cout << "Sessio tancada correctament!\n";
	}
	else
		cout << "No s'ha tancat la sessio.\n";
}

void CapaDePresentacio::mostraMenuGestioUsuari(PetitFlix &pF)
{
	int opcio;
	do
	{
		system("clear");
		cout << "*********************\n";
		cout << "    Menu Principal   \n";
		cout << "*********************\n";
		cout << "1. Consulta usuari\n";
		cout << "2. Modifica usuari\n";
		cout << "3. Esborra usuari\n";
		cout << "4. Tornar\n";
		cout << "Escriu opció: ";
		cin >> opcio;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Opció no vàlida. Torna-ho a intentar.\n";
			continue;
		}

		switch (opcio)
		{
		case 1:
			consultaUsuari(pF);
			break;
		case 2:
			modificaUsuari(pF);
			sleep(2.5);
			break;
		case 3:
			esborraUsuari(pF);
			if (!pF.isLoggedIn())
				return;
			break;
		case 4:
			return;
		default:
			cout << "Opció no vàlida.\n";
			break;
		}
	} while (true);

	return;
}

void CapaDePresentacio::consultaUsuari(PetitFlix &pF)
{
	system("clear");
	TxConsultaUsuari TxCons;
	TxCons.executar(pF);
	Usuari infoU = TxCons.obteResultat();

	TxInfoVisualitzacions TxInfo;
	TxInfo.executar(pF);
	std::pair infoVisualitzacions = TxInfo.obteResultat();

	cout << "** Modifica usuari **\n";
	cout << "Nom complet: " + infoU.obteNom() + "\n";
	cout << "Sobrenom: " + infoU.obteSobrenom() + "\n";
	cout << "Correu electronic: " + infoU.obteCorreuElectronic() + "\n";
	cout << "Data naixement: " + infoU.obteDataNaixement() + "\n";
	cout << "Modalitat subscripció: " + infoU.obteModalitat() + "\n";

	cout << "\n"
		 << infoVisualitzacions.first << " pel·licules visualitzades";
	cout << "\n"
		 << infoVisualitzacions.second << " capítols visualitzats";

	std::string intro;
	cin.ignore();
	std::getline(cin, intro);
}

void CapaDePresentacio::modificaUsuari(PetitFlix &pF)
{
	system("clear");
	CtrlModificaUsuari ctrlMod;
	Usuari infoU = ctrlMod.consultaUsuari(pF);

	cout << "** Modifica usuari **\n";
	cout << "Nom complet: " + infoU.obteNom() + "\n";
	cout << "Sobrenom: " + infoU.obteSobrenom() + "\n";
	cout << "Correu electronic: " + infoU.obteCorreuElectronic() + "\n";
	cout << "Data naixement: " + infoU.obteDataNaixement() + "\n";
	cout << "Modalitat subscripció: " + infoU.obteModalitat() + "\n";

	std::string intro;
	cin.ignore();
	std::getline(cin, intro);

	std::string nomU, contrasenyaU, correuU, dataU, modalitatU;
	cout << "Omplir la informació que es vol modificar ...\n";
	cout << "Nom complet: ";
	std::getline(cin, nomU);

	cout << "Contrasenya: ";
	std::getline(cin, contrasenyaU);

	cout << "Correu electronic: ";
	std::getline(cin, correuU);

	cout << "Data naixement: ";
	std::getline(cin, dataU);

	cout << "Modalitat subscripció: ";
	std::getline(cin, modalitatU);

	if (!ctrlMod.modificaUsuari(nomU, contrasenyaU, correuU, dataU, modalitatU, pF))
	{
		cout << "Error: el nou correu ja existeix. No s'ha modificat l'usuari.";
		return;
	}

	Usuari infoU_mod = ctrlMod.consultaUsuari(pF);

	cout << "\n** Dades usuari modificades **\n";
	cout << "Nom complet: " + infoU_mod.obteNom() + "\n";
	cout << "Sobrenom: " + infoU_mod.obteSobrenom() + "\n";
	cout << "Correu electronic: " + infoU_mod.obteCorreuElectronic() + "\n";
	cout << "Data naixement: " + infoU_mod.obteDataNaixement() + "\n";
	cout << "Modalitat subscripció: " + infoU_mod.obteModalitat() + "\n";

	cin.ignore();
	std::getline(cin, intro);
	return;
}

void CapaDePresentacio::esborraUsuari(PetitFlix &pF)
{
	system("clear");
	std::string contr;
	cout << "** Esborrar usuari **\n";
	cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ...\n";
	cout << "Contrasenya: ";
	cin >> contr;
	// std::string contr = getHiddenInput("Contrasenya: ");
	// cout << contr << endl;
	TxEsborraUsuari TxEsb(contr);
	if (TxEsb.executar(pF))
	{
		cout << "L'usuari s'ha esborrat correctament!\n";
		cout << "Tancant la sessió ...\n";
		sleep(2.5);
	}
	else
	{
		cout << "La contrasenya no és correcta, l'usuari no s'ha esborrat.\n";
		sleep(2.5);
	}
	return;
}

std::string CapaDePresentacio::getHiddenInput(const std::string &prompt)
{
	std::cout << prompt;
	// Turn off terminal echo
	termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt); // Save old terminal settings
	newt = oldt;
	newt.c_lflag &= ~ECHO;					 // Disable echo
	tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

	std::string input;
	std::getline(std::cin, input); // Use getline to properly handle input

	// Restore terminal settings
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	std::cout << std::endl; // Add a newline for better UX

	return input;
}


void CapaDePresentacio::mostraMenuVisualitzar(PetitFlix& pF) {
	int opcio;
	do {
		system("clear");
		std::cout << "*********************\n";
		std::cout << "    Menu Principal   \n";
		std::cout << "*********************\n";
		std::cout << "1. Visualitzar pel·lícula\n";
		std::cout << "2. Visualitzar capítol\n";
		std::cout << "3. Consultar visualitzacions\n";
		std::cout << "4. Tornar\n";
		std::cout << "Escriu opció: ";
		std::cin >> opcio;

		switch (opcio) {
		case 1:
			//visualitzaPelicula(pF);
			break;
		case 2:
			//visualitzaCapitol();
			break;
		case 3:
			//consultaVisualitzacions(pF); 
			break;
		case 4:
			return;
		default:
			std::cout << "Opció no vàlida.\n";
			break;
		}
	} while (true);

	return;
}
/*
void CapaDePresentacio::visualitzaPelicula(PetitFlix& pF) {
	system("clear");
	std::string titolPelicula;

	std::cout << "** Visualitzar Pel·lícula **\n";
	std::cout << "Introdueix el títol de la pel·lícula: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, titolPelicula);

	try {
		TxVisualitzaPelicula tx(titolPelicula); // Se pasa el objeto PetitFlix y el título de la película
		if (tx.executar()) {
			std::cout << "Pel·lícula visualitzada correctament!\n";
		}
	}
	catch (const TxVisualitzaPelicula::PeliculaNoExisteix&) {
		std::cout << "Error: La pel·lícula no existeix.\n";
	}
	catch (const TxVisualitzaPelicula::ErrorEdatInadequada&) {
		std::cout << "Error: No tens l'edat adequada per veure aquesta pel·lícula.\n";
	}
	catch (const TxVisualitzaPelicula::PeliculaNoEstrenada&) {
		std::cout << "Error: La pel·lícula encara no ha estat estrenada.\n";
	}

	std::cout << "Prem Intro per continuar...\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}


void CapaDePresentacio::visualitzaCapitol()
{
    system("clear");
    std::string titolSerie;
    int numeroTemporada, numeroCapitol;

    cout << "** Visualitzar Capítol **\n";
    cout << "Introdueix el títol de la série: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, titolSerie);

    cout << "Introdueix el número de la temporada: ";
    cin >> numeroTemporada;

    cout << "Introdueix el número del capítol: ";
    cin >> numeroCapitol;

    try
    {
        TxVisualitzaCapitol tx(titolSerie, numeroTemporada, numeroCapitol);
        if (tx.executar())
        {
            cout << "Capítol visualitzat correctament!\n";
        }
    }
    catch (const TxVisualitzaCapitol::CapitolNoExisteix&)
    {
        cout << "Error: El capítol no existeix.\n";
    }
    catch (const TxVisualitzaCapitol::ErrorEdatInadequada&)
    {
        cout << "Error: No tens l'edat adequada per veure aquest cap\u00edtol.\n";
    }
    catch (const TxVisualitzaCapitol::CapitolNoEstrenat&)
    {
        cout << "Error: El capítol encara no ha estat estrenat.\n";
    }
    cout << "Prem Intro per continuar...\n";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void CapaDePresentacio::consultaVisualitzacions(PetitFlix& pF) {
	if (!pF.isLoggedIn()) {
		std::cout << "Error: No hi ha cap usuari loguejat.\n";
		return;
	}

	std::string sobrenomUsuari = pF.getLoggedInUser(); // Usar getLoggedInUser para obtener el sobrenombre del usuario
	TxConsultaVisualitzacions tx;
	tx.executar(sobrenomUsuari);

	auto pelicules = tx.obtePelicules();
	auto capitols = tx.obteCapitols();

	std::cout << "Visualitzacions de Pel·lícules:\n";
	for (const auto& pelicula : pelicules) {
		std::cout << "- " << pelicula.first << " (Visualitzacions: " << pelicula.second << ")\n";
	}

	std::cout << "\nVisualitzacions de Capítols:\n";
	for (const auto& capitol : capitols) {
		std::cout << "- " << capitol.getTitolSerie() << " Temporada " << capitol.getNumeroTemporada()
			<< ", Capítol " << capitol.getNumeroCapitol()
			<< " (Visualitzacions: " << capitol.getNumVisualitzacions() << ")\n";
	}
	std::cout << "Prem Intro per continuar...\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}
*/


void CapaDePresentacio::mostraMenuConsultes()
{
	int opcio;
	do
	{
		system("clear");
		cout << "*********************\n";
		cout << "    Menu Principal   \n";
		cout << "*********************\n";
		cout << "1. Properes Estrenes\n";
		cout << "2. Últimes novetats\n";
		cout << "3. Pel·lícules més vistes\n";
		cout << "4. Tornar\n";
		cout << "Escriu opció: ";
		cin >> opcio;

		switch (opcio)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return;
		default:
			cout << "Opció no vàlida.\n";
			break;
		}
	} while (true);

	return;
}
