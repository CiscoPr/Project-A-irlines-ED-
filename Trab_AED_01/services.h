#ifndef TRAB_AED_01_SERVICES_H
#define TRAB_AED_01_SERVICES_H


#include "employees.h"
using namespace std;
enum Servicetype{
    maintenance, cleaning};
class Service{
    float data;
    Employee employee;
    Servicetype type;
public:
    Servicetype get_type();
    float get_data();
    Employee get_employee();
};


#endif
