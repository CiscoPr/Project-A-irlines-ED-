#include "company.h"
using namespace std;

void Company::set_planes(ifstream &f) {
    while( !f.eof()){
        string registration, capacityStr;
        unsigned capacity;
        getline(f, registration);
        getline(f,capacityStr);
        capacity= stoi(capacityStr);
    }

}