#include <iostream>
#include "company.h"
using namespace std;

Company::Company() {
    vector<Plane> empty;
    this->planes = empty;
}

void Company::set_planes(ifstream &f) {
    vector<Plane> up_plane;
    while (!f.eof()){
        string registration, capacityStr;
        unsigned capacity;
        getline(f, registration);
        getline(f, capacityStr);
        capacity= stoi(capacityStr);
        Plane p1(registration,capacity);
        up_plane.push_back(p1);
    }
    this->planes=up_plane;
}

void Company::show_planes() {
    int a =1;
    for (int i =0; i < planes.size();i++){
        cout << "plane" << a << " " << planes[i].get_registration() << " capacity = " <<planes[i].get_capacity()<<endl;
        a++;
    }
}

//void Company::add_plane(Plane p1) {
  //  planes.push_back(p1);
//}
bool Company::remove_plane(string registration) {
    for( int i =0; i < planes.size();i++){
        if (registration == planes[i].get_registration()){
            planes.erase(planes.begin()+i);
            return true;
        }
    }
    return false;
}

vector<Plane> Company::get_planes() {
    return planes;
}
