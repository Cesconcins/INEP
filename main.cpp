#include <iostream>
#include "DBConnection.h"
#include "mainMenu.h"

using namespace std;

int main() {
    sql::Connection* conn = open_connection();
    int opcio;

    do {
        mostraMenuPrincipalNoLogin();
        cin >> opcio;

        switch (opcio) {
            case 1:
                // do IniciaSessió
            case 2:
                // do RegistraUsuari
            case 3:
                // do consultes
            default:
                cout << "Opció no vàlida.\n";
        }
    } while (opcio != 4);

    close_connection(conn);
    return 0;
}
