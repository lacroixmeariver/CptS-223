out: main.o 
	g++ main.o -o main

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp testingClass.hpp


clean:
	rm -f *.o main

run:
	./main
