#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE
#include "QueueInterface.h"
#include "Event.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType> {
private:
   static const int DEFAULT_CAPACITY = 50;
   ItemType items[DEFAULT_CAPACITY];
   int front; // Index to front of queue
   int back; // Index to back of queue
   int numItems; // Number of items in queue
   
public:
   ArrayQueue();
   bool isEmpty() const;
   bool enqueue(const ItemType& newEntry);
   bool dequeue();
   
   /** @throw exception if queue is empty */
   ItemType peekFront() const;// throw(std::exception);
};

#include "ArrayQueue.cpp"
#endif