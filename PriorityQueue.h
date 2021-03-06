#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include <iostream>
#include <sstream>
#include "QueueInterface.h"

template<class ItemType>
class PriorityQueue : public QueueInterface<ItemType>{
    private:
        static const int DEFAULT_CAPACITY = 30;
        ItemType items[DEFAULT_CAPACITY];
        int front; // Index to front of queue
        int back; // Index to back of queue
        int numItems; // Number of items in queue
    public:
        PriorityQueue();
        PriorityQueue(const PriorityQueue& pq);

        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();
        void clear();
        int getItemCount() const;

        ItemType peekFront() const;
        template<class T>
        friend std::ostream& operator<<(std::ostream& stream, const PriorityQueue<T>& priorityQueue);
};

#include "PriorityQueue.cpp"
#endif