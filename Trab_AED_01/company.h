#ifndef TRAB_AED_01_COMPANY_H
#define TRAB_AED_01_COMPANY_H
#include "flights.h"
#include "planes.h"
#include <vector>
#include <fstream>
using namespace std;
class Plane;
class Company{
private:
    vector<Plane> planes;
public:
    Company();
    void set_planes(ifstream &f);
    void show_planes();
    bool remove_plane(string registration);
    vector<Plane> get_planes();
    void update();
};

#endif //TRAB_AED_01_COMPANY_H
