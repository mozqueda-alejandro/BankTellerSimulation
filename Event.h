#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event {
private:
    std::string type;
    int arrivalTime;
    int transactionTime;
public:
    Event();
    Event(std::string type, int arrivalTime);
    Event(std::string type, int arrivalTime, int transactionTime);

    bool operator>=(const Event& rhs);
    bool operator<(const Event& rhs);
    friend std::ostream& operator<<(std::ostream& stream, const Event& event);
    std::string getType() const;
    int getArrivalTime() const;
    int getTransactionTime() const;
};

#endif