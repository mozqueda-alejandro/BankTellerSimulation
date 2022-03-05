#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event {
private:
    std::string type;
    static const std::string DEFAULT_ARRIVAL;
    static const std::string DEFAULT_DEPARTURE;
    int arrivalTime;
    int transactionTime;
public:
    Event();
    Event(int arrivalTime, std::string type = DEFAULT_DEPARTURE);
    Event(int arrivalTime, int transactionTime, std::string type = DEFAULT_ARRIVAL);

    bool operator>(const Event& rhs);
    bool operator<(const Event& rhs);
    friend std::ostream& operator<<(std::ostream& stream, const Event& event);
    std::string getType() const;
    bool isArrivalEvent() const;
    int getArrivalTime() const;
    int getTransactionTime() const;
};

#endif