#ifndef TRAB_AED_01_PLANES_H
#define TRAB_AED_01_PLANES_H

#include "planes.h"
#include "flights.h"
#include <string>
#include <list>

using namespace std;

class Plane{
private:
    string registration;
    int capacity;
    list<Flight> plan;
public:
    Plane(string registration, int capacity);
    string get_registration();
    bool remove_plane();
    void add_plane();

};
#endif
