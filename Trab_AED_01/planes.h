#ifndef TRAB_AED_01_PLANES_H
#define TRAB_AED_01_PLANES_H

#include "planes.h"
#include "company.h"
#include "flights.h"
#include <string>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

class Flight;
class Company;

class Plane{
private:
            string registration;
            string type;
            int capacity;
            vector<Flight> plan;
public:
    Plane(string registration, string type, int capacity);
    void set_plans(vector<Flight> plan);
    string get_registration();
    string get_type();
    vector<Flight> get_plan();
    int get_capacity();
    void set_flights(ifstream &f);
    void show_flights();
    bool add_flight(Flight flight);
    bool cancel_flight(int id);
    void uopdate(fstream &f);
};


#endif
