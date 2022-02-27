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

    std::string getType() const;
    int getArrivalTime() const;
    int getTransactionTime() const;
};