driver: driver.o
	g++ driver.o -o driver

driver.o: driver.cpp ArrayQueue.h PriorityQueue.h LinkedStack.h Node.h
	g++ -c driver.cpp

clean:
	rm *.o driver