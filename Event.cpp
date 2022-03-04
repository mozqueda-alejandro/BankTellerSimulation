#include "Event.h"

Event::Event() : type(""), arrivalTime(0), transactionTime(0) {}

Event::Event(int newArrivalTime, std::string newType = "D") {
    arrivalTime = newArrivalTime;
    transactionTime = 0;
    type = newType;
} 

Event::Event(int newArrivalTime, int newTransactionTime, std::string newType = "A") {
    arrivalTime = newArrivalTime;
    transactionTime = newTransactionTime;
    type = newType;
} 

// Format: queueItem > toEnqueueItem
// Greater priority object has smaller arrivalTime
bool Event::operator>(const Event& rhs) {
    return (arrivalTime <= rhs.arrivalTime); // Add: type == "A" || rhs.type == "D"
}

// Lesser priority object has larger transactionTime
bool Event::operator<(const Event& rhs) {
    return arrivalTime > rhs.arrivalTime;
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