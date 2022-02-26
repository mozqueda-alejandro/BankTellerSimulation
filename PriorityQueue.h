#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_


#include "QueueInterface.h"
#include "Node.h"

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>{
    private:
        std::unique_ptr<LinkedSortedList<ItemType>> slistPtr;
    public:
        SL_PriorityQueue();
        SL_PriorityQueue(const SL_PriorityQueue& pq);
        ~SL_PriorityQueue();

        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();

/** @throw  PrecondViolatedExcept if priority queue is empty. */
ItemType peekFront() const throw(PrecondViolatedExcept);
}; // end SL_PriorityQueue
#include "PriorityQueue.cpp"
#endif