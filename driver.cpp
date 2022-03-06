//Created by Cody Long and Alejandro Mozqueda
//GitHub team: mozqueda-long
#include <fstream>
#include "ArrayQueue.h"
#include "PriorityQueue.h"
#include "Event.h"

int currentTime = 0;
bool tellerFree = true;

template<class ItemType>
void loadData(PriorityQueue<ItemType>& priorityQueue) {
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
        priorityQueue.enqueue(newArrivalEvent);
    }
    infile.close();
}

template<class ItemType>
void processArrival(Event arrivalEvent, PriorityQueue<ItemType>& eventList, ArrayQueue<ItemType>& bankQueue) {
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
}

template<class ItemType>
void processDeparture(Event departureEvent, PriorityQueue<ItemType>& eventList, ArrayQueue<ItemType>& bankQueue) {
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

int main() {
    ArrayQueue<Event> bankQueue;
    PriorityQueue<Event> eventList;
    bool tellerAvailable = true;
    //int currentTime; // peekFront().getArrivalTime()
    int totalCustomers; // processArrival() { totalCustomers++ }
    /**
     * Easy implementation: (SUM: For front/being served customers ( currentTime - arrivalTime ) ) / totalCustomers
     * 
     * Instantaneous wait: (SUM: For every BankQueue arrival (For every notServed (currentTime-arrivalTime) + beingServed.partialWait) ) ) / totalCustomers
     * Validation for partialWait if chosen time interval ends while customer, who previously waited, is being served
     * In this case currentTime - arrivalTime > actualWait
     * ex. averageWait from 0 to 15(currentTIme), arrivalTime = 5, servedAt = 10, actualWait = 5; calculatedWait = 10
     */
    float averageWait;

    float maxWait; // max_element during averageWait loop
    float averageLineLen; // ((currentTime - lastTime) * lineLen) / (Last arrivalTime + transactionTime)
    int maxLineLen; // max_element (currentTime - lastTime) * lineLen)
    
//TEST
    // Event test1(9);
    // Event test2(15);
    // for (int i = 0; i < 8; i++) {
    //     Event test3(0);
    //     eventList.testenqueue(test3);
    // }

    // loadData(eventList);
    // eventList.enqueue(test2);
    // eventList.enqueue(test1);
    loadData(eventList);

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
            processArrival(newEvent, eventList, bankQueue);
        } else {
            processDeparture(newEvent, eventList, bankQueue);
        }
    }

    return 0;
};

// b. Add some statistics to the simulation. For example, compute the maximum wait in line, the average 
// length of the line, and the maximum length of the line.  
// c. Modify the simulation so that it accounts for three tellers, each with a distinct line. You should keep in 
// mind that there should be 
// •   Three queues, one for each teller  
// •   A rule that chooses a line when processing an arrival event (for example, enter the shortest line)  
// •   Three distinct departure events, one for each line  
// •   Rules for breaking ties in the event list   
// Run  both  this  simulation  and  the  original  simulation  on  several  sets  of  input  data.  How  do  the  statistics  
// compare?
// d. The bank is considering the following change: Instead of having three distinct lines (one for each 
// teller), there will be a single line for the three tellers. The person at the front of the line will go to the 
// fi rst available teller. Modify the simulation of part  c  to account for this variation. Run both simulations 
// on several sets of input data. How do the various statistics compare (averages and maximums)? What 
// can you conclude about having a single line as opposed to having distinct lines?