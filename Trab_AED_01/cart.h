#ifndef TRAB_AED_01_CART_H
#define TRAB_AED_01_CART_H
#include "baggage.h"
#include <queue>
#include <stack>
#include <list>
#include <vector>
using namespace std;
class Cart{
private:
    vector<vector<stack<Baggage>>> cart;
    int c,n,m;

public:
    Cart(int c, int n, int m);
    bool add_baggage_c(Baggage baggage); //adds baggage to the first available place
    bool remove_baggage_c(int id);  //removes baggage from a stack if it is at the top

};

#endif //TRAB_AED_01_CART_H
