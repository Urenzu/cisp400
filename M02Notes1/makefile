CC=g++ 

CFLAGS= -g -c -Wall -std=c++14
EXENAME= M02Notes1

default: main.o 
	$(CC) -g main.o -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)