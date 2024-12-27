#ifndef VISUALITZAPELLICULA_H
#define VISUALITZAPELLICULA_H

#include <iostream>
#include "DBConnection.h"

class VisualitzaPellicula {
public:
    static void visualitza(const std::string& userNickname, const std::string& movieTitle);
};

#endif
