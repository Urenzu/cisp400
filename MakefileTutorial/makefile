CC=g++ 

CFLAGS= -g -c -Wall -std=c++14
EXENAME= hello

default: main.o factorial.o hello.o 
	$(CC) main.o factorial.o hello.o -o $(EXENAME)

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

factorial.o: factorial.cpp 
	$(CC) $(CFLAGS) factorial.cpp 

hello.o: hello.cpp 
	$(CC) $(CFLAGS) hello.cpp 

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)