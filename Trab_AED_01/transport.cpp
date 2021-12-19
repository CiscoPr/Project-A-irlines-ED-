//
// Created by Francisco Prada on 19/12/2021.
//
#include <iostream>
#include <string>
#include <fstream>
#include "transport.h"
#include "bst.h"
using namespace std;

Transport::Transport(string t, string h, string d): type(t), distance(d), hours(h) {}

string Transport::getType() const {
    return type;
}

string Transport::getD() const{
    return distance;
}

string Transport::getHours() const {
    return hours;
}

void Transport::setType(string t) {
    type = t;
}

void Transport::setDistance(string d) {
    distance=d;
}

void Transport::setHours(string h) {
    hours=h;
}


BST<Transport> Local_of_Transport::getTrans() const {
    return transports;
}

bool operator<(const Transport &a, const Transport &b){
    return (a.type < b.type);
}

ostream & operator <<(ostream& out, const Transport &a){
    out << a.type << endl << a.hours << endl << a.distance;
    return out;
}


void Local_of_Transport::readFile(ifstream &f) {
    while(!f.eof()){
        string t, d, h;
        getline(f, t);
        getline(f, h);
        getline(f, d);
        transports.insert(Transport(t,h,d));
    }
}


void Local_of_Transport::print() const {
    transports.printTree();
}