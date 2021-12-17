#include "flights.h"
#include "planes.h"
using namespace std;

Flight::Flight(int id, float duration, float departure, string origin, string destination) {
    this->id=id;
    this->duration=duration;
    this->departure=departure;
    this->origin=origin;
    this->destination=destination;
}

int Flight::get_id() {
    return id;
}
float Flight::get_departure() {
    return departure;
}
float Flight::get_duration(){
    return duration;
}
string Flight::get_origin() {
    return origin;
}
string Flight::get_destination() {
    return destination;
}
bool Flight::cancel_flight(int id, Company &comp1) {
    vector<Plane> planes=comp1.get_planes();
    list<Flight>::iterator it;
    for(int i =0; i < planes.size(); i++){
        Plane p1 = planes[i];
        list<Flight> plan= p1.get_plan();
        for(it=plan.begin();it != plan.end();it++){
            if((*it).get_id()==id){
                plan.erase(it);
                return true;
            }
        }
    }
    return false;
}