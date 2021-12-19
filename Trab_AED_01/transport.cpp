//
// Created by Francisco Prada on 19/12/2021.
//
#include <iostream>
#include <string>
#include <fstream>
#include "transport.h"
using namespace std;

Transport::Transport(string t, int d, float h): type(t), distance(d), hours(h) {}

string Transport::getType() const {
    return type;
}

int Transport::getD() const{
    return distance;
}

float Transport::getHours() const {
    return hours;
}

void Transport::setType(string t) {
    type = t;
}

void Transport::