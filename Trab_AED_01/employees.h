#ifndef TRAB_AED_01_EMPLOYEES_H
#define TRAB_AED_01_EMPLOYEES_H

#include <string>
#include <system_error>

using namespace std;

class Employee {
private:
    string name;
public:
    Employee();
    Employee(string name);
    string get_name();
};
#endif
