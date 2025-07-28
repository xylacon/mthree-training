# How to use...
# Compile (all) - In the terminal, run: make
# Compile (single) - In the terminal, run: make <target>
# Remove executables - In the terminal, run: make clean
# Run a file - In the terminal, run: ./<target>

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -MMD -MP
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(OBJECTS:.o=.d)
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)