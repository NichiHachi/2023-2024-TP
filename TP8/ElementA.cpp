#include "ElementA.h"

#include <iostream>

void afficherElementA(ElementA e) { std::cout << e; }

bool estInferieurElementA(ElementA e1, ElementA e2) { return e1 < e2; }

bool estSuperieurElementA(ElementA e1, ElementA e2) { return e1 > e2; }

bool estSuperieurOuEgalElementA(ElementA e1, ElementA e2) { return e1 >= e2; }

bool estEgalElementA(ElementA e1, ElementA e2) { return e1 == e2; }
