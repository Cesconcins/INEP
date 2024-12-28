#include <iostream>
#include <unistd.h>
#include <stdlib.h> 
#include "CapaDePresentacio.h"
#include "../sistema/PetitFlix.h"

using namespace std;

int main() {
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number.\n";
            continue; // Skip this iteration
        }

        if (!pF.isLoggedIn()) {
            switch (opcio) {
                case 1:
                    capaP.iniciaSessio(pF);
                    sleep(2);
                    break;
                case 2:
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
            std::system("clear");
        } else {
            // Add logic for logged-in menu actions if needed
            switch (opcio) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                	break;
                case 4:
                	capaP.tancaSessio(pF);
                	sleep(2);
                	break;
                case 5:
                	cout << "Sortint de l'applicació...\n";
                	exit(0);
                default:
                    cout << "Opció no vàlida.\n";
                    break;
            }
            std::system("clear");
        }
    } while (true);

    return 0;
}
