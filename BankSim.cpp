#include "BankSim.h"

BankSim::BankSim() : 
    tellerFree(true),
    currentTime(0), 
    totalCustomers(0), 
    totalWait(0),
    maxWait(0), 
    totalLineLen(0),
    maxLineLen(0),
    numQueues(0),
    totalWaitingTime(0.0),
    totalTransaction(0),
    totalDeparture(0),
    totalArrival(0) {}

void BankSim::loadData() {
    int arrivalTime, transactionTime;
    std::cout << "Enter bank simulation text file: ";
    std::string fileName;
    std::cin >> fileName;

    // Quick check
    if (fileName == "q") fileName = "test3.txt";
    if (fileName == "r") fileName = "readmetest.txt";
    if (fileName == "t") fileName = "textbooktrace.txt";

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
    // customer = customer referenced in arrivalEvent
    if (bankQueue.isEmpty() && tellerFree) {
        int departureTime = currentTime + arrivalEvent.getTransactionTime();
        Event newDepartureEvent(departureTime);
        eventList.enqueue(newDepartureEvent);
        tellerFree = false;
    } else{
        bankQueue.enqueue(arrivalEvent); // enqueue customer
    }
    std::cout << "Processing arrival event at time: " << currentTime << std::endl;
    totalArrival += arrivalEvent.getArrivalTime();
    totalTransaction += arrivalEvent.getTransactionTime();
    eventList.dequeue();
    totalCustomers++;
}

void BankSim::processDeparture(Event departureEvent) {
    eventList.dequeue();
    if (!bankQueue.isEmpty()) { 
    // Customer at front of line begins transaction
        Event customerEvent = bankQueue.peekFront();
        int departureTime = currentTime + bankQueue.peekFront().getTransactionTime();
        Event newDepartureEvent(departureTime);
        eventList.enqueue(newDepartureEvent);
        totalWait = currentTime - departureEvent.getArrivalTime();
        bankQueue.dequeue();
    } else {
        tellerFree  = true;
    }
    std::cout << "Processing departure event at time: " << currentTime << std::endl;
    totalDeparture += currentTime;
}

void BankSim::test() {
    // Event test1(9);
    // Event test2(15);
    // for (int i = 0; i < 8; i++) {
    //     Event test3(0);
    //     eventList.testenqueue(test3);
    // }

    // loadData();
    // eventList.enqueue(test2);
    // eventList.enqueue(test1);
    loadData();

    std::cout << "EVENT COUNT: " << eventList.getItemCount() << std::endl;

    // Print PQueue elements
    // while (eventList.peekFront().isArrivalEvent()) {
    //     std::cout << eventList.peekFront() << std::endl;
    //     eventList.dequeue();
    // }
    // std::cout << "div" << std::endl;
    // while (!eventList.isEmpty()) {
    //     std::cout << eventList.peekFront() << std::endl;
    //     eventList.dequeue();
    // }
    Event timeEvent = eventList.peekFront();
    currentTime = timeEvent.getArrivalTime();
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
    std::cout << "Simulation ends." << '\n' << std::endl;

    totalWaitingTime = (totalDeparture - totalTransaction - totalArrival)/totalCustomers;
    std::cout << "Final Statistics:" << std::endl;
    std::cout << "\tTotal number of people processed: " << totalCustomers << std::endl;
    std::cout << "\tAverage amount of time spent waiting: " << totalWaitingTime << std::endl;
}