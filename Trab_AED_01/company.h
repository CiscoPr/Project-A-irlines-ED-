#ifndef TRAB_AED_01_COMPANY_H
#define TRAB_AED_01_COMPANY_H
#include "planes.h"
#include <fstream>
#include <vector>

using namespace std;

class Company {
private:
    vector<Plane> planes;
public:
    Company();
    vector<Plane> get_planes();
    void set_planes(ifstream &plane);
    void show_planes();
    void add_plane(Plane p1);
    bool remove_plane(string registration);
};

#endif