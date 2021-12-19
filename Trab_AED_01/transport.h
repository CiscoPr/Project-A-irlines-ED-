//
// Created by Francisco Prada on 19/12/2021.
//

#ifndef TRAB_AED_01_TRANSPORT_H
#define TRAB_AED_01_TRANSPORT_H
#include <string>
#include "bst.h"
#include <fstream>
using namespace std;
class Transport {
    string type, distance, hours;
    friend bool operator <(const Transport & a, const Transport & b);
    friend ostream& operator <<(ostream& out ,const Transport & a);
public:
    Transport(string t, string d, string h);
    string getType() const;
    string getD() const;
    string getHours() const;
    void setType(string t);
    void setDistance(string d);
    void setHours(string h);
};

class Local_of_Transport{
    BST<Transport> transports;
public:
    Local_of_Transport(): transports(Transport("", "", "")){};    //not sure if it is right
    BST<Transport> getTrans() const;
    void readFile(ifstream& f);
    void print() const;

};
#endif //TRAB_AED_01_TRANSPORT_H
