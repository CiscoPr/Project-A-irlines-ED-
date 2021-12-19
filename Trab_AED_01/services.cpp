#include "services.h"
using namespace std;

Servicetype Service::get_type() {
    return this->type;
}

float Service::get_data() {
    return data;
}

Employee Service::get_employee() {
    return employee;
}