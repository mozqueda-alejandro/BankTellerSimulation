#include "BankSim.h"

BankSim::BankSim() : 
    tellerFree(true),
    previousTime(0),
    totalCustomers(0), 
    totalWait(0.0f),
    maxWait(0), 
    totalLineLen(0.0f),
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
        totalLineLen += bankQueue.getItemCount() * (currentTime - previousTime);
        bankQueue.enqueue(arrivalEvent);
        if (bankQueue.getItemCount() > maxLineLen) {
            maxLineLen = bankQueue.getItemCount();
        }
    }
    eventList.dequeue();
    totalCustomers++;
}

void BankSim::processDeparture(Event departureEvent) {
    eventList.dequeue();
    if (!bankQueue.isEmpty()) { 
        int departureTime = currentTime + bankQueue.peekFront().getTransactionTime();
        Event newDepartureEvent(departureTime);
        eventList.enqueue(newDepartureEvent);

        // Wait/line length statistics
        int currentWait = currentTime - bankQueue.peekFront().getArrivalTime();
        if (currentWait > maxWait) {
            maxWait = currentWait;
        }
        totalWait += currentWait;
        totalLineLen += bankQueue.getItemCount() * (currentTime - previousTime);
        bankQueue.dequeue();
    } else {
        tellerFree  = true;
    }
}

void BankSim::runSimulation() {
    loadData();

    std::cout << "Simulation Begins" << std::endl;
    while (!eventList.isEmpty()) {
        Event newEvent = eventList.peekFront();
        currentTime = newEvent.getArrivalTime();
        if (newEvent.isArrivalEvent()) {
            std::cout << "Processing an arrival event at time: " << currentTime << std::endl;
            processArrival(newEvent);
        } else {
            std::cout << "Processing a departure event at time: " << currentTime << std::endl;
            processDeparture(newEvent);
        }
        previousTime = currentTime;
    }
    std::cout << "Simulation Ends\n" << std::endl;
}

void BankSim::printStats() {
    std::cout << "Final Statistics:" << std::endl;
    std::cout << "\tTotal number of people processed:        " << totalCustomers << std::endl;
    std::cout << "\tAverage amount of time spent waiting:    " << (totalWait / totalCustomers) << std::endl;
    std::cout << "\tMaximum amount of time spent waiting:    " << maxWait << std::endl;
    std::cout << "\tAverage bank line length:                " << (totalLineLen / currentTime) << std::endl;
    std::cout << "\tMaximum bank line length:                " << maxLineLen << "\n\n" << std::endl;
}

void BankSim::printTrace() {
    // std::cout << currentTime << "\t" << eventList << "\n" << std::endl;
}