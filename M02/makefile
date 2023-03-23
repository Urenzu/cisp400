CC=g++ 

CFLAGS= -g -c -Wall -std=c++14
EXENAME= M02

default: main.o RSA.o
	$(CC) -g main.o RSA.o -o $(EXENAME)

main.o: main.cpp RSA.h
	$(CC) $(CFLAGS) main.cpp

RSA.o: RSA.cpp RSA.h
	$(CC) $(CFLAGS) RSA.cpp  

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)