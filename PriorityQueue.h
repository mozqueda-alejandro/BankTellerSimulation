#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include "QueueInterface.h"

template<class ItemType>
class PriorityQueue : public QueueInterface<ItemType>{
    private:
        static const int DEFAULT_CAPACITY = 8;
        ItemType items[DEFAULT_CAPACITY];
        int front; // Index to front of queue
        int back; // Index to back of queue
        int numItems; // Number of items in queue
    public:
        PriorityQueue();
        PriorityQueue(const PriorityQueue& pq);
        // ~PriorityQueue();

        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        // bool testenqueue(const ItemType& newEntry);
        bool dequeue();
        int getItemCount() const;

        /** @throw  PrecondViolatedExcept if priority queue is empty. */
        ItemType peekFront() const;// throw(PrecondViolatedExcept);
};

#include "PriorityQueue.cpp"
#endif