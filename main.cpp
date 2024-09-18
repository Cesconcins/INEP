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