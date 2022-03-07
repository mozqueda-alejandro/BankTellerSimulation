#include "Event.h"

const std::string Event::DEFAULT_ARRIVAL = "A";
const std::string Event::DEFAULT_DEPARTURE = "D";

Event::Event() : type(""), arrivalTime(0), transactionTime(0) {}

Event::Event(int newArrivalTime, std::string newType) {
    arrivalTime = newArrivalTime;
    transactionTime = 0;
    type = newType;
} 

Event::Event(int newArrivalTime, int newTransactionTime, std::string newType) {
    arrivalTime = newArrivalTime;
    transactionTime = newTransactionTime;
    type = newType;
} 

// Greater priority object has smaller arrivalTime
// Format: queueItem > toEnqueueItem
bool Event::operator>(const Event& rhs) {
    return (arrivalTime <= rhs.arrivalTime); // Add: type == "A" || rhs.type == "D"
}

// Lesser priority object has larger transactionTime
// Format: queueItem < toEnqueueItem
bool Event::operator<(const Event& rhs) {
    return arrivalTime > rhs.arrivalTime;
}

std::ostream& operator<<(std::ostream& stream, const Event& event) {
    int typeLen = (event.type).length();
    int arrivalLen = 4, transactionLen = 3;
    
    if (std::to_string(event.arrivalTime).length() > arrivalLen) {
        std::cout << "error1\n";
        throw std::runtime_error("Event.cpp: error in operator<<: Arrival time cannot be formatted properly");
    } else if (std::to_string(event.transactionTime).length() > transactionLen) {
        std::cout << "error2\n";
        throw std::runtime_error("Event.cpp: error in operator<<: Transaction time cannot be formatted properly");
    } else {
        // for (int i = 0; i < typeLen + arrivalLen + transactionLen + 4; i++) {
        //     stream << "_";
        // }
        // stream << "\n";

        stream << "|" << event.type << "|";
        for (int i = std::to_string(event.arrivalTime).length(); i < arrivalLen; i++) {
            stream << "0";
        }
        stream << event.arrivalTime;
        stream << "|";
        for (int i = std::to_string(event.transactionTime).length(); i < transactionLen; i++) {
            if (event.type == event.DEFAULT_ARRIVAL) {
                stream << "0";
            } else {
                stream << "-";
            }
        }
        if (event.type == event.DEFAULT_ARRIVAL) {
            stream << event.transactionTime;
        } else {
            stream << "-";
        }
        stream << "|\t";

        // stream << "\n";
        // for (int i = 0; i < typeLen + arrivalLen + transactionLen + 4; i++) {
        //     stream << "\u203E";
        // }
    }
    // Processing Print function . . .
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

bool Event::isArrivalEvent() const {
    return type == DEFAULT_ARRIVAL;
}

int Event::getArrivalTime() const {
    return arrivalTime;
}

int Event::getTransactionTime() const {
    return transactionTime;
}