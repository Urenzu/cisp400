CXX=g++

PROJECT_O=String.o

CXXFLAGS= -c -Wall -g -std=c++14

EXE=M08

default : main.o $(PROJECT_O)
	$(CXX) main.o $(PROJECT_O) -o $(EXE)
main.o : main.cpp String.cpp
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm *.o $(EXE)
run:
	./$(EXE)
