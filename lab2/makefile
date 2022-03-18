.PHONY = clean all
CXX = aarch64-linux-gnu-g++  #TX-2 complier 
CXXFLAGS =-std=c++11
OBJ = main.o
SRC = main.cpp
EXE = lab2
all: $(SRC)
		$(CXX) -o $(EXE) $^

%.o:%.c
		$(CXX) -c $< -o $@

clean:
		rm -rf $(EXE)
		rm -rf *.o
