# How to use...
# Compile (all) - In the terminal, run: make
# Compile (single) - In the terminal, run: make <target>
# Remove executables - In the terminal, run: make clean
# Run a file - In the terminal, run: ./<target>

CXX = clang++
CXXFLAGS = -std=c++11 -Wall
SOURCES := $(wildcard *.cpp)
TARGET := main

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)