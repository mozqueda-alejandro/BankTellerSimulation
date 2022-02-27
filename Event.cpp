#include "Event.h"

Event::Event(std::string newType, int newArrivalTime) : 
    type(newType),
    arrivalTime(newArrivalTime) {}

Event::Event(std::string newType, int newArrivalTime, int newTransactionTime) : 
    type(newType), 
    arrivalTime(newArrivalTime),
    transactionTime(newTransactionTime) {}

std::string Event::getType() const {
    return type;
}

int Event::getArrivalTime() const {
    return arrivalTime;
}

int Event::getTransactionTime() const {
    return transactionTime;
}