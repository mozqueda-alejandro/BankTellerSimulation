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
                // if (items[front].getArrivalTime() + items[front].getTransactionTime() < newEntry.getTransactionTime()) {
                //     break;
                // }
                // More validations needed
                int index = (back - i + DEFAULT_CAPACITY) % DEFAULT_CAPACITY;
                if (items[index] >= newEntry) {
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

// static bool firstEnqueue = true;
// if (firstEnqueue) {
//     front = 0;
//     back = DEFAULT_CAPACITY - 1;
//     numItems = 0;
//     firstEnqueue = false;
// }

// template<class ItemType>
// bool PriorityQueue<ItemType>::testenqueue(const ItemType& newEntry) {
//     static int count = 1;
//     bool canEnqueue = false;
//     if (numItems < DEFAULT_CAPACITY) {
//         //Event event1("A", 1, 1);
//         if (items[0] >= newEntry) {
//             back = (back + 1) % DEFAULT_CAPACITY;
//             items[back] = newEntry;
//             numItems++;
//             canEnqueue = true;
//             std::cout << "SUCCESS: " << count << std::endl;
//         } else {
//             std::cout << "FAILURE: " << count << std::endl;
//         }
//     }
//     count++;
//     return canEnqueue;
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
        throw ("Queue has no items");
    } else {
        return items[front];
    }
}