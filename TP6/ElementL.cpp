#include "ElementL.h"
#include <iostream>

void afficherElementL (ElementL e) { std::cout << e; }

bool estEgalElementL (ElementL e1, ElementL e2) { return e1 == e2; }

bool estInferieurElementL (ElementL e1, ElementL e2) { return e1 < e2; }
