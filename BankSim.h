#ifndef BANK_SIM
#define BANK_SIM

#include <fstream>
#include "ArrayQueue.h"
#include "PriorityQueue.h"
#include "Event.h"

class BankSim {
private:
    bool tellerFree;
    int currentTime; // peekFront().getArrivalTime()
    double totalCustomers;
    /**
     * Easy implementation: (SUM: For front/being served customers ( currentTime - arrivalTime ) ) / totalCustomers
     * 
     * Instantaneous wait: (SUM: For every BankQueue arrival (For every notServed (currentTime-arrivalTime) + beingServed.partialWait) ) ) / totalCustomers
     * Validation for partialWait if chosen time interval ends while customer, who previously waited, is being served
     * In this case currentTime - arrivalTime > actualWait
     * ex. averageWait from 0 to 15(currentTIme), arrivalTime = 5, servedAt = 10, actualWait = 5; calculatedWait = 10
     */
    float totalWait; //averageWeight

    /**
     * Extra Credit
     */
    float maxWait; // max_element during averageWait loop
    float totalLineLen; // averageLineLen // ((currentTime - lastTime) * lineLen) / (Last arrivalTime + transactionTime)
    int maxLineLen; // max_element (currentTime - lastTime) * lineLen)

    int numQueues;
    static const int DEFAULT_QUEUES = 5;
    ArrayQueue<Event> bankQueues[DEFAULT_QUEUES];
    ArrayQueue<Event> bankQueue;
    PriorityQueue<Event> eventList; 
public:
    BankSim();

    void loadData();
    void processArrival(Event arrivalEvent);
    void processDeparture(Event departureEvent);

    void test();
};

#endif //BANK_SIM

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