/*
 Per cada una de les opcions del menú principal, es crida a una operació separada
que és on es posa el codi per processar l’opció escollida. Aquesta operació no té
paràmetres, ni retorna res. Per exemple, per a l’opció 1, aquesta operació tindrà de
nom procesarRegistreUsuari (sense paràmetres).
● Les operacions que processen les diferents opcions tindran el codi perquè l’usuari
entri la informació que es necessiti i a continuació mostraran el missatge “operació
procesada”. Per exemple, per la operació procesarRegistreUsuari:
1. Es demana a l’usuari que entri el sobrenom i el seu nom complet.
2. Si l’usuari entra els dos camps es mostrarà el missatge “El registre de l’usuari
<nom complet> (<sobrenom>) s’ha processat correctament”.
3. Si algun dels camps s’ha deixat en blanc, es mostrarà el missatge “Error al
registrar usuari”.
*/

#ifndef GESTIO_USUARIS_H
#define GESTIO_USUARIS_H

#include <iostream>
#include <string>

class GestioUsuaris {
public:
    void procesarRegistreUsuari() {
        std::string sobrenom, nomComplet;
        
        // Demana sobrenom i nom complet
        std::cout << "Entra el sobrenom: ";
        std::cin >> sobrenom;
        std::cout << "Entra el nom complet: ";
        std::cin.ignore(); // Neteja el buffer
        std::getline(std::cin, nomComplet);

        // Processa l'entrada i mostra el resultat
        if (sobrenom.empty() || nomComplet.empty()) {
            std::cout << "Error al registrar usuari.\n";
        } else {
            std::cout << "El registre de l'usuari " << nomComplet << " (" << sobrenom << ") s'ha processat correctament.\n";
        }
    }
};

#endif // GESTIO_USUARIS_H
