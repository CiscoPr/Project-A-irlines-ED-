#include "planes.h"
#include "algorithm"
#include "company.h"
using namespace std;

Plane::Plane(string registration, int capacity) {
    this->registration=registration;
    this->capacity=capacity;
}

string Plane::get_registration() {
    return registration;
}

int Plane::get_capacity() {
    return capacity;
}





/*
bool compFlights(Flight &f1, Flight &f2){
    if (f1.get_departure() != f2.get_departure()){
        return f1.get_departure()< f2.get_departure();
    }
    else if (f1.get_departure() != f2.get_departure() && f1.get_duration() == f1.get_duration()){
        return f1.get_duration()< f2.get_duration();
    }
    else return f1.get_id()< f2.get_id();
};


void Plane::set_flights(list<Flight> plan) {
    this->plan=plan ;
    plan.sort(compFlights);
}
bool Plane::cancel_flight(Flight flight){
    list<Flight>::iterator it;
    for (it= plan.begin();it != plan.end(); it++){
        if ( (*it).get_id()==flight.get_id()){
            plan.erase(it);
            return true;
        }
    }
    return false;
}
 */