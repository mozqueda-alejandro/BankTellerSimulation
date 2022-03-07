#include "BankSim.h"

BankSim::BankSim() : 
    tellerFree(true),
    currentTime(0), 
    totalCustomers(0), 
    totalWait(0.0f),
    maxWait(0), 
    totalLineLen(0),
    maxLineLen(0),
    numQueues(0) {}

void BankSim::loadData() {
    int arrivalTime, transactionTime;
    std::cout << "Enter bank simulation text file: ";
    std::string fileName;
    std::cin >> fileName;

    // Quick check
    if (fileName == "q") fileName = "random.txt";
    if (fileName == "r") fileName = "readmetest.txt";
    if (fileName == "t") fileName = "textbooktrace.txt";
    if (fileName == "s") fileName = "uexercise11.txt";

    std::ifstream infile;
    infile.open(fileName);
    while (infile >> arrivalTime >> transactionTime) {
        Event newArrivalEvent(arrivalTime, transactionTime);
        // Type works here but not in enqueue
        // std::cout << "1-" << newArrivalEvent.getType() << "-2" << std::endl;
        eventList.enqueue(newArrivalEvent);
    }
    infile.close();
}

void BankSim::processArrival(Event arrivalEvent) {
    if (bankQueue.isEmpty() && tellerFree) {
        int departureTime = currentTime + arrivalEvent.getTransactionTime();
        Event newDepartureEvent(departureTime);
        eventList.enqueue(newDepartureEvent);
        tellerFree = false;
    } else{
        bankQueue.enqueue(arrivalEvent);
    }
    std::cout << "Processing arrival event at time: " << currentTime << std::endl;
    eventList.dequeue();
    totalCustomers++;
}

void BankSim::processDeparture(Event departureEvent) {
    eventList.dequeue();
    if (!bankQueue.isEmpty()) { 
    // Customer at front of line begins transaction
        int departureTime = currentTime + bankQueue.peekFront().getTransactionTime();
        Event newDepartureEvent(departureTime);
        eventList.enqueue(newDepartureEvent);
        totalWait += currentTime - bankQueue.peekFront().getArrivalTime();
        bankQueue.dequeue();
    } else {
        tellerFree  = true;
    }
    std::cout << "Processing departure event at time: " << currentTime << std::endl;
}

void BankSim::test() {
    loadData();

    std::cout << "Simulation Begins" << std::endl;
    while (!eventList.isEmpty()) {
        Event newEvent = eventList.peekFront();
        currentTime = newEvent.getArrivalTime();
        // std::cout << currentTime << "\t" << eventList << "\n" << std::endl;
        if (newEvent.isArrivalEvent()) {
            processArrival(newEvent);
        } else {
            processDeparture(newEvent);
        }
    }
    std::cout << "Simulation Ends\n" << std::endl;

    std::cout << "Final Statistics:" << std::endl;
    std::cout << "\tTotal number of people processed: " << totalCustomers << std::endl;
    std::cout << "\tAverage amount of time spent waiting: " << (totalWait / totalCustomers) << std::endl;
}