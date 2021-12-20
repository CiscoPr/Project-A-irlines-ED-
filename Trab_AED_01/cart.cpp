#include "cart.h"
Cart::Cart(int c, int n, int m) {
    this->c=c;
    this->n=n;
    this->m=m;
}

bool Cart::add_baggage_c(Baggage baggage) {
    for (int i=0; i< c;i++ ){
        for(int j=0; i <n; i++){
            if (cart[i][j].size()<m){
                cart[i][j].push(baggage);
                return true;
            }
        }
    }
    return false;
}
bool Cart::remove_baggage_c(int id) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; i < n; i++) {
            if (cart[i][j].top().get_id() == id) {
                cart[i][j].pop();
                return true;
            }
        }
    }
    return false;
}