/*#include <iostream>
//Nil Ferran
int main()
{
    std::string entrada;
    std::cout << "Hola INEP!\n";
    std::cout << "----------\n";
    std::cout << "Escriu un nombre:";
    std::cin >> entrada;
    std::cout << "Has escollit el nombre " + entrada + "\n";
}*/

//canvi fet per Ausias Plaza

/*
Cadascuna de les opcions del menú principal portarà a un altre menú. A continuació
s’inclouen totes les opcions dels menús:
1. Gestió usuari
    1. Registre usuari
    2. Consulta usuari
    3. Modifica usuari
    4. Esborra usuari
    5. Tornar

2. Gestió continguts
    1. Gestió pel·lícules
    2. Gestió sèries
    3. Tornar

3. Consultes
    1. Consulta per qualificació d’edat
    2. Últimes novetats
    3. Pròximes estrenes
    4. Tornar
4. Sortir
*/


#include <iostream>
#include "gestio_usuari.h"

using namespace std;

void mostrarMenuPrincipal() {
    cout << "Menú principal\n";
    cout << "1. Registre usuari\n";
    cout << "2. Sortir\n";
    cout << "Tria una opció: ";
}

int main() {
    int opcio;
    GestioUsuaris gestioUsuaris;

    do {
        mostrarMenuPrincipal();
        cin >> opcio;

        switch (opcio) {
            case 1: 
                gestioUsuaris.procesarRegistreUsuari(); 
                break;
            case 2: 
                cout << "Sortint de l'aplicació...\n"; 
                break;
            default: 
                cout << "Opció no vàlida.\n";
        }
    } while (opcio != 2);

    return 0;
}
