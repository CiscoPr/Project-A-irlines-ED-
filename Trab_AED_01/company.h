#ifndef TRAB_AED_01_COMPANY_H
#define TRAB_AED_01_COMPANY_H
#include "flights.h"
#include "planes.h"
#include <vector>
using namespace std;
class Flight;
class Plane;

class Company{
private:
    vector<Plane> planes;
public:
    Company();

};

#endif //TRAB_AED_01_COMPANY_H
