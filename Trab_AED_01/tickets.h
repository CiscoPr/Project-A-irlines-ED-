#ifndef TRAB_AED_01_TICKETS_H
#define TRAB_AED_01_TICKETS_H
#include "flights.h"
using namespace std;

class Ticket{
    int number_of_tickets;
    //Flight flight;
public:
    Ticket(int number_of_tickets);
    int getNumberOfTickets();
    bool baggage;

    Ticket();
};
#endif
