#include "Event.h"

Event::Event() : 
    type(""),
    arrivalTime(0),
    transactionTime(0) {}

Event::Event(std::string newType, int newArrivalTime) : 
    type(newType),
    arrivalTime(newArrivalTime) {}

Event::Event(std::string newType, int newArrivalTime, int newTransactionTime) : 
    type(newType), 
    arrivalTime(newArrivalTime),
    transactionTime(newTransactionTime) {}

// // Greater priority object has smaller transactionTime
// bool Event::operator>(const Event& rhs) {
//     return transactionTime < rhs.transactionTime;
// }

// Greater priority object has smaller transactionTime
bool Event::operator>=(const Event& rhs) {
    return transactionTime <= rhs.transactionTime;
}

// Lesser priority object has larger transactionTime
bool Event::operator<(const Event& rhs) {
    return transactionTime > rhs.transactionTime;
}

std::ostream& operator<<(std::ostream& stream, const Event& event) {
    int typeLen = (event.type).length();
    int arrivalLen = 4, transactionLen = 3;
    for (int i = 0; i < typeLen + arrivalLen + transactionLen + 4; i++) {
        stream << "_";
    }
    stream << "\n|" << event.type << "|";
    for (int i = std::to_string(event.arrivalTime).length(); i < arrivalLen; i++) {
        stream << "0";
    }
    stream << event.arrivalTime;
    stream << "|";
    for (int i = std::to_string(event.transactionTime).length(); i < transactionLen; i++) {
        stream << "0";
    }
    stream << event.transactionTime;
    stream << "|\n";
    for (int i = 0; i < typeLen + arrivalLen + transactionLen + 4; i++) {
        stream << "\u203E";
    }
    // stream << "Processing a";
    // if (event.type == "A") {
    //     stream << "n arrival";
    // } else if (event.type == "D") {
    //     stream << " departure";
    // }
    // stream << " event at time: ";// << time;
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