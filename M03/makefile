CC=g++
CFLAGS= -g -c -Wall -std=c++14
EXENAME= M03

default: main.o calculator.o Token_stream.o
	$(CC) -g main.o calculator.o Token_stream.o -o $(EXENAME)

main.o: main.cpp calculator.h Token_stream.h
	$(CC) $(CFLAGS) main.cpp

calculator.o: calculator.cpp calculator.h
	$(CC) $(CFLAGS) calculator.cpp

Token_stream.o: Token_stream.cpp Token_stream.h
	$(CC) $(CFLAGS) Token_stream.cpp

clean:
	rm *.o $(EXENAME)

run:
	./$(EXENAME)
