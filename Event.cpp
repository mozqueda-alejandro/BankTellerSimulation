#include "Event.h"

Event::Event(std::string newType, int newArrivalTime) : 
    type(newType),
    arrivalTime(newArrivalTime) {}

Event::Event(std::string newType, int newArrivalTime, int newTransactionTime) : 
    type(newType), 
    arrivalTime(newArrivalTime),
    transactionTime(newTransactionTime) {}

// Greater priority object has smaller transactionTime
bool Event::operator>(const Event& rhs) {
    return transactionTime < rhs.transactionTime;
}

std::ostream& Event::operator<<(std::ostream& stream) {
    stream << "|" << type << "|";

    for (int i = std::to_string(arrivalTime).length(); i < 3; i++) {
        stream << "0";
    }
    stream << arrivalTime;
    stream << "|";

    for (int i = std::to_string(transactionTime).length(); i < 2; i++) {
        stream << "0";
    }
    stream << transactionTime;
    stream << "|";
    return stream;
}

std::string Event::getType() const {
    return type;
}

int Event::getArrivalTime() const {
    return arrivalTime;
}

int Event::getTransactionTime() const {
    return transactionTime;
}