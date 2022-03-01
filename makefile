driver: driver.o Event.o
	g++ driver.o Event.o -o driver

driver.o: driver.cpp ArrayQueue.h PriorityQueue.h
	g++ -c driver.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

clean:
	rm *.o driver