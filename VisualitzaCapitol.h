#ifndef VISUALITZACAPITOL_H
#define VISUALITZACAPITOL_H

#include <iostream>
#include "DBConnection.h"

class VisualitzaCapitol {
public:
    static void visualitza(const std::string& userNickname, const std::string& seriesTitle);
};

#endif
