CC=g++ 

CFLAGS= -g -c -Wall -std=c++14
EXENAME= M04Copy

default: mainCopy.o MatricesCopy.o 
	$(CC) -g mainCopy.o MatricesCopy.o -o $(EXENAME)

mainCopy.o: mainCopy.cpp MatricesCopy.h
	$(CC) $(CFLAGS) mainCopy.cpp

MatricesCopy.o: MatricesCopy.cpp MatricesCopy.h
	$(CC) $(CFLAGS) MatricesCopy.cpp

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)