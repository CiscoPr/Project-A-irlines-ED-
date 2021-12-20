#include "tickets.h"
#include <iostream>

//useless class

using namespace std;

Ticket::Ticket(int number_of_tickets) {
    this->number_of_tickets=number_of_tickets;
}

int Ticket::getNumberOfTickets() {
    return number_of_tickets;
}

Ticket::Ticket() {

}
