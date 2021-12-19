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
Service::Service(Servicetype s1, float data, Employee employee) {
    this->type=s1;
    this->data=data;
    this->employee=employee;
}