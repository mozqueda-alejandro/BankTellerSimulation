//Created by Cody Long and Alejandro Mozqueda
//GitHub team: mozqueda-long
#include <fstream>
#include "ArrayQueue.h"
#include "PriorityQueue.h"
#include "Event.h"

template<class ItemType>
void loadData(PriorityQueue<ItemType>& priorityQueue) {
    int arrivalTime, transactionTime;
    std::cout << "Enter bank simulation text file: ";
    std::string fileName;
    std::cin >> fileName;

    // Quick check
    if (fileName == "q") fileName = "test3.txt";

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
    
//TEST
    // Event event1("A", 1, 1);
    // Event event2("A", 1, 0);
    // Event arr[7] = {event1, event2};
    // eventList.testenqueue(event1);
    // eventList.testenqueue(event2);

    // for (int i = 0; i < 50; i++) {
    //     Event event1("", 0, 0);
    //     eventList.testenqueue(event1);
    // }

    loadData(eventList);
    std::cout << "EVENT COUNT: " << eventList.getItemCount() << std::endl;

    while (!eventList.isEmpty()) {
        std::cout << eventList.peekFront() << std::endl;
        eventList.dequeue();
    }


//PSEUDOCODE
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