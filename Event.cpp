#include "Event.h"

Event::Event(std::string newType, int newTransactionTime) : 
    type(newType),
    transactionTime(newTransactionTime)
{}

std::string Event::getType() const {
    return type;
}

int Event::getArrivalTime() const {
    return 1;
}

int Event::getTransactionTime() const {
    return transactionTime;
}