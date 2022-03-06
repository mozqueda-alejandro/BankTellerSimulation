#include "BankSim.h"

BankSim::BankSim() : 
    tellerFree(true),
    currentTime(0), 
    totalCustomers(0), 
    averageWait(0),
    maxWait(0), 
    averageLineLen(0),
    maxLineLen(0),
    numQueues(0) {}

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
    eventList.dequeue();
    // customer = customer referenced in arrivalEvent
    if (bankQueue.isEmpty() && tellerFree) {
        //std::cout << "Processing arrival at time:" << currentTime << std::endl;
        int departureTime = currentTime + arrivalEvent.getTransactionTime();
        Event newDepartureEvent(departureTime);
        eventList.enqueue(newDepartureEvent);
        tellerFree = false;
    } else{
        bankQueue.enqueue(arrivalEvent); // enqueue customer
    }
    totalCustomers++;
}

void BankSim::processDeparture(Event departureEvent) {
    eventList.dequeue();
    if (!bankQueue.isEmpty()) { 
    // Customer at front of line begins transaction  
        int departureTime = currentTime + bankQueue.peekFront().getTransactionTime();
        //std::cout << "Processing arrival at time:" << currentTime << std::endl;
        //std::cout << "Processing departure at time: "  << departureTime << std::endl;
        Event newDepartureEvent(departureTime);
        eventList.enqueue(newDepartureEvent);
        bankQueue.dequeue();
    } else {
        tellerFree  = true;
    }
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

    while (!eventList.isEmpty()) {
        Event newEvent = eventList.peekFront();
        currentTime = newEvent.getArrivalTime();
        std::cout << currentTime << "\t" << eventList << "\n" << std::endl;
        if (newEvent.isArrivalEvent()) {
            processArrival(newEvent);
            std::cout << "Processing arrival event at time: " << currentTime << std::endl;
        } else {
            processDeparture(newEvent);
            std::cout << "Processing departure event at time: " << (currentTime + bankQueue.peekFront().getTransactionTime());
        }
    }
}