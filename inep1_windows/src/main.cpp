#include <iostream>
#include <stdlib.h> 
#include "CapaDePresentacio.h"
#include "../sistema/PetitFlix.h"
#include <windows.h>

using namespace std;

int main() {
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);
    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    CapaDePresentacio capaP;
    PetitFlix pF;
    int opcio;

    do {
        if (!pF.isLoggedIn()) {
            capaP.mostraMenuPrincipalNoLogin();
        } else {
            capaP.mostraMenuPrincipalLogin();
        }

        if (!(cin >> opcio)) { // Input validation
            cin.clear();
            cin.ignore('\n'); 
            cout << "Invalid input. Please enter a number.\n";
            continue; // Skip this iteration
        }

        if (!pF.isLoggedIn()) {
            switch (opcio) {
                case 1:
                    capaP.iniciaSessio(pF);
                    Sleep(2000);
                    break;
                case 2:
                	capaP.registrarUsuari();
                	Sleep(3000);
                    break;
                case 3:
                    break;
                case 4:
                	cout << "Sortint de l'applicació...\n";
                	exit(0);
                default:
                    cout << "Opció no vàlida.\n";
                    break;
            }
        } else {
            switch (opcio) {
                case 1:
                	capaP.mostraMenuGestioUsuari(pF);
                    break;
                case 2:
                	capaP.mostraMenuVisualitzar(pF);
                    break;
                case 3:
                	capaP.mostraMenuConsultes();
                	break;
                case 4:
                	capaP.tancaSessio(pF);
                	Sleep(2000);
                	break;
                case 5:
                	cout << "Sortint de l'applicació...\n";
                	exit(0);
                default:
                    cout << "Opció no vàlida.\n";
                    break;
            }
        }
    } while (true);

    return 0;
}
