CXX      ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra

SRC := $(wildcard exercises/*.cpp)
BIN := $(patsubst exercises/%.cpp,build/%,$(SRC))

# `make`            -> build every lesson
# `make 01_vector`  -> build AND run one lesson (by its filename, no .cpp)
# `make clean`      -> remove the build folder

all: $(BIN)

build:
	mkdir -p build

build/%: exercises/%.cpp | build
	$(CXX) $(CXXFLAGS) $< -o $@

# Let you type e.g. `make 01_vector` to build + run a single lesson.
%: build/%
	@echo "----- running $* -----"
	@./build/$*

clean:
	rm -rf build

.PHONY: all clean
