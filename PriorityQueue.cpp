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
        // Queue has space to enqueue item
        back = (back + 1) % DEFAULT_CAPACITY;
        items[back] = newEntry;
        numItems++;
        canEnqueue = true;
    }
    return canEnqueue;
}

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
ItemType PriorityQueue<ItemType>::peekFront() const {// throw(exception) {
    if (isEmpty()) {
        throw ("Queue has no items");
    } else {
        return items[front];
    }
}