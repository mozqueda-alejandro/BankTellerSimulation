driver: driver.o event.o
	g++ driver.o event.o -o driver

driver.o: driver.cpp ArrayQueue.h PriorityQueue.h
	g++ -c driver.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

clean:
	rm *.o driver