#ifndef TRAB_AED_01_TREADMILL_H
#define TRAB_AED_01_TREADMILL_H
#include <queue>
#include "baggage.h"
using namespace std;
class Treadmill{
private:
    queue<Baggage> bag_queue;
public:
    Treadmill();
    void add_baggage(Baggage baggage);
    void dump_baggage(); //in the menu should be followed by adding to cart

};
#endif //TRAB_AED_01_TREADMILL_H
