#ifndef TRAB_AED_01_PLANES_H
#define TRAB_AED_01_PLANES_H

#include "planes.h"
#include "flights.h"
#include <string>
#include <list>

using namespace std;

class Plane{
private:
    string registration3;
    int capacity;
    list<Flight> plan;
public:
    Plane(int registration, int capacity);
    void set_flights(list<Flight> plan);
    bool cancel_flight( Flight flight); // provavelmnete deveria ser feito na class flights
    bool add_flight();  //adiciona um voo na lista do avião com menos flights dos disponíveis se nenhum avião tiver disponivel da return de false
};
#endif
