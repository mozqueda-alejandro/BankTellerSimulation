#include "ArrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : 
    front(0),
    back(DEFAULT_CAPACITY - 1),
    numItems(0) {}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
   return numItems == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry) {
    bool canEnqueue = false;
    if (numItems < DEFAULT_CAPACITY) {
        back = (back + 1) % DEFAULT_CAPACITY;
        items[back] = newEntry;
        numItems++;
        canEnqueue = true;
    }
    return canEnqueue;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() {
    bool canDequeue = false;
    if (!isEmpty()) {
        front = (front + 1) % DEFAULT_CAPACITY;
        numItems--;
        canDequeue = true;
    }
    return canDequeue;
}

template<class ItemType>
void ArrayQueue<ItemType>::clear() {
    while (dequeue()) {}
    front = 0;
    back = DEFAULT_CAPACITY - 1;
    numItems = 0;
}

template<class ItemType>
int ArrayQueue<ItemType>::getItemCount() const{
    return numItems;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {// throw(exception) {
    if (isEmpty()) {
        std::cout << "error4\n";
        throw ("Queue has no items");
    } else {
        return items[front];
    }
}

template<class T>
std::ostream& operator<<(std::ostream& stream, const ArrayQueue<T>& arrayQueue) {
    for (int i = 0; i < + arrayQueue.numItems; i++) {
        stream << arrayQueue.items[(arrayQueue.front + i) % arrayQueue.DEFAULT_CAPACITY];
    }
    return stream;
}