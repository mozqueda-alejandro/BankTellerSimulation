driver: driver.o Event.o BankSim.o
	g++ driver.o Event.o BankSim.o -o driver

driver.o: driver.cpp ArrayQueue.h PriorityQueue.h BankSim.h
	g++ -c driver.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

BankSim.o: BankSim.cpp BankSim.h
	g++ -c BankSim.cpp

clean:
	rm *.o driver