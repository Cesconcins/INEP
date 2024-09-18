#include <iostream>
//Nil Ferran
int main()
{
    std::string entrada;
    std::cout << "Hola INEP!\n";
    std::cout << "----------\n";
    std::cout << "Escriu un nombre:";
    std::cin >> entrada;
    std::cout << "Has escollit el nombre " + entrada + "\n";
}

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