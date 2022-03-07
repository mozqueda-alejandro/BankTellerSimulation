#include "BankSim.h"

BankSim::BankSim() {
    initVars();
}

void BankSim::initVars() {
    eventList.clear();
    bankQueue.clear();
    tellerFree = true;
    currentTime = 0;
    previousTime = 0;
    totalCustomers = 0; 
    totalWait = 0.0f;
    
    maxWait = 0;
    totalLineLen = 0.0f;
    maxLineLen = 0;
    // numQueues = 0;
}

void BankSim::loadData() {
    int arrivalTime, transactionTime;
    std::ifstream infile;
    for (int repeats = 0; repeats < 3; repeats++) {
        if (fileName.empty()) {
            std::cout << "**To try the example in the README.MD enter:       \'r\'" << std::endl;
            std::cout << "**To try the example in the textbook enter:        \'t\'" << std::endl;
            std::cout << "**To try the example trace in Exercise 11 enter:   \'s\'" << std::endl;
            std::cout << "Enter bank simulation text file: ";
            std::cin >> fileName;
        }
        
        // Quick check
        if (fileName == "q") fileName = "random.txt";
        if (fileName == "r") fileName = "readmetest.txt";
        if (fileName == "t") fileName = "textbooktrace.txt";
        if (fileName == "s") fileName = "uexercise11.txt";

        infile.open(fileName);
        if (!infile) {
            std::cout << "Invalid file name" << std::endl;
            continue;
        }
        while (infile >> arrivalTime >> transactionTime) {
            Event newArrivalEvent(arrivalTime, transactionTime);
            // Type works here but not in enqueue
            // std::cout << "1-" << newArrivalEvent.getType() << "-2" << std::endl;
            eventList.enqueue(newArrivalEvent);
        }
        break;
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

        int currentWait = currentTime - bankQueue.peekFront().getArrivalTime();
        if (currentWait > maxWait) maxWait = currentWait;
        totalWait += currentWait;
        totalLineLen += bankQueue.getItemCount() * (currentTime - previousTime);
        bankQueue.dequeue();
    } else {
        tellerFree  = true;
    }
}

void BankSim::runSimulation(std::string flag) {
    loadData();
    if (flag == "trace") std::cout << "Trace of Bank Simulation\n" << std::endl;
    if (flag != "trace") std::cout << "Simulation Begins" << std::endl;
    while (!eventList.isEmpty()) {
        Event newEvent = eventList.peekFront();
        currentTime = newEvent.getArrivalTime();
        if (flag == "trace") std::cout << currentTime << "\t" << eventList << "\n" << std::endl;
        if (newEvent.isArrivalEvent()) {
            if (flag != "trace") std::cout << "Processing an arrival event at time: " << currentTime << std::endl;
            processArrival(newEvent);
        } else {
            if (flag != "trace") std::cout << "Processing a departure event at time: " << currentTime << std::endl;
            processDeparture(newEvent);
        }
        previousTime = currentTime;
    }
    if (flag != "trace") std::cout << "Simulation Ends\n" << std::endl;
}

void BankSim::printStats() const {
    std::cout << "Final Statistics:" << std::endl;
    std::cout << "\tTotal number of people processed:        " << totalCustomers << std::endl;
    std::cout << "\tAverage amount of time spent waiting:    " << (totalWait / totalCustomers) << std::endl;
    std::cout << "\tMaximum amount of time spent waiting:    " << maxWait << std::endl;
    std::cout << "\tAverage bank line length:                " << (totalLineLen / currentTime) << std::endl;
    std::cout << "\tMaximum bank line length:                " << maxLineLen << "\n\n" << std::endl;
}