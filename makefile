driver: driver.o
	g++ driver.o -o driver

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm*.o driver