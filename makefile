out: main.o BST.h
	g++ -g main.o -o main

main.o: main.cpp BST.h
	g++ -c -g -Wall -std=c++11  main.cpp 

clean: 
	-rm *.o
run:
	./main