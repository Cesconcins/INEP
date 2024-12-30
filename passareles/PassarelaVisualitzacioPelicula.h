#ifndef PASSARELAVISUALITZACIOPELICULA_H
#define PASSARELAVISUALITZACIOPELICULA_H

#include <string>

class PassarelaVisualitzacioPelicula {
public:
    static void registraVisualitzacio(const std::string& sobrenomUsuari, const std::string& titolPelicula);
    static std::vector<std::pair<std::string, int>> consultaVisualitzacions(const std::string& sobrenomUsuari);
};

#endif // PASSARELAVISUALITZACIOPELICULA_H
