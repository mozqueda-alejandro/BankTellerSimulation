#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include "QueueInterface.h"

template<class ItemType>
class PriorityQueue : public QueueInterface<ItemType>{
    private:
        //std::unique_ptr<LinkedSortedList<ItemType>> slistPtr;
    public:
        PriorityQueue();
        PriorityQueue(const PriorityQueue& pq);
        ~PriorityQueue();

        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();

        /** @throw  PrecondViolatedExcept if priority queue is empty. */
        ItemType peekFront() const;// throw(PrecondViolatedExcept);
};

#include "PriorityQueue.cpp"
#endif