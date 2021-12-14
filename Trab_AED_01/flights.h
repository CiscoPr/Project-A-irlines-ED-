#ifndef TRAB_AED_01_FLIGHTS_H
#define TRAB_AED_01_FLIGHTS_H

#include <string>

using namespace std;

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
    bool cancel_flight()
    bool add_flight();  //adiciona um voo na lista do avião com menos flights dos disponíveis se nenhum avião tiver disponivel da return de false
};

#endif
