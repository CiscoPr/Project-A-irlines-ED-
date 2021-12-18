#include <iostream>
#include "planes.h"
#include "company.h"
#include "algorithm"

using namespace std;


Plane::Plane(string registration, string type, int capacity) {
    this->registration=registration;
    this->type=type;
    this->capacity=capacity;
}


string Plane::get_registration() {
    return registration;
}

string Plane::get_type() {
    return type;
}
int Plane::get_capacity() {
    return capacity;
}

void Plane::set_plans(vector<Flight> plan) {
    this->plan=plan;
}

vector<Flight> Plane::get_plan() {
    return plan;
}

void Plane::set_flights(ifstream &f) {
    int id;
    float duration;
    float departure;
    string id_str, duration_str, departure_str, origin, destination;
    getline(f, id_str);
    getline(f, duration_str);
    getline(f, departure_str);
    getline(f, origin);
    getline(f, destination);
    stringstream s1(id_str), s2(duration_str), s3(departure_str);
    s1 >> id;
    s2 >> duration;
    s3 >> departure;
    Flight f1(id, duration, departure, origin, destination);
    this->plan.push_back(f1);
}

void Plane::show_flights() {
    for (int i =0; i < plan.size();i++){
        cout << "id= " << plan[i].get_id()<<" duration= " << plan[i].get_duration() << " departure= " <<plan[i].get_departure()<< endl << "origin= "<<plan[i].get_origin()<< " destination="<<plan[i].get_destination();
        }
    }
/*
bool compFlights(Flight &f1, Flight &f2){
    if (f1.get_departure() != f2.get_departure()){
        return f1.get_departure()< f2.get_departure();
    }
    else if (f1.get_departure() == f2.get_departure() && f1.get_duration() != f1.get_duration()){
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