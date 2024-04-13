# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source directory
SRCDIR = src

# Main source file (outside src directory)
MAIN = main.cpp

# Main executable name
EXECUTABLE = project

# Find all .cpp files in subdirectories of Class (Data, Items, Player)
SRCS := $(wildcard $(SRCDIR)/Class/Data/*.cpp) \
        $(wildcard $(SRCDIR)/Class/Items/*.cpp) \
        $(wildcard $(SRCDIR)/Class/Player/*.cpp)

# Exclude files in folderDriver directories
SRCS := $(filter-out %/Driver/%, $(SRCS))

# Object files derived from source files
OBJS := $(SRCS:.cpp=.o)

.PHONY: all clean

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile each .cpp file into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the main executable
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean up
clean:
	rm -f $(OBJS) $(EXECUTABLE)
