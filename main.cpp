#include <iostream>
#include <unistd.h>
#include <stdlib.h> 
#include "CapaDePresentacio.h"
#include "PetitFlix.h"

using namespace std;

int main() {
    CapaDePresentacio capaP;
    PetitFlix pF;
    int opcio;

    do {
        if (pF.isLoggedIn()) {
            capaP.mostraMenuPrincipalNoLogin();

            if (opcio == 4) {
                break; 
            }

            switch (opcio) {
                case 1:
                    capaP.iniciaSessio();
                    break;
                case 2:
                    // do RegistraUsuari
                    break;
                case 3:
                    // do consultes
                    break;
                default:
                    cout << "Opció no vàlida.\n";
                    break;
            }
            sleep(4);
            system("clear");
        } else {
            capaP.mostraMenuPrincipalLogin();
        }
        
    } while (cin >> opcio);

    return 0;
}
