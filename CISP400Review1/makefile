CC=g++ 

CFLAGS= -g -c -Wall -std=c++14
EXENAME= ReviewM01M04

default: main.o SemanticDictionary.o SemanticDescriptor.o
	$(CC) -g main.o SemanticDictionary.o SemanticDescriptor.o -o $(EXENAME)

main.o: main.cpp SemanticDictionary.h SemanticDescriptor.h
	$(CC) $(CFLAGS) main.cpp

SemanticDictionary.o: SemanticDictionary.cpp SemanticDictionary.h
	$(CC) $(CFLAGS) SemanticDictionary.cpp

SemanticDescriptor.o: SemanticDescriptor.cpp SemanticDescriptor.h
	$(CC) $(CFLAGS) SemanticDescriptor.cpp

clean: 
	rm *.o $(EXENAME)

run:
	./$(EXENAME)