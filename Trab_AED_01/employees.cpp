#include "employees.h"
using namespace std;
Employee::Employee(){

}
Employee::Employee(string name) {
    this->name=name;
}
string Employee::get_name() {
    return name;
}