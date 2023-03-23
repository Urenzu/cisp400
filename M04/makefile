CC=g++ 

CFLAGS= -g -c -Wall -std=c++14
EXENAME= M04

default: main.o Matrices.o 
	$(CC) -g main.o Matrices.o -o $(EXENAME)

main.o: main.cpp Matrices.h
	$(CC) $(CFLAGS) main.cpp

Matrices.o: Matrices.cpp Matrices.h
	$(CC) $(CFLAGS) Matrices.cpp

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)