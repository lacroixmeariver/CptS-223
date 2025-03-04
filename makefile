out: main.o 
	g++ main.o -o main

main.o: main.cpp testingClass.hpp
	g++ -g -Wall -std=c++11 -c main.cpp 


clean:
	rm -f *.o main

run:
	./main
