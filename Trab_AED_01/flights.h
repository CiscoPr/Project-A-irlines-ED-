#ifndef TRAB_AED_01_FLIGHTS_H
#define TRAB_AED_01_FLIGHTS_H

#include <string>
#include "company.h"
#include "tickets.h"
using namespace std;
class Company;

class Flight {
private:
    int id, seats_available;
    float duration;
    float departure;
    string origin;
    string destination;
public:
    Flight(int id, int seats_available, float duration, float departure, string origin, string destination);

    int get_id();

    int get_seats_available();

    float get_departure();

    float get_duration();

    string get_origin();

    string get_destination();
};

#endif
