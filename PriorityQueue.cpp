#include "PriorityQueue.h"

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue() : 
    front(0),
    back(DEFAULT_CAPACITY - 1),
    numItems(0) {}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
   return numItems == 0;
}

template<class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry) {
    bool canEnqueue = false;
        if (numItems < DEFAULT_CAPACITY) {          
            for (int i = 0; i < DEFAULT_CAPACITY - 1; i++) {
                int index = (back - i + DEFAULT_CAPACITY) % DEFAULT_CAPACITY;
                // First enqueue has no type
                if (items[index] > newEntry) {
                    // std::cout << "1-" << items[index].getType() << "-2" << std::endl;
                    back = (back + 1) % DEFAULT_CAPACITY;
                    items[(index + 1) % DEFAULT_CAPACITY] = newEntry;
                    numItems++;
                    break;
                } else {
                    items[(index + 1) % DEFAULT_CAPACITY] = items[index];
                }
            }
            canEnqueue = true;
        }
    return canEnqueue;
}
// Extra
// if (items[front].getArrivalTime() + items[front].getTransactionTime() < newEntry.getTransactionTime()) {
//     break;
// }

template<class ItemType>
bool PriorityQueue<ItemType>::dequeue() {
    bool canDequeue = false;
    if (!isEmpty()) {
        front = (front + 1) % DEFAULT_CAPACITY;
        numItems--;
        canDequeue = true;
    }
    return canDequeue;
}

template<class ItemType>
int PriorityQueue<ItemType>::getItemCount() const{
    return numItems;
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peekFront() const {// throw(exception) {
    if (isEmpty()) {
        std::cout << "error3\n";
        throw ("Queue has no items");
    } else {
        return items[front];
    }
}

template<class T>
std::ostream& operator<<(std::ostream& stream, const PriorityQueue<T>& priorityQueue) {
    //std::ostringstream temp;
    // try {
        for (int i = 0; i < + priorityQueue.numItems; i++) {
            /*temp*/stream << priorityQueue.items[(priorityQueue.front + i) % priorityQueue.DEFAULT_CAPACITY];
        }
        //stream << temp.rdbuf();
    // } catch(const std::exception& e) {
    //     stream << e.what();
    // }
    return stream;
}