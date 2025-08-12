# How to use...
# Compile (all) - In the terminal, run: make
# Compile (single) - In the terminal, run: make <target>
# Remove executables - In the terminal, run: make clean
# Run a file - In the terminal, run: ./<target>

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -MMD -MP -Iinclude

SOURCES := main.cpp $(shell find src -name '*.cpp')

OBJECTS := build/main.o $(patsubst src/%.cpp, build/%.o, $(filter-out main.cpp, $(SOURCES)))

DEPS := $(OBJECTS:.o=.d)

TARGET := main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)

build/%.o: src/%.cpp | build_dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/main.o: main.cpp | build_dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@

build_dirs:
	mkdir -p build/models build/service build/dao

clean:
	rm -rf $(TARGET) build