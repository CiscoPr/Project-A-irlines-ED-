#ifndef TRAB_AED_01_COMPANY_H
#define TRAB_AED_01_COMPANY_H
#include "flights.h"
#include "planes.h"
#include <vector>
#include <fstream>
using namespace std;
class Plane;
class Company{
private:
    vector<Plane> planes;
public:
    Company(); //Constructor
    void set_planes(ifstream &f); //reads from file and adds all planes to the vector of planes of the company
    void show_planes(); // shows in the console all the info from the planes that belong to company
    void add_plane(string registration, string type, int capacity); // adds plane with the attributes we give to the vector planes of the company
    bool remove_plane(string registration); // checks if there's some plane with the registration we gave removing him from the vector planes of the company
    vector<Plane> &get_planes(); // returns the vector of planes its usefull in other methods
    void update(ofstream &f); // change the file to contain the information we changed and store it for the future
};

#endif //TRAB_AED_01_COMPANY_H
