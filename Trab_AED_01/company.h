#ifndef TRAB_AED_01_COMPANY_H
#define TRAB_AED_01_COMPANY_H
#include "planes.h"
#include <fstream>

using namespace std;

class Company {
private:
    list<Plane> planes;
public:
    void set_planes(ifstream &plane);
};

#endif