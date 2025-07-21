# How to use...
# Compile (all) - In the terminal, run: make
# Compile (single) - In the terminal, run: make <target>
# Remove executables - In the terminal, run: make clean
# Run a file - In the terminal, run: ./<target>

CXX = clang++
SOURCES := $(wildcard *.cpp)
TARGETS := $(SOURCES:.cpp=)

all: $(TARGETS)

%: %.cpp
	$(CXX) -o $@ $<

clean:
	rm -f $(TARGETS)