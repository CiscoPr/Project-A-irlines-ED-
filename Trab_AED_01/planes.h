#ifndef TRAB_AED_01_PLANES_H
#define TRAB_AED_01_PLANES_H

#include "planes.h"
#include "company.h"
#include "flights.h"
#include "flights.cpp"
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
    list<Flight> get_plan();
    void set_plans(list<Flight> plan);
    string get_registration();
    int get_capacity();
    bool add_flight();

};
#endif
