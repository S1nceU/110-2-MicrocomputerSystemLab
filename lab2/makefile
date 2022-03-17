CXX = aarch64-linux-gnu-g++  #TX-2 complier 
OBJ = main.o
SRC = main.cpp
EXE = lab2
all: clean $(OBJ)
		$(CXX) $(OBJ) main.cpp -o $(EXE)

%.o:%.c
		$(CXX) -c $< -o $@

clean:
		rm -f $(EXE)
		rm -f *.o



