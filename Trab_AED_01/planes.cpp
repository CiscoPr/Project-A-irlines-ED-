#include <iostream>
#include "planes.h"
#include "company.h"
#include "algorithm"

using namespace std;

bool compFlights(Flight &f1, Flight &f2){
    if (f1.get_departure() != f2.get_departure()){
        return f1.get_departure()< f2.get_departure();
    }
    else if (f1.get_departure() == f2.get_departure() && f1.get_duration() != f1.get_duration()){
        return f1.get_duration()< f2.get_duration();
    }
    else return f1.get_id()< f2.get_id();
};


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

vector<Flight> &Plane::get_plan() {
    return plan;
}

void Plane::set_flights(ifstream &f) {
    vector<Flight>c;
    vector<string> a;
    string s1,b;
    int id;
    float duration;
    float departure;
    string id_str, duration_str, departure_str, origin, destination;
    getline(f, s1);
    stringstream s2(s1);
    while(s2>>b) {
        a.push_back(b);
    }
    for (int i =0;i < a.size();i++){
        id_str=a[i];
        i++;
        duration_str=a[i];
        i++;
        departure_str=a[i];
        i++;
        origin=a[i];
        i++;
        destination=a[i];
        stringstream s3(id_str);
        s3>>id;
        stringstream s4(duration_str);
        s4>>duration;
        stringstream s5(departure_str);
        s5>>departure;
        Flight f1(id,duration,departure,origin,destination);
        c.push_back(f1);
    }
    sort(c.begin(), c.end(), compFlights);
    this->plan=c;
}

void Plane::show_flights() {
    for (int i =0; i < plan.size();i++){
        cout << endl << "id= " << plan[i].get_id()<<" duration= " << plan[i].get_duration() << " departure= " <<plan[i].get_departure()<< " origin= "<<plan[i].get_origin()<< " destination= "<<plan[i].get_destination()<<endl;
        }
    }

bool Plane::add_flight(Flight flight ) {
    for (int i = 0 ; i < plan.size();i++){
        if ((flight.get_departure() > plan[i].get_departure()+plan[i].get_duration()) && (flight.get_departure()+flight.get_duration() < plan[i+1].get_departure())){
            plan.push_back(flight);
            sort ( plan.begin(), plan.end(), compFlights);
            return true;
        }
    }
    return false;
}


bool Plane::cancel_flight(int id) {
    for (int i = 0; i < plan.size();i++){
        if (plan[i].get_id()==id){
            plan.erase(plan.begin()+i);
            return true;
        }
    }
    return false;
}

void Plane::update(ofstream &f) {
    for (int i=0;i < plan.size();i++){
        f << plan[i].get_id() << " "<<plan[i].get_duration()<< " "<<plan[i].get_departure()<< " "<<plan[i].get_origin()<<" "<<plan[i].get_destination()<< endl;
    }
}

queue<Service> Plane::get_service() {
    return service;
}

void Plane::do_service() {
    Service a =service.front();
    service.pop();
    service_done.push(a);
}
void Plane::show_last_service_done() {
    cout << service_done.top().get_type() << " " << service_done.top().get_employee().get_name() << " "<<service_done.top().get_data() ;
}

void Plane::set_services(ifstream &f) {
    vector<string> a;
    int data;
    Servicetype type;
    string s1,b,date_str, name;
    string type_str;
    getline(f, s1);
    stringstream s2(s1);
    while(s2>>b) {
        a.push_back(b);
    }
    for (int i =0;i < a.size();i++){
        type_str=a[i];
        i++;
        date_str=a[i];
        i++;
        stringstream s3(date_str);
        stringstream s4(type_str);
        s3>> data;
        s4 >> type;
        name=a[i];
        Employee e1(name);
        Service s1(type,data,e1);
    }
    sort(c.begin(), c.end(), compFlights);
    this->plan=c;
}