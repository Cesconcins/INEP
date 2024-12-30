#ifndef PASSARELAVISUALITZACIOCAPITOL_H
#define PASSARELAVISUALITZACIOCAPITOL_H

#include <string>

class PassarelaVisualitzacioCapitol {
public:
    static void registraVisualitzacio(const std::string& sobrenomUsuari, const std::string& titolSerie, int numeroTemporada, int numeroCapitol);
    static std::vector<Capitol> consultaVisualitzacions(const std::string& sobrenomUsuari);
};

#endif // PASSARELAVISUALITZACIOCAPITOL_H
