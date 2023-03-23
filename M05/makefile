CXX=g++

PROJECT_0=Bmp.o Topograph.o

CXXFLAGS= -c -Wall -g -std=c++14

EXE=M05

default: main.o $(PROJECT_0)
	$(CXX) main.o $(PROJECT_0) -o $(EXE)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
Bmp.o: Bmp.cpp
	$(CXX) $(CXXFLAGS) Bmp.cpp
Topograph.o: Topograph.cpp Topograph.h
	$(CXX) $(CXXFLAGS) Topograph.cpp
clean:
	rm *.0 $(EXE)
run:
	./$(EXE)
