#ifndef TRAB_AED_01_FLIGHTS_H
#define TRAB_AED_01_FLIGHTS_H

#include <string>
#include "company.h"
#include "company.cpp"
using namespace std;
class Company;
class Plane;

class Flight {
private:
    int id;
    float duration;
    float departure;
    string origin;
    string destination;
public:
    Flight(int id, float duration, float departure, string origin, string destination);
    int get_id();
    float get_departure();
    float get_duration();
    string get_origin();
    string get_destination();
    bool add_flight();
    bool cancel_flight(int id, Company &comp1);
};

#endif
