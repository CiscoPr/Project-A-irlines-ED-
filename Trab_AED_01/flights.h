#ifndef TRAB_AED_01_FLIGHTS_H
#define TRAB_AED_01_FLIGHTS_H

#include <string>
#include "company.h"

using namespace std;
class Company;

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
};

#endif
