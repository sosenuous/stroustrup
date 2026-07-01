CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

TARGET = main
SRC = main.cpp 

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

test: heap_test.cpp heap.h heap.cpp heapsort.h
	$(CXX) $(CXXFLAGS) heap_test.cpp -o heap_test
	./heap_test

clean:
	rm -f $(TARGET) heap_test
	