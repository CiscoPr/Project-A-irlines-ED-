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
    Company(); //done
    vector<Plane> get_planes();
    void set_planes(ifstream &f); //done
    void show_planes(); //done
    void add_plane(string registration, int capacity);
    bool remove_plane(string registration);
    void update(ofstream &f);
};

#endif //TRAB_AED_01_COMPANY_H
