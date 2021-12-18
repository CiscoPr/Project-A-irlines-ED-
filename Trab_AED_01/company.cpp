#include <iostream>
#include "company.h"
#include <sstream>
#include <algorithm>
using namespace std;
bool compPlane( Plane &p1,  Plane &p2){
    return p1.get_registration()< p2.get_registration();
}



Company::Company() {
    vector<Plane> empty;
    this->planes = empty;
}

void Company::set_planes(ifstream &f) {
    vector<Plane> up_plane;
    while (!f.eof()){
        string registration, capacityStr;
        getline(f, registration);
        getline(f, capacityStr);
        stringstream s1(capacityStr);
        int capacity;
        s1 >> capacity;
        Plane p1(registration,capacity);
        up_plane.push_back(p1);
    }
    sort(up_plane.begin(), up_plane.end(), compPlane);
    this->planes=up_plane;
}

void Company::show_planes() {
    int a =1;
    for (int i =0; i < planes.size();i++){
        cout << endl<<"plane" << a << " " << planes[i].get_registration() << " capacity = " <<planes[i].get_capacity()<<endl;
        a++;
    }
}

void Company::add_plane(string registration, int capacity) {
    Plane p1(registration, capacity);
    planes.push_back(p1);
    sort(planes.begin(), planes.end(), compPlane);
}
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

void Company::update(ofstream &f) {
    for (int i = 0; i < planes.size();i++){
        f << planes[i].get_registration() << endl << planes[i].get_capacity()<< endl;
    }
}

