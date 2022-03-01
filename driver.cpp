//Created by Cody Long and Alejandro Mozqueda
//GitHub team: mozqueda-long
#include <fstream>
#include "ArrayQueue.h"
#include "PriorityQueue.h"
#include "Event.h"

template<class ItemType>
void loadData(PriorityQueue<ItemType>& priorityQueue) {
    int arrivalTime, transactionTime;
    std::string fileName;
    std::cin >> fileName;

    std::ifstream infile;
    infile.open(fileName);
    while (infile >> arrivalTime >> transactionTime) {
        Event newArrivalEvent("A", arrivalTime, transactionTime);
        priorityQueue.enqueue(newArrivalEvent);
    }
    infile.close();
}

template<class ItemType>
void processArrival(bool tellerFree, PriorityQueue<ItemType>& priorityQueue, ArrayQueue<ItemType>& bankQueue) {
    // // Remove this event from the event list
    // eventListPQueue.remove()
    // customer = customer referenced in arrivalEvent
    // if (bankQueue.isEmpty() && tellerAvailable) {
    //     departureTime = currentTime + transaction time in arrivalEvent
    //     newDepartureEvent = a new departure event with departureTime
    //     eventListPQueue.add(newDepartureEvent)
    //     tellerAvailable = false
    // }
    // else
    // bankQueue.enqueue(customer)

}

template<class ItemType>
void processDeparture(bool tellerFree, PriorityQueue<ItemType>& priorityQueue, ArrayQueue<ItemType>& bankQueue) {
    // Processes a departure event .
    
    // //Event currentEvent = priorityQueue.peekFront();
    // // Remove this event from the event list  
    // priorityQueue.remove();
    // if (!bankQueue.isEmpty()) { 
    // // Customer at front of line begins transaction  
    //     customer = bankQueue.peek() 
    //     bankQueue.dequeue() 
    //     departureTime = currentTime + transaction time in customer
    //     newDepartureEvent =  a new departure event with departureTime 
    //     eventListPQueue.add(newDepartureEvent) 
    // } 
    // else {
    //     tellerAvailable  = true
    // }
}

int main() {
    ArrayQueue<Event> bankQueue;
    PriorityQueue<Event> eventList;
    bool tellerAvailable = true;
    loadData(eventList);

    while (!eventList.isEmpty()) {
        std::cout << eventList.peekFront() << std::endl;
        eventList.dequeue();
    }

    // while (!eventList.isEmpty()) {
    //     newEvent = eventListPQueue.peek()
    //     // Get current time
    //     currentTime = time of newEvent
    //     if (newEvent == type arrivalEvent)
    //     processArrival(newEvent, eventListPQueue, bankQueue)
    //     else
    //     processDeparture(newEvent, eventListPQueue, bankQueue)
    // }


    return 0;
};