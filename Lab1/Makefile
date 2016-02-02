driver: driver.o
	g++ driver.o -o driver

driver.o: driver.cpp graph.h adj_list.cpp
	g++ -c driver.cpp

clean:
	rm *.o driver
