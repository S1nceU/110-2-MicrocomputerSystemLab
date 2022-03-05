CXX = g++
CXXFLAGS =-std=c++11
HEADER = circular_sector.h ellipse.h sort.h triangle.h
OBJ = circular_sector.o ellipse.o sort.o triangle.o
SRC = circular_sector.cpp ellipse.cpp sort.cpp triangle.cpp
EXE = lab1
all: clean $(OBJ)
		$(CXX) $(OBJ) main.cpp -o $(EXE)

%.o:%.c
		$(CXX) -c $< -o $@

clean:
		rm -f $(EXE)
		rm -f *.o




