CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

TARGET = main
SRC = main.cpp structures.cpp Heap.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
	