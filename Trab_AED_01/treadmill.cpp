#include "treadmill.h"
Treadmill::Treadmill() {
}
void Treadmill::add_baggage(Baggage baggage) {
    bag_queue.push(baggage);
}

void Treadmill::dump_baggage() {
    bag_queue.pop();
}