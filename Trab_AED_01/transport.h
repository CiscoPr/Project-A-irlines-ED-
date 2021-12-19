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
    string type;
    int distance;
    float hours;
    friend bool operator <(const Transport & a, const Transport & b);
    friend ostream& operator <<(ostream& out ,const Transport & a);
public:
    Transport(string t, int d, float h);
    string getType() const;
    int getD() const;
    float getHours() const;
    void setType(string t);
    void setDistance(int d);
    void setHours(float h);
};

class Local_of_Transport{
    BST<Transport> transports;
public:
    Local_of_Transport(): transports(Transport("", 0, 0.0)){};    //not sure if it is right
    BST<Transport> getTypes() const;
    void readFile(ifstream& f);
    string consult(string type1, Transport& previous, Transport& next) const;
    bool update(string type1, int distance1, float hours1);
    void print() const;

};
#endif //TRAB_AED_01_TRANSPORT_H
