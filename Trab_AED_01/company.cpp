#include <iostream>
#include "company.h"
using namespace std;

void Company::set_planes(ifstream &f) {
    while (!f.eof()) {
        string registration, capacityStr;
        unsigned capacity;
        getline(f, registration);
        getline(f, capacityStr);
        capacity = stoi(capacityStr);
        Plane p1(registration, capacity);
        planes.push_back(p1);
    }
}
void Company::show_planes() {
    int a =1;
    for (int i =0; i < planes.size();i++){
        cout << "plane"<<a<< " " << planes[i].get_registration() << " capacity = "<<planes[i].get_capacity()<<endl;
        a++;
    }
}

void Company::add_plane(Plane p1) {
    planes.push_back(p1);
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
