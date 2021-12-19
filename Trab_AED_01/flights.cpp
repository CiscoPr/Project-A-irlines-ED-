#include "flights.h"
#include "planes.h"
#include <iostream>
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




