#ifndef TRAB_AED_01_SERVICES_H
#define TRAB_AED_01_SERVICES_H


#include "employees.h"
using namespace std;

class Service{
private:
    enum service{
        maintenance, cleaning};
    float data;
    Employee employee;
};



#endif
